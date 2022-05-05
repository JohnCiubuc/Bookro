#ifndef SCRIPTENGINELITE_H
#define SCRIPTENGINELITE_H

#include <QObject>
#include <QIODevice>
#include <QFile>
#include <QDebug>

namespace ScriptEngine
{
struct dik_codes_s
{
    QString DIK_Name;
    int DIK_Code;
};

struct vk_codes_s
{
    QString VK_Name;
    int VK_Code;
};
}
class ScriptEngineLite : public QObject
{
    Q_OBJECT
public:
    explicit ScriptEngineLite(QObject *parent = nullptr);
public slots:
    QString getDikName(int keyCode);
    QString getVKName(int keyCode);
signals:
private:
    void setDefinitions(QString sPathToDefines);

    QList<ScriptEngine::dik_codes_s> _dikCodes;
    QList<ScriptEngine::vk_codes_s> _vkCodes;
};

#endif // SCRIPTENGINELITE_H
