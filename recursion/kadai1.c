#include <stdio.h>

int sum(int x){
    if(x < 1) return 0;
    return sum(x-1) + x;
}

int main(void){
    int n;
    scanf("%d", &n);
    printf("%d\n", sum(n));
    return 0;
}