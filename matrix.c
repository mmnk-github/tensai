#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct matrix {
    // nrow, ncol はそれぞれ行列の行数、列数を保存します
    int nrow, ncol;
    // data は行列の要素を保存する2次元配列です
    double **data;
} MATRIX;

// allocM はnrow行ncol列の行列を作成し、0埋めした状態で行列のポインタを返します
MATRIX* allocM(int nrow, int ncol){
    MATRIX* matrix;
    matrix = malloc(sizeof(MATRIX));
    matrix->nrow = nrow;
    matrix->ncol = ncol;
    matrix->data = malloc(sizeof(double *) * nrow);
    for(int i = 0; i < nrow; i ++){
        matrix->data[i] = malloc(sizeof(double) * ncol);
        for(int j = 0; j < ncol; j ++){
            matrix->data[i][j] = 0.0;
        }
    }
    return matrix;
}

// freeM は行列のメモリを解放します
void freeM(MATRIX* m){
    for(int i = 0; i < m->nrow; i ++){
        free(m->data[i]);
    }
    free(m->data);
    free(m);
    return;
}

// printM は行列を表示します
void printM(MATRIX* m){
    printf("\n");
    for(int i = 0; i < m->nrow; i ++){
        for(int j = 0; j < m->ncol; j ++){
            printf("%7.3lf ", m->data[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(void){
    int col, row;
    printf("Will make a matrix.\ncol = ");
    scanf("%d", &col);
    printf("row = ");
    scanf("%d", &row);
    MATRIX* matrix = allocM(col, row);
    matrix->data[0][0] = 123.5;
    printM(matrix);
    freeM(matrix);
    return 0;
}