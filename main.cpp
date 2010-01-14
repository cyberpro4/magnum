#include <QtGui/QApplication>
#include "ccodeeditor.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CCodeEditor w;
    w.show();
    return a.exec();
}
