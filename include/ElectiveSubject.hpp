#ifndef OOP_ELECTIVESUBJECT_HPP
#define OOP_ELECTIVESUBJECT_HPP

#include <string>

#include "Subject.hpp"

class ElectiveSubject : public Subject {
private:
    std::string type = "Elective Subject";
public:
    ElectiveSubject(std::string name, std::set<int> time) : Subject(name, time) {}
    std::string GetType() {
        return type;
    }


};

#endif // OOP_ELECTIVESUBJECT_HPP
