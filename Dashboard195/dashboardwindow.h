#ifndef DASHBOARDWINDOW_H
#define DASHBOARDWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class DashboardWindow; }
QT_END_NAMESPACE

class DashboardWindow : public QMainWindow
{
    Q_OBJECT

public:
    DashboardWindow(QWidget *parent = nullptr);
    ~DashboardWindow();
    int x = 0;
    int w = 10;
    int h = 50;
    int b = 100;

public slots:
    void setHoodAngle();
    void button_pressed();
    void button_2_pressed();
    void button_3_pressed();
    void button_4_pressed();
    void makeMap();

private:
    Ui::DashboardWindow *ui;
};
#endif // DASHBOARDWINDOW_H
