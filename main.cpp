#include <QtGui/QApplication>
#include "widget.h"
#include <QTextCodec>
#include "menu_ui.h"
#include "login_widget.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GB2312"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());
//    menu_ui *menuui=new menu_ui;
//    menuui->show();
//    Widget w;
//    w.show();
    login_widget *b=new login_widget;
    b->show();
    return a.exec();
}
