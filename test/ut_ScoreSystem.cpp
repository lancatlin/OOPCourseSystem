#include "ElectiveSubject.hpp"
#include "RequiredSubject.hpp"
#include "ScoreSystem.hpp"
#include "Subject.hpp"
#include <gtest/gtest.h>
#include <memory>
#include <set>

TEST(ScoreSystem, InitScoreSystemSuccess) {
  ScoreSystem scoreSystem;
  std::shared_ptr<Subject> s1 = std::make_shared<RequiredSubject>(
      "Object Oriented Programming", std::set({15, 20, 31}));
  scoreSystem.AddCourse(s1);
  ASSERT_EQ(scoreSystem.getCourses(),
            std::vector<std::shared_ptr<Subject>>{s1});
}