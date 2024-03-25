#include <stdlib.h>
#include "tensor.h"

Tensor* xSCAL(Tensor* t, float alpha) {
	Tensor *result = (Tensor*)malloc(sizeof(Tensor));

	if (result == NULL){
		return NULL;
	}

	result->dim = t->dim;
	result->shape = t->shape;
	result->stride = t->stride;
	result->type = t->type;
	result->data = (float*)malloc(sizeof(t->data));

	for (int j = 0; j < t->dim; j++){
		for (int i = 0; i < t->shape*t->shape; i++){
			result->data[i] = alpha*t->data[i];
		}
	}

	return result;
}	
