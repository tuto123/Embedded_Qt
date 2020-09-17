/****************************************************************************
** Meta object code from reading C++ file 'weatherquery.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../4418_home_security/weatherquery.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'weatherquery.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WeatherQuery_t {
    QByteArrayData data[14];
    char stringdata0[207];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WeatherQuery_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WeatherQuery_t qt_meta_stringdata_WeatherQuery = {
    {
QT_MOC_LITERAL(0, 0, 12), // "WeatherQuery"
QT_MOC_LITERAL(1, 13, 10), // "InitWindow"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 10), // "paintEvent"
QT_MOC_LITERAL(4, 36, 12), // "QPaintEvent*"
QT_MOC_LITERAL(5, 49, 5), // "event"
QT_MOC_LITERAL(6, 55, 26), // "on_home_pushButton_clicked"
QT_MOC_LITERAL(7, 82, 33), // "on_ch_que_city_comboBox_activ..."
QT_MOC_LITERAL(8, 116, 4), // "arg1"
QT_MOC_LITERAL(9, 121, 33), // "on_weather_que_pushButton_cli..."
QT_MOC_LITERAL(10, 155, 11), // "weather_que"
QT_MOC_LITERAL(11, 167, 18), // "finish_weather_que"
QT_MOC_LITERAL(12, 186, 14), // "QNetworkReply*"
QT_MOC_LITERAL(13, 201, 5) // "reply"

    },
    "WeatherQuery\0InitWindow\0\0paintEvent\0"
    "QPaintEvent*\0event\0on_home_pushButton_clicked\0"
    "on_ch_que_city_comboBox_activated\0"
    "arg1\0on_weather_que_pushButton_clicked\0"
    "weather_que\0finish_weather_que\0"
    "QNetworkReply*\0reply"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WeatherQuery[] = {

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
       9,    0,   57,    2, 0x08 /* Private */,
      10,    0,   58,    2, 0x08 /* Private */,
      11,    1,   59,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   13,

       0        // eod
};

void WeatherQuery::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WeatherQuery *_t = static_cast<WeatherQuery *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->InitWindow(); break;
        case 1: _t->paintEvent((*reinterpret_cast< QPaintEvent*(*)>(_a[1]))); break;
        case 2: _t->on_home_pushButton_clicked(); break;
        case 3: _t->on_ch_que_city_comboBox_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_weather_que_pushButton_clicked(); break;
        case 5: _t->weather_que(); break;
        case 6: _t->finish_weather_que((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    }
}

const QMetaObject WeatherQuery::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_WeatherQuery.data,
      qt_meta_data_WeatherQuery,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *WeatherQuery::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WeatherQuery::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WeatherQuery.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int WeatherQuery::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
