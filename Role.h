//
// Created by stanb on 29.03.2025.
//
#include <iostream>
#include <string>
#ifndef OOP_ROLE_H
#define OOP_ROLE_H


class Role {
private:
    //this is a description of what a pony role usually consists of, not just the name of the role
    std::string name;
public:
    Role(): name("farmer") {}
    Role(const std::string& name_): name(name_) {}
    Role(Role &other): name(other.name) {}
    Role& operator= (Role &other)
    {
        this->name=other.name;
        return *this;
    }
    ~Role()=default;
    friend std::ostream& operator<<(std::ostream& os, Role &ob)
    {
        os<<"the role of "<<ob.name;
        return os;
    }


};

//std::ostream& operator<<(std::ostream& os, Role &ob)
//{
//    os<<"the role of "<<ob.name;
//    return os;
//}


#endif //OOP_ROLE_H
