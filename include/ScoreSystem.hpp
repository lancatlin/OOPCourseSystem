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
  std::set<int> emptyCourses;                    // 剩餘空堂的集合
  std::set<int> courseHours;                     // 剩餘空堂的集合
  std::vector<std::shared_ptr<Subject>> courses; // 已加入的課程

public:
  ScoreSystem();

  void AddCourse(std::shared_ptr<Subject> NewCourse);

  std::set<int> GetEmptyCourses() const;

  int GetSize() const { return courses.size(); };

  std::vector<std::shared_ptr<Subject>> GetCourses() const;

  std::unordered_map<std::string, int> CalculateCredits() const;

  void Print();

  ~ScoreSystem();
};

#endif