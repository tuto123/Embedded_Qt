/****************************************************************************
** Meta object code from reading C++ file 'environmentalmonitor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../4418_home_security/environmentalmonitor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'environmentalmonitor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EnvironmentalMonitor_t {
    QByteArrayData data[16];
    char stringdata0[197];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EnvironmentalMonitor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EnvironmentalMonitor_t qt_meta_stringdata_EnvironmentalMonitor = {
    {
QT_MOC_LITERAL(0, 0, 20), // "EnvironmentalMonitor"
QT_MOC_LITERAL(1, 21, 26), // "on_home_pushButton_clicked"
QT_MOC_LITERAL(2, 48, 0), // ""
QT_MOC_LITERAL(3, 49, 10), // "paintEvent"
QT_MOC_LITERAL(4, 60, 12), // "QPaintEvent*"
QT_MOC_LITERAL(5, 73, 5), // "event"
QT_MOC_LITERAL(6, 79, 17), // "connect_to_server"
QT_MOC_LITERAL(7, 97, 10), // "onreceived"
QT_MOC_LITERAL(8, 108, 14), // "QMQTT::Message"
QT_MOC_LITERAL(9, 123, 7), // "message"
QT_MOC_LITERAL(10, 131, 12), // "onSubscribed"
QT_MOC_LITERAL(11, 144, 5), // "topic"
QT_MOC_LITERAL(12, 150, 13), // "parse_message"
QT_MOC_LITERAL(13, 164, 16), // "received_message"
QT_MOC_LITERAL(14, 181, 10), // "Delay_MSec"
QT_MOC_LITERAL(15, 192, 4) // "msec"

    },
    "EnvironmentalMonitor\0on_home_pushButton_clicked\0"
    "\0paintEvent\0QPaintEvent*\0event\0"
    "connect_to_server\0onreceived\0"
    "QMQTT::Message\0message\0onSubscribed\0"
    "topic\0parse_message\0received_message\0"
    "Delay_MSec\0msec"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EnvironmentalMonitor[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    1,   50,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    1,   54,    2, 0x08 /* Private */,
      10,    1,   57,    2, 0x08 /* Private */,
      12,    1,   60,    2, 0x08 /* Private */,
      14,    1,   63,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QByteArray,   13,
    QMetaType::Void, QMetaType::UInt,   15,

       0        // eod
};

void EnvironmentalMonitor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        EnvironmentalMonitor *_t = static_cast<EnvironmentalMonitor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_home_pushButton_clicked(); break;
        case 1: _t->paintEvent((*reinterpret_cast< QPaintEvent*(*)>(_a[1]))); break;
        case 2: _t->connect_to_server(); break;
        case 3: _t->onreceived((*reinterpret_cast< const QMQTT::Message(*)>(_a[1]))); break;
        case 4: _t->onSubscribed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->parse_message((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 6: _t->Delay_MSec((*reinterpret_cast< uint(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMQTT::Message >(); break;
            }
            break;
        }
    }
}

const QMetaObject EnvironmentalMonitor::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_EnvironmentalMonitor.data,
      qt_meta_data_EnvironmentalMonitor,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *EnvironmentalMonitor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EnvironmentalMonitor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EnvironmentalMonitor.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int EnvironmentalMonitor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
