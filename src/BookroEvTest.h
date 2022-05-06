#ifndef BOOKROEVTEST_H
#define BOOKROEVTEST_H

#include <QObject>
#include <QDebug>
#include <QDir>
class BookroEvTest : public QObject
{
    Q_OBJECT
public:
    explicit BookroEvTest(QObject *parent = nullptr);
    QString getTopDevice();
    QStringList getAllDevices();
public slots:
    void setIndex(int);
private slots:
    void evtestQtDeviceScan();
signals:
private:
    QStringList _evdevNames;
    int _index = -1;
};

#endif // BOOKROEVTEST_H
