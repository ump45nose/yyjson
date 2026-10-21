/*
 This file is used to test the compatibility of ANSI C.
 It should be able to compile successfully in strict ANSI C environments.
*/

#include <stdlib.h>

/* The public header must tolerate function-like allocator macros. */
#define malloc(size) test_malloc(size)
#define realloc(ptr, size) test_realloc(ptr, size)
#define free(ptr) test_free(ptr)
#include "yyjson.h"
#undef malloc
#undef realloc
#undef free

#include "yyjson.c"

int main(void) {
    yyjson_mut_doc *mdoc = yyjson_mut_doc_new(NULL);
    yyjson_mut_val *root = yyjson_mut_int(mdoc, 0);
    yyjson_mut_doc_set_root(mdoc, root);
    yyjson_mut_doc_free(mdoc);
    return 0;
}
