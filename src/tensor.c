#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int* data;
	int shape[3]; // restricted to 3D tensor at the moment
	int dim;
}
Tensor;


void tensor_init(Tensor* t, int* data, int* shape, int dim)
/* takes a tensor pointer and initializes it with the given data, shape and dimension */
{
    t->data = data;
    for (int i = 0; i < dim; i++)
    {
	t->shape[i] = shape[i];
    }
    t->dim = dim;
}

Tensor* tensor_create(int* data, int* shape, int dim)
/* creates a tensor and returns a pointer to it */
{
    Tensor* t = (Tensor*)malloc(sizeof(Tensor));
    tensor_init(t, data, shape, dim);
    return t;
}


int main(){
	int* data_ptr = malloc(9*sizeof(int));
	int* shape_ptr = malloc(3*sizeof(int));
	int dim = 2;

	shape_ptr[0] = 3;
	shape_ptr[1] = 3;

	int i;
	Tensor* tensor_ptr = tensor_create(data_ptr, shape_ptr, dim);
	int total_elements = tensor_ptr->shape[0]*tensor_ptr->shape[1];

	for (i = 0; i<total_elements; i++){
		tensor_ptr->data[i] = i;
	}


	printf("%s", "Tensor data: ");
	i = 0;
	for (i = 0; i<total_elements; i++){
		printf("%d ", tensor_ptr->data[i]);
	}

	printf("\n");
	printf("%s\n", "Tensor shape: ");
	printf("%d\n", tensor_ptr->shape[0]);
	printf("%d\n", tensor_ptr->shape[1]);

	return 0;
}
