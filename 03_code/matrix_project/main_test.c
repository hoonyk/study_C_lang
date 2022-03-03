#include <stdio.h>
#include <stdlib.h>

typedef struct _matrix
{
    int row;
    int col;
} Matrix;

int matrix_calloc(int ***matrix, int row, int col);
int matrix_print(int ***matrix, int row, int col);
int matrix_printf(int **matrix, int row, int col);
int matrix_multiply(int **matrix3, int **matrix1, int **matrix2, int m1_row, int m1_col, int m2_col);
int matrix_emultiply(int **matrix3, int **matrix1, int **matrix2, int m1_row, int m1_col);
int matrix_add(int **matrix3, int **matrix1, int **matrix2, int m1_row, int m1_col);
int matrix_inverse(int **matrix3, int **matrix1, int m1_row, int m1_col);
int matrix_einverse(int **matrix3, int **matrix1, int m1_row, int m1_col);
int matrix_pseudoinv(int **matrix3, int **matrix1, int m1_row, int m1_col);
int matrix_free(int ***matrix, int row);
int matrix_free2(int **matrix, int row);
int vector_print(int *matrix, const Matrix *m);

int matrix_test(int* matrix, int row, int col){
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%3d", *(matrix+(i*col)+j));
        }
        printf("\n");
    }
}
int main()
{
    // int **matrix1 = NULL;
    // // int **matrix2 = NULL;
    // // int **matrix3 = NULL;
    // Matrix m1 = {2, 2};
    // Matrix m2 = {2, 2};
    Matrix m3 = {2, 2};
    int a[4] = {0, 1, 2, 3};
    matrix_test(&a[0],m3.row,m3.row);

    // matrix_calloc(&matrix1, m1.row, m2.col);
    // matrix1[0][0] = 0;
    // matrix1[0][1] = 1;
    // matrix1[1][0] = 3;
    // matrix1[1][1] = 4;
    // matrix_printf(matrix1, m1.row, m2.col);
    // printf("matrix1 : %p \n", matrix1);
    // printf("%d \n", matrix1[0][1]);
    // // for(int i=0;i<m1.row;i++)
    // // {
    // //     free(matrix1[i]);
    // // }
    // // free(matrix1);
    // matrix_free2(matrix1, m1.row);
    // printf("%d \n", matrix1[0][1]);
    // vector_print(a, &m1);
}

int matrix_calloc(int ***matrix, int row, int col)
{
    matrix[0] = (int **)malloc(sizeof(int *) * row);
    for (int i = 0; i < row; i++)
    {
        matrix[0][i] = (int *)calloc(col, sizeof(int));
    }
    return 0;
}

int matrix_print(int ***matrix, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%3d", matrix[0][i][j]);
        }
        printf("\n");
    }
    printf("matrix : %p : \n", matrix);
    return 0;
}

int matrix_printf(int **matrix, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%3d", matrix[i][j]);
        }
        printf("\n");
    }
    printf("matrix : %p : \n", matrix);
    return 0;
}

int vector_print(int *matrix, const Matrix *m)
{
    for (int i = 0; i < m->row; i++)
    {
        for (int j = 0; j < m->col; j++)
        {
            printf("%3d", *(matrix+(i*m->col)+j));
        }
        printf("\n");
    }
}

int matrix_multiply(int **matrix3, int **matrix1, int **matrix2, int m1_row, int m1_col, int m2_col)
{
    int temp = 0;
    for (int i = 0; i < m1_row; i++)
    {
        for (int j = 0; j < m2_col; j++)
        {
            for (int k = 0; k < m1_col; k++)
            {
                temp += matrix1[i][k] * matrix2[k][j];
            }
            matrix3[i][j] = temp;
            temp = 0;
        }
    }
    return 0;
}

int vector_multiply(int* output, int *matrix1, int *matrix2, const Matrix *m1, const Matrix *m2)
{
    int temp = 0;
    for (int i = 0; i < m1->row; i++)
    {
        for (int j = 0; j < m2->col; j++)
        {
            for (int k = 0; k < m1->col; k++)
            {
                temp += (*(matrix1+(i*m1->col)+k))*(*(matrix2+(k*m2->col)+j));
            }
            *(output+(i*m1->col)+j) = temp;
            temp = 0;
        }
    }
    return 0;
}

int matrix_emultiply(int **matrix3, int **matrix1, int **matrix2, int m1_row, int m1_col)
{
    for (int i = 0; i < m1_row; i++)
    {
        for (int j = 0; j < m1_col; j++)
        {
            matrix3[i][j] = matrix1[i][j] * matrix2[i][j];
        }
    }
    return 0;
}

int matrix_add(int **matrix3, int **matrix1, int **matrix2, int m1_row, int m1_col)
{
    for (int i = 0; i < m1_row; i++)
    {
        for (int j = 0; j < m1_col; j++)
        {
            matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

int matrix_inverse(int **matrix3, int **matrix1, int m1_row, int m1_col)
{
    return 0;
}

int matrix_einverse(int **matrix3, int **matrix1, int m1_row, int m1_col)
{
    return 0;
}

int matrix_pseudoinv(int **matrix3, int **matrix1, int m1_row, int m1_col)
{
    return 0;
}

int matrix_free(int ***matrix, int row)
{
    for (int i = 0; i < row; i++)
    {
        free(matrix[0][i]);
    }
    free(matrix[0]);
}

int matrix_free2(int **matrix, int row)
{
    for (int i = 0; i < row; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}