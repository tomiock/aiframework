#ifndef OPS_TENSOR_H_   /* Include guard */
#define OPS_TENSOR_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "tensor.h"

void xSCAL(Tensor* A, float alpha);

void xSWAP (Tensor *tensor1, Tensor *tensor2);

Tensor * xCOPY (Tensor *tensor1);

float xDOT (Tensor *tensor1, Tensor *tensor2);

#ifdef __cplusplus
}
#endif

#endif // OPS_TENSOR_H_
