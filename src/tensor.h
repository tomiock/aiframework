#include <stdio.h>
#include <cblas.h>
#include <stdlib.h>

typedef struct {
	char dim;
	unsigned short shape; // restricted to 3D tensor at the moment
	unsigned short stride;
	char type;
	float* data;
} Tensor;


Tensor* tensor_create(char dim, unsigned short shape[], float data[])
/* creates the variables of the tensor and calls tensor_alloc to initialize the tensor
 calculates the necessary size of the chunks based on the input parameters */
{
	char type = 0;

	Tensor* t = (Tensor*)malloc(sizeof(Tensor));
	unsigned short stride = sizeof(float)*shape[0];

	if(t == NULL){
		return NULL;
	}

	t->dim = dim;
	t->shape = *shape;
	t->stride = stride;
	t->type = type;
	t->data = data;

	// fill in the struct
	return t;
}

