/****************************************************************************
** Meta object code from reading C++ file 'GUIAdmin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../TicketSystem/GUIAdmin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GUIAdmin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GUIAdmin_t {
    QByteArrayData data[12];
    char stringdata0[199];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GUIAdmin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GUIAdmin_t qt_meta_stringdata_GUIAdmin = {
    {
QT_MOC_LITERAL(0, 0, 8), // "GUIAdmin"
QT_MOC_LITERAL(1, 9, 15), // "AddTrainClicked"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 18), // "DeleteTrainClicked"
QT_MOC_LITERAL(4, 45, 17), // "UpdateTrainComBox"
QT_MOC_LITERAL(5, 63, 18), // "AddTrainNumClicked"
QT_MOC_LITERAL(6, 82, 21), // "UpdateTrainNumClicked"
QT_MOC_LITERAL(7, 104, 21), // "DeleteTrainNumClicked"
QT_MOC_LITERAL(8, 126, 19), // "AddTrainPassClicked"
QT_MOC_LITERAL(9, 146, 22), // "DeleteTrainPassClicked"
QT_MOC_LITERAL(10, 169, 10), // "ShowParent"
QT_MOC_LITERAL(11, 180, 18) // "TabTrainNumClicked"

    },
    "GUIAdmin\0AddTrainClicked\0\0DeleteTrainClicked\0"
    "UpdateTrainComBox\0AddTrainNumClicked\0"
    "UpdateTrainNumClicked\0DeleteTrainNumClicked\0"
    "AddTrainPassClicked\0DeleteTrainPassClicked\0"
    "ShowParent\0TabTrainNumClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GUIAdmin[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    0,   65,    2, 0x08 /* Private */,
       4,    0,   66,    2, 0x08 /* Private */,
       5,    0,   67,    2, 0x08 /* Private */,
       6,    0,   68,    2, 0x08 /* Private */,
       7,    0,   69,    2, 0x08 /* Private */,
       8,    0,   70,    2, 0x08 /* Private */,
       9,    0,   71,    2, 0x08 /* Private */,
      10,    0,   72,    2, 0x08 /* Private */,
      11,    2,   73,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,

       0        // eod
};

void GUIAdmin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GUIAdmin *_t = static_cast<GUIAdmin *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->AddTrainClicked(); break;
        case 1: _t->DeleteTrainClicked(); break;
        case 2: _t->UpdateTrainComBox(); break;
        case 3: _t->AddTrainNumClicked(); break;
        case 4: _t->UpdateTrainNumClicked(); break;
        case 5: _t->DeleteTrainNumClicked(); break;
        case 6: _t->AddTrainPassClicked(); break;
        case 7: _t->DeleteTrainPassClicked(); break;
        case 8: _t->ShowParent(); break;
        case 9: _t->TabTrainNumClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject GUIAdmin::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_GUIAdmin.data,
      qt_meta_data_GUIAdmin,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GUIAdmin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GUIAdmin::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GUIAdmin.stringdata0))
        return static_cast<void*>(const_cast< GUIAdmin*>(this));
    return QDialog::qt_metacast(_clname);
}

int GUIAdmin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
