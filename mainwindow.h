#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Models/agent.h>
#include <Models/server.h>
#include <QVector>
#include <QMessageBox>

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

    void on_buttonDisconnect_clicked();

    void on_buttonSettingClient_clicked();

    void on_menuClient_clicked();

    void on_menuServer_clicked();
private:
    Server *server_;
    Agent *agent_;
    Ui::MainWindow *ui;
    QVector<Agent*> agents_;
    QMap<QWidget*, Agent*> tabToAgent_;
};
#endif // MAINWINDOW_H
