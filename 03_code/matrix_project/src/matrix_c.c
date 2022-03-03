#include "matrix_c.h"

int matrix_calloc(Double ***matrix, const Matrix* m)
{
    matrix[0] = (int **)malloc(sizeof(int *) * m->row);
    for (int i = 0; i < m->row; i++)
    {
        matrix[0][i] = (int *)calloc(m->col, sizeof(int));
    }
    return 0;
}

int matrix_print(Double ***matrix, const Matrix* m)
{
    for (int i = 0; i < m->row; i++)
    {
        for (int j = 0; j < m->col; j++)
        {
            printf("%3d", matrix[0][i][j]);
        }
        printf("\n");
    }
    printf("matrix : %p : \n", matrix);
    return 0;
}

int matrix_printf(Double **matrix, const Matrix* m)
{
    for (int i = 0; i < m->row; i++)
    {
        for (int j = 0; j < m->col; j++)
        {
            printf("%3d", matrix[i][j]);
        }
        printf("\n");
    }
    printf("matrix : %p : \n", matrix);
    return 0;
}

int matrix_multiply(Double **matrix3, Double **matrix1, Double **matrix2, const Matrix* m1, const Matrix* m2)
{
    if(m1->col!=m2->row)
    {
        printf("The matrices are the incorect size. m1 col is %d, m2 row is %d\n",m1->col,m2->row);
        return 1;
    }
    int temp = 0;
    for (int i = 0; i < m1->row; i++)
    {
        for (int j = 0; j < m2->col; j++)
        {
            for (int k = 0; k < m1->col; k++)
            {
                temp += matrix1[i][k] * matrix2[k][j];
            }
            matrix3[i][j] = temp;
            temp = 0;
        }
    }
    return 0;
}

int matrix_emultiply(Double **matrix3, Double **matrix1, Double **matrix2, const Matrix* m1, const Matrix* m2)
{
    if(m1->row!=m2->row || m1->col!=m2->col)
    {
        printf("The matrices are not the same size.");
        return 0;
    }
    for (int i = 0; i < m1->row; i++)
    {
        for (int j = 0; j < m1->col; j++)
        {
            matrix3[i][j] = matrix1[i][j] * matrix2[i][j];
        }
    }
    return 0;
}

int matrix_add(Double **matrix3, Double **matrix1, int **matrix2, const Matrix* m1, const Matrix* m2)
{
    if(m1->row!=m2->row || m1->col!=m2->col)
    {
        printf("The matrices are not the same size.");
        return 0;
    }
    for (int i = 0; i < m1->row; i++)
    {
        for (int j = 0; j < m1->col; j++)
        {
            matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

int matrix_inverse(Double **matrix3, Double **matrix1, const Matrix* m1)
{
    return 0;
}

int matrix_einverse(Double **matrix3, Double **matrix1, const Matrix* m1)
{
    return 0;
}

int matrix_pseudoinv(Double **matrix3, Double **matrix1, const Matrix* m1)
{
    return 0;
}

int matrix_free(Double ***matrix, Int row)
{
    for (int i = 0; i < row; i++)
    {
        free(matrix[0][i]);
    }
    free(matrix[0]);
}

int matrix_free2(Double **matrix, Int row)
{
    for (int i = 0; i < row; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

int matrix_transpose(Double **matrix3, Double **matrix1, const Matrix* m1)
{
    for (int i = 0; i < m1->row; i++)
    {
        for (int j = 0; j < m1->col; j++)
        {
            matrix3[j][i] = matrix1[i][j];
        }
    }
    return 0;
}