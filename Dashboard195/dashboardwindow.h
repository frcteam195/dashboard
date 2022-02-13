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
    void UpdateTime();
    void ballcolor();
    int ball = 2;
public slots:
    void button_pressed();

private:
    Ui::DashboardWindow *ui;
};
#endif // DASHBOARDWINDOW_H
