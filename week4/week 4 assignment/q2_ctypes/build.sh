set -e
(cd q1_extension && python3 setup.py build_ext --inplace)
(cd q3_pybind11 && python3 setup.py build_ext --inplace)
(cd q5_array_module && python3 setup.py build_ext --inplace)
(cd q2_ctypes && gcc -shared -fPIC -o libmystr.so mystr.c)


