#ifndef MY_CLASS_PY_TYPE_H
#define MY_CLASS_PY_TYPE_H

#include <stdint.h> 
#include <stddef.h>
#include <python3.10/Python.h>
#include <structmember.h>
#include "my_cpp_class.h"
#include "pyport.h"

typedef struct {
    PyObject_HEAD
    int         m_value;
    MyClass*    m_myclass;
} MyClassObject;

int MyClass_init(PyObject *self, PyObject *args, PyObject *kwds);
PyObject *MyClass_new(PyTypeObject *subtype, PyObject *args, PyObject *kwds);
void MyClass_dealloc(MyClassObject *self);
PyObject* MyClass_addOne(PyObject *self, PyObject *args);

static PyMethodDef MyClass_methods[] = {
    {"addOne", (PyCFunction)MyClass_addOne, METH_NOARGS, PyDoc_STR("Return an incremented integer")},
    {NULL, NULL}
};

static struct PyMemberDef MyClass_members[] = {
    {"value", PY_INT32_T, offsetof(MyClassObject, m_value)},
    {NULL}
};


static PyType_Slot MyClass_slots[] = {
    {Py_tp_new, (void*)MyClass_new},
    {Py_tp_init, (void*)MyClass_init},
    {Py_tp_dealloc, (void*)MyClass_dealloc},
    {Py_tp_members, MyClass_members},
    {Py_tp_methods, MyClass_methods},
    {0, 0}
};

static PyType_Spec spec_myclass = {
    "MyClass",
    sizeof(MyClassObject) + sizeof(MyClass),
    0,
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
    MyClass_slots
};


#endif // !MY_CLASS_PY_TYPE_H
