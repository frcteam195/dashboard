#include "dashboardwindow.h"
#include "ui_dashboardwindow.h"
#include "iostream"
#include <QDateTime>
#include <QTextStream>
#include <QTime>
#include <QDate>


DashboardWindow::DashboardWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DashboardWindow)
{
    ui->setupUi(this);
    UpdateTime();
    ballcolor();
}

DashboardWindow::~DashboardWindow()
{
}

#include <QColor>
#include <QColorDialog>
void DashboardWindow::button_pressed(){}
void DashboardWindow::UpdateTime()
{
    QTextStream out(stdout);

    QDate cd = QDate::currentDate();
    QTime ct = QTime::currentTime();

    out << "Current date is:\n" << cd.toString();
    out << "Current time is:\n" << ct.toString();
    QString time_string = cd.toString();
    ui->Date->setText(time_string);

    QString hour_string = ct.toString();

    ui->Time->setTime(ct);

    ui->Color->setStyleSheet(QString("background-color: rgba(255, 0, 255, 255);"));
    ui->Color->repaint();
}
void DashboardWindow::ballcolor(){
    if( ball ==1)
    {
        ui->Color->setStyleSheet(QString("background-color: rgb(0,0,255);"));
        ui->Color->repaint();
    }
    else if (ball ==2)
    {
        ui->Color->setStyleSheet(QString("background-color: rgb(255,0,0);"));
        ui->Color->repaint();
    }
}

