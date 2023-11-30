#ifndef SUBJECT_HPP
#define SUBJECT_HPP
#include <string>
#include <vector>
#include <set>

class Subject {
private:
    std::set<int> time;
    std::string name;

public:
    Subject(std::string name, std::set<int> time): time(time),name(name){};
    std::set<int> GetTime() const { return time; };
    std::string GetName() const { return name; };
};
#endif