#include "ScoreSystem.hpp"
#include <iostream>
#include <set>
#include <stdexcept>

#define MaxTime 45

std::set<int> setinter(std::set<int> a, std::set<int> b) { // 交集
  std::set<int> r;
  std::set_intersection(a.begin(), a.end(), b.begin(), b.end(),
                        std::inserter(r, r.begin()));
  return r;
}

std::set<int> setdiff(std::set<int> a, std::set<int> b) { // 差集
  std::set<int> r;
  std::set_difference(a.begin(), a.end(), b.begin(), b.end(),
                      std::inserter(r, r.begin()));
  return r;
}

bool issubset(std::set<int> parent,
              std::set<int> child) { // child是否為parent的子集合
  if (setdiff(child, parent).empty())
    return true;
  else
    return false;
}

void outputSet(std::set<int> s) { // 輸出集合元素
  for (std::set<int>::iterator iter = s.begin(); iter != s.end(); iter++)
    printf("%d ", *iter);
  printf("\n");
}

ScoreSystem::ScoreSystem() {
  for (int i = 1; i <= MaxTime; i++)
    this->emptyCourses.insert(i);
};

void ScoreSystem::AddCourse(std::shared_ptr<Subject> course) {
  std::set<int> time = course->GetTime();
  std::set<int> inter = setinter(courseHours, time);
  if (!inter.empty()) {
    throw std::invalid_argument("Course time conflicts");
  }
  courses.push_back(course);
  courseHours.insert(time.begin(), time.end());
};

std::set<int> ScoreSystem::GetEmptyCourses() const {
  return this->emptyCourses;
};

std::vector<std::shared_ptr<Subject>> ScoreSystem::GetCourses() const {
  return this->courses;
};

void ScoreSystem::Print(){};

ScoreSystem::~ScoreSystem(){};

// int main() { return 0; }