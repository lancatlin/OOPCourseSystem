#ifndef OOP_REQUIREDSUBJECT_HPP
#define OOP_REQUIREDSUBJECT_HPP
#include <string>

#include "Subject.hpp"

class RequiredSubject : public Subject {
private:
    std::string type = "Required Subject";
public:
    RequiredSubject(std::string name, std::set<int> time) : Subject(name, time) {}
    std::string GetType()  {
        return type;
    }

};

#endif // OOP_REQUIREDSUBJECT_HPP
