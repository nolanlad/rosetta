#include <Python.h>
#include <converters/registry.hpp>
#include <typeinfo>
#include <iostream>
#include <vector>
#include <tuple>
#include <functional>

#define ZERO 0


template <typename ReturnType, typename... Args>
auto arg_tuple(ReturnType (*fun)(Args... args))
{
    return std::tuple<Args...>();
}

template <typename ReturnType, typename... Args>
auto get_return_type(ReturnType (*fun)(Args... args))
{
    ReturnType out;
    return out;
}

// implementation details, users never invoke these directly
namespace detail
{
    template <typename F, typename Tuple, bool Done, int Total, int... N>
    struct call_impl
    {
        static auto call(F f, Tuple && t)
        {
            return call_impl<F, Tuple, Total == 1 + sizeof...(N), Total, N..., sizeof...(N)>::call(f, std::forward<Tuple>(t));
        }
    };

    template <typename F, typename Tuple, int Total, int... N>
    struct call_impl<F, Tuple, true, Total, N...>
    {
        static auto call(F f, Tuple && t)
        {
            return f(std::get<N>(std::forward<Tuple>(t))...);
        }
    };
}

// user invokes this
template <typename F, typename Tuple>
auto call(F f, Tuple && t)
{
    typedef typename std::decay<Tuple>::type ttype;
    return detail::call_impl<F, Tuple, 0 == std::tuple_size<ttype>::value, std::tuple_size<ttype>::value>::call(f, std::forward<Tuple>(t));
}

template<int N>
auto & runtime_get(auto & in,int index)
{
    if(index == N){
        return std::get<N>(in);
    }
    else{
        return std::get<N+1>(in);
    }

}

//=================================================================================
//                   PYTHON STUFF
//=================================================================================


double test(int n,int m)
{
    return n*m;
}

template<typename F, F f>
static
PyObject *
cpp_converter(PyObject *self, PyObject *args)
{
    auto sts = get_return_type(test);
    PyObject * temp;
    if (PyTuple_Size(args)==2)
    {
        auto ttt = arg_tuple(test);

        for(int i=0;i<PyTuple_Size(args);++i){
            temp = PyTuple_GetItem(args,i);
            converter(runtime_get<ZERO>(ttt,i),temp);

        }
        sts = call(test,ttt);
        PyObject * out;
        converter(out,sts);
        //return Py_BuildValue("i", sts);
        return out;
    }
    else return NULL;
}

template<typename F>
static PyMethodDef def(F f)
{
    PyMethodDef out = {"plus2", cpp_converter<F,f> , METH_VARARGS,
     "Add."};
    return out;
}



static PyMethodDef SpamMethods[] = {
    {"plus2", cpp_converter<double (*)(int,int),test> , METH_VARARGS,
     "Add."},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};


PyMODINIT_FUNC
initspam2(void)
{
    PyObject *m;

    m = Py_InitModule("spam2", SpamMethods);
    if (m == NULL)
        return;
}
