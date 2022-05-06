#ifndef BOOKRO_H
#define BOOKRO_H
#include <QMainWindow>
//#include <QWaylandKeyboard>
#include <QTimer>
#include <QDebug>
#include <QMenu>
#include "BookroSystemTrayIcon.h"

#include "emulation/xkeys.h"
#include "EvDevKeyboardListener.h"
#include "ScriptEngineLite.h"
#include "BookroEvTest.h"

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

    void on_lineEdit_3_returnPressed();

    void on_lineEdit_3_textChanged(const QString &arg1);

    void createTrayIcon();

    void showBookro();
private:
    Ui::Bookro *ui;

    QTimer * debugTimer;
    EvDevKeyboardListener * Listener;
    ScriptEngineLite * ScriptEngine;
    QMap<QString, QString> macros;
    int _triggerKeyStatus = 0;
    QString _lastMacroKeyName;
    bool _evdevTextChanged = false;
    BookroSystemTrayIcon * _tray;
};
#endif // BOOKRO_H
