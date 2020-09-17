/****************************************************************************
** Meta object code from reading C++ file 'homecontrol.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../4418_home_security/homecontrol.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'homecontrol.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_HomeControl_t {
    QByteArrayData data[16];
    char stringdata0[230];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HomeControl_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HomeControl_t qt_meta_stringdata_HomeControl = {
    {
QT_MOC_LITERAL(0, 0, 11), // "HomeControl"
QT_MOC_LITERAL(1, 12, 26), // "on_home_pushButton_clicked"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 10), // "paintEvent"
QT_MOC_LITERAL(4, 51, 12), // "QPaintEvent*"
QT_MOC_LITERAL(5, 64, 5), // "event"
QT_MOC_LITERAL(6, 70, 30), // "on_light_checkBox_stateChanged"
QT_MOC_LITERAL(7, 101, 4), // "arg1"
QT_MOC_LITERAL(8, 106, 29), // "on_door_checkBox_stateChanged"
QT_MOC_LITERAL(9, 136, 28), // "on_fan_checkBox_stateChanged"
QT_MOC_LITERAL(10, 165, 10), // "Delay_MSec"
QT_MOC_LITERAL(11, 176, 4), // "msec"
QT_MOC_LITERAL(12, 181, 17), // "connect_to_server"
QT_MOC_LITERAL(13, 199, 12), // "onSubscribed"
QT_MOC_LITERAL(14, 212, 5), // "topic"
QT_MOC_LITERAL(15, 218, 11) // "onPublished"

    },
    "HomeControl\0on_home_pushButton_clicked\0"
    "\0paintEvent\0QPaintEvent*\0event\0"
    "on_light_checkBox_stateChanged\0arg1\0"
    "on_door_checkBox_stateChanged\0"
    "on_fan_checkBox_stateChanged\0Delay_MSec\0"
    "msec\0connect_to_server\0onSubscribed\0"
    "topic\0onPublished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HomeControl[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    1,   60,    2, 0x08 /* Private */,
       6,    1,   63,    2, 0x08 /* Private */,
       8,    1,   66,    2, 0x08 /* Private */,
       9,    1,   69,    2, 0x08 /* Private */,
      10,    1,   72,    2, 0x08 /* Private */,
      12,    0,   75,    2, 0x08 /* Private */,
      13,    1,   76,    2, 0x08 /* Private */,
      15,    0,   79,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::UInt,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void,

       0        // eod
};

void HomeControl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HomeControl *_t = static_cast<HomeControl *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_home_pushButton_clicked(); break;
        case 1: _t->paintEvent((*reinterpret_cast< QPaintEvent*(*)>(_a[1]))); break;
        case 2: _t->on_light_checkBox_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_door_checkBox_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_fan_checkBox_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->Delay_MSec((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 6: _t->connect_to_server(); break;
        case 7: _t->onSubscribed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->onPublished(); break;
        default: ;
        }
    }
}

const QMetaObject HomeControl::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_HomeControl.data,
      qt_meta_data_HomeControl,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *HomeControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HomeControl::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HomeControl.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int HomeControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
