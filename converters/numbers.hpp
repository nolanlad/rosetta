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