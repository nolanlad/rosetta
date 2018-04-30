#include <Python.h>
#include <converters/registry.hpp>
#include <cstdarg>

static PyObject *
plus_wrap(PyObject *self, PyObject *args)
{
    int one,two;
    int sts;
    va_list temp;
    //if (!PyArg_ParseTuple(args, "ii", &one, &two))
    //    return NULL;
    //sts = system(command);
    if (PyTuple_Size(args)==2)
    {
        PyObject * PyOne = PyTuple_GetItem(args,0);
        PyObject * PyTwo = PyTuple_GetItem(args,1);
        converter(one,PyOne);
        converter(two,PyTwo);
    }
    else return NULL;
    //one = va_arg(temp,int);
    //two = va_arg(temp,int);
    //sts = one+two;
    sts=one+two;
    return Py_BuildValue("i", sts);
}

static PyMethodDef SpamMethods[] = {
    {"plus",  plus_wrap, METH_VARARGS,
     "Add."},
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