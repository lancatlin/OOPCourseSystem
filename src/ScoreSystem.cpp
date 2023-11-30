#include "ScoreSystem.hpp"
#include "Subject.hpp"
#include <iostream>
#include <memory>
#include <set>
#include <stdexcept>

#define MaxTime 45

std::set<int> setinter(std::set<int> a, std::set<int> b) { // 交集
  std::set<int> r;
  std::set_intersection(a.begin(), a.end(), b.begin(), b.end(),
                        std::inserter(r, r.begin()));
  return r;
}

void ScoreSystem::AddCourse(std::shared_ptr<Subject> course) {
  std::set<int> time = course->GetTime();
  std::set<int> inter = setinter(courseHours, time);
  if (!inter.empty()) {
    throw std::invalid_argument("Course time conflicts");
  }
  courses.push_back(course);
  courseHours.insert(time.begin(), time.end());
};

std::vector<std::shared_ptr<Subject>> ScoreSystem::GetCourses() const {
  return this->courses;
};

std::unordered_map<std::string, int> ScoreSystem::CalculateCredits() const {
  std::unordered_map<std::string, int> credits;
  for (std::shared_ptr<Subject> course : courses) {
    credits[course->GetType()] += course->GetCredits();
  }
  return credits;
};

void ScoreSystem::Print(){};

ScoreSystem::~ScoreSystem(){};
