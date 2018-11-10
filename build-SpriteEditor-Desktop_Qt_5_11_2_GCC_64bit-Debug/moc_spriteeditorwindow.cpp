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
    QByteArrayData data[17];
    char stringdata0[280];
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
QT_MOC_LITERAL(4, 50, 21), // "addInitialFrameSignal"
QT_MOC_LITERAL(5, 72, 6), // "Frame*"
QT_MOC_LITERAL(6, 79, 5), // "frame"
QT_MOC_LITERAL(7, 85, 27), // "resolutionSliderMovedSignal"
QT_MOC_LITERAL(8, 113, 5), // "value"
QT_MOC_LITERAL(9, 119, 28), // "drawMirroredBoxChangedSignal"
QT_MOC_LITERAL(10, 148, 7), // "checked"
QT_MOC_LITERAL(11, 156, 25), // "on_chooseColorBox_clicked"
QT_MOC_LITERAL(12, 182, 15), // "updateFrameList"
QT_MOC_LITERAL(13, 198, 10), // "frameIndex"
QT_MOC_LITERAL(14, 209, 31), // "on_resolutionSlider_sliderMoved"
QT_MOC_LITERAL(15, 241, 8), // "position"
QT_MOC_LITERAL(16, 250, 29) // "on_drawMirrorCheckBox_toggled"

    },
    "SpriteEditorWindow\0updateCurrentFrameIndex\0"
    "\0index\0addInitialFrameSignal\0Frame*\0"
    "frame\0resolutionSliderMovedSignal\0"
    "value\0drawMirroredBoxChangedSignal\0"
    "checked\0on_chooseColorBox_clicked\0"
    "updateFrameList\0frameIndex\0"
    "on_resolutionSlider_sliderMoved\0"
    "position\0on_drawMirrorCheckBox_toggled"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SpriteEditorWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       4,    1,   57,    2, 0x06 /* Public */,
       7,    1,   60,    2, 0x06 /* Public */,
       9,    1,   63,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,   66,    2, 0x08 /* Private */,
      12,    1,   67,    2, 0x08 /* Private */,
      14,    1,   70,    2, 0x08 /* Private */,
      16,    1,   73,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Bool,   10,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Bool,   10,

       0        // eod
};

void SpriteEditorWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SpriteEditorWindow *_t = static_cast<SpriteEditorWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateCurrentFrameIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->addInitialFrameSignal((*reinterpret_cast< Frame*(*)>(_a[1]))); break;
        case 2: _t->resolutionSliderMovedSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->drawMirroredBoxChangedSignal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_chooseColorBox_clicked(); break;
        case 5: _t->updateFrameList((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_resolutionSlider_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_drawMirrorCheckBox_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Frame* >(); break;
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
            using _t = void (SpriteEditorWindow::*)(Frame * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SpriteEditorWindow::addInitialFrameSignal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SpriteEditorWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SpriteEditorWindow::resolutionSliderMovedSignal)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (SpriteEditorWindow::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SpriteEditorWindow::drawMirroredBoxChangedSignal)) {
                *result = 3;
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
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
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
void SpriteEditorWindow::addInitialFrameSignal(Frame * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SpriteEditorWindow::resolutionSliderMovedSignal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void SpriteEditorWindow::drawMirroredBoxChangedSignal(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
