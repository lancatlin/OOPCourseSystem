#include "ElectiveSubject.hpp"
#include "RequiredSubject.hpp"
#include "ScoreSystem.hpp"
#include "Subject.hpp"
#include <gtest/gtest.h>
#include <memory>
#include <set>
#include <stdexcept>
#include <string>
#include <unordered_map>

TEST(ScoreSystem, InitScoreSystemSuccess) {
  ScoreSystem scoreSystem;
  std::shared_ptr<Subject> s1 = std::make_shared<RequiredSubject>(
      "Object Oriented Programming", std::set({15, 20, 31}));
  scoreSystem.AddCourse(s1);
  ASSERT_EQ(scoreSystem.GetCourses(),
            std::vector<std::shared_ptr<Subject>>{s1});
}

TEST(ScoreSystem, InitScoreSystemConflict) {
  ScoreSystem scoreSystem;
  scoreSystem.AddCourse(std::make_shared<RequiredSubject>(
      "Object Oriented Programming", std::set({15, 20, 31})));
  ASSERT_THROW(scoreSystem.AddCourse(std::make_shared<RequiredSubject>(
      "Linear Algebra", std::set({15, 16, 17})));
               , std::invalid_argument);

  ASSERT_EQ(scoreSystem.GetSize(), 1);
}

TEST(ScoreSystem, CalculateCredits) {
  ScoreSystem scoreSystem;
  scoreSystem.AddCourse(std::make_shared<RequiredSubject>(
      "Object Oriented Programming", std::set({15, 20, 31})));
  scoreSystem.AddCourse(
      std::make_shared<ElectiveSubject>("Linear Algebra", std::set({1, 2})));

  std::unordered_map<std::string, int> credits = scoreSystem.CalculateCredits();
  ASSERT_EQ(credits["Required"], 3);
  ASSERT_EQ(credits["Elective"], 2);
}
