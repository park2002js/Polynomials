#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "array_poly.h"

/*-------- 추가한 부분 --------- */
void test_ArrayPoly_A(ArrayPoly *a){
    int coef[] = {1,-2,3,-4,5};
    for(int i=0; i< 5 ; i++ ){
        a->coef[i] = coef[i];
    }
}

void test_ArrayPoly_B(ArrayPoly *a){
    int coef[] = {5,-3,2,-1,4};
    for(int i=0; i< 5 ; i++ ){
        a->coef[i] = coef[i];
    }
}
/*------------------------------ */

int main(){
    srand(time(NULL));

    ArrayPoly *a = createArrayPoly(100000);
    ArrayPoly *b = createArrayPoly(1500000);

    test_ArrayPoly_A(a);
    // randArrayPoly(a);
    printf("f(x) = ");
    printArrayPoly(a);

    test_ArrayPoly_B(b);
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
