#include <cblas.h>
#include <iostream>
#include <vector>
#include <cassert>

#include "my_blas_test.hpp"


void test_sgemv () {

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

tomi::my_sgemv(CblasColMajor, // order
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
	std::cout << "cblas_segemv OK" << std::endl;
}


int main() {
	test_sgemv();
	return 0;
}
