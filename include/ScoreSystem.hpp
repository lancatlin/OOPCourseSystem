#ifndef scoresystem_hpp
#define scoresystem_hpp

#include "Subject.hpp"
#include <algorithm>
#include <memory>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

class ScoreSystem {
private:
  std::set<int> courseHours;
  std::vector<std::shared_ptr<Subject>> courses;

public:
  ScoreSystem();

  void AddCourse(std::shared_ptr<Subject> NewCourse);

  int GetSize() const { return courses.size(); };

  std::vector<std::shared_ptr<Subject>> GetCourses() const;

  std::unordered_map<std::string, int> CalculateCredits() const;

  void Print();

  ~ScoreSystem();
};

#endif