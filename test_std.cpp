#include "./converters/registry.hpp"
#include "./converters/boost_ublas_vector.hpp"
#include <boost/numeric/ublas/vector.hpp>
#include <vector>
#include <iostream>
#include <sstream>
#include <complex>

using namespace std;


int main()
{

    cout << "vector<double> to vector<int>" << endl << endl;

    boost::numeric::ublas::vector<double> boost_x(3,3);
    vector<double> x = {1.1, 2.1, 3.1};
    vector<int> xd;
    converter(xd,x);
    converter(boost_x,x);
    print(boost_x);
    print(x);
    cout << endl;
    cout << "vector<vector<double>> to vector<vector<int>>" << endl << endl;

    vector<vector<double>> xx = {{2.2, 2.3},{2.4,2.5}};
    vector<vector<int>> xxd(1);
    converter(xxd,xx);
    print(xx);
    print(xxd);
}


