#pragma once

/**
 *  Include converters 
 *
 */
#include "std_vector.hpp"
#include "numbers.hpp"
#include <iostream>

using namespace std;

void converter(double & out, int & in){

    out = in;

}

void converter(int & out, double & in){

    out = in;

}

void converter(auto & out,auto & in)
{
   if(is_iterable(in))
   {
      int len = get_length(in);
      set_length(out,len);
      cout << "iterable" << endl;
      for(int i = 0; i < len; ++i)
      {
           //cout << "converting " << i << endl;
           // auto & temp = get(out,i);
           //converter(temp, get(in,i));
           set(out,i, get(in,i));
           //set(out,i, temp);
           //converter(get(out,i),get(in,i));
      }
   }
}



