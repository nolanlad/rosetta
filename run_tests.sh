g++ -std=c++17 -DWITH_BOOST -I./ -I/usr/include ./tests/test_boost.cpp -o ./tests/test_boost

echo "returned"
./tests/test_boost

echo "expected"
echo "[ 1.1  2.1  3.1 ]"

#g++ -std=c++17 -DWITH_PYTHON -DWITH_BOOST -I/usr/include/python2.7 -I./ -I/usr/include ./tests/test_python.cpp -lboost_python -lpython2.7 -fPIC -shared -o ./tests/spam.so
g++ -std=c++17 -DWITH_PYTHON -DWITH_BOOST -I/usr/include/python2.7 -I./ -I/usr/include ./tests/test_python3.cpp -lboost_python -lpython2.7 -fPIC -shared -o ./tests/spam2.so

clang++-5.0 -std=c++17 -DWITH_PYTHON -DWITH_BOOST -I/usr/include/python2.7 -I./ -I/usr/include ./tests/function_names.cpp -lboost_python -lpython2.7 -fPIC -shared -o ./tests/spam3.so

echo "test python"
#python ./tests/test_python.py
