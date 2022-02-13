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
public slots:
   void button_increase();
   void button_decrease();
   void dial_changed();
   void slider_changed();
   void check_box();


private:
    Ui::DashboardWindow *ui;
};
#endif // DASHBOARDWINDOW_H
