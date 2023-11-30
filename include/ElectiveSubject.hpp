#ifndef OOP_ELECTIVESUBJECT_HPP
#define OOP_ELECTIVESUBJECT_HPP

#include <string>

#include "Subject.hpp"

class ElectiveSubject : public Subject {
private:
public:
  ElectiveSubject(std::string name, std::set<int> time)
      : Subject(name, time, "Elective Subject") {}
};

#endif // OOP_ELECTIVESUBJECT_HPP
