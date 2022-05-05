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

    input = new UInput();
    if(!input->init())
        db "WARNING: input failed to manifest. Will not be able to send keys at this time";

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

}

