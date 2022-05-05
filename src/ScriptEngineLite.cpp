// This is a slimmed down version of the script engine used in VoiceCommander



#include "ScriptEngineLite.h"

ScriptEngineLite::ScriptEngineLite(QObject *parent)
    : QObject{parent}
{
    setDefinitions(":/definitions/src/emulation/definitions/keysyms_defines.h");
    setDefinitions(":/definitions/src/emulation/definitions/dik_defines.h");

    qDebug() << _dikCodes.size();
}


void ScriptEngineLite::setDefinitions(QString sPathToDefines)
{
    QByteArray baDefines;
    QFile fDefines(sPathToDefines);

    if (!fDefines.open(QIODevice::ReadOnly | QIODevice::Text))
        qWarning() << "ScriptEngine::setDefinitions: Unable to find defines file or currently open in another program. Can not load defines: " << sPathToDefines;
    else
    {
        qDebug() << "ScriptEngine::setDefinitions: Successfully read definitions file:" << sPathToDefines;
        baDefines = fDefines.readAll();
    }

    fDefines.close();
    baDefines.replace('\t', ' ');
//    baDefines = baDefines.simplified();
    QList<QByteArray> qlDefines = baDefines.split('\n');

    if (sPathToDefines.contains("dik"))
    {
        for (int i = 0; i < qlDefines.size(); i++)
        {
            QList<QByteArray> slLine = qlDefines.at(i).split(' ');

            foreach (QByteArray ba, slLine)
            {
                if (ba.isEmpty())
                    continue;

                if (ba == "/*")
                    break;

                if (ba == "#define")
                    _dikCodes.append(ScriptEngine::dik_codes_s());
                else if (ba.contains("DIK"))
                    _dikCodes.last().DIK_Name = ba;
                else
                    _dikCodes.last().DIK_Code = ba.toUInt(nullptr, 16);
            }
        }
    }
    else if (sPathToDefines.contains("keysyms"))
    {
        for (int i = 0; i < qlDefines.size(); i++)
        {
            QList<QByteArray> slLine = qlDefines.at(i).split(' ');

            foreach (QByteArray ba, slLine)
            {
                if (ba.isEmpty())
                    continue;

                if (ba == "/*")
                    break;

                if (ba == "#define")
                    _vkCodes.append(ScriptEngine::vk_codes_s());
                else if (ba.contains("KS"))
                    _vkCodes.last().VK_Name = ba;
                else
                    _vkCodes.last().VK_Code = ba.toInt(nullptr, 16);
            }
        }
    }

    qlDefines.clear();
    baDefines.clear();
}
