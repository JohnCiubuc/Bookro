#ifndef BOOKRO_H
#define BOOKRO_H
#include <QMainWindow>
//#include <QWaylandKeyboard>
#include <QTimer>
#include <QWaylandCompositor>
#include <QDebug>

#include "emulation/xkeys.h"
#include "EvDevKeyboardListener.h"
#include "ScriptEngineLite.h"

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
public slots:
    void keyboardListener(int key, int keyState);
    void triggerMacro(QString);
private slots:
    void on_pushButton_clicked();

private:
    Ui::Bookro *ui;

    QTimer * debugTimer;
    EvDevKeyboardListener * Listener;
    ScriptEngineLite * ScriptEngine;
    QMap<QString, QString> macros;
    int debug = 0;
    QString _lastMacroKeyName;
};
#endif // BOOKRO_H
