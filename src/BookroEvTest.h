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
private slots:
    void evtestQtDeviceScan();
signals:
private:
    QStringList _evdevNames;
};

#endif // BOOKROEVTEST_H
