#include "ops_tensor.h"
#include "tensor.h"
#include <assert.h>
#include <stdlib.h>

/*
----------------------------------------
Level 0 BLAS
----------------------------------------
*/

// scalar multiplication for any dim tensor
// x <- alpha*X
void xNSCAL(Tensor *A, float alpha) {
  unsigned short shape_tensor = 1;
  for (int i = 0; i < A->dim; i++) {
    shape_tensor *= A->shape[i];
  }

  for (int i = 0; i < shape_tensor; i++) {
    A->data[i] = A->data[i]*alpha;
  }
}

// swap two tensors
// x <-> y
void xSWAP(Tensor *tensor1, Tensor *tensor2) {
  Tensor *tmp;

  tmp = tensor1;
  tensor1 = tensor2;
  tensor2 = tmp;
}

// copy of a tensor with newly created one
// needs to be freed after use
// y <- x
Tensor *xNCOPY(Tensor *tensor) {
  Tensor *result = (Tensor *)malloc(sizeof(Tensor));

  if (result == NULL) {
    return NULL;
  }

  result->dim = tensor->dim;
  result->shape = tensor->shape;
  result->stride = tensor->stride;
  result->type = tensor->type;
  result->data = (float *)malloc(sizeof(tensor->data));

  unsigned short tensor_shape = 1;
  for (int i = 0; i < tensor->dim; i++) {
    tensor_shape *= tensor->shape[i];
  }

  for (int i = 0; i < tensor_shape; i++) {
    result->data[i] = tensor->data[i];
  }

  return result;
}

float xNDOT(Tensor *tensor1, Tensor *tensor2) {
  float result = 0;

  // check if the tensors are compatible (same shape and dim)
  assert(tensor1->dim == tensor2->dim);
  assert(tensor1->shape == tensor2->shape);

  return result;
}

/*
----------------------------------------
Level 1 BLAS
----------------------------------------
*/

// scalar multiplication for any dim tensor
// x <- alpha*x
void xSCAL(Tensor *A, float alpha) {
  unsigned short shape_tensor = A->shape[0]*A->shape[0];
  for (int i = 0; i < shape_tensor; i++) {
    A->data[i] = A->data[i]*alpha;
  }
}


// copy of a tensor with newly created one
// needs to be freed after use
// y <- x
Tensor *xCOPY(Tensor *tensor) {
  Tensor *result = (Tensor *)malloc(sizeof(Tensor));

  if (result == NULL) {
    return NULL;
  }

  result->dim = tensor->dim;
  result->shape = tensor->shape;
  result->stride = tensor->stride;
  result->type = tensor->type;
  result->data = (float *)malloc(sizeof(tensor->data));

  unsigned short tensor_shape = tensor->shape[0] * tensor->shape[0];

  for (int i = 0; i < tensor_shape; i++) {
    result->data[i] = tensor->data[i];
  }

  return result;
}

// dot product of two tensors
// dot <- x^T y
float xDOT(Tensor *tensor1, Tensor *tensor2) {
  float result = 0;

  // check if the tensors are compatible (same shape and dim)
  //assert(tensor1->dim == 1); // only 1D tensors are allowed
  //assert(tensor1->dim == tensor2->dim);
  //assert(tensor1->shape == tensor2->shape);

  for (int i = 0; i < tensor1->shape[0]; i++) {
    result += tensor1->data[i] * tensor2->data[i];
  }

  return result;
}

// sum of two tensors
// y <- x*alpha + y
void xAXPY(Tensor *tensor1, Tensor *tensor2) {
  assert(tensor1->dim == tensor2->dim);
  assert(tensor1->shape == tensor2->shape);
}

/*
----------------------------------------
Level 2 BLAS
----------------------------------------
*/

/*
----------------------------------------
Level 3 BLAS
----------------------------------------
*/
