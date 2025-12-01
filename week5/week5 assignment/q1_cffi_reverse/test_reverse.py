from rev_module import ffi, lib

s = ffi.new("char[]", b"hello")
lib.reverse(s)

print("Reversed string:", ffi.string(s).decode())
