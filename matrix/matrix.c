#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

typedef struct matrix {
    // nrow, ncol はそれぞれ行列の行数、列数を保存します
    int nrow, ncol;
    // data は行列の要素を保存する2次元配列です
    double **data;
} MATRIX;

// allocM はnrow行ncol列の行列を作成し、0埋めした状態で行列のポインタを返します
MATRIX* allocM(int nrow, int ncol){
    // 数値が小さすぎたり大きすぎたりすると危なそうなのでNULLを返しとく
    if(nrow <= 0 || ncol <= 0 || nrow > 1000 || ncol > 1000){
        puts("ERROR!! Abnormal numerical value");
        return NULL;
    }
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
    unsigned char flag = 0;
    for(int i = 0; i < m->nrow; i ++){
        for(int j = 0; j < m->ncol; j ++){
            if(m->data[i][j] >= 1000.0){
                flag = 1;
            }
        }
    }
    if(flag == 1){
        puts("Since elements with more than 4 digits are included, displaying the matrix as it is may cause the display to collapse. Do you still want to display it? (Y/N)");
        char c;
        getchar();
        scanf("%c", &c);
        if(c != 'Y' && c != 'y'){
            return ;
        }
    }

    printf("\n");
    for(int i = 0; i < m->nrow; i ++){
        for(int j = 0; j < m->ncol; j ++){
            printf("%7.3lf ", m->data[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// addM は行列の和を返します
MATRIX* addM(MATRIX* n, MATRIX* m){
    if(n->ncol != m->ncol || n->nrow != m->nrow){
        printf("size error!\n");
        return NULL;
    }else{
        MATRIX *res = allocM(n->nrow, n->ncol);
        for(int i = 0; i < n->nrow; i ++){
            for(int j = 0; j < n->ncol; j ++){
                res->data[i][j] = n->data[i][j] + m->data[i][j];
            }
        }
        return res;
    }
}

// subM は行列の差を返します
MATRIX* subM(MATRIX* n, MATRIX* m){
    if(n->ncol != m->ncol || n->nrow != m->nrow){
        printf("size error!\n");
        return NULL;
    }else{
        MATRIX *res = allocM(n->nrow, n->ncol);
        for(int i = 0; i < n->nrow; i ++){
            for(int j = 0; j < n->ncol; j ++){
                res->data[i][j] = n->data[i][j] - m->data[i][j];
            }
        }
        return res;
    }
}

// mulM は行列の積を返します
MATRIX* mulM(MATRIX* n, MATRIX* m){

}

int main(void){
    srand((unsigned)time(NULL)); // rand() de ransu deru
    int row = 4, col = 5;
    MATRIX *matrix = allocM(row, col);
    printf("%d\n", rand() % 100);
    freeM(matrix);
    return 0;
}