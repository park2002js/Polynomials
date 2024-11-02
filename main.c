#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "array_poly.h"

int main(){
    srand(time(NULL));

    ArrayPoly *a = createArrayPoly(2);
    ArrayPoly *b = createArrayPoly(5);

    randArrayPoly(a);
    printf("f(x) = ");
    printArrayPoly(a);

    randArrayPoly(b);
    printf("g(x) = ");
    printArrayPoly(b);


    printf("f(x) + g(x) = ");
    ArrayPoly *c = addArrayPoly(a, b);
    printArrayPoly(c);

    printf("f(x) - g(x) = ");
    ArrayPoly *d = subArrayPoly(a, b);
    printArrayPoly(d);

    freeArrayPoly(a);
    freeArrayPoly(b);
    freeArrayPoly(c);
    freeArrayPoly(d);
    return 0;
}
