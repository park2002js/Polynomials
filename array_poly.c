#include <stdio.h>
#include <stdlib.h>
#include "array_poly.h"
#include "util.h"

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

void printArrayPoly(ArrayPoly *a)  {
    int first = 1;

    for (int i = a->deg; i>=0; i--) {
        if(a->coef[i] == 0)
	    continue;

	if (first) {
	    printf("%dx^%d", a->coef[i], i);
	    first = 0;
	} else
            printf(" %c %dx^%d", a->coef[i] > 0 ? '+' : '-', iabs(a->coef[i]), i);
    }
    
    puts(first ? "0" : "");
}

// helper function for addition/subtraction operations on ArrayPoly structs.
static ArrayPoly *__addArrayPoly(ArrayPoly *a, ArrayPoly *b, int sign, int *status) {
    ArrayPoly *res = createArrayPoly(imax2(a->deg, b->deg));
    int cnt = 0;

    for (int i = 0; i <= a->deg; i++) {
        res->coef[i] += a->coef[i]; 
        cnt++;
    }

    for (int i = 0; i <= b->deg; i++) {
	res->coef[i] += sign * b->coef[i];
        cnt++;
    }

    // only save the count if the status variable is non-null.
    if (status)
        *status = cnt;
    return res;
}

ArrayPoly *addArrayPoly(ArrayPoly *a, ArrayPoly *b, int *status) {
    return __addArrayPoly(a, b, 1, status);
}

ArrayPoly *subArrayPoly(ArrayPoly *a, ArrayPoly *b, int *status) {
    return __addArrayPoly(a, b, -1, status);
}
