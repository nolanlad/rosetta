#pragma once
#include "registry.hpp"

/************************************************************
 *                   FLOATING POINT
 ************************************************************/

auto & get(double & in, size_t i)
{
    return in;
}

void set(double & in, size_t i, auto val)
{
    in = val;
}

size_t get_length(double & in)
{
    return 1;
}

void set_length(double & in, size_t new_size)
{
}

bool is_iterable(double in){ return false; }

/************************************************************
 *                      INTEGERS
 ************************************************************/

auto & get(int & in, size_t i)
{
    return in;
}

void set(int & in, size_t i, auto val)
{
    in = val;
}

size_t get_length(int & in)
{
    return 1;
}

void set_length(int & in, size_t new_size)
{
}

bool is_iterable(int & in){ return false; }

/*******************************************************
 *                    PYTHON SCALAR 
 *                       TYPES
 ******************************************************/

#ifdef WITH_PYTHON

auto & get(PyObject* & in, size_t i)
{
    if PyFloat_Check(in)
    {
        double out = PyFloat_AsDouble(in);
        double & out2 = out;
        return out2;
    }
    if PyInt_Check(in)
    {
        double out = double(PyInt_AsLong(in));
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