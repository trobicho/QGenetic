/****************************************************************************
** Meta object code from reading C++ file 'GeneticWorker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "GeneticWorker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GeneticWorker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GeneticWorker_t {
    QByteArrayData data[6];
    char stringdata0[62];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GeneticWorker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GeneticWorker_t qt_meta_stringdata_GeneticWorker = {
    {
QT_MOC_LITERAL(0, 0, 13), // "GeneticWorker"
QT_MOC_LITERAL(1, 14, 16), // "signal_genFinish"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 3), // "gen"
QT_MOC_LITERAL(4, 36, 20), // "std::vector<double>&"
QT_MOC_LITERAL(5, 57, 4) // "best"

    },
    "GeneticWorker\0signal_genFinish\0\0gen\0"
    "std::vector<double>&\0best"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GeneticWorker[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4,    3,    5,

       0        // eod
};

void GeneticWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GeneticWorker *_t = static_cast<GeneticWorker *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_genFinish((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< std::vector<double>(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (GeneticWorker::*_t)(int , std::vector<double> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GeneticWorker::signal_genFinish)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject GeneticWorker::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_GeneticWorker.data,
      qt_meta_data_GeneticWorker,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *GeneticWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GeneticWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GeneticWorker.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "GeneticReal"))
        return static_cast< GeneticReal*>(this);
    return QThread::qt_metacast(_clname);
}

int GeneticWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void GeneticWorker::signal_genFinish(int _t1, std::vector<double> & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
