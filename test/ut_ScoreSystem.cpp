#include "ScoreSystem.hpp"
#include "ElectiveSubject.hpp"
#include "RequiredSubject.hpp"
#include <gtest/gtest.h>

TEST(ScroeSysyem, InitScroeSysyemSuccess) {
    ScoreSystem scoreSystem;
    scoreSystem.AddCourse(std::shared_ptr<Subject>(new RequiredSubject("Object Oriented Programming", {15, 20, 31})));
//    scoreSystem.AddCourse(std::shared_ptr<Subject>(new RequiredSubject("Data Structure", {11, 16, 32})));
//    scoreSystem.AddCourse(std::shared_ptr<Subject>(new ElectiveSubject("Network Programming", {23, 28, 33})));
    ASSERT_EQ(scoreSystem.getCourses(),std::vector<Subject>{"Object Oriented Programming", {15, 20, 31}});
}