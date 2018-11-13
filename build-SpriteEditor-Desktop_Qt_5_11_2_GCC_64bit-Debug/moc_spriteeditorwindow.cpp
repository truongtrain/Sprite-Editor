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
    QByteArrayData data[12];
    char stringdata0[180];
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
QT_MOC_LITERAL(4, 50, 9), // "saveFrame"
QT_MOC_LITERAL(5, 60, 8), // "fileName"
QT_MOC_LITERAL(6, 69, 9), // "loadFrame"
QT_MOC_LITERAL(7, 79, 25), // "on_chooseColorBox_clicked"
QT_MOC_LITERAL(8, 105, 15), // "updateFrameList"
QT_MOC_LITERAL(9, 121, 10), // "frameIndex"
QT_MOC_LITERAL(10, 132, 23), // "on_actionSave_triggered"
QT_MOC_LITERAL(11, 156, 23) // "on_actionOpen_triggered"

    },
    "SpriteEditorWindow\0updateCurrentFrameIndex\0"
    "\0index\0saveFrame\0fileName\0loadFrame\0"
    "on_chooseColorBox_clicked\0updateFrameList\0"
    "frameIndex\0on_actionSave_triggered\0"
    "on_actionOpen_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SpriteEditorWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    1,   52,    2, 0x06 /* Public */,
       6,    1,   55,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   58,    2, 0x08 /* Private */,
       8,    1,   59,    2, 0x08 /* Private */,
      10,    0,   62,    2, 0x08 /* Private */,
      11,    0,   63,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
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
        case 1: _t->saveFrame((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->loadFrame((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->on_chooseColorBox_clicked(); break;
        case 4: _t->updateFrameList((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_actionSave_triggered(); break;
        case 6: _t->on_actionOpen_triggered(); break;
        default: ;
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
            using _t = void (SpriteEditorWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SpriteEditorWindow::saveFrame)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SpriteEditorWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SpriteEditorWindow::loadFrame)) {
                *result = 2;
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
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
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
void SpriteEditorWindow::saveFrame(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SpriteEditorWindow::loadFrame(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
