#include <stdio.h>
#include "poly.h"
#include "array_poly.h"

// for all the test functions, the exponents are expected to be in descending order.

void testPoly(int m, int *exp1, int *coef1, int n, int *exp2, int *coef2)
{
    puts("<Poly>");
    Poly *a = createPoly();
    Poly *b = createPoly();

    // assigning coefficients for a.
    for (int i = 0; i < m; i++)
        appendTerm(a, coef1[i], exp1[i]);

    // assigning coefficients for b.
    for (int i = 0; i < n; i++)
	appendTerm(b, coef2[i], exp2[i]);

    printf("f(x) = ");
    printPoly(a);
    puts("");

    printf("g(x) = ");
    printPoly(b);
    puts("");

    int status;
    Poly *c = addPoly(a, b, &status);
    printf("f(x) + g(x) = ");
    printPoly(c);
    printf("%d iteration(s)\n\n", status);

    Poly *d = subPoly(a, b, &status);
    printf("f(x) - g(x) = ");
    printPoly(d);
    printf("%d iteration(s)\n\n", status);

    freePoly(a);
    freePoly(b);
    freePoly(c);
    freePoly(d);
}

void testArrayPoly(int m, int *exp1, int *coef1, int n, int *exp2, int *coef2)
{
    puts("<ArrayPoly>");
    ArrayPoly *a = createArrayPoly(exp1[0]);
    ArrayPoly *b = createArrayPoly(exp2[0]);

    // assigning coefficients for a.
    for (int i = 0; i < m; i++)
	    a->coef[exp1[i]] = coef1[i];

    // assigning coefficients for b.
    for (int i = 0; i < n; i++)
	    b->coef[exp2[i]] = coef2[i];

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
}

int main() {
    int coef[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int exp[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    testPoly(10, exp, coef, 10, exp, coef);
    testArrayPoly(10, exp, coef, 10, exp, coef);

    int coef1[5] = {5, 4, 3, 2, 1};
    int exp1[5] = {1000000, 999999, 2500, 100, 1};

    int coef2[7] = {-1, -2, -3, -4, -5, -6, -7};
    int exp2[7] = {1000000, 500000, 100000, 5000, 2500, 5, 0};

    testPoly(5, exp1, coef1, 7, exp2, coef2);
    testArrayPoly(5, exp1, coef1, 7, exp2, coef2);

    return 0;
}
