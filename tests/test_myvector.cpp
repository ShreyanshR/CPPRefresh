#include <gtest/gtest.h>
#include "MyVector.h"

TEST(MyVectorTest, PushBackIncreaseSize) {
	MyVector<int> v;
	v.push_back(1);
	v.push_back(2);
	EXPECT_EQ(v.vsize(), 2);
}