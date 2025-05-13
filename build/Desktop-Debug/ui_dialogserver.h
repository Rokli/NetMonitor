/********************************************************************************
** Form generated from reading UI file 'dialogserver.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGSERVER_H
#define UI_DIALOGSERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_DialogServer
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogServer)
    {
        if (DialogServer->objectName().isEmpty())
            DialogServer->setObjectName("DialogServer");
        DialogServer->resize(240, 320);
        buttonBox = new QDialogButtonBox(DialogServer);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(10, 270, 221, 41));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        retranslateUi(DialogServer);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, DialogServer, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, DialogServer, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(DialogServer);
    } // setupUi

    void retranslateUi(QDialog *DialogServer)
    {
        DialogServer->setWindowTitle(QCoreApplication::translate("DialogServer", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogServer: public Ui_DialogServer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGSERVER_H
