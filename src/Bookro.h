#ifndef BOOKRO_H
#define BOOKRO_H
#include <QMainWindow>
//#include <QWaylandKeyboard>
#include <QTimer>
#include <QWaylandCompositor>
#include <QDebug>

#include "emulation/xkeys.h"
#include "EvDevKeyboardListener.h"
#include "UInput.h"

#define db qDebug() << this <<

QT_BEGIN_NAMESPACE
namespace Ui
{
class Bookro;
}
QT_END_NAMESPACE

class Bookro : public QMainWindow
{
    Q_OBJECT

public:
    Bookro(QWidget *parent = nullptr);
    ~Bookro();

private:
    Ui::Bookro *ui;

    QTimer * debugTimer;
    EvDevKeyboardListener * Listener;
    UInput * input;
};
#endif // BOOKRO_H
