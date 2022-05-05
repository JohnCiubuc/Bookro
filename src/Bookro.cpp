#include "Bookro.h"
#include "ui_Bookro.h"


Bookro::Bookro(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Bookro)
{
    ui->setupUi(this);

    debugTimer = new QTimer;
    Listener = new EvDevKeyboardListener();
    ScriptEngine = new ScriptEngineLite();


    connect(Listener, &EvDevKeyboardListener::evdevKey, this, &Bookro::keyboardListener);
//    connect(debugTimer, &QTimer::timeout, this, [=]()
//    {
//        input->sendKey(0x33, UInput::Keypress);
//        db "test";
//        input->sendKey(0x33, UInput::Release);
////        as->sendKeyPressEvent(0x4A);
//    });
//    debugTimer->start(1000);
}

Bookro::~Bookro()
{
    delete ui;
}

void Bookro::keyboardListener(int key, int keyState)
{
    db ScriptEngine->getDikName(key) <<   ", " << keyState;
    if (ScriptEngine->getDikName(key) == "DIK_APOSTROPHE")
        debug=1;
    else if (ScriptEngine->getDikName(key) == "DIK_A" && debug == 1 && keyState == 1)
    {
        ScriptEngine->key_backspace(2);
        ScriptEngine->key_send("Test");
    }
    else debug=0;
}

