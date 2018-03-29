/****************************************************************************
** Meta object code from reading C++ file 'GUIUser.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../TicketSystem/GUIUser.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GUIUser.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GUIUser_t {
    QByteArrayData data[7];
    char stringdata0[95];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GUIUser_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GUIUser_t qt_meta_stringdata_GUIUser = {
    {
QT_MOC_LITERAL(0, 0, 7), // "GUIUser"
QT_MOC_LITERAL(1, 8, 10), // "ShowParent"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 16), // "ShowTicketDialog"
QT_MOC_LITERAL(4, 37, 22), // "ShowTicketInfromDialog"
QT_MOC_LITERAL(5, 60, 15), // "ShowOtherDialog"
QT_MOC_LITERAL(6, 76, 18) // "BtnRechargeClicked"

    },
    "GUIUser\0ShowParent\0\0ShowTicketDialog\0"
    "ShowTicketInfromDialog\0ShowOtherDialog\0"
    "BtnRechargeClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GUIUser[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GUIUser::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GUIUser *_t = static_cast<GUIUser *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ShowParent(); break;
        case 1: _t->ShowTicketDialog(); break;
        case 2: _t->ShowTicketInfromDialog(); break;
        case 3: _t->ShowOtherDialog(); break;
        case 4: _t->BtnRechargeClicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject GUIUser::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_GUIUser.data,
      qt_meta_data_GUIUser,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GUIUser::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GUIUser::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GUIUser.stringdata0))
        return static_cast<void*>(const_cast< GUIUser*>(this));
    return QDialog::qt_metacast(_clname);
}

int GUIUser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
