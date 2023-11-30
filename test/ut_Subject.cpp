#include "RequiredSubject.hpp"
#include "Subject.hpp"
#include <gtest/gtest.h>
#include <memory>
#include <set>

TEST(Subject, InitRequiredSubjectSuccess) {
  RequiredSubject s("TestCourse", {1, 2, 3});
  // std::shared_ptr<Subject> sub1 =
  // std::make_shared<RequiredSubject>("TestCourse", {12, 23, 45});
  ASSERT_EQ(s.GetTime(), std::set({1, 2, 3}));
  ASSERT_EQ(s.GetName(), "TestCourse");
}

TEST(Subject, InitRequiredSubjectAsSubject) {
  std::shared_ptr<Subject> s =
      std::make_shared<RequiredSubject>("TestCourse", std::set({1, 2, 3}));

  // This doesn't work:
  // std::shared_ptr<Subject> s =
  //     std::make_shared<RequiredSubject>("TestCourse", {1, 2, 3});
  ASSERT_EQ(s->GetTime(), std::set({1, 2, 3}));
  ASSERT_EQ(s->GetName(), "TestCourse");
}