#include <stdio.h>

// n, kを受け取り、その二項係数を返す関数bin
int bin(int n, int k){
    if(k == 0) return 1;
    if(n == k) return 1;
    if(k > n) return 0;
    return bin(n-1, k-1) + bin(n-1, k);
}

int main(void){
    int n, k;
    scanf("%d%d", &n, &k);
    bin(n, k);
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < k; j ++){
            printf("%3d ", bin(i, j));
        }
        printf("\n");
    }
    return 0;
}