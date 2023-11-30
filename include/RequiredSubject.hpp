#ifndef OOP_REQUIREDSUBJECT_HPP
#define OOP_REQUIREDSUBJECT_HPP
#include <string>

#include "Subject.hpp"

class RequiredSubject : public Subject {
private:
public:
  RequiredSubject(std::string name, std::set<int> time)
      : Subject(name, time, "Required Subject") {}
};

#endif // OOP_REQUIREDSUBJECT_HPP
