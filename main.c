#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "array_poly.h"

int main(){
    srand(time(NULL));

    ArrayPoly *a = createArrayPoly(100000);
    ArrayPoly *b = createArrayPoly(1500000);

    test_randArrayPoly(a,5);
    // randArrayPoly(a);
    printf("f(x) = ");
    printArrayPoly(a);

    test_randArrayPoly(b,5);
    //randArrayPoly(b);
    printf("g(x) = ");
    printArrayPoly(b);

   
    ArrayPoly *c = addArrayPoly(a, b);
    printf("f(x) + g(x) = ");
    printArrayPoly(c);

    
    ArrayPoly *d = subArrayPoly(a, b);
    printf("f(x) - g(x) = ");
    printArrayPoly(d);

    freeArrayPoly(a);
    freeArrayPoly(b);
    freeArrayPoly(c);
    freeArrayPoly(d);
    return 0;
}
