#include <stdio.h>
#include <stdlib.h>
#include "tensor.h"


/* creates the variables of the tensor and calls tensor_alloc to initialize the tensor
 calculates the necessary size of the chunks based on the input parameters */
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
	t->shape = *shape;
	t->stride = stride;
	t->type = type;
	t->data = data;

	return t;
}

