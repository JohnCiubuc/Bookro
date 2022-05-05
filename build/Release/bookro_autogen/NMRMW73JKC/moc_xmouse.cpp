/****************************************************************************
** Meta object code from reading C++ file 'xmouse.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../src/emulation/xmouse.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'xmouse.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_xmouse_t {
    const uint offsetsAndSize[44];
    char stringdata0[270];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_xmouse_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_xmouse_t qt_meta_stringdata_xmouse = {
    {
QT_MOC_LITERAL(0, 6), // "xmouse"
QT_MOC_LITERAL(7, 18), // "mouse_button_click"
QT_MOC_LITERAL(26, 0), // ""
QT_MOC_LITERAL(27, 22), // "mouse_button_type_enum"
QT_MOC_LITERAL(50, 11), // "xmouse_enum"
QT_MOC_LITERAL(62, 17), // "mouse_button_down"
QT_MOC_LITERAL(80, 15), // "mouse_button_up"
QT_MOC_LITERAL(96, 10), // "mouse_move"
QT_MOC_LITERAL(107, 13), // "Leap_Finger_x"
QT_MOC_LITERAL(121, 13), // "Leap_Finger_y"
QT_MOC_LITERAL(135, 24), // "mouse_map_leap_to_screen"
QT_MOC_LITERAL(160, 8), // "Finger_x"
QT_MOC_LITERAL(169, 8), // "Finger_y"
QT_MOC_LITERAL(178, 21), // "mouse_set_leap_ranges"
QT_MOC_LITERAL(200, 4), // "int*"
QT_MOC_LITERAL(205, 14), // "iLeapMouseRect"
QT_MOC_LITERAL(220, 21), // "mouse_get_coordinates"
QT_MOC_LITERAL(242, 4), // "int&"
QT_MOC_LITERAL(247, 1), // "x"
QT_MOC_LITERAL(249, 1), // "y"
QT_MOC_LITERAL(251, 11), // "mouse_setup"
QT_MOC_LITERAL(263, 6) // "XEvent"

    },
    "xmouse\0mouse_button_click\0\0"
    "mouse_button_type_enum\0xmouse_enum\0"
    "mouse_button_down\0mouse_button_up\0"
    "mouse_move\0Leap_Finger_x\0Leap_Finger_y\0"
    "mouse_map_leap_to_screen\0Finger_x\0"
    "Finger_y\0mouse_set_leap_ranges\0int*\0"
    "iLeapMouseRect\0mouse_get_coordinates\0"
    "int&\0x\0y\0mouse_setup\0XEvent"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_xmouse[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   62,    2, 0x0a,    1 /* Public */,
       5,    1,   65,    2, 0x0a,    3 /* Public */,
       6,    1,   68,    2, 0x0a,    5 /* Public */,
       7,    2,   71,    2, 0x0a,    7 /* Public */,
      10,    2,   76,    2, 0x0a,   10 /* Public */,
      13,    1,   81,    2, 0x0a,   13 /* Public */,
      16,    2,   84,    2, 0x0a,   15 /* Public */,
      20,    0,   89,    2, 0x08,   18 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Float, QMetaType::Float,    8,    9,
    QMetaType::QPoint, QMetaType::Float, QMetaType::Float,   11,   12,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, 0x80000000 | 17, 0x80000000 | 17,   18,   19,
    0x80000000 | 21,

       0        // eod
};

void xmouse::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<xmouse *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->mouse_button_click((*reinterpret_cast< std::add_pointer_t<mouse_button_type_enum>>(_a[1]))); break;
        case 1: _t->mouse_button_down((*reinterpret_cast< std::add_pointer_t<mouse_button_type_enum>>(_a[1]))); break;
        case 2: _t->mouse_button_up((*reinterpret_cast< std::add_pointer_t<mouse_button_type_enum>>(_a[1]))); break;
        case 3: _t->mouse_move((*reinterpret_cast< std::add_pointer_t<float>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[2]))); break;
        case 4: { QPoint _r = _t->mouse_map_leap_to_screen((*reinterpret_cast< std::add_pointer_t<float>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QPoint*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->mouse_set_leap_ranges((*reinterpret_cast< std::add_pointer_t<int*>>(_a[1]))); break;
        case 6: _t->mouse_get_coordinates((*reinterpret_cast< std::add_pointer_t<int&>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int&>>(_a[2]))); break;
        case 7: { XEvent _r = _t->mouse_setup();
            if (_a[0]) *reinterpret_cast< XEvent*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject xmouse::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_xmouse.offsetsAndSize,
    qt_meta_data_xmouse,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_xmouse_t
, QtPrivate::TypeAndForceComplete<xmouse, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<mouse_button_type_enum, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<mouse_button_type_enum, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<mouse_button_type_enum, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<float, std::false_type>, QtPrivate::TypeAndForceComplete<float, std::false_type>, QtPrivate::TypeAndForceComplete<QPoint, std::false_type>, QtPrivate::TypeAndForceComplete<float, std::false_type>, QtPrivate::TypeAndForceComplete<float, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int &, std::false_type>, QtPrivate::TypeAndForceComplete<int &, std::false_type>, QtPrivate::TypeAndForceComplete<XEvent, std::false_type>


>,
    nullptr
} };


const QMetaObject *xmouse::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *xmouse::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_xmouse.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int xmouse::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
