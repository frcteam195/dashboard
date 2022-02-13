#include "dashboardwindow.h"
#include "ui_dashboardwindow.h"
#include "iostream"

DashboardWindow::DashboardWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DashboardWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::pressed, this, &DashboardWindow::button_increase);
    connect(ui->pushButton_3, &QPushButton::pressed, this, &DashboardWindow::button_decrease);
    connect(ui->dial, &QDial::valueChanged, this, &DashboardWindow::dial_changed);
    connect(ui->horizontalSlider, &QSlider::valueChanged, this, &DashboardWindow::slider_changed);
    connect(ui->checkBox, &QCheckBox::clicked, this, &DashboardWindow::check_box);

    QGraphicsScene* scene = new QGraphicsScene();

    QPixmap* item = new QPixmap("/home/team195/Downloads/meme6.png");
    QGraphicsPixmapItem* PixMapItem = scene->addPixmap(*item);
    ui->meme->setScene(scene);

    for(int i=0;i<=250;i++) {
        ui->listWidget->addItem(QString::number(i));
    }
}
DashboardWindow::~DashboardWindow()
{
    delete ui;
}

void DashboardWindow::button_increase(){
    ui->dial->setValue(ui->dial->value() + 10);
    ui->label->setText(QString("Flywheel Speed - ") + QString::number(ui->dial->value()) + QString("RPM"));
    ui->horizontalSlider->setValue(ui->dial->value());

}
void DashboardWindow::button_decrease(){
    ui->dial->setValue(ui->dial->value() - 10);
    ui->label->setText(QString("Flywheel Speed - ") + QString::number(ui->dial->value()) + QString("RPM"));
    ui->horizontalSlider->setValue(ui->dial->value());
}
void DashboardWindow::dial_changed(){
    ui->label->setText(QString("Flywheel Speed - ") + QString::number(ui->dial->value()) + QString("RPM"));
    ui->horizontalSlider->setValue(ui->dial->value());
    ui->progressBar->setValue((ui->dial->value()) * .4);
}
void DashboardWindow::slider_changed(){
    ui->label->setText(QString("Flywheel Speed - ") + QString::number(ui->dial->value()) + QString("RPM"));
    ui->dial->setValue(ui->horizontalSlider->value());
}
void DashboardWindow::check_box(){
    ui->label->setText(QString("Flywheel Speed - 0RPM"));
    ui->dial->setValue(0);
    ui->horizontalSlider->setValue(0);
    ui->checkBox->setChecked(false);
}





