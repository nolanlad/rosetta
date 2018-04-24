#pragma once
#include "registry.hpp"

/*******************************************************
 *                    PYTHON SCALAR 
 *                       TYPES
 ******************************************************/

#ifdef WITH_PYTHON

auto & get(PyObject* & in, size_t i)
{
    if(PyNumber_Check(in))
    {
        double out = PyFloat_AsDouble(PyNumber_Float(in));
        double & out2 = out;
        return out2;
    }
    else
    {
        double out = 6.9;
        double & out2 = out;
        return out2;
    }

}

void set(PyObject* & in, size_t i, int val)
{
    in = PyLong_FromLong(val);
}

void set(PyObject* & in, size_t i, double val)
{
    in = PyFloat_FromDouble(val);
}

size_t get_length(PyObject* & in)
{
    return 1;
}

void set_length(PyObject* & in, size_t new_size)
{
}

#endif //WITH_PYTHON