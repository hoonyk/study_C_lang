#include "type_c.h"

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