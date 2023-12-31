#include <limits.h>
/*@
    requires INT_MIN <= *p + *q <= INT_MAX;
    requires \valid(p) && \valid(q);
    assigns \nothing;
    ensures \result == *p + *q;
*/
int add(int *p, int *q){
    return *p + *q;
}
//@ assigns \nothing;
int main(){
    int a = 24;
    int b = 42;

    int x;

    x = add(&a, &b);
    //@ assert x == a+b;
    //@ assert x == 66;

    x = add(&a, &a);
    //@ assert x == a+a;
    //@ assert x == 48;
}