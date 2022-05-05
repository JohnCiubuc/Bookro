#include "Bookro.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Bookro w;
    w.show();
    return a.exec();
}
