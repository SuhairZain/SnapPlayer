/****************************************************************************
** Meta object code from reading C++ file 'PortraitImageGrid.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/Gui/ImageGrid/PortraitImageGrid.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PortraitImageGrid.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PortraitImageGrid[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x05,
      40,   18,   18,   18, 0x05,
      63,   61,   18,   18, 0x05,

 // slots: signature, parameters, type, tag, flags
      92,   18,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_PortraitImageGrid[] = {
    "PortraitImageGrid\0\0nextChanged(QString)\0"
    "prevChanged(QString)\0,\0"
    "tapped(QString,QVariantList)\0"
    "onListViewTriggered(QVariantList)\0"
};

void PortraitImageGrid::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PortraitImageGrid *_t = static_cast<PortraitImageGrid *>(_o);
        switch (_id) {
        case 0: _t->nextChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->prevChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->tapped((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QVariantList(*)>(_a[2]))); break;
        case 3: _t->onListViewTriggered((*reinterpret_cast< QVariantList(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PortraitImageGrid::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PortraitImageGrid::staticMetaObject = {
    { &CustomControl::staticMetaObject, qt_meta_stringdata_PortraitImageGrid,
      qt_meta_data_PortraitImageGrid, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PortraitImageGrid::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PortraitImageGrid::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PortraitImageGrid::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PortraitImageGrid))
        return static_cast<void*>(const_cast< PortraitImageGrid*>(this));
    return CustomControl::qt_metacast(_clname);
}

int PortraitImageGrid::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CustomControl::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void PortraitImageGrid::nextChanged(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PortraitImageGrid::prevChanged(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PortraitImageGrid::tapped(QString _t1, QVariantList _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
