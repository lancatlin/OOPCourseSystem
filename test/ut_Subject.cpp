#include "Subject.hpp"
#include <gtest/gtest.h>
TEST(Subject, InitSubjectSuccess) {
    Subject sub1("TestCourse", {12, 23, 45});
    ASSERT_EQ(sub1.GetTime(), std::set({12, 23, 45}));
    ASSERT_EQ(sub1.GetName(), "TestCourse");
}