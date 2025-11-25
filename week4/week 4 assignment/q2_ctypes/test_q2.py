import ctypes
import os

# adjust library name per platform
libname = "./libmystr.so"  # Linux/WSL
# libname = "./mystr.dll"  # Windows

lib = ctypes.CDLL(libname)

# declare argtypes and restype
lib.to_upper.argtypes = [ctypes.c_char_p, ctypes.c_char_p]
lib.to_upper.restype = None

input_s = b"Hello World!"
output = ctypes.create_string_buffer(256)
lib.to_upper(input_s, output)

print(output.value.decode())  # HELLO WORLD!
