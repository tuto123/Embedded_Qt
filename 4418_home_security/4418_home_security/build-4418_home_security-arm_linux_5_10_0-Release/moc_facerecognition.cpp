/****************************************************************************
** Meta object code from reading C++ file 'facerecognition.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../4418_home_security/facerecognition.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'facerecognition.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FaceRecognition_t {
    QByteArrayData data[22];
    char stringdata0[309];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FaceRecognition_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FaceRecognition_t qt_meta_stringdata_FaceRecognition = {
    {
QT_MOC_LITERAL(0, 0, 15), // "FaceRecognition"
QT_MOC_LITERAL(1, 16, 26), // "on_home_pushButton_clicked"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 10), // "InitWindow"
QT_MOC_LITERAL(4, 55, 34), // "on_start_detect_pushButton_cl..."
QT_MOC_LITERAL(5, 90, 12), // "update_video"
QT_MOC_LITERAL(6, 103, 11), // "update_face"
QT_MOC_LITERAL(7, 115, 11), // "MatToQImage"
QT_MOC_LITERAL(8, 127, 7), // "cv::Mat"
QT_MOC_LITERAL(9, 135, 3), // "mtx"
QT_MOC_LITERAL(10, 139, 15), // "detect_and_draw"
QT_MOC_LITERAL(11, 155, 3), // "Mat"
QT_MOC_LITERAL(12, 159, 5), // "image"
QT_MOC_LITERAL(13, 165, 16), // "QImageToIplImage"
QT_MOC_LITERAL(14, 182, 9), // "IplImage*"
QT_MOC_LITERAL(15, 192, 13), // "const QImage*"
QT_MOC_LITERAL(16, 206, 6), // "qImage"
QT_MOC_LITERAL(17, 213, 33), // "on_openc_video_pushButton_cli..."
QT_MOC_LITERAL(18, 247, 10), // "paintEvent"
QT_MOC_LITERAL(19, 258, 12), // "QPaintEvent*"
QT_MOC_LITERAL(20, 271, 5), // "event"
QT_MOC_LITERAL(21, 277, 31) // "on_rt_detect_pushButton_clicked"

    },
    "FaceRecognition\0on_home_pushButton_clicked\0"
    "\0InitWindow\0on_start_detect_pushButton_clicked\0"
    "update_video\0update_face\0MatToQImage\0"
    "cv::Mat\0mtx\0detect_and_draw\0Mat\0image\0"
    "QImageToIplImage\0IplImage*\0const QImage*\0"
    "qImage\0on_openc_video_pushButton_clicked\0"
    "paintEvent\0QPaintEvent*\0event\0"
    "on_rt_detect_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FaceRecognition[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    1,   74,    2, 0x08 /* Private */,
      10,    1,   77,    2, 0x08 /* Private */,
      13,    1,   80,    2, 0x08 /* Private */,
      17,    0,   83,    2, 0x08 /* Private */,
      18,    1,   84,    2, 0x08 /* Private */,
      21,    0,   87,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QImage, 0x80000000 | 8,    9,
    0x80000000 | 11, 0x80000000 | 11,   12,
    0x80000000 | 14, 0x80000000 | 15,   16,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 19,   20,
    QMetaType::Void,

       0        // eod
};

void FaceRecognition::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FaceRecognition *_t = static_cast<FaceRecognition *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_home_pushButton_clicked(); break;
        case 1: _t->InitWindow(); break;
        case 2: _t->on_start_detect_pushButton_clicked(); break;
        case 3: _t->update_video(); break;
        case 4: _t->update_face(); break;
        case 5: { QImage _r = _t->MatToQImage((*reinterpret_cast< cv::Mat(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QImage*>(_a[0]) = std::move(_r); }  break;
        case 6: { Mat _r = _t->detect_and_draw((*reinterpret_cast< Mat(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< Mat*>(_a[0]) = std::move(_r); }  break;
        case 7: { IplImage* _r = _t->QImageToIplImage((*reinterpret_cast< const QImage*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< IplImage**>(_a[0]) = std::move(_r); }  break;
        case 8: _t->on_openc_video_pushButton_clicked(); break;
        case 9: _t->paintEvent((*reinterpret_cast< QPaintEvent*(*)>(_a[1]))); break;
        case 10: _t->on_rt_detect_pushButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject FaceRecognition::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_FaceRecognition.data,
      qt_meta_data_FaceRecognition,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *FaceRecognition::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FaceRecognition::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FaceRecognition.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FaceRecognition::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
