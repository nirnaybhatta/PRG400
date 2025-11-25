#include <Python.h>
#include <stdlib.h>

static int *arr = NULL;
static int arr_size = 0;

static PyObject* init_array(PyObject* self, PyObject* args) {
    if (!PyArg_ParseTuple(args, "i", &arr_size)) return NULL;
    if (arr) free(arr);
    arr = (int*)malloc(sizeof(int) * arr_size);
    for (int i = 0; i < arr_size; ++i) arr[i] = 0;
    Py_RETURN_NONE;
}

static PyObject* set_val(PyObject* self, PyObject* args) {
    int idx, val;
    if (!PyArg_ParseTuple(args, "ii", &idx, &val)) return NULL;
    if (idx < 0 || idx >= arr_size) {
        PyErr_SetString(PyExc_IndexError, "index out of range");
        return NULL;
    }
    arr[idx] = val;
    Py_RETURN_NONE;
}

static PyObject* get_val(PyObject* self, PyObject* args) {
    int idx;
    if (!PyArg_ParseTuple(args, "i", &idx)) return NULL;
    if (idx < 0 || idx >= arr_size) {
        PyErr_SetString(PyExc_IndexError, "index out of range");
        return NULL;
    }
    return PyLong_FromLong(arr[idx]);
}

static PyObject* free_array(PyObject* self, PyObject* args) {
    if (arr) { free(arr); arr = NULL; arr_size = 0; }
    Py_RETURN_NONE;
}

static PyMethodDef ArrayMethods[] = {
    {"init", init_array, METH_VARARGS, "Initialize array with given size"},
    {"set", set_val, METH_VARARGS, "Set value at index"},
    {"get", get_val, METH_VARARGS, "Get value at index"},
    {"free", free_array, METH_VARARGS, "Free the array"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef arraymodule = {
    PyModuleDef_HEAD_INIT,
    "arraymodule",
    NULL,
    -1,
    ArrayMethods
};

PyMODINIT_FUNC PyInit_arraymodule(void) {
    return PyModule_Create(&arraymodule);
}
