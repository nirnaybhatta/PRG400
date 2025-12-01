from cffi import FFI

ffi = FFI()
ffi.cdef("int dot(int *a, int *b, int n);")

ffi.set_source(
    "dot_module",
    '#include "dotprod.c"',
    sources=["dotprod.c"]
)

ffi.compile()
