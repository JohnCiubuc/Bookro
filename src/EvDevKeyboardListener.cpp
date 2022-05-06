#include "EvDevKeyboardListener.h"

// Code adapted from https://stackoverflow.com/a/53255835

EvDevKeyboardListener::EvDevKeyboardListener(QObject *parent)
    : QObject{parent}
{
    _evdevTimer = new QTimer(this);
    connect(_evdevTimer, &QTimer::timeout, this, &EvDevKeyboardListener::evdevTimeout);
}

void EvDevKeyboardListener::updateEvDevice(QString dev)
{
    const char *eventDevice = dev.toLocal8Bit().data();

    const int fd = open(eventDevice, O_RDONLY | O_NONBLOCK);

    if (fd < 0)
    {
        qDebug() <<  "ERROR: cannot open device"<< eventDevice<<", " <<strerror(errno);
        return;
    }

    int err = libevdev_new_from_fd(fd, &_dev);

    if (err < 0)
    {
        qDebug() <<  "ERROR: cannot associate event device "<< strerror(-err);
        return;
    }

    qDebug("Device %s is open and associated w/ libevent\n", eventDevice);
}

void EvDevKeyboardListener::startMonitor(bool status)
{
    status ? _evdevTimer->start(1):_evdevTimer->stop();
}

void EvDevKeyboardListener::evdevTimeout()
{
    struct input_event ev;

    int err = libevdev_next_event(_dev, LIBEVDEV_READ_FLAG_NORMAL, &ev);

    if (err == 0 && ev.type == EV_KEY)
        emit evdevKey(ev.code, ev.value);
};
