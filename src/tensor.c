#include <stdio.h>
#include <stdlib.h>
#include "tensor.h"


Tensor* tensor_create(char dim, unsigned short shape[], float data[])
{
	char type = 0;

	Tensor* t = (Tensor*)malloc(sizeof(Tensor));
	unsigned short stride = sizeof(float)*shape[0];

	if(t == NULL){
		return NULL;
	}
	// fill in the struct
	t->dim = dim;
	t->shape = shape;
	t->stride = stride;
	t->type = type;
	t->data = data;

	// fill in the struct
	return t;
}
