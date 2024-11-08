#include <stdio.h>
#include <stdlib.h>
#include "poly.h"
#include "util.h"

Term *createTerm(int coef, int exp) {
    Term *newTerm = (Term*) malloc(sizeof(Term));
    newTerm->coef = coef;
    newTerm->exp = exp;
    newTerm->next = NULL;
    return newTerm;
}

Poly *createPoly() {
    Poly *newPoly = (Poly*) malloc(sizeof(Poly));
    newPoly->first = NULL;
    newPoly->last = NULL;
    return newPoly;
}

void appendTerm(Poly *poly, int coef, int exp) {
    // zero coefficients are immediately rejected.
    if (coef == 0)
        return;

    Term *newTerm = createTerm(coef, exp);
    if (poly->first == NULL) {
        poly->first = newTerm;
        poly->last = newTerm;
    }
    else {
        poly->last->next = newTerm;
        poly->last = newTerm;
    }
}

void printPoly(Poly *poly) {
    if (poly->first == NULL) {
        puts("0");
        return;
    }

    // immediately print the first term.
    Term *current = poly->first;
    printf("%dx^%d", current->coef, current->exp);
    current = current->next;

    while (current != NULL) {
        printf(" %c %dx^%d", current->coef > 0 ? '+' : '-', iabs(current->coef), current->exp);
        current = current->next;
    }
    puts("");
}

void freePoly(Poly *poly) {
    Term *current = poly->first;
    Term *temp;

    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
}

// helper function for addition/subtraction operations on Poly structs.
static Poly *__addPoly(Poly *poly1, Poly *poly2, int sign, int *status) {
    Poly *res = createPoly();
    Term *t1 = poly1->first, *t2 = poly2->first;
    int cnt = 0;

    while (t1 != NULL && t2 != NULL) {
        if (t1->exp > t2->exp) {
            appendTerm(res, t1->coef, t1->exp);
            t1 = t1->next;
        } else if (t1->exp < t2->exp) {
            appendTerm(res, sign * t2->coef, t2->exp);
            t2 = t2->next;
        } else {
            appendTerm(res, t1->coef + sign * t2->coef, t1->exp);
            t1 = t1->next;
            t2 = t2->next;
        }
	cnt++;
    }

    while (t1 != NULL) {
        appendTerm(res, t1->coef, t1->exp);
        t1 = t1->next;
	cnt++;
    }
    while (t2 != NULL) {
        appendTerm(res, sign * t2->coef, t2->exp);
        t2 = t2->next;
	cnt++;
    }

    // only save the count if the status variable is non-null.
    if (status)
        *status = cnt;
    return res;
}

Poly *addPoly(Poly *poly1, Poly *poly2, int *status) {
    return __addPoly(poly1, poly2, 1, status);
}

Poly *subPoly(Poly *poly1, Poly *poly2, int *status) {
    return __addPoly(poly1, poly2, -1, status);
}
