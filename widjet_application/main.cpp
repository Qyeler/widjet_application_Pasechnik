#include "widjet_application.h"
#include <QtWidgets/QApplication>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    widjet_application w;
    w.show();
    return a.exec();
}