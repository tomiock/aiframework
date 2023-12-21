#include <python3.10/Python.h>
#include <python3.10/modsupport.h>
#include <python3.10/moduleobject.h>
#include <python3.10/object.h>
#include <python3.10/pyport.h>

#include "my_class_py_type.h"

PyModuleDef my_module = {
	PyModuleDef_HEAD_INIT,
	"MyModule",
	"this is my modules docstring",
	-1,	// Optional size of the module state memory
	NULL,
	NULL,
	NULL,
	NULL,
	NULL
};

PyMODINIT_FUNC
PyInit_mymodule(void) {
	PyObject* module = PyModule_Create(&my_module);

	PyObject *myclass = PyType_FromSpec(&spec_myclass);
	if (myclass == NULL){
		return NULL;
	}
	Py_IncRef(myclass);

	if (PyModule_AddObject(module, "MyClass", myclass) < 0){
		Py_DecRef(myclass);
		Py_DecRef(module);
		return NULL;
	}
	return module;
}
