#include "../include/ScoreSystem.hpp"

#define MaxTime 45

/*std::set<int> setinter(std::set<int> a, std::set<int> b) {//交集
    std::set<int> r;
    std::set_intersection(a.begin(), a.end(), b.begin(), b.end(),
        std::inserter(r, r.begin()));
    return r;
}*/

/*std::set<int> setunion(std::set<int> a, std::set<int> b) {//聯集
    std::set<int> r;
    std::set_union(a.begin(), a.end(), b.begin(), b.end(),
        std::inserter(r, r.begin()));
    return r;
}*/

std::set<int> setdiff(std::set<int> a, std::set<int> b) {//差集
    std::set<int> r;
    std::set_difference(a.begin(), a.end(), b.begin(), b.end(), std::inserter(r, r.begin()));
    return r;
}

bool issubset(std::set<int> parent, std::set<int> child) {//child是否為parent的子集合
    if (setdiff(child, parent).empty())
        return true;
    else
        return false;
}

void outputSet(std::set<int> s) {//輸出集合元素
    for (std::set<int>::iterator iter = s.begin(); iter != s.end(); iter++)
        printf("%d ", *iter);
    printf("\n");
}

ScoreSystem::ScoreSystem() {
    for (int i = 1; i <= MaxTime; i++)
        this->EmptyCourses.insert(i);
};

void ScoreSystem::AddCourse(const std::shared_ptr<Subject>& NewCourse) {
    if (issubset(EmptyCourses, NewCourse->GetTime())) {//加入的課程的時間是否為空堂的子集合，是代表沒有衝堂
        Courses.push_back(NewCourse);//加入課程
        EmptyCourses = setdiff(EmptyCourses, NewCourse->GetTime());//把課程的時間從空堂中移除(差集)
        printf("\"%s\" added successfully !\n", NewCourse->GetName().c_str());
    }
    else {
        printf("Can't add \"%s\" ! Course clash with:\n", NewCourse->GetName().c_str());
        outputSet(setdiff(NewCourse->GetTime(), EmptyCourses));
    }
};

std::set<int> ScoreSystem::getEmptyCourses() const {
    return this->EmptyCourses;
};

std::vector<std::shared_ptr<Subject>> ScoreSystem::getCourses() const {
    return this->Courses;
};

void ScoreSystem::Print() {};

ScoreSystem::~ScoreSystem() {};

//int main() { return 0; }