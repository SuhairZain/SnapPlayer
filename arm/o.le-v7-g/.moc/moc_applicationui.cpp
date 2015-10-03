/****************************************************************************
** Meta object code from reading C++ file 'applicationui.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/applicationui.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'applicationui.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ApplicationUI[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x08,
      29,   14,   14,   14, 0x08,
      40,   14,   14,   14, 0x08,
      67,   14,   14,   14, 0x08,
      94,   14,   14,   14, 0x08,
     149,   14,   14,   14, 0x08,
     179,   14,   14,   14, 0x08,
     239,   14,   14,   14, 0x08,
     276,   14,   14,   14, 0x08,
     306,   14,   14,   14, 0x08,
     319,   14,   14,   14, 0x08,
     333,   14,   14,   14, 0x08,
     346,   14,   14,   14, 0x08,
     371,   14,   14,   14, 0x08,
     401,  399,   14,   14, 0x08,
     432,   14,   14,   14, 0x08,
     460,   14,   14,   14, 0x08,
     493,   14,   14,   14, 0x08,
     524,   14,   14,   14, 0x08,
     573,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ApplicationUI[] = {
    "ApplicationUI\0\0onAppAsleep()\0onClosed()\0"
    "onListNextChanged(QString)\0"
    "onListPrevChanged(QString)\0"
    "onOrientationChange(bb::cascades::UIOrientation::Type)\0"
    "onPlayerDurationChanged(uint)\0"
    "onPlayerMediaStateChanged(bb::multimedia::MediaState::Type)\0"
    "onPlayerMetaDataChanged(QVariantMap)\0"
    "onPlayerPositionChanged(uint)\0"
    "onPlayNext()\0onPlayPause()\0onPlayPrev()\0"
    "onScrollSeekForward(int)\0"
    "onSliderValueChanged(float)\0,\0"
    "onTapped(QString,QVariantList)\0"
    "onVideoOptionsBackPressed()\0"
    "onVideoOptionsRotationLock(bool)\0"
    "onVideoOptionsScreenLock(bool)\0"
    "onVideoOptionsZoomLevelChanged(ZoomLevel::Level)\0"
    "onVideoOptionsZoomReset()\0"
};

void ApplicationUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ApplicationUI *_t = static_cast<ApplicationUI *>(_o);
        switch (_id) {
        case 0: _t->onAppAsleep(); break;
        case 1: _t->onClosed(); break;
        case 2: _t->onListNextChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->onListPrevChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->onOrientationChange((*reinterpret_cast< bb::cascades::UIOrientation::Type(*)>(_a[1]))); break;
        case 5: _t->onPlayerDurationChanged((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 6: _t->onPlayerMediaStateChanged((*reinterpret_cast< bb::multimedia::MediaState::Type(*)>(_a[1]))); break;
        case 7: _t->onPlayerMetaDataChanged((*reinterpret_cast< QVariantMap(*)>(_a[1]))); break;
        case 8: _t->onPlayerPositionChanged((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 9: _t->onPlayNext(); break;
        case 10: _t->onPlayPause(); break;
        case 11: _t->onPlayPrev(); break;
        case 12: _t->onScrollSeekForward((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->onSliderValueChanged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 14: _t->onTapped((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QVariantList(*)>(_a[2]))); break;
        case 15: _t->onVideoOptionsBackPressed(); break;
        case 16: _t->onVideoOptionsRotationLock((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->onVideoOptionsScreenLock((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: _t->onVideoOptionsZoomLevelChanged((*reinterpret_cast< ZoomLevel::Level(*)>(_a[1]))); break;
        case 19: _t->onVideoOptionsZoomReset(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ApplicationUI::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ApplicationUI::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ApplicationUI,
      qt_meta_data_ApplicationUI, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ApplicationUI::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ApplicationUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ApplicationUI::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ApplicationUI))
        return static_cast<void*>(const_cast< ApplicationUI*>(this));
    return QObject::qt_metacast(_clname);
}

int ApplicationUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
