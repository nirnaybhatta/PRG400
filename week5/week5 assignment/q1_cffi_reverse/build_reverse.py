from cffi import FFI

ffi = FFI()
ffi.cdef("void reverse(char *s);")

ffi.set_source(
    "rev_module",
    '#include "reverse.c"',
    sources=["reverse.c"]
)

ffi.compile()
