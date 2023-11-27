#ifndef SUBJECT_HPP
#define SUBJECT_HPP
#include <string>
#include <vector>

class Subject {
private:
    std::vector<int> time;
    std::string name;

public:
    Subject(std::string name, std::vector<int> time)
        : time(time),
          name(name){};
    std::vector<int> GetTime() const { return time; };
    std::string GetName() const { return name; };
};
#endif