#pragma once

/**
 *  Include converters 
 *
 */
#include "std_vector.hpp"



//template<class T>
void converter(auto & out,auto & in)
{
   int len = get_length(in);
   set_length(out,len);
   for(int i = 0; i < len; ++i)
   {
        if(!is_iterable(get(in,i)))
           set(out,i, get(in,i));
   }
   //return out;
}



