#include "dashboardwindow.h"
#include "ui_dashboardwindow.h"

#include <iostream>
#include "oscpp/server.hpp"
#include "oscpp/client.hpp"

DashboardWindow::DashboardWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DashboardWindow)
{
    ui->setupUi(this);

    init_osc_thread();
}

DashboardWindow::~DashboardWindow()
{
    delete osc_timer;
    delete ui;
}

void DashboardWindow::init_osc_thread()
{
	memset(buffer, 0, BUFSIZE);

    sockaddr recvFromAddr;
    socklen_t recvFromAddrSize;
    int numBytes = recvfrom(fd, &buffer, sizeof(buffer), MSG_WAITALL, &recvFromAddr, &recvFromAddrSize);
    OSCPP::Server::Packet oscPacket(&buffer, numBytes);
    //handlePacket(oscPacket, recvFromAddr);

    connect_osc( "10.1.95.5", 5809 );
    std::cout << " socket FD: " << fd << "\n";

    osc_timer = new QTimer(this);
    connect( osc_timer, &QTimer::timeout, this, &DashboardWindow::osc_step );
    osc_timer->start(50);

}

void DashboardWindow::osc_step()
{
    if( fd == -1 )
    {
        return;
    }

    // read input data if there is any
    sockaddr recvFromAddr;
    socklen_t recvFromAddrSize;

    memset( buffer, '\0', sizeof(buffer) );

    int num_bytes = recvfrom(fd,
                            &buffer,
                            sizeof(buffer),
                            MSG_DONTWAIT,
                            &recvFromAddr,
                            &recvFromAddrSize);
    if( num_bytes > 0 )
    {
        std::cout << "Broo you got: " << num_bytes << " bytes\n";
        recieve_packet( buffer, num_bytes );
    }

    send_heartbeat();
}

void DashboardWindow::send_heartbeat()
{
    OSCPP::Client::Packet heartbeat_packet( &heartbeat_buffer,
                                            BUFSIZE );

    memset( heartbeat_buffer, '\0', BUFSIZE );

    heartbeat_packet
        .openMessage("/RegisterRequestor", 1)
        .int32(1)
        .closeMessage();

    sendto(fd,
           heartbeat_buffer,
           heartbeat_packet.size(),
           0,
           (struct sockaddr*)&send_addr,
           sizeof(send_addr));
}

void DashboardWindow::recieve_packet( char* buffer_in, int num_bytes )
{

    OSCPP::Server::Packet packet(buffer_in, num_bytes);

    if( packet.isBundle() )
    {
    }
    else
    {
        // Convert to message
        OSCPP::Server::Message msg(packet);
        // Get argument stream
        OSCPP::Server::ArgStream args(msg.args());

        if( msg == "/RobotPose")
        {
            std::cout << args.float32() << " "
                      << args.float32() << " "
                      << args.float32() << " "
                      << "\n";
        }

    }

}

void DashboardWindow::connect_osc( std::string ip_in, int port_in )
{
    fd = socket(AF_INET,SOCK_DGRAM,0);
    if(fd<0)
    {
        std::cout << "[ERROR] " << "cannot open socket!";
        fd = -1;
        return;
    }

    port = port_in;

    memset(&recv_addr, 0, sizeof(recv_addr));
    recv_addr.sin_family = AF_INET;
    recv_addr.sin_addr.s_addr = INADDR_ANY;
    recv_addr.sin_port = htons(port);

    memset(&send_addr, 0, sizeof(send_addr));
    send_addr.sin_family = AF_INET;
    inet_pton(AF_INET, ip_in.c_str(), &(send_addr.sin_addr));
    send_addr.sin_port = htons(port);

	// Bind the socket with the server address
    if ( bind(fd, (const struct sockaddr *)&recv_addr, sizeof(recv_addr)) < 0 )
    {
        std::cout << "[ERROR] " << "bind failed" << "\n";
    }

}

