/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created: Mon Jul 29 20:13:54 2019
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QTableView>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QTableView *tableView;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(443, 628);
        tableView = new QTableView(Dialog);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(40, 10, 351, 461));
        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(60, 530, 93, 28));
        pushButton_2 = new QPushButton(Dialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(280, 530, 93, 28));
        pushButton_3 = new QPushButton(Dialog);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(320, 590, 93, 28));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Dialog", "\344\270\212\344\270\200\351\241\265", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Dialog", "\344\270\213\344\270\200\351\241\265", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("Dialog", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
