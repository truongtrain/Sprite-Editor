/****************************************************************************
** Meta object code from reading C++ file 'spriteeditorwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SpriteEditor/spriteeditorwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'spriteeditorwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SpriteEditorWindow_t {
    QByteArrayData data[21];
    char stringdata0[299];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SpriteEditorWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SpriteEditorWindow_t qt_meta_stringdata_SpriteEditorWindow = {
    {
QT_MOC_LITERAL(0, 0, 18), // "SpriteEditorWindow"
QT_MOC_LITERAL(1, 19, 23), // "updateCurrentFrameIndex"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 5), // "index"
QT_MOC_LITERAL(4, 50, 15), // "updateAnimation"
QT_MOC_LITERAL(5, 66, 7), // "QImage&"
QT_MOC_LITERAL(6, 74, 5), // "image"
QT_MOC_LITERAL(7, 80, 25), // "on_chooseColorBox_clicked"
QT_MOC_LITERAL(8, 106, 18), // "handleRemovedFrame"
QT_MOC_LITERAL(9, 125, 16), // "handleAddedFrame"
QT_MOC_LITERAL(10, 142, 10), // "framesMade"
QT_MOC_LITERAL(11, 153, 11), // "updateFrame"
QT_MOC_LITERAL(12, 165, 6), // "Frame*"
QT_MOC_LITERAL(13, 172, 7), // "current"
QT_MOC_LITERAL(14, 180, 18), // "updatePreviewImage"
QT_MOC_LITERAL(15, 199, 19), // "updatePreviewImage2"
QT_MOC_LITERAL(16, 219, 13), // "receiveImages"
QT_MOC_LITERAL(17, 233, 13), // "QList<QImage>"
QT_MOC_LITERAL(18, 247, 6), // "images"
QT_MOC_LITERAL(19, 254, 20), // "handleFrameSelection"
QT_MOC_LITERAL(20, 275, 23) // "on_popOutButton_clicked"

    },
    "SpriteEditorWindow\0updateCurrentFrameIndex\0"
    "\0index\0updateAnimation\0QImage&\0image\0"
    "on_chooseColorBox_clicked\0handleRemovedFrame\0"
    "handleAddedFrame\0framesMade\0updateFrame\0"
    "Frame*\0current\0updatePreviewImage\0"
    "updatePreviewImage2\0receiveImages\0"
    "QList<QImage>\0images\0handleFrameSelection\0"
    "on_popOutButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SpriteEditorWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       4,    2,   72,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   77,    2, 0x0a /* Public */,
       8,    0,   78,    2, 0x0a /* Public */,
       9,    1,   79,    2, 0x0a /* Public */,
      11,    1,   82,    2, 0x0a /* Public */,
      14,    0,   85,    2, 0x0a /* Public */,
      15,    0,   86,    2, 0x0a /* Public */,
      16,    1,   87,    2, 0x0a /* Public */,
      19,    0,   90,    2, 0x08 /* Private */,
      20,    0,   91,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 5,    3,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SpriteEditorWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SpriteEditorWindow *_t = static_cast<SpriteEditorWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateCurrentFrameIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->updateAnimation((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QImage(*)>(_a[2]))); break;
        case 2: _t->on_chooseColorBox_clicked(); break;
        case 3: _t->handleRemovedFrame(); break;
        case 4: _t->handleAddedFrame((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->updateFrame((*reinterpret_cast< Frame*(*)>(_a[1]))); break;
        case 6: _t->updatePreviewImage(); break;
        case 7: _t->updatePreviewImage2(); break;
        case 8: _t->receiveImages((*reinterpret_cast< QList<QImage>(*)>(_a[1]))); break;
        case 9: _t->handleFrameSelection(); break;
        case 10: _t->on_popOutButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Frame* >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QImage> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SpriteEditorWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SpriteEditorWindow::updateCurrentFrameIndex)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SpriteEditorWindow::*)(int , QImage & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SpriteEditorWindow::updateAnimation)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SpriteEditorWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_SpriteEditorWindow.data,
      qt_meta_data_SpriteEditorWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SpriteEditorWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SpriteEditorWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SpriteEditorWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int SpriteEditorWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void SpriteEditorWindow::updateCurrentFrameIndex(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SpriteEditorWindow::updateAnimation(int _t1, QImage & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
