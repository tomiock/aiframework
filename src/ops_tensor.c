#include <stdlib.h>
#include "tensor.h"
#include "ops_tensor.h"
#include <assert.h>

// scal multiplication
// x <- alpha*x
void xSCAL(Tensor* A, float alpha) {
	for (int j = 0; j < A->dim; j++){
		for (int i = 0; i < A->shape*A->shape; i++){
			A->data[i] = alpha*A->data[i];
		}
	}
}	

// swap of two tensors
// x <-> y
void xSWAP (Tensor *tensor1, Tensor *tensor2) {
	Tensor * tmp;

	tmp = tensor1;
	tensor1 = tensor2;
	tensor2 = tmp;
}

// copy of a tensor with newly created one
// needs to be freed after use
// y <- x
Tensor* xCOPY (Tensor *tensor) {
	Tensor *result = (Tensor*)malloc(sizeof(Tensor));

	if (result == NULL){
		return NULL;
	}

	result->dim = tensor->dim;
	result->shape = tensor->shape;
	result->stride = tensor->stride;
	result->type = tensor->type;
	result->data = (float*)malloc(sizeof(tensor->data));

	for (int j = 0; j < tensor->dim; j++){
		for (int i = 0; i < tensor->shape*tensor->shape; i++){
			result->data[i] = tensor->data[i];
		}
	}

	return result;
}

// dot product of two tensors
// dot <- x^T y
float xDOT (Tensor *tensor1, Tensor *tensor2) {
	float result = 0;

	// check if the tensors are compatible (same shape and dim)
	assert (tensor1->dim == tensor2->dim);
	assert (tensor1->shape == tensor2->shape);

	for (int i = 0; i < tensor1->shape*tensor1->shape; i++){
		result += tensor1->data[i]*tensor2->data[i];
	}

	return result;
}
