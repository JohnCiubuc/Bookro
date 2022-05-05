#include "Bookro.h"
#include "ui_Bookro.h"


Bookro::Bookro(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Bookro)
{
    ui->setupUi(this);

    debugTimer = new QTimer;
//    QWaylandCompositor comp = QWaylandCompositor();

//    QWaylandPointerPrivate::Resource *resource = view ? d->resourceMap().value(view->surface()->waylandClient()) : 0;
//    if (resource && !d->hasSentEnter)
//    {
//        uint32_t serial = d->compositor()->nextSerial();
//        QWaylandKeyboard *keyboard = d->seat->keyboard();
//        if (keyboard)
//        {
//            keyboard->sendKeyModifiers(view->surface()->client(), serial);
//        }
//        d->send_enter(resource->handle, serial, view->surface()->resource(),
//                      wl_fixed_from_double(d->localPosition.x()), wl_fixed_from_double(d->localPosition.y()));

//        d->focusDestroyListener.listenForDestruction(view->surface()->resource());
//        d->hasSentEnter = true;
//    }
    xkeys * key = new xkeys();
    connect(debugTimer, &QTimer::timeout, this, [=]()
    {
        key->pressKey_Dik(0x33);
        db "test";
        key->releaseKey_Dik(0x33);
//        as->sendKeyPressEvent(0x4A);
    });
    debugTimer->start(1000);
}

Bookro::~Bookro()
{
    delete ui;
}

