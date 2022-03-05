#include <stdio.h>
#include <stdlib.h>

// typedef short Int;
typedef int Int;
// typedef long Int;

typedef float Double;
// typedef double Double;
typedef struct _matrix
{
    int row;
    int col;
} Matrix;

/* include int
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
*/

/* vector include
int vector_print(const Double *matrix, const Matrix *m);
int vector_add(Double *matrix3, Double *matrix2, Double *matrix1, const Matrix *m);
int vector_multiply(Double *matrix3, Double *matrix2, Double *matrix1, const Matrix *m1,const Matrix *m2);
int vector_emultiply(Double *matrix3, Double *matrix2, Double *matrix1, const Matrix *m);
int vector_transpose(Double *matrix3, Double *matrix1, const Matrix* m1);
Double vector_innerProduct(Double *matrix1, Double *matrix2, const Matrix *m1,const Matrix *m2);
*/

int matrix_init(Double **matrix,Double* value,const Matrix* m);
int matrix_calloc(Double ***matrix, const Matrix* m);
int matrix_print(Double ***matrix, const Matrix* m);
int matrix_printf(Double **matrix, const Matrix* m);
int matrix_multiply(Double **matrix3, Double **matrix1, Double **matrix2, const Matrix* m1, const Matrix* m2);
int matrix_emultiply(Double **matrix3, Double **matrix1, Double **matrix2, const Matrix* m1, const Matrix* m2);
int matrix_add(Double **matrix3, Double **matrix1, Double **matrix2, const Matrix* m1, const Matrix* m2);
int matrix_inverse(Double **matrix3, Double **matrix1, const Matrix* m1);
int matrix_einverse(Double **matrix3, Double **matrix1, const Matrix* m1);
int matrix_pseudoinv(Double **matrix3, Double **matrix1, const Matrix* m1);
int matrix_free(Double ***matrix, Int row);
int matrix_free2(Double **matrix, Int row);
int matrix_transpose(Double **matrix3, Double **matrix1, const Matrix* m1);

int main()
{
    /* vector library test
    // vector test
    Double vet1[5] = {1.0,2.0,3.0,4.0,5.0};
    Matrix v1 = {1,5};
    Double vet2[5] = {1.0,2.0,3.0,4.0,5.0};
    Matrix v2 = v1;
    Double vet3[5] = {0.0};
    Matrix v3 = v1;
    Double vet4[2] = {0.0};
    Matrix v4 = {1,2};

    // print test
    vector_print(&vet1[0],&v1);

    // add test
    vector_add(&vet3[0],&vet1[0],&vet2[0],&v1);
    vector_print(&vet3[0], &v3);

    // emultiply test
    vector_emultiply(&vet3[0],&vet1[0],&vet2[0],&v1);
    vector_print(&vet3[0], &v3);

    // innerProduct test
    Double inner = 0;
    inner = vector_innerProduct(&vet1[0],&vet2[0],&v1,&v2);
    printf("inner Product = %f\n", inner);

    inner = vector_innerProduct(&vet1[0],&vet4[0],&v1,&v4);
    printf("inner Product = %f\n", inner);

    // matrix test 
    Double mat1[2][3]={1.0,2.0,3.0,4.0,5.0,6.0};
    Matrix m1 = {2,3};
    Double mat2[3][2]={1.0,2.0,3.0,4.0,5.0,6.0};
    Matrix m2 = {3,2};
    Double mat3[3][3]={0.0};
    Matrix m3 = {3,3};
    Double mat4[3][2]={0.0};
    Matrix m4 = {3,2};
    // print
    vector_print(&mat1[0][0],&m1);
    vector_print(&mat2[0][0],&m2);

    // muliply
    vector_multiply(&mat3[0][0],&mat2[0][0],&mat1[0][0],&m2,&m1);
    vector_print(&mat3[0][0],&m3);

    // transpose
    vector_transpose(&mat4[0][0],&mat1[0][0], &m1);
    vector_print(&mat4[0][0],&m4);
    return 0;
    */

    // matrix test
    Double** mat1 = NULL;
    Matrix m1 = {2,3};
    Double** mat2 = NULL;
    Matrix m2 = {3,2};
    Double** mat3 = NULL;
    Matrix m3 ={3,3};

    matrix_calloc(&mat1,&m1);
    matrix_calloc(&mat2,&m2);
    matrix_calloc(&mat3,&m3);

    // matrix init test & print test
    Double a[6] = {1,2,3,4,5,6};
    matrix_init(mat1,&a[0],&m1);
    matrix_print(&mat1,&m1);
    matrix_init(mat2,&a[0],&m2);
    matrix_print(&mat2,&m2);
    
    // multiply test
    matrix_multiply(mat3,mat2,mat1,&m2,&m1);
    matrix_print(&mat3,&m3);

    // emultiply test
    matrix_emultiply(mat1,mat1,mat1,&m1,&m1);
    matrix_print(&mat1,&m1);
    
    // add test
    matrix_add(mat1,mat1,mat1,&m1,&m1);
    matrix_print(&mat1,&m1);

    // matrix transpose
    matrix_transpose(mat2,mat1,&m1);
    matrix_print(&mat2,&m2);

    // matrix einverse test
    matrix_einverse(mat1,mat1,&m1);
    matrix_print(&mat1,&m1);

    // matirx free test
    matrix_free(&mat1,m1.row);
    matrix_free(&mat2,m2.row);
    matrix_free(&mat3,m3.row);

    return 0;
}

/* int test
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
*/

/* vector source
int vector_print(const Double *matrix, const Matrix *m)
{
    for (int i =0; i<m->row;i++)
    {
        for(int j=0;j<m->col;j++)
        {
            printf("%4.3f  ", *(matrix +(i*m->col)+ j));  // #define 3.3f, 3.3lf setting
        }
        printf("\n");
    }
    return 0;
}

int vector_add(Double *matrix3, Double *matrix2, Double *matrix1, const Matrix *m)
{
    for (int i =0; i<m->row;i++)
    {
        for(int j=0;j<m->col;j++)
        {
            *(matrix3+(i*m->col)+j) = *(matrix1+(i*m->col)+j) + *(matrix2+(i*m->col)+j);
        }
    }
    return 0;
}

int vector_multiply(Double *matrix3, Double *matrix2, Double *matrix1, const Matrix *m1,const Matrix *m2)
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
                temp += (*(matrix1+(i*m1->col)+k))*(*(matrix2+(k*m2->col)+j));
            }
            *(matrix3+(i*m1->row)+j) = temp;
            temp = 0;
        }
    }
    return 0;

}

int vector_emultiply(Double *matrix3, Double *matrix2, Double *matrix1, const Matrix *m)
{
    for (int i =0; i<m->row;i++)
    {
        for(int j=0;j<m->col;j++)
        {
            *(matrix3+(i*m->col)+j) = *(matrix1+(i*m->col)+j) * (*(matrix2+(i*m->col)+j));
        }
    }
    return 0;
}

int vector_transpose(Double *matrix3, Double *matrix1, const Matrix* m1)
{
    for (int i =0; i<m1->row;i++)
    {
        for(int j=0;j<m1->col;j++)
        {
            *(matrix3+(j*m1->row)+i) = *(matrix1+(i*m1->col)+j);
        }
    }
    return 0;    
}

Double vector_innerProduct(Double *matrix1, Double *matrix2, const Matrix *m1,const Matrix *m2)
{   
    if(m1->col != m2->col)
    {
        printf("size is incorrect!!\n");
        return -1;
    }

    Double temp =0;
    for(int i=0;i<m1->col;i++)
    {
        temp += matrix1[i]+matrix2[i];
    }
    return temp;
}
*/

int matrix_init(Double **matrix,Double* value,const Matrix* m)
{
    for(int i=0;i<m->row;i++)
    {
        for(int j=0;j<m->col;j++)
        {
            matrix[i][j] = *(value+(i*m->col)+j);
        }
    }
}

int matrix_calloc(Double ***matrix, const Matrix* m)
{
    matrix[0] = (Double **)malloc(sizeof(Double *) * m->row);
    for (int i = 0; i < m->row; i++)
    {
        matrix[0][i] = (Double *)calloc(m->col, sizeof(Double));
    }
    return 0;
}

int matrix_print(Double ***matrix, const Matrix* m)
{
    printf("ans =\n");
    for (int i = 0; i < m->row; i++)
    {
        for (int j = 0; j < m->col; j++)
        {
            printf("%4.3f  ", matrix[0][i][j]);
        }
        printf("\n");
    }
    return 0;
}

int matrix_printf(Double **matrix, const Matrix* m)
{
    for (int i = 0; i < m->row; i++)
    {
        for (int j = 0; j < m->col; j++)
        {
            printf("%4.3f  ", matrix[i][j]);
        }
        printf("\n");
    }
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
        return -1;
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

int matrix_add(Double **matrix3, Double **matrix1, Double **matrix2, const Matrix* m1, const Matrix* m2)
{
    if(m1->row!=m2->row || m1->col!=m2->col)
    {
        printf("The matrices are not the same size.");
        return -1;
    }
    for (int i = 0; i < m1->row; i++)
    {
        for (int j = 0; j < m1->col; j++)
        {
            matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return 0;
}

int matrix_inverse(Double **matrix3, Double **matrix1, const Matrix* m1)
{
    return 0;
}

int matrix_einverse(Double **matrix3, Double **matrix1, const Matrix* m1)
{
    for (int i = 0; i < m1->row; i++)
    {
        for (int j = 0; j < m1->col; j++)
        {
            if (matrix1[i][j]==0)
            {
                matrix3[i][j] = 0;
            }
            else
            {
                matrix3[i][j] = 1/matrix1[i][j];
            }
        }
    }
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