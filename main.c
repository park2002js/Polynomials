#include <stdio.h>
#include <stdlib.h>
#include "array_poly.h"

int main(){
    ArrayPoly *a = createArrayPoly(1000000);
    ArrayPoly *b = createArrayPoly(1000000);

    // assigning coefficients.
    a->coef[1000000] = 5;
    a->coef[50000] = -3;
    a->coef[25000] = 2;
    a->coef[100] = -1;
    a->coef[0] = 4;
    b->coef[1000000] = 1;
    b->coef[999999] = -2;
    b->coef[1000] = 3;
    b->coef[999] = -4;
    b->coef[0] = 5;

    printf("f(x) = ");
    printArrayPoly(a);
    puts("");

    printf("g(x) = ");
    printArrayPoly(b);
    puts("");

    int status;
    ArrayPoly *c = addArrayPoly(a, b, &status);
    printf("f(x) + g(x) = ");
    printArrayPoly(c);
    printf("%d iteration(s)\n\n", status);

    ArrayPoly *d = subArrayPoly(a, b, &status);
    printf("f(x) - g(x) = ");
    printArrayPoly(d);
    printf("%d iteration(s)\n\n", status);

    freeArrayPoly(a);
    freeArrayPoly(b);
    freeArrayPoly(c);
    freeArrayPoly(d);
    return 0;
}
