#ifndef DASHBOARDWINDOW_H
#define DASHBOARDWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>


namespace Ui {
class DashboardWindow;
}

class DashboardWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DashboardWindow(QWidget *parent = 0);
    ~DashboardWindow();    void updatemap ();
    int posx = 0;
    int posy =0;
    double direction = 0.0;
public slots:
    void Up();
    void Down();
    void Left();
    void Right();
private:
    Ui::DashboardWindow *ui;
};

#endif // DASHBOARDWINDOW_H
