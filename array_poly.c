#include <stdio.h>
#include <stdlib.h>
#include "array_poly.h"

/*-------- 추가한 부분1 --------- */
#include <time.h>
void test_randArrayPoly(ArrayPoly *a, int max){
    int count = 0;
    int index = 0;
    while(count != max){
        index = rand() % (a->deg+1);
        if(a->coef[index] == 0 ){
            int i=0;
            while(i==0){
                i = (rand() % 21) - 10;
            }
            a->coef[index] = i;
            count++;
        }
    }
}
/*------------------------------ */

static inline int __imax2(int a, int b)
{
	return a > b ? a : b;
}

static inline int __iabs(int a)
{
	return a < 0 ? -a : a;
}

ArrayPoly *createArrayPoly(int deg) {
    ArrayPoly *a = (ArrayPoly*) malloc(sizeof(ArrayPoly));
    a->deg = deg;
    a->coef = (int*) calloc(deg+1, sizeof(int));
    return a;
}

void freeArrayPoly(ArrayPoly* a) {
    free(a->coef);
    free(a);
}

// randArrayPoly: randomize ArrayPoly coefficients.
void randArrayPoly(ArrayPoly *a) {
    for (int i = 0; i <= a->deg; i++)
        a->coef[i] = (rand() % 21) - 10; // randomized values are within [-10, 10].
}



void printArrayPoly(ArrayPoly *a){
    int first = 1;

    for (int i = a->deg; i>=0; i--) {
        if(a->coef[i] == 0)
	    continue;

	if (first) {
	    printf("%dx^%d", a->coef[i], i);
	    first = 0;
	} else
            printf(" %c %dx^%d", a->coef[i] > 0 ? '+' : '-', __iabs(a->coef[i]), i);
    }

    puts("");
}

// helper function for addition/subtraction operations on ArrayPoly structs.
static ArrayPoly *__addArrayPoly(ArrayPoly *a, ArrayPoly *b, int sign) {
    ArrayPoly *res = createArrayPoly(__imax2(a->deg, b->deg));

    // 추가1
    clock_t start = clock(); 
    //-----

    for (int i = 0; i <= a->deg; i++)
        res->coef[i] += a->coef[i];

    for (int i = 0; i <= b->deg; i++)
	    res->coef[i] += sign * b->coef[i];

    // 추가2
    clock_t end = clock();
    double t = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\n경과 시간 : %lf\n", t);
    //-------

    return res;
}

ArrayPoly *addArrayPoly(ArrayPoly *a, ArrayPoly *b) {
	return __addArrayPoly(a, b, 1);
}

ArrayPoly *subArrayPoly(ArrayPoly *a, ArrayPoly *b) {
	return __addArrayPoly(a, b, -1);
}
