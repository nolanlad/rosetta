#pragma once
#include "registry.hpp"
#include <vector>

void converter(auto & out,auto & in);

using namespace std;

auto & get(vector<auto> & in, size_t i)
{
    return in.at(i);
}

void set(vector<auto> & in, size_t i, auto val)
{
    converter(in.at(i),val);
}

size_t get_length(vector<auto> & in)
{
    return in.size();
}

void set_length(vector<auto> & in, size_t new_size)
{
    return in.resize(new_size);
}

bool is_iterable(vector<auto> & in){ return true; }