#ifndef MY_SOLVER_H
#define MY_SOLVER_H

#include "myMatrix.h"

double nrm(const Vector&);
extern bool jacobi(const dnMatrix&, const Vector&);

#endif
