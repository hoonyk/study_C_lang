#ifndef __VECTOR_C_H__
#define __VECTOR_C_H__

#include "type_c.h"

int vector_print(const Double *matrix, const Matrix *m);
int vector_add(Double *matrix3, Double *matrix2, Double *matrix1, const Matrix *m);
int vector_multiply(Double *matrix3, Double *matrix2, Double *matrix1, const Matrix *m1,const Matrix *m2);
int vector_emultiply(Double *matrix3, Double *matrix2, Double *matrix1, const Matrix *m);
int vector_transpose(Double *matrix3, Double *matrix1, const Matrix* m1);
Double vector_innerProduct(Double *matrix1, Double *matrix2, const Matrix *m1,const Matrix *m2);

#endif