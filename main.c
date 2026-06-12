#include "svectorlib.h"

// generate vector types
SVECTOR_DEFINE(int, int, "%d")
SVECTOR_DEFINE(float, float, "%f")
SVECTOR_DEFINE(char*, string, "%c")

int main() {

    // int vector
    svector_int vi;
    svector_int_init(&vi);

    svector_int_push(&vi, 10);
    svector_int_push(&vi, 20);

    svector_int_print(&vi);

    svector_int_free(&vi);

    // float vector
    svector_float vf;
    svector_float_init(&vf);

    svector_float_push(&vf, 3.14f);

    printf("%f\n", svector_float_get(&vf, 0));

    svector_float_free(&vf);

    // string vector
    svector_string vs;
    svector_string_init(&vs);

    svector_string_push(&vs, "hello");
    svector_string_push(&vs, "world");

    svector_string_print(&vs);

    svector_string_free(&vs);

    return 0;
}
