#ifndef DIALOGSERVER_H
#define DIALOGSERVER_H

#include <QDialog>

namespace Ui {
class DialogServer;
}

class DialogServer : public QDialog
{
    Q_OBJECT

public:
    explicit DialogServer(QWidget *parent = nullptr);
    ~DialogServer();

private:
    Ui::DialogServer *ui;
};

#endif // DIALOGSERVER_H
