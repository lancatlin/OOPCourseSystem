#ifndef scoresystem_hpp
#define scoresystem_hpp

#include "Subject.hpp"
#include <memory>
#include <algorithm>
#include <set>
#include <string>
#include <vector>

class ScoreSystem {
private:
    std::set<int> EmptyCourses;//剩餘空堂的集合
    std::vector<std::shared_ptr<Subject>> Courses;//已加入的課程

public:
    ScoreSystem();

    void AddCourse(const std::shared_ptr<Subject>& NewCourse);

    std::set<int> getEmptyCourses() const;

    std::vector<std::shared_ptr<Subject>> getCourses() const;

    void Print();

    ~ScoreSystem();
};

#endif