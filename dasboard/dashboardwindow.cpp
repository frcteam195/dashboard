#include "dashboardwindow.h"
#include "ui_dashboardwindow.h"
#include "QFileDialog"
#include <iostream>
#include <math.h>
#include <a.out.h>
#include <QtMath>

DashboardWindow::DashboardWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DashboardWindow)
{
    ui->setupUi(this);
     updatemap();
     connect(ui->Up, &QPushButton::pressed, this, &DashboardWindow::Up);
     connect(ui->Down, &QPushButton::pressed, this, &DashboardWindow::Down);
     connect(ui->Left, &QPushButton::pressed, this, &DashboardWindow::Left);
     connect(ui->Right, &QPushButton::pressed, this, &DashboardWindow::Right);
}

DashboardWindow::~DashboardWindow()
{
    delete ui;
}
    void DashboardWindow::Up()
    {
        posy = posy - 5;
        direction =direction + 10;
        updatemap();
    }
    void DashboardWindow::Down()
    {
        posy = posy + 5;
        updatemap();
    }
    void DashboardWindow::Left()
    {
        posx = posx - 5;
        updatemap();
//    }e
    void DashboardWindow::Right()
    {
        posx = posx + 5;
        updatemap();
    }
    void DashboardWindow::updatemap(){


        QGraphicsScene* scene = new QGraphicsScene();
        QImage image("/home/sulicat/Downloads/field.png");
        QImage image2 = image.scaled(400, 200, Qt::KeepAspectRatio);


        QPixmap* item = new QPixmap(QPixmap::fromImage(image2));
        QGraphicsPixmapItem* PixMapItem =   scene->addPixmap(*item);


        double radians = qDegreesToRadians(direction);

        QGraphicsRectItem *rect = scene->addRect(QRectF(posx, posy, 24, 16));
         QGraphicsLineItem *line = scene->addLine(QLineF(posx, posy, posx + cos(radians) * 25,  posy + sin(radians) *25));
        ui->Map->setScene(scene);

//home/sulicat/Downloads/Maplayout.jpeg
}
