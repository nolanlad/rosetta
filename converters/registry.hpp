#pragma once

/**
 *  Include converters 
 *
 */
#include "std_vector.hpp"
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


void print(int & in){ cout << in;}
void print(double & in){ cout << in;}
void print(auto & in)
{
    cout << "[";
    for(size_t i = 0; i < get_length(in)-1; ++i)
    {
        print(get(in,i));
        cout << "  ";
    }
    print(get(in,get_length(in)-1)) ;
    cout << "]" << endl;
}


