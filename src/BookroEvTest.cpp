#include "BookroEvTest.h"
#include <string>
#include <vector>
#include <algorithm>
#include <sys/types.h>
#include <dirent.h>
#include <stdexcept>
#include <string.h>
#include <fnmatch.h>
#include <sstream>

BookroEvTest::BookroEvTest(QObject *parent)
    : QObject{parent}
{
    evtestQtDeviceScan();
}

QString BookroEvTest::getTopDevice()
{
    return _index == -1 ? QString() : _evdevNames.at(_index);
}

QStringList BookroEvTest::getAllDevices()
{
    return _evdevNames;
}

void BookroEvTest::setIndex(int index)
{
    _index = index;
}

// Adapted from https://github.com/Grumbel/evtest-qt
void BookroEvTest::evtestQtDeviceScan()
{
    _evdevNames.clear();
    char * evdev_directory = (char*)"/dev/input";
    DIR* dirp = opendir(evdev_directory);
    if (!dirp)
    {
        qWarning() << this << strerror(errno);
    }
    else
    {
        std::vector<std::string> devices;

        struct dirent* dentry;
        while((dentry = readdir(dirp)) != nullptr)
        {
            if (fnmatch("event[0-9]", dentry->d_name, FNM_PATHNAME) == 0 ||
                    fnmatch("event[0-9][0-9]*", dentry->d_name, FNM_PATHNAME) == 0)
            {
                std::ostringstream str;
                str << evdev_directory << "/" << dentry->d_name;
                devices.push_back(str.str());
            }
        }
        closedir(dirp);

        // numerical sort (i.e. event2 < event10)
        std::sort(devices.begin(), devices.end(),
                  [](std::string const& lhs, std::string const& rhs) -> bool
        {
            if (lhs.size() < rhs.size())
            {
                return true;
            }
            else if (lhs.size() > rhs.size())
            {
                return false;
            }
            else
            {
                return lhs < rhs;
            }
        });

        for (std::vector<std::string>::iterator   it = devices.begin(); it != devices.end(); it++)
        {
            _evdevNames << QString::fromStdString(*it);
        }
    }
}
