from dot_module import ffi, lib

a = [1,2,3,4,5,6,7,8,9,10]
b = [10,9,8,7,6,5,4,3,2,1]

arr1 = ffi.new("int[]", a)
arr2 = ffi.new("int[]", b)

result = lib.dot(arr1, arr2, len(a))
print("Dot product =", result)
