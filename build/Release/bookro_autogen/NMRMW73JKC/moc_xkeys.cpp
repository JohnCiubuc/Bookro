/****************************************************************************
** Meta object code from reading C++ file 'xkeys.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../src/emulation/xkeys.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'xkeys.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_xkeys_t {
    const uint offsetsAndSize[16];
    char stringdata0[70];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_xkeys_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_xkeys_t qt_meta_stringdata_xkeys = {
    {
QT_MOC_LITERAL(0, 5), // "xkeys"
QT_MOC_LITERAL(6, 12), // "pressKey_Dik"
QT_MOC_LITERAL(19, 0), // ""
QT_MOC_LITERAL(20, 8), // "iKeyCode"
QT_MOC_LITERAL(29, 14), // "releaseKey_Dik"
QT_MOC_LITERAL(44, 8), // "key_down"
QT_MOC_LITERAL(53, 6), // "key_up"
QT_MOC_LITERAL(60, 9) // "key_setup"

    },
    "xkeys\0pressKey_Dik\0\0iKeyCode\0"
    "releaseKey_Dik\0key_down\0key_up\0key_setup"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_xkeys[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   44,    2, 0x0a,    1 /* Public */,
       4,    1,   47,    2, 0x0a,    3 /* Public */,
       5,    1,   50,    2, 0x0a,    5 /* Public */,
       6,    1,   53,    2, 0x0a,    7 /* Public */,
       7,    0,   56,    2, 0x08,    9 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,

       0        // eod
};

void xkeys::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<xkeys *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->pressKey_Dik((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->releaseKey_Dik((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->key_down((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->key_up((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->key_setup(); break;
        default: ;
        }
    }
}

const QMetaObject xkeys::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_xkeys.offsetsAndSize,
    qt_meta_data_xkeys,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_xkeys_t
, QtPrivate::TypeAndForceComplete<xkeys, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *xkeys::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *xkeys::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_xkeys.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int xkeys::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
