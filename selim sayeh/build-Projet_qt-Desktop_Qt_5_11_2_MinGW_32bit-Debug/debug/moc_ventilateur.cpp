/****************************************************************************
** Meta object code from reading C++ file 'ventilateur.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Projet_qt/ventilateur.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ventilateur.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Ventilateur_t {
    QByteArrayData data[11];
    char stringdata0[202];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Ventilateur_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Ventilateur_t qt_meta_stringdata_Ventilateur = {
    {
QT_MOC_LITERAL(0, 0, 11), // "Ventilateur"
QT_MOC_LITERAL(1, 12, 20), // "on_dial_valueChanged"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 5), // "value"
QT_MOC_LITERAL(4, 40, 22), // "on_dial_2_valueChanged"
QT_MOC_LITERAL(5, 63, 22), // "on_dial_sliderReleased"
QT_MOC_LITERAL(6, 86, 24), // "on_dial_2_sliderReleased"
QT_MOC_LITERAL(7, 111, 21), // "on_pb_ajouter_clicked"
QT_MOC_LITERAL(8, 133, 23), // "on_pb_supprimer_clicked"
QT_MOC_LITERAL(9, 157, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(10, 179, 22) // "on_pb_modifier_clicked"

    },
    "Ventilateur\0on_dial_valueChanged\0\0"
    "value\0on_dial_2_valueChanged\0"
    "on_dial_sliderReleased\0on_dial_2_sliderReleased\0"
    "on_pb_ajouter_clicked\0on_pb_supprimer_clicked\0"
    "on_pushButton_clicked\0on_pb_modifier_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Ventilateur[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x08 /* Private */,
       4,    1,   57,    2, 0x08 /* Private */,
       5,    0,   60,    2, 0x08 /* Private */,
       6,    0,   61,    2, 0x08 /* Private */,
       7,    0,   62,    2, 0x08 /* Private */,
       8,    0,   63,    2, 0x08 /* Private */,
       9,    0,   64,    2, 0x08 /* Private */,
      10,    0,   65,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Ventilateur::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Ventilateur *_t = static_cast<Ventilateur *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_dial_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_dial_2_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_dial_sliderReleased(); break;
        case 3: _t->on_dial_2_sliderReleased(); break;
        case 4: _t->on_pb_ajouter_clicked(); break;
        case 5: _t->on_pb_supprimer_clicked(); break;
        case 6: _t->on_pushButton_clicked(); break;
        case 7: _t->on_pb_modifier_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Ventilateur::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Ventilateur.data,
      qt_meta_data_Ventilateur,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Ventilateur::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Ventilateur::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Ventilateur.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Ventilateur::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
