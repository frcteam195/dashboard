#ifndef DASHBOARDWINDOW_H
#define DASHBOARDWINDOW_H

#include <QMainWindow>
#include <QTimer>

#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define MAXLINE  1024
#define BUFSIZE  1500

namespace Ui {
class DashboardWindow;
}

class DashboardWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DashboardWindow(QWidget *parent = 0);
    ~DashboardWindow();
    void init_osc_thread();
    void osc_step();

    bool socket_init();
    void connect_osc( std::string ip, int port );
    void send_heartbeat();
    void recieve_packet( char* buffer_in, int num_bytes );

    float robot_x;
    float robot_y;
    float robot_z;

    float robot_qx;
    float robot_qy;
    float robot_qz;
    float robot_qw;

    float robot_vx;
    float robot_vy;
    float robot_vz;

    float robot_vx_linear;
    float robot_vy_linear;
    float robot_vz_linear;

private:
    Ui::DashboardWindow *ui;
    QTimer* osc_timer;
	char buffer[BUFSIZE];
	char heartbeat_buffer[BUFSIZE];

    sockaddr_in recv_addr;
    sockaddr_in send_addr;
    int port;

    int fd;
};

#endif // DASHBOARDWINDOW_H