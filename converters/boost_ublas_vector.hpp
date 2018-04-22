#pragma once
#include "registry.hpp"
#include <boost/numeric/ublas/vector.hpp>

void converter(auto & out,auto & in);


auto & get(boost::numeric::ublas::vector<auto> & in, size_t i)
{
    return in(i);
}

void set(boost::numeric::ublas::vector<auto> & in, size_t i, auto val)
{
    converter(in(i),val);
}

size_t get_length(boost::numeric::ublas::vector<auto> & in)
{
    return in.size();
}

void set_length(boost::numeric::ublas::vector<auto> & in, size_t new_size)
{
    return in.resize(new_size);
}

bool is_iterable(boost::numeric::ublas::vector<auto> & in){ return true; }