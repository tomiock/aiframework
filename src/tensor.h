#ifndef TENSOR_H
#define TENSOR_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	char dim;
	unsigned short* shape; // restricted to 3D tensor at the moment
	unsigned short stride;
	char type;
	float* data;
} Tensor;


Tensor * tensor_create(char dim, unsigned short shape[], float data[]);

#ifdef __cplusplus
}
#endif

#endif // TENSOR_H
