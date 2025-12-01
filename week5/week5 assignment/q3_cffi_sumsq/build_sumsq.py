from cffi import FFI

ffi = FFI()
ffi.cdef("int sumsq(int n);")

ffi.set_source(
    "sumsq_module",
    '#include "sumsq.c"',
    sources=["sumsq.c"]
)

ffi.compile()
