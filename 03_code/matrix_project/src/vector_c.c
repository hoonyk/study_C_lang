#include "vector_c.h"

int vector_print(const Double *matrix, const Matrix *m)
{
    for (int i = 0; i < m->row + m->col; i++)
    {
        printf("%3d", *(matrix + i));
        if (i % m->col == 1)
        {
            printf("\n");
        }
    }
}

int vector_add(Double *matrix3, Double *matrix2, Double *matrix1, const Matrix *m)
{
    for (int i =0; i<m->row;i++)
    {
        for(int j=0;i<m->col;i++)
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
            *(matrix3+(i*m1->col)+j) = temp;
            temp = 0;
        }
    }
    return 0;

}

int vector_emultiply(Double *matrix3, Double *matrix2, Double *matrix1, const Matrix *m)
{
    for (int i =0; i<m->row;i++)
    {
        for(int j=0;i<m->col;i++)
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
        for(int j=0;i<m1->col;i++)
        {
            *(matrix3+(j*m1->row)+i) = *(matrix1+(i*m1->col)+j);
        }
    }
    return 0;    
}