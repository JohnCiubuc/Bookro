// This is a slimmed down version of the script engine used in VoiceCommander



#include "ScriptEngineLite.h"
#include <linux/input-event-codes.h>

#define KEY_DELAY qrand() % ((30 + 1) - 20) + 10

ScriptEngineLite::ScriptEngineLite(QObject *parent)
    : QObject{parent}
{
    setDefinitions(":/definitions/src/emulation/definitions/keysyms_defines.h");
    setDefinitions(":/definitions/src/emulation/definitions/dik_defines.h");
    // Used for XKeysymToKeycode
    xDisplay = XOpenDisplay(0);
    _input = new UInput();
    if(!_input->init())
        qDebug() << this << "WARNING: input failed to manifest. Will not be able to send keys at this time";
    qDebug() << _dikCodes.size();
}

QString ScriptEngineLite::getDikName(int keyCode)
{
    foreach(ScriptEngine::dik_codes_s s, _dikCodes)
    {
        if (s.DIK_Code == keyCode)
            return s.DIK_Name;
    }
    return QString();
}

QString ScriptEngineLite::getVKName(int keyCode)
{
    foreach(ScriptEngine::vk_codes_s s, _vkCodes)
    {
        if (s.VK_Code == keyCode)
            return s.VK_Name;
    }
    return QString();
}

void ScriptEngineLite::key_send(QString baScript)
{

    foreach (QChar cChar, baScript)
    {
        uint32_t code = XKeysymToKeycode(xDisplay,  cChar.unicode())-8;
        qDebug() << this  <<cChar<<cChar.unicode()<<code;
        if (int(cChar.toLatin1()) >= 65 && int(cChar.toLatin1()) <= 90)
        {
#ifdef _WIN32
            int shiftKey = 0x2A;
#elif __linux__
            int shiftKey = 0x2A;
#endif
            _input->sendKey(shiftKey, UInput::Keypress);
            QThread::msleep(KEY_DELAY);
            _input->sendKey(code, UInput::Keypress);
            QThread::msleep(KEY_DELAY);
            _input->sendKey(code, UInput::Release);
            QThread::msleep(KEY_DELAY);
            _input->sendKey(shiftKey, UInput::Release);
        }
        else if (int(cChar.toLatin1()) >= 97 && int(cChar.toLatin1()) <= 122)
        {
            cChar = QChar(int(cChar.toLatin1()) - 32);
            _input->sendKey(code, UInput::Keypress);
            QThread::msleep(KEY_DELAY);
            _input->sendKey(code, UInput::Release);
        }
        else
        {
#ifdef _WIN32
            Key_Sim->key_down(cChar.unicode(), true);
            QThread::msleep(KEY_DELAY);
            Key_Sim->key_up(cChar.unicode(), true);
#elif __linux__
            _input->sendKey(code, UInput::Keypress);
            QThread::msleep(KEY_DELAY);
            _input->sendKey(code, UInput::Release);
#endif
        }
    }
}

void ScriptEngineLite::key_backspace(int count = 1)
{
    for(int i = 0; i <count; i++)
    {
        _input->sendKey(0x0E, UInput::Keypress);
        QThread::msleep(KEY_DELAY);
        _input->sendKey(0x0E, UInput::Release);
        QThread::msleep(KEY_DELAY);
    }
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
