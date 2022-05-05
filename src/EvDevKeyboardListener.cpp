#include "EvDevKeyboardListener.h"

// Code adapted from https://stackoverflow.com/a/53255835

EvDevKeyboardListener::EvDevKeyboardListener(QObject *parent)
    : QObject{parent}
{
    const char *eventDevice = "/dev/input/event20";

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

    _evdevTimer = new QTimer(this);
    connect(_evdevTimer, &QTimer::timeout, this, &EvDevKeyboardListener::evdevTimeout);
    _evdevTimer->start(1);
}

void EvDevKeyboardListener::evdevTimeout()
{
    struct input_event ev;

    int err = libevdev_next_event(_dev, LIBEVDEV_READ_FLAG_NORMAL, &ev);

    if (err == 0 && ev.type == EV_KEY)
    {
        qDebug("KEY: Code=%hu, Value=%d\n",
               ev.code,
               ev.value);
    }
};
