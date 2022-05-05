#include "Bookro.h"
#include "ui_Bookro.h"


Bookro::Bookro(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Bookro)
{
    ui->setupUi(this);
    this->hide();
    Listener = new EvDevKeyboardListener();
    ScriptEngine = new ScriptEngineLite();

    connect(Listener, &EvDevKeyboardListener::evdevKey, this, &Bookro::keyboardListener);

}

Bookro::~Bookro()
{
    delete ui;
}

void Bookro::keyboardListener(int key, int keyState)
{
    QString keyName = ScriptEngine->getDikName(key);
    db keyName <<   ", " << keyState;
    if (keyName == "DIK_APOSTROPHE")
        _triggerKeyStatus = keyState;

    if (keyName != "DIK_APOSTROPHE" && _triggerKeyStatus == 1 && keyState == 1)
    {
        triggerMacro(keyName);
    }
}

void Bookro::triggerMacro(QString keyName)
{
    _lastMacroKeyName = keyName;
    if (macros.contains(keyName))
    {
        ui->lineEdit->setText("'"+keyName);
        ui->lineEdit_2->setText(macros.value(keyName));
        ScriptEngine->key_backspace(2);
        ScriptEngine->key_send(macros.value(keyName));
    }
    else
    {
        this->show();
        QMainWindow::activateWindow();
        this->setFocus();
        ui->lineEdit->setText("'"+keyName);
    }
}


void Bookro::on_pushButton_clicked()
{
    macros[_lastMacroKeyName] = ui->lineEdit_2->text();
    ui->lineEdit_2->clear();
}

