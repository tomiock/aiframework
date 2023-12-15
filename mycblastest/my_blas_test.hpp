#include <cblas.h>


namespace tomi {

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

} // namespace tomi 
