#include "./converters/registry.hpp"
#include <vector>
#include <iostream>
#include <complex>


using namespace std;
int main()
{
    cout << "1d vector" << endl;
    vector<double> x = {1., 2., 3.};
    vector<int> xd(3);
    converter(xd,x);
    cout << xd[0] << endl;
    cout << "2d vector" << endl;
    vector<vector<double>> xx = {{2.,2.},{2.,2.}};
    vector<vector<int>> xxd(2);
    //converter(xxd,xx);
    //cout << xxd[0][0] << endl;
    double ii = 9.0;
    int jj = 8;
    converter(ii,jj); 
    cout << ii << endl;
   //converter(xd,x);
   /*
   vector<double> x = {1., 2., 3.};
   vector<int> xd(3);
   converter(xd,x);
   //cout << real(xd.at(0)) << endl;
   for(int i = 0; i < 3; ++i){
      cout << is_iterable(get(x,i)) << endl;
      converter(get(xd,i),get(x,i));
   }
   vector<vector<double>> xx = {{2.,2.},{2.,2.}};
   vector<vector<int>> xxd(2);
   //converter(xd,x);
   //cout << real(xd.at(0)) << endl;
   for(int i = 0; i < 2; ++i){
      cout << is_iterable(get(xx,i)) << endl;
      converter(get(xxd,i),get(xx,i));
   }
   
   //cout << xd.at(0) << endl;
   double ii = 9.0;
   int jj;
   converter(ii,jj);
   
   vector<vector<int>> x2 = {{1,2},{1,2}};
   vector<vector<double>> dx2 = {{2.,2.},{2.,2.}};
   vector<int> arm = {2,1};
   //converter(x2.at(0),arm);
   converter(get(x2,0),get(dx2,0));
   cout << x2.at(0).at(0) << endl;
   set(x2,1,arm);
   cout << x2.at(1).at(0) << endl;
   double ii = 9.0;
   int jj = 8;
   converter(ii,jj); 
   return 1;
   */
}


