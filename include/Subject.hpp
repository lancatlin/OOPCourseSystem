#ifndef SUBJECT_HPP
#define SUBJECT_HPP
#include <set>
#include <string>
#include <vector>

class Subject {
private:
  std::set<int> time;
  std::string name;
  std::string type;

public:
  Subject(std::string name, std::set<int> time, std::string type)
      : time(time), name(name), type(type){};
  std::set<int> GetTime() const { return time; };
  std::string GetName() const { return name; };
  std::string GetType() { return type; }
};
#endif