#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char dim;
	unsigned short shape; // restricted to 3D tensor at the moment
	unsigned short stride;
	char type;
	float data;
}
Tensor;


void tensor_alloc(Tensor* t, char* dim, unsigned short* shape, unsigned short* stride, char *type, float data[])
/* initializes the tensor with the given data, shape and dim 
 does the memory allocation of the whole tensor */
{
}

Tensor* tensor_create(char dim, unsigned short shape[], float data[])
/* creates the variables of the tensor and calls tensor_alloc to initialize the tensor
 calculates the necessary size of the chunks based on the input parameters */
{
	char type = 0;

	Tensor* t = (Tensor*)malloc(sizeof(Tensor));
	unsigned short stride = sizeof(float)*shape[0];
	unsigned short size_data;
	unsigned short num_elements;
	
	char i;
	while (i<dim){
		num_elements*=shape[i];
	}

	size_data = sizeof(float)*num_elements;


	// allocation of the necessary memory
	tensor_alloc(t, &dim, shape, &stride, &type, data);
	// shape and data are passed normally bc it is an array
    
	// fill in the struct
	return t;
}


int main(){
	float data[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
	unsigned short shape[3] = {3, 3};
	char dim = 2;

	Tensor* tensor_ptr = tensor_create(dim, shape, data);

	char tensor_d = tensor_ptr->dim;
	unsigned short tensor_shape = tensor_ptr->shape;
	unsigned short tensor_stride = tensor_ptr->stride;
	char tensor_type = tensor_ptr->type;
	float tensor_data = tensor_ptr->data;

	unsigned short total_elements = tensor_shape*tensor_shape;

	printf("%s", "Tensor dim: ");
	printf("%d\n", tensor_d);

	return 0;
}
