#include <Python.h>
#include <converters/registry.hpp>

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