#include <boost/numeric/ublas/vector.hpp>
#include <converters/registry.hpp>

int main()
{
    boost::numeric::ublas::vector<double> boost_x(3,3);
    vector<double> x = {1.1, 2.1, 3.1};
    converter(boost_x,x);
    print(boost_x);
    return 1;
}