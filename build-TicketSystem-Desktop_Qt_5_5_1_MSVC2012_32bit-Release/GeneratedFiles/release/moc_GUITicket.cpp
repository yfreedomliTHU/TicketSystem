/****************************************************************************
** Meta object code from reading C++ file 'GUITicket.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../TicketSystem/GUITicket.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GUITicket.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GUITicket_t {
    QByteArrayData data[8];
    char stringdata0[115];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GUITicket_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GUITicket_t qt_meta_stringdata_GUITicket = {
    {
QT_MOC_LITERAL(0, 0, 9), // "GUITicket"
QT_MOC_LITERAL(1, 10, 23), // "TableTrainNumRowClicked"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 13), // "SelectSeatNum"
QT_MOC_LITERAL(4, 49, 17), // "UserChoseEStation"
QT_MOC_LITERAL(5, 67, 15), // "BtnOrderClicked"
QT_MOC_LITERAL(6, 83, 14), // "BtnBackClicked"
QT_MOC_LITERAL(7, 98, 16) // "BtnSearchClicked"

    },
    "GUITicket\0TableTrainNumRowClicked\0\0"
    "SelectSeatNum\0UserChoseEStation\0"
    "BtnOrderClicked\0BtnBackClicked\0"
    "BtnSearchClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GUITicket[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x08 /* Private */,
       3,    0,   49,    2, 0x08 /* Private */,
       4,    1,   50,    2, 0x08 /* Private */,
       5,    0,   53,    2, 0x08 /* Private */,
       6,    0,   54,    2, 0x08 /* Private */,
       7,    0,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GUITicket::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GUITicket *_t = static_cast<GUITicket *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->TableTrainNumRowClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->SelectSeatNum(); break;
        case 2: _t->UserChoseEStation((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->BtnOrderClicked(); break;
        case 4: _t->BtnBackClicked(); break;
        case 5: _t->BtnSearchClicked(); break;
        default: ;
        }
    }
}

const QMetaObject GUITicket::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_GUITicket.data,
      qt_meta_data_GUITicket,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GUITicket::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GUITicket::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GUITicket.stringdata0))
        return static_cast<void*>(const_cast< GUITicket*>(this));
    return QDialog::qt_metacast(_clname);
}

int GUITicket::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE