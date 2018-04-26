#include <typeinfo>
#include <iostream>
#include <vector>

void what_type(size_t hash)
{
    if(hash == typeid(int).hash_code()) std::cout << "int" << std::endl;
    if(hash == typeid(double).hash_code()) std::cout << "double" << std::endl;
    
}

int set_hash(std::vector<size_t> & types,size_t hash)
{
    types.push_back(hash);
    return 1;
}

template<class...A>
void dummy(A&&...)
{
}

template <class ...A>
std::vector<size_t> do_something()
{
    std::vector<size_t> hashes;
    int temp;
    dummy( ( temp= set_hash(hashes,typeid(A).hash_code())  )... );
    return hashes;
}

template <typename ReturnType, typename... Args>
void get_types(ReturnType (*fun)(Args... args))
{
    std::vector<size_t> hh = do_something<Args...>();
    for(size_t x: hh)
    {
        std::cout << "parameter: ";
        what_type(x);
    }
    std::cout << "return type: ";
    what_type(typeid(ReturnType).hash_code());
}

int test(int n,double m)
{
    return n*m;
}

int main()
{
    do_something<int,double,int,int>();
    get_types(test);
}
