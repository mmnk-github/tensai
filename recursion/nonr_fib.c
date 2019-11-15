#include <stdio.h>

int fib_memory[1000] = {};
int nonr_fib(int n){
    if(n < 0) return -1;
    if(n == 0) return 0;
    if(n == 1) return 1;
    fib_memory[1] = 1;
    if(fib_memory[n] != 0) return fib_memory[n];
    int i = n - 1;
    while(fib_memory[i] == 0) -- i;
    for(; i < n; i ++) fib_memory[i+1] = fib_memory[i] + fib_memory[i-1];
    return fib_memory[n];
}

int main(void){
    int n;
    scanf("%d", &n);
    printf("%d\n", nonr_fib(n));
    return 0;
}