#ifndef __POLY_H
#define __POLY_H

typedef struct Term {
    int coef;
    int exp;
    struct Term *next;
} Term;

typedef struct Poly {
    Term *first;
    Term *last;
} Poly;

Term* createTerm(int, int);
Poly* createPoly();
void appendTerm(Poly*, int, int);
void printPoly(Poly*);
void freePoly(Poly*);
Poly* addPoly(Poly*, Poly*, int*);
Poly* subPoly(Poly*, Poly*, int*);

#endif
