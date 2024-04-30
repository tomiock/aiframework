#include "../src/ops_tensor.h"
#include "../src/tensor.h"
#include "gtest/gtest.h"

using testing::Test;

int test(int a, int b) { return a + b; }

TEST(TestXDOT, OutputUnitaryVector) {
  unsigned short shape[] = {4, 1};
  float data[] = {1, 0, 0, 0};
  Tensor *t = tensor_create(2, shape, data);
  EXPECT_EQ(xDOT(t, t), 1.0);
}

TEST(TestXDOT, OutputOrtogonalVectors) {
  unsigned short shape[] = {4, 1};
  float data1[] = {1, 0, 0, 0};
  float data2[] = {0, 0, 1, 0};
  Tensor *t1 = tensor_create(2, shape, data1);
  Tensor *t2 = tensor_create(2, shape, data2);
  EXPECT_EQ(xDOT(t1, t2), 0.0);
}
