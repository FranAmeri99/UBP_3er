/****************************************************************************
** Meta object code from reading C++ file 'ventana.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../COVID-RECUPERADOS/ventana.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ventana.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ventana_t {
    QByteArrayData data[13];
    char stringdata0[148];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ventana_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ventana_t qt_meta_stringdata_ventana = {
    {
QT_MOC_LITERAL(0, 0, 7), // "ventana"
QT_MOC_LITERAL(1, 8, 11), // "slot_Borrar"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 10), // "slot_Crear"
QT_MOC_LITERAL(4, 32, 13), // "slot_CargarCB"
QT_MOC_LITERAL(5, 46, 12), // "slot_Mostrar"
QT_MOC_LITERAL(6, 59, 13), // "slot_Insertar"
QT_MOC_LITERAL(7, 73, 14), // "slot_respuesta"
QT_MOC_LITERAL(8, 88, 14), // "QNetworkReply*"
QT_MOC_LITERAL(9, 103, 14), // "slot_solicitar"
QT_MOC_LITERAL(10, 118, 12), // "process_line"
QT_MOC_LITERAL(11, 131, 11), // "QByteArray*"
QT_MOC_LITERAL(12, 143, 4) // "line"

    },
    "ventana\0slot_Borrar\0\0slot_Crear\0"
    "slot_CargarCB\0slot_Mostrar\0slot_Insertar\0"
    "slot_respuesta\0QNetworkReply*\0"
    "slot_solicitar\0process_line\0QByteArray*\0"
    "line"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ventana[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x0a /* Public */,
       3,    0,   60,    2, 0x0a /* Public */,
       4,    0,   61,    2, 0x0a /* Public */,
       5,    0,   62,    2, 0x0a /* Public */,
       6,    0,   63,    2, 0x0a /* Public */,
       7,    1,   64,    2, 0x0a /* Public */,
       9,    0,   67,    2, 0x0a /* Public */,
      10,    0,   68,    2, 0x0a /* Public */,
      10,    1,   69,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,

       0        // eod
};

void ventana::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ventana *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slot_Borrar(); break;
        case 1: _t->slot_Crear(); break;
        case 2: _t->slot_CargarCB(); break;
        case 3: _t->slot_Mostrar(); break;
        case 4: _t->slot_Insertar(); break;
        case 5: _t->slot_respuesta((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 6: _t->slot_solicitar(); break;
        case 7: _t->process_line(); break;
        case 8: _t->process_line((*reinterpret_cast< QByteArray*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ventana::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_ventana.data,
    qt_meta_data_ventana,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ventana::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ventana::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ventana.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ventana::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
