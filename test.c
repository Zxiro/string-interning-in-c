#include <stdio.h>
#include <time.h>

#include "cstr.h"

static cstring cmp(cstring t)
{
    CSTR_LITERAL(hello, "Hello string");
    CSTR_BUFFER(ret);
    cstr_cat(ret, cstr_equal(hello, t) ? "equal" : "not equal");
    return cstr_grab(CSTR_S(ret));
}

static void test_cstr()
{
    CSTR_BUFFER(a);
    cstr_cat(a, "Hello ");
    cstr_cat(a, "string");
    cstring b = cmp(CSTR_S(a));
    printf("%s\n", b->cstr);
    CSTR_CLOSE(a);
    cstr_release(b);
}

int main(int argc, char *argv[])
{
    for (int i = 0; i< 10; i++){
    clock_t start, end;
    start = clock();
    test_cstr();
    end = clock();
    double time = ((double)(end-start))/ CLOCKS_PER_SEC;
    printf("%f\n", time);
    }
    return 0;
}
