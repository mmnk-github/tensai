#include <stdio.h>

int sum_memory[10000] = {};
int nonr_sum(int n){
    if(n < 0) return -1;
    if(n == 0) return 0;
    if(sum_memory[n] != 0) return sum_memory[n];
    int i = n - 1;
    while(i > 0 && sum_memory[i] == 0) -- i;
    if(i == 0) sum_memory[i] = 0;
    for(; i < n; i ++) sum_memory[i+1] = sum_memory[i] + (i + 1);
    return sum_memory[n];
}

int main(void){
    int n;
    scanf("%d", &n);
    printf("%d\n", nonr_sum(n));
    return 0;
}

