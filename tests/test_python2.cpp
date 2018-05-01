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


//static PyObject *
PyObject *
plus_wrap(PyObject *self, PyObject *args)
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

template<typename F, F f>
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

template <typename F>
class regis
{
    public:
    F func;
    regis(F f){ func = f; };
    //static F func;
    void reg(F f)
    {
        func = f;
    }
    double run()
    {
        return func(2,2);
    }
    PyObject *
    cpp_wrap(PyObject *self, PyObject *args)
    {
        auto sts = get_return_type(func);
        PyObject * temp;
        if (PyTuple_Size(args)==2)
        {
            auto ttt = arg_tuple(func);

            for(int i=0;i<PyTuple_Size(args);++i){
                temp = PyTuple_GetItem(args,i);
                converter(runtime_get<ZERO>(ttt,i),temp);

            }
            sts = call(func,ttt);
            PyObject * out;
            converter(out,sts);
            //return Py_BuildValue("i", sts);
            return out;
        }
        else return NULL;
    }
    
    
};


template <typename F>
auto get_regis(F f)
{
    regis<F> x = regis<F>(f);
    //double out = x.run();
    //x.reg(f);
    return x;
}

template<class T>
static PyObject *
plus_wrap2(PyObject *self, PyObject *args)
{
    auto xx = get_regis(test);
    return xx.cpp_wrap(self,args);
    //return plus_wrap(self,args);
}

template<PyObject * (*f)(PyObject*,PyObject*)>
static PyObject *
plus_wrap3(PyObject *self, PyObject *args)
{
    //auto xx = get_regis(test);
    return f(self,args);
    //return plus_wrap(self,args);
}

auto cc = get_regis(test);



static PyObject * (*this_test2)(PyObject *,PyObject *) = &plus_wrap;

static PyObject *SpamError;

static PyMethodDef SpamMethods[] = {
    {"plus",  plus_wrap, METH_VARARGS,
     "Add."},
    {"plus2", cpp_converter<double (*)(int,int),test> , METH_VARARGS,
     "Add."},
//     {"plus2",  cpp_wrapper(test)::wrapper, METH_VARARGS,
//     "Add."},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};

PyMODINIT_FUNC
initspam2(void)
{
    PyObject *m;

    m = Py_InitModule("spam2", SpamMethods);
    if (m == NULL)
        return;

    //SpamError = PyErr_NewException("spam2.error", NULL, NULL);
    //Py_INCREF(SpamError);
    //PyModule_AddObject(m, "error", SpamError);
}
