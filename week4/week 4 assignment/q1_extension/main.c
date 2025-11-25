#include <Python.h>

static PyObject* square(PyObject* self, PyObject* args) {
    int x;
    if (!PyArg_ParseTuple(args, "i", &x)) return NULL;
    int s = x * x;
    return Py_BuildValue("i", s);
}

static PyMethodDef MyMethods[] = {
    {"square", square, METH_VARARGS, "Return square of an integer"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef mymodule = {
    PyModuleDef_HEAD_INIT, "mymodule", NULL, -1, MyMethods
};

PyMODINIT_FUNC PyInit_mymodule(void) {
    return PyModule_Create(&mymodule);
}
