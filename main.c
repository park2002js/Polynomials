#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BUFF 20

struct Poly{
    int *a; // 계수 저장 배열
    int *x; // 차수 인덱스
    int n; // 항의 갯수
    // 5x^4 - 4x^2 +5
    // => n[0] = 4, n[1] = 2, n[2] = 0
    // => a[0] = 5, a[1] = -4, a[3] = 5
};
typedef struct Poly Poly;

void AUX(Poly a, Poly b, Poly* res, int s){

    int i=0;
    int k=0;
    int t=0;
    res->n = 0;

    while( i<a.n || k<b.n ){
        if(a.x[i]==b.x[k]){
            res->x[t] = a.x[i];
            res->a[t] = a.a[i]+b.a[k]*s;
            i++;
            k++;
            t++;
            res->n=t;

        } else if ( a.x[i]>b.x[k]) {
            res->x[t] = a.x[i];
            res->a[t] = a.a[i];
            i++;
            t++;
            res->n=t;

        } else if ( a.x[i]<b.x[k]){
            res->x[t] = b.x[k];
            res->a[t] = b.a[k]*s;
            k++;
            t++;
            res->n=t;
        }
    }
}

void printPoly(Poly a){
    for(int i=0; i<a.n; i++){
        printf("  %dX^%d",a.a[i],a.x[i]);
    }
}

void PolyMake(Poly* a){
    int i = 5;
    int s;
    
    a->a = (int*)malloc(sizeof(int)*50);
    a->x = (int*)malloc(sizeof(int)*50);

    if(rand()%2!=0)
        s=-1;
    else
        s=1;

    a->n = i;
    a->a[i-1] = (rand()%10+1)*s;
    a->x[i-1] = rand()%3; 

    for(int j=i-2; j>=0; j--){
        if(rand()%2!=0)
            s=-1;
        else
            s=1;

        a->a[j] = (rand()%10+1)*s;
        a->x[j] = (rand()%5+1)+a->x[j+1];
    }
}

void freePoly(Poly* a){
    free(a->a);
    free(a->x);
}

int main(){
    Poly a;
    Poly b;
    Poly c;

    srand(time(NULL));

    PolyMake(&a);
    printPoly(a);

    printf("\n");

    PolyMake(&b);
    printPoly(b);

    PolyMake(&c);

    printf("\n\nADD");
    AUX(a,b,&c,1);
    printPoly(c);

    printf("\nSUB");
    AUX(a,b,&c,-1);
    printPoly(c);

    freePoly(&a);
    freePoly(&b);
    freePoly(&c);

    return 0;
}