/****************************************************************************
** Meta object code from reading C++ file 'VideoOptionsBar.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/Gui/CustomControls/VideoOptionsBar.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'VideoOptionsBar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_VideoOptionsBar[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x05,
      31,   16,   16,   16, 0x05,
      50,   16,   16,   16, 0x05,
      67,   16,   16,   16, 0x05,
     102,   16,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
     114,   16,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_VideoOptionsBar[] = {
    "VideoOptionsBar\0\0backPressed()\0"
    "rotationLock(bool)\0screenLock(bool)\0"
    "zoomLevelChanged(ZoomLevel::Level)\0"
    "zoomReset()\0onZoomButtonClicked()\0"
};

void VideoOptionsBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        VideoOptionsBar *_t = static_cast<VideoOptionsBar *>(_o);
        switch (_id) {
        case 0: _t->backPressed(); break;
        case 1: _t->rotationLock((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->screenLock((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->zoomLevelChanged((*reinterpret_cast< ZoomLevel::Level(*)>(_a[1]))); break;
        case 4: _t->zoomReset(); break;
        case 5: _t->onZoomButtonClicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData VideoOptionsBar::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject VideoOptionsBar::staticMetaObject = {
    { &CustomControl::staticMetaObject, qt_meta_stringdata_VideoOptionsBar,
      qt_meta_data_VideoOptionsBar, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &VideoOptionsBar::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *VideoOptionsBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *VideoOptionsBar::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VideoOptionsBar))
        return static_cast<void*>(const_cast< VideoOptionsBar*>(this));
    return CustomControl::qt_metacast(_clname);
}

int VideoOptionsBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CustomControl::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void VideoOptionsBar::backPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void VideoOptionsBar::rotationLock(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void VideoOptionsBar::screenLock(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void VideoOptionsBar::zoomLevelChanged(ZoomLevel::Level _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void VideoOptionsBar::zoomReset()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}
QT_END_MOC_NAMESPACE
