#include<stdio.h>
#include<stdlib.h>

void Allocate_2D_Array(int n, int m, float** mat){
    for(int i = 0; i< n; i++)
        mat[i] = (float*)malloc(m * sizeof(float));
}

void Read_2D_Array(int n, int m, float** mat){
    printf("Enter the Matrix: \n");
    for(int i = 0; i< n; i++){
        for(int j = 0; j < m; j++)
            scanf("%f", &mat[i][j]);
    }
}

void Print_2D_Array(int n, int m, float** mat){

    for(int i = 0; i< n; i++){
        for(int j = 0; j < m; j++)
            printf("%.3f ", mat[i][j]);
        printf("\n");
    }
}

void Free_2D_Array(int n, int m, float** mat){
    for(int i = 0; i< n; i++)
        free(mat[i]);
}

float** Multiply(int n, int m, int a, int b, float** mat1, float** mat2){
    if(m != a){
       printf("Can't be multiplied, Try different Matrices!!\n");
       return NULL;
    }

    float** ans = (float**)malloc(n * sizeof(float));
    Allocate_2D_Array(n, b, ans);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < b; j++){
            ans[i][j] = 0;
            for(int k = 0; k < a; k++){
                ans[i][j] += mat1[i][k] * mat2[k][j];
            }
            //printf("%.3f ",ans[i][j]);
        }
        //printf("\n");
    }
    return ans;
}

float trace(int n, int m, float **mat){
    float t = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            if(i == j)
                t += mat[i][j];
    }
    return t;
}

int main(){
    int n, m, a, b;
    printf("Enter size n and m: ");
    scanf("%d %d", &n,&m);
    float **mat1 = (float**)malloc(n * sizeof(float));
    Allocate_2D_Array(n, m, mat1);
    Read_2D_Array(n, m, mat1);
    //Print_2D_Array(n, m, mat1);
    printf("Enter size a and b: ");
    scanf("%d %d", &a,&b);
    float **mat2 = (float**)malloc(n * sizeof(float));
    Allocate_2D_Array(a, b, mat2);
    Read_2D_Array(a, b, mat2);
    float **ans = (float**)malloc(n * sizeof(float));
    Allocate_2D_Array(n, b, ans);
    ans = Multiply(n, m, a, b, mat1, mat2);
    printf("Matrix 1:\n");
    Print_2D_Array(n, m, mat1);
    printf("Matrix 2:\n");
    Print_2D_Array(a, b, mat2);
    printf("Matrix 3(M1 X M2):\n");
    Print_2D_Array(n, b, ans);
    printf("Trace of Matrix 1: %f\n", trace(n, m, mat1));
    printf("Trace of Matrix 2: %f\n", trace(a, b, mat2));
    printf("Trace of Matrix 3: %f\n", trace(n, b, ans));
    Free_2D_Array(n, m, mat1);
    Free_2D_Array(a, b, mat2);
    Free_2D_Array(n, b, ans);


    return 0;
}
