#include "./converters/registry.hpp"
#include <vector>
#include <iostream>
#include <sstream>
#include <complex>

using namespace std;


int main()
{

    cout << "vector<double> to vector<int>" << endl << endl;

    vector<double> x = {1.1, 2.1, 3.1};
    vector<int> xd(3);
    converter(xd,x);
    print(x);
    cout << x << endl;
    //print(xd);
    cout << xd << endl;
    cout << endl;

    cout << "vector<vector<double>> to vector<vector<int>>" << endl << endl;

    vector<vector<double>> xx = {{2.2, 2.3},{2.4,2.5}};
    vector<vector<int>> xxd(1);
    converter(xxd,xx);
    //print(xx);
    cout << xx << endl;
    cout << xxd << endl;
    //print(xxd);
}


