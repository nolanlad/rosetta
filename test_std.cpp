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
   vector<vector<double>> in(2);
   //cout << in[0][0] << endl;
   in.at(0) = {2.,2.,2.};
   in.at(1) = {2.,2.,2.};
   vector<double> in2 = {3., 2., 1.};
   in.at(0) = in2;
   cout << in[0][0] << endl;
   return 1;
}


