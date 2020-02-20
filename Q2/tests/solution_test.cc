#include "src/lib/solution.h"
#include "gtest/gtest.h"
#include <vector>

TEST(Test1, HandlesTest1) {
  std::vector<int> v = {7, 1, 6, 3, 5, 2, 8, 4, 9, 10};
  BST bst(v);
  testing::internal::CaptureStdout();
  bst.print();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "1 2 3 4 5 6 7 8 9 10 \n1 2 3 4 5 6 7 8 9 10 \n");
}

