#ifndef ARRAY_POLY_H
#define ARRAY_POLY_H

typedef struct ArrayPoly {
    int deg;
    int *coef;
} ArrayPoly;

ArrayPoly* createArrayPoly(int);
void freeArrayPoly(ArrayPoly*);
void randArrayPoly(ArrayPoly*);
void printArrayPoly(ArrayPoly*);
ArrayPoly* addArrayPoly(ArrayPoly*, ArrayPoly*);
ArrayPoly* subArrayPoly(ArrayPoly*, ArrayPoly*);

#endif
