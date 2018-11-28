/****************************************************************************
** Meta object code from reading C++ file 'chaufage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Projet_qt/chaufage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chaufage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Chaufage_t {
    QByteArrayData data[12];
    char stringdata0[226];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Chaufage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Chaufage_t qt_meta_stringdata_Chaufage = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Chaufage"
QT_MOC_LITERAL(1, 9, 22), // "on_dial_sliderReleased"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 20), // "on_dial_valueChanged"
QT_MOC_LITERAL(4, 54, 5), // "value"
QT_MOC_LITERAL(5, 60, 22), // "on_dial_2_valueChanged"
QT_MOC_LITERAL(6, 83, 24), // "on_dial_2_sliderReleased"
QT_MOC_LITERAL(7, 108, 21), // "on_pb_ajouter_clicked"
QT_MOC_LITERAL(8, 130, 23), // "on_pb_supprimer_clicked"
QT_MOC_LITERAL(9, 154, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(10, 176, 25), // "on_pb_supprimer_2_clicked"
QT_MOC_LITERAL(11, 202, 23) // "on_pushButton_2_clicked"

    },
    "Chaufage\0on_dial_sliderReleased\0\0"
    "on_dial_valueChanged\0value\0"
    "on_dial_2_valueChanged\0on_dial_2_sliderReleased\0"
    "on_pb_ajouter_clicked\0on_pb_supprimer_clicked\0"
    "on_pushButton_clicked\0on_pb_supprimer_2_clicked\0"
    "on_pushButton_2_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Chaufage[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    1,   60,    2, 0x08 /* Private */,
       5,    1,   63,    2, 0x08 /* Private */,
       6,    0,   66,    2, 0x08 /* Private */,
       7,    0,   67,    2, 0x08 /* Private */,
       8,    0,   68,    2, 0x08 /* Private */,
       9,    0,   69,    2, 0x08 /* Private */,
      10,    0,   70,    2, 0x08 /* Private */,
      11,    0,   71,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Chaufage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Chaufage *_t = static_cast<Chaufage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_dial_sliderReleased(); break;
        case 1: _t->on_dial_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_dial_2_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_dial_2_sliderReleased(); break;
        case 4: _t->on_pb_ajouter_clicked(); break;
        case 5: _t->on_pb_supprimer_clicked(); break;
        case 6: _t->on_pushButton_clicked(); break;
        case 7: _t->on_pb_supprimer_2_clicked(); break;
        case 8: _t->on_pushButton_2_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Chaufage::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Chaufage.data,
      qt_meta_data_Chaufage,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Chaufage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Chaufage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Chaufage.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Chaufage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
