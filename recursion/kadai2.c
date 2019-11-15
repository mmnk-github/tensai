#include <stdio.h>

int fib(int x){
    if(x == 1) return 1;
    if(x < 1) return 0;
    return fib(x-1) + fib(x-2);
}

int main(void){
    int n;
    scanf("%d", &n);
    printf("%d\n", fib(n));
    return 0;
}