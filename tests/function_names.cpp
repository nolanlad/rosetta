#include <Python.h>

#define PYTHON_MOD(name) PyMODINIT_FUNC init##name(void){\
static PyMethodDef Methods[] = {\
{"test",  test_func, METH_VARARGS, "test"},\
{NULL, NULL, 0, NULL}\
};\
(void) Py_InitModule(#name, Methods);\
}\


extern "C"
{
static PyObject * test_func(PyObject *self, PyObject *args)
{
return PyInt_FromLong(0);
}

//static PyMethodDef TestMethods[] = {
//{"test",  test_func, METH_VARARGS, "test"},
//{NULL, NULL, 0, NULL}
//};

PYTHON_MOD(spam3)

#undef PYTHON_MOD

//PyMODINIT_FUNC initspam3(void) {
//(void) Py_InitModule("spam3", TestMethods);
//}
}

/*
//make function factory and use it
#define FUNCTION(name, a) int fun_##name() { return a;}
 
FUNCTION(abcd, 12)
FUNCTION(fff, 2)
FUNCTION(qqq, 23)
 
#undef FUNCTION
#define FUNCTION 34
#define OUTPUT(a) std::cout << "output: " #a << '\n'


int main()
{
    std::cout << "abcd: " << fun_abcd() << '\n';
    std::cout << "fff: " << fun_fff() << '\n';
    std::cout << "qqq: " << fun_qqq() << '\n';
    std::cout << FUNCTION << '\n';
    OUTPUT(million);               //note the lack of quotes
}
*/
