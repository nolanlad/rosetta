#pragma once

/**
 *  Include converters 
 *
 */
#include "std_vector.hpp"

#ifdef WITH_BOOST
#include "boost_ublas_vector.hpp"
#endif

#ifdef WITH_PYTHON
   #include <Python.h>
   #include "python.hpp"
#endif

#include "numbers.hpp"
#include <iostream>

using namespace std;
/*
void converter(double & out, int & in)
{
    out = in;
}

void converter(int & out, double & in)
{
    out = in;
}
*/

void converter(auto & out,auto & in)
{
    size_t len = get_length(in);
    set_length(out,len);
    for(size_t i = 0; i < len; ++i)
    {
        set(out,i, get(in,i));
    }
}

void print(){cout << endl;}

void print(int & in){ cout << in;}

void print(double & in){ cout << in;}

void print(auto & in)
{
    cout << "[ ";
    for(size_t i = 0; i < get_length(in); ++i)
    {
        print(get(in,i));
        cout << "  ";
    }
    cout << "]" << endl;
}

/*
ostream & operator << (ostream &out, vector<auto> &c){
    out << "[ ";
    for(size_t i = 0; i < get_length(c)-1; ++i)
    {
        out << get(c,i) << " , ";
    }
    out << get(c,get_length(c)-1) << " ]";
    return out;
}
*/
