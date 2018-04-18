#pragma once

/**
 *  Include converters 
 *
 */
#include "std_vector.hpp"



//template<class T>
void converter(auto & out,auto & in)
{
   int len = length(in);
   //T out(3);
   for(int i = 0; i < len; ++i)
      set(out,i, get(in,i));
   //return out;
}



