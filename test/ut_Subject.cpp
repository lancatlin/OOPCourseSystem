#include "RequiredSubject.hpp"
#include "Subject.hpp"
#include <gtest/gtest.h>
#include <memory>

TEST(Subject, InitRequiredSubjectSuccess) {
  RequiredSubject s("TestCourse", {1, 2, 3});
  // std::shared_ptr<Subject> sub1 =
  // std::make_shared<RequiredSubject>("TestCourse", {12, 23, 45});
  ASSERT_EQ(s.GetTime(), std::set({1, 2, 3}));
  ASSERT_EQ(s.GetName(), "TestCourse");
}