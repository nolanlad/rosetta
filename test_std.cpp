#include "./converters/registry.hpp"
#include <vector>
#include <iostream>
#include <complex>


using namespace std;
int main()
{
   vector<double> x = {1., 2., 3.};
   vector<int> xd;
   converter(xd,x);
   cout << real(xd.at(0)) << endl;
   vector<vector<int>> x2 = {{1,2},{1,2}};
   vector<int> arm = {2,1};
   converter(x2.at(0),arm);
   cout << x2.at(0).at(0) << endl;
   set(x2,1,arm);
   cout << x2.at(1).at(0) << endl;
   return 1;
}


