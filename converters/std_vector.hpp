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
    in.push_back(val);
}

int length(vector<auto> & in)
{
    return in.size();
}

bool is_iterable(vector<auto> & in){ return true; }

