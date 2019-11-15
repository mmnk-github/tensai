#include <stdio.h>

int fact_memory[10000] = {};
int nonr_fact(int n){
    if(n < 0) return -1;
    if(fact_memory[n] != 0) return fact_memory[n];
    if(n <= 1) return fact_memory[n] = 1;
    int i = n - 1;
    while(i > 0 && fact_memory[i] == 0) -- i;
    if(i == 0) fact_memory[i] = 1;
    for(; i < n; i ++) fact_memory[i+1] = fact_memory[i] * (i + 1);
    return fact_memory[n];
}

int main(void){
    int n;
    scanf("%d", &n);
    printf("%d\n", nonr_fact(n));
    return 0;
}

