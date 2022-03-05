#ifndef __TYPE_C_H__
#define __TYPE_C_h__

#ifndef _TYPE_INT
typedef short Int;
#else
typedef int Int;
// typedef long Int;
#endif

#ifndef _TYPE_DOUBLE
typedef float Double;
#else
typedef double Double;
#endif

typedef struct _matrix
{
    Int row;
    Int col;
} Matrix;

#endif