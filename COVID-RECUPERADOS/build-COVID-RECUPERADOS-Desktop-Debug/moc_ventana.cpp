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
struct qt_meta_stringdata_Ventana_t {
    QByteArrayData data[12];
    char stringdata0[133];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Ventana_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Ventana_t qt_meta_stringdata_Ventana = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Ventana"
QT_MOC_LITERAL(1, 8, 11), // "slot_Borrar"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 10), // "slot_Crear"
QT_MOC_LITERAL(4, 32, 13), // "slot_CargarCB"
QT_MOC_LITERAL(5, 46, 12), // "slot_Mostrar"
QT_MOC_LITERAL(6, 59, 13), // "slot_Insertar"
QT_MOC_LITERAL(7, 73, 14), // "slot_respuesta"
QT_MOC_LITERAL(8, 88, 14), // "QNetworkReply*"
QT_MOC_LITERAL(9, 103, 12), // "process_line"
QT_MOC_LITERAL(10, 116, 11), // "QByteArray*"
QT_MOC_LITERAL(11, 128, 4) // "line"

    },
    "Ventana\0slot_Borrar\0\0slot_Crear\0"
    "slot_CargarCB\0slot_Mostrar\0slot_Insertar\0"
    "slot_respuesta\0QNetworkReply*\0"
    "process_line\0QByteArray*\0line"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Ventana[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x0a /* Public */,
       3,    0,   55,    2, 0x0a /* Public */,
       4,    0,   56,    2, 0x0a /* Public */,
       5,    0,   57,    2, 0x0a /* Public */,
       6,    0,   58,    2, 0x0a /* Public */,
       7,    1,   59,    2, 0x0a /* Public */,
       9,    0,   62,    2, 0x0a /* Public */,
       9,    1,   63,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,

       0        // eod
};

void Ventana::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Ventana *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slot_Borrar(); break;
        case 1: _t->slot_Crear(); break;
        case 2: _t->slot_CargarCB(); break;
        case 3: _t->slot_Mostrar(); break;
        case 4: _t->slot_Insertar(); break;
        case 5: _t->slot_respuesta((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 6: _t->process_line(); break;
        case 7: _t->process_line((*reinterpret_cast< QByteArray*(*)>(_a[1]))); break;
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

QT_INIT_METAOBJECT const QMetaObject Ventana::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Ventana.data,
    qt_meta_data_Ventana,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Ventana::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Ventana::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Ventana.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Ventana::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
