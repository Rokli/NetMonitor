#include "dialogserver.h"
#include "ui_dialogserver.h"

DialogServer::DialogServer(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogServer)
{
    ui->setupUi(this);
}

DialogServer::~DialogServer()
{
    delete ui;
}
