#include <cblas.h>
#include <iostream>
#include <vector>
#include <assert.h>

void my_sgemv(const enum CBLAS_ORDER order,
	   const enum CBLAS_TRANSPOSE TransA,
	   const int M,
	   const int N,
	   const float alpha, 
	   const float *A,
	   const int lda,
	   const float *X,
	   const int incX, 
	   const float beta,
	   float *Y,
	   const int incY) {
	
	if (TransA == CblasNoTrans){
		int num_rows = M;
		int num_cols = N;
		
		for (int r=0; r<num_cols; ++r) {
			float row_sum = 0;

			for (int c=0; c<num_cols; ++c) {
				if (order == CblasRowMajor){
					float value = A[r * lda + c];
					row_sum += value * X[c * incX];
				} else {
					float value = A[r + c * lda];
					row_sum += value * X[c * incX];
				}
			}
			*Y = alpha * row_sum + beta * (*Y);

			Y += incY;
		}
	} else {
		int num_rows = N;
		int num_cols = M;
		
		for (int r=0; r<num_rows; ++r) {
			float row_sum = 0;

			for (int c=0; c<num_cols; ++c) {
				float value;
				if (order == CblasRowMajor) {
					value = A[c * lda +r];
				} else {
					value = A[c + r * lda];
				}
				row_sum += value * X[c * incX];
			}
			*Y = alpha * row_sum + beta * (*Y);

			Y += incY;
		}
	}
}

int main () {

std::vector<float> m{1, 2, -1, 0, 1, 0, 1, 0};
std::vector<float> v{1, 2, -1};
std::vector<float> y1{10, 20};
std::vector<float> y2 = y1;

cblas_sgemv(CblasColMajor, // order
	    CblasTrans,    // trans
	    3,          // m, number of rows
	    2,          // n, numner of columns
	    5,          // alpha
	    m.data(),   // matrix A
	    4, 		// lda, column major, so lda is 8, i.e. number of rows + padding=3+1=4
	    v.data(), 	// vector x
	    1, 		// incx
	    4, 		// beta 
	    y1.data(), 	// y
	    1);		// incy

my_sgemv(CblasColMajor, // order
	    CblasTrans, // trans
	    3,          // m, number of rows
	    2,          // n, numner of columns
	    5,          // alpha
	    m.data(),   // matrix A
	    4, 		// lda, column major, so lda is 8, i.e. number of rows + padding=3+1=4
	    v.data(), 	// vector x
	    1, 		// incx
	    4, 		// beta 
	    y2.data(), 	// y
	    1);		// incy
	
	assert(y1 == y2);

	std::cout << y2.data()[0] << std::endl;

	return 0;
}
