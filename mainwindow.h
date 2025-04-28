#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Models/agent.h>
#include <Models/server.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_buttonStart_clicked();

    void on_buttonStop_clicked();

    void on_buttonWrite_clicked();

    void on_buttonSendClient_clicked();

    void on_buttonDisconnect_clicked();

    void on_buttonSettingClient_clicked();

    void on_buttonConnect_clicked();

private:
    Server *server_;
    Agent *agent_;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
