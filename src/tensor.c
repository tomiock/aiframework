#include <stdio.h>
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


int main(){
	printf("%s", "Hello World\n");
	float data[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
	unsigned short shape[3] = {3, 3};
	char dim = 2;

	Tensor* tensor_ptr = tensor_create(dim, shape, data);

	// check if the tensor is NULL
	if (tensor_ptr == NULL){
		printf("%s", "Tensor is NULL");
		return 1;
	}

	// print the data to make a test
	for (int i = 0; i < 9; i++){
		printf("%f ", data[i]);
	}

	printf("\n");

	char tensor_d = tensor_ptr->dim;
	unsigned short tensor_shape = tensor_ptr->shape;
	unsigned short tensor_stride = tensor_ptr->stride;
	char tensor_type = tensor_ptr->type;
	float *tensor_data = tensor_ptr->data;

	unsigned short total_elements = tensor_shape*tensor_shape;

	printf("%s", "Tensor dim: ");
	printf("%d\n", tensor_d);
	printf("%s", "Tensor shape: ");
	printf("%d\n", tensor_shape);
	printf("%s", "Tensor stride: ");
	printf("%d\n", tensor_stride);
	printf("%s", "Tensor type: ");
	printf("%d\n", tensor_type);

	if (tensor_data == NULL){
		printf("%s", "Tensor data is NULL");
		return 1;
	}

	printf("\n");
	printf("%s", "Tensor data: ");
	for (int i = 0; i < total_elements; i++){
		printf("%f ", tensor_data[i]);
	}

	free(tensor_ptr);

	return 0;
}
