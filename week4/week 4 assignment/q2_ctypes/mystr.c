#include <ctype.h>
#include <string.h>

// input and output are char* buffers.
// output must be preallocated by caller.
void to_upper(const char *input, char *output) {
    size_t i;
    for (i = 0; input[i]; ++i) {
        output[i] = toupper((unsigned char)input[i]);
    }
    output[i] = '\0';
}
