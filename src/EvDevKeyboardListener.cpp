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

    struct libevdev *dev;

    int err = libevdev_new_from_fd(fd, &dev);

    if (err < 0)
    {
        qDebug() <<  "ERROR: cannot associate event device "<< strerror(-err);
        return;
    }

    qDebug("Device %s is open and associated w/ libevent\n", eventDevice);

    do
    {
        struct input_event ev;

        err = libevdev_next_event(dev, LIBEVDEV_READ_FLAG_NORMAL, &ev);

        if (err == 0 && ev.type == EV_KEY)
        {
            qDebug("KEY: Code=%hu\n",
                   ev.code);
        }
    }
    while (err == 1 || err == 0 || err == -EAGAIN);

}
