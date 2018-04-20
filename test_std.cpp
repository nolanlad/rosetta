#include "./converters/registry.hpp"
#include <vector>
#include <iostream>
#include <complex>

using namespace std;

int main()
{

    cout << "vector<double> to vector<int>" << endl << endl;

    vector<double> x = {1.1, 2.1, 3.1};
    vector<int> xd(3);
    converter(xd,x);
    print(x);
    print(xd);
    cout << endl;

    cout << "vector<vector<double>> to vector<vector<int>>" << endl << endl;

    vector<vector<double>> xx = {{2.2,2.2},{2.2,2.2}};
    vector<vector<int>> xxd;
    converter(xxd,xx);
    print(xx);
    print(xxd);

    vector<vector<double>> xx2 = {{2.2,2.2},{2.2,2.2},{2.2,2.2}};
    vector<vector<int>> xxd2;
    converter(xxd2,xx2);
    print(xx2);
    print(xxd2);
}


