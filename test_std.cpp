#include "./converters/registry.hpp"
#include <vector>
#include <iostream>


using namespace std;
int main()
{
   vector<double> x = {1., 2., 3.};
   vector<double> xd;
   converter(xd,x);
   cout << xd.at(0) << endl;
   return 1;
}
