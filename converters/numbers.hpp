#pragma once
#include "registry.hpp"

auto & get(double & in, int i)
{
    return in;
}

void set(double & in, int i, auto val)
{
    in = val;
}

int get_length(double & in)
{
    return 1;
}

void set_length(double & in, size_t new_size)
{
}

bool is_iterable(double in){ return false; }

/************************************************************
 *             INTEGERS
 ************************************************************/

auto & get(int & in, int i)
{
    return in;
}

void set(int & in, int i, auto val)
{
    in = val;
}

int get_length(int & in)
{
    return 1;
}

void set_length(int & in, size_t new_size)
{
}

bool is_iterable(int & in){ return false; }