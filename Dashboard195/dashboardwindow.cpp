#include "dashboardwindow.h"
#include "ui_dashboardwindow.h"
#include "iostream"
#include <QMediaPlayer>
#include <QMediaPlaylist>

DashboardWindow::DashboardWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DashboardWindow)
{
    ui->setupUi(this);
    connect(ui->hoodAngle, &QProgressBar::valueChanged, this, &DashboardWindow::setHoodAngle);
    connect(ui->pushButton, &QPushButton::pressed, this, &DashboardWindow::button_pressed);
    connect(ui->rectangleGrow, &QPushButton::pressed, this, &DashboardWindow::button_2_pressed);
    connect(ui->changeBattery, &QPushButton::pressed, this, &DashboardWindow::button_3_pressed);
    connect(ui->Music, &QPushButton::pressed, this, &DashboardWindow::button_4_pressed);
}

DashboardWindow::~DashboardWindow()
{
    delete ui;
}

void DashboardWindow::makeMap()
{
    QGraphicsScene* scene = new QGraphicsScene();
    //QGraphicsRectItem *rect = scene.addRect(QRectF(0, 0, 100, 100));

    QGraphicsItem *item = scene->itemAt(50, 50, QTransform());
    scene->addRect(0, 0, w, h);

}


void DashboardWindow::button_pressed()
{
     std::cout << "Hello\n";
     ui->hoodAngle->setValue(x);
     x = x + 5;

     if (x > 25)
     {
         x = 0;
     }
}
void DashboardWindow::button_2_pressed()
{
    std::cout << "Bonjour\n";

     w = w + 20;
     h = h + 50;

     if (w >200)
     {
         w = 10;
     }
     if (h > 100)
     {
         h = 50;
     }

     makeMap();
}

void DashboardWindow::button_3_pressed()
{
    ui->Battery->setValue(b);
    b = b - 5;

    if (b <0)
    {
        b = 100;
    }

    if (b == 100)
    {
           //ui->Battery->setPalette(Qt::yellow);
        QPalette p = ui->Battery->palette();
            p.setColor(QPalette::Highlight, QColor(Qt::green));
            p.setColor(QPalette::HighlightedText, QColor(Qt::black));
            ui->Battery->setPalette(p);
    }
    if (b == 45)
    {
           //ui->Battery->setPalette(Qt::yellow);
        QPalette p = ui->Battery->palette();
            p.setColor(QPalette::Highlight, QColor(Qt::yellow));
            p.setColor(QPalette::HighlightedText, QColor(Qt::black));
            ui->Battery->setPalette(p);
    }
    if (b == 5)
    {
           //ui->Battery->setPalette(Qt::yellow);
        QPalette p = ui->Battery->palette();
            p.setColor(QPalette::Highlight, QColor(Qt::red));
            p.setColor(QPalette::HighlightedText, QColor(Qt::black));
            ui->Battery->setPalette(p);
    }
}

void DashboardWindow::button_4_pressed()
{
    std::cout << "Music\n";

    QMediaPlayer* player = new QMediaPlayer;

    //connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));

    QMediaPlaylist* playlist = new QMediaPlaylist(player);
    playlist->addMedia(QUrl::fromLocalFile("/home/team195/Downloads/FinalCountdown.mp3"));
    playlist->addMedia(QUrl::fromLocalFile("/home/team195/Downloads/FinalCountdown.mp3"));
    // ...
    playlist->setCurrentIndex(1);
    player->setVolume(100);
    player->play();

}
void DashboardWindow::setHoodAngle()
{
    //Set the hood angle to whatever x is.
}

