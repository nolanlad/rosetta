#include <Python.h>
#include <converters/registry.hpp>

static PyObject *
spam_system(PyObject *self, PyObject *args)
{
    int command;
    int sts;

    if (!PyArg_ParseTuple(args, "i", &command))
        return NULL;
    //sts = system(command);
    sts = command+2;
    return Py_BuildValue("i", sts);
}

static PyMethodDef SpamMethods[] = {
    {"system",  spam_system, METH_VARARGS,
     "Add 2."},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};

static PyObject *SpamError;

PyMODINIT_FUNC
initspam(void)
{
    PyObject *m;

    m = Py_InitModule("spam", SpamMethods);
    if (m == NULL)
        return;

    SpamError = PyErr_NewException("spam.error", NULL, NULL);
    Py_INCREF(SpamError);
    PyModule_AddObject(m, "error", SpamError);
}


/*
PyObject * test(PyObject * in)
{
    PyObject * out;
    double test2;
    converter(test2,in);
    converter(out,test2);
    return out;
}

#include <boost/python.hpp>

BOOST_PYTHON_MODULE(test_python)
{
    using namespace boost::python;
    def("test", test,"test docstring");
}
*/