#pragma once
#include "registry.hpp"
#include <vector>


using namespace std;

auto get(vector<auto> & in, int i)
{
    return in.at(i);
}

void set(vector<auto> & in, int i, auto val)
{
    in.at(i) = val;
}

int get_length(vector<auto> & in)
{
    return in.size();
}

void set_length(vector<auto> & in, size_t new_size)
{
    return in.resize(new_size);
}

bool is_iterable(vector<auto> & in){ return true; }

bool is_iterable(int i){ return false;}
