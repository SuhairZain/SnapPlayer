/****************************************************************************
** Meta object code from reading C++ file 'ImageGridItem.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/Gui/ImageGrid/ImageGridItem.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ImageGridItem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ImageGridItem[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x08,
      34,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ImageGridItem[] = {
    "ImageGridItem\0\0fadeOutCompleted()\0"
    "onTimeout()\0"
};

void ImageGridItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ImageGridItem *_t = static_cast<ImageGridItem *>(_o);
        switch (_id) {
        case 0: _t->fadeOutCompleted(); break;
        case 1: _t->onTimeout(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData ImageGridItem::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ImageGridItem::staticMetaObject = {
    { &CustomControl::staticMetaObject, qt_meta_stringdata_ImageGridItem,
      qt_meta_data_ImageGridItem, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ImageGridItem::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ImageGridItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ImageGridItem::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ImageGridItem))
        return static_cast<void*>(const_cast< ImageGridItem*>(this));
    if (!strcmp(_clname, "ListItemListener"))
        return static_cast< ListItemListener*>(const_cast< ImageGridItem*>(this));
    return CustomControl::qt_metacast(_clname);
}

int ImageGridItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CustomControl::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
