#define PY_SSIZE_T_CLEAN
#include </usr/include/python3.10/Python.h>
#include </usr/include/python3.10/structmember.h>
#include "point_test.h"

/*
 typedef struct point Point;

struct point {
	int x;
	int y;
};
*/

static void
Point_dealloc(Point* self) {
	Py_XDECREF(self->x);
	Py_XDECREF(self->y);
	Py_TYPE(self)->tp_free((PyObject *)self);
}

static PyObject*
Point_new(PyTypeObject *type, PyObject *args, PyObject *kwds) {
	Point* self;

	self = (Point*)type->tp_alloc(type, 0);
	
	self->x = 0;
	self->y = 0;

	return (PyObject*)self;
}


static int
Point_init(Point *self, PyObject *args, PyObject *kwds) {
	static char *kwlist[] = {"x", "y", NULL};
	PyObject *x = NULL, *y = NULL;
	
	// |ii means that x and y are optional and must be integers
	if (!PyArg_ParseTupleAndKeywords(args, kwds, "|ii", kwlist, &x, &y))
		return -1;

	if (x) {
		if (PyLong_Check(x)) {
			self->x = PyLong_AsLong(x);
		} else {
			PyErr_SetString(PyExc_TypeError, "x must be an integer");
			return -1;
		}
	}

	if (y) {
		if (PyLong_Check(y)) {
			self->y = PyLong_AsLong(y);
		} else {
			PyErr_SetString(PyExc_TypeError, "y must be an integer");
			return -1;
		}
	}

	return 0;
}


static struct PyMemberDef Point_members[] = {
	{"x", T_INT, offsetof(Point, x), 0, "x-coordinate"},
	{"y", T_INT, offsetof(Point, y), 0, "y-coordinate"},
	{NULL},
};


static PyObject*
Point_repr(Point *self) {
	return PyUnicode_FromFormat("Point(%d, %d)", self->x, self->y);
}


static PyMethodDef Point_methods[] = {
	{NULL}
};


static PyTypeObject PointType = {
	.ob_base = PyVarObject_HEAD_INIT(NULL, 0)
	.tp_name = "aiframework.Point",
	.tp_basicsize = sizeof(Point),
	.tp_itemsize = 0,
	.tp_flags = Py_TPFLAGS_DEFAULT,
	.tp_doc = "Just a 2D point",
	.tp_new = Point_new,
	.tp_init = (initproc)Point_init,
	.tp_dealloc = (destructor)Point_dealloc,
	.tp_members = Point_members,
	.tp_repr = (reprfunc)Point_repr,
	.tp_methods = Point_methods,
};


static PyModuleDef aiframework = {
	PyModuleDef_HEAD_INIT,
	.m_name = "aiframework",
	.m_doc = "My own ai framework :D",
	.m_size = -1,
};


PyMODINIT_FUNC
PyInit_aiframework(void) {
	PyObject *m;

	if (PyType_Ready(&PointType) < 0)
		return NULL;

	m = PyModule_Create(&aiframework);	
	if (m == NULL)
		return NULL;

	Py_INCREF(&PointType);
	// the string that is on this functions is the name of the PyObject implemented
	// "from ai import Point" must be used
	PyModule_AddObject(m, "Point", (PyObject *)&PointType);
	return m;
}
