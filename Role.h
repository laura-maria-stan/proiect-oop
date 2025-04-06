//
// Created by stanb on 29.03.2025.
//
#include <iostream>
#include <string>
#ifndef OOP_ROLE_H
#define OOP_ROLE_H
#include <vector>
#include "Obiect.h"

class Role {
private:
    void create_Shop()
    {
        Obiect *ob1=new Obiect("seminte rosii",10,10,1);
        Shop.push_back(ob1);
        Obiect *ob2=new Obiect("seminte grau",2,10,1);
        Shop.push_back(ob2);
        Obiect *ob3=new Obiect("seminte ceapa",6,10,1);
        Shop.push_back(ob3);
        Obiect *ob4=new Obiect("seminte morcovi",5,10,1);
        Shop.push_back(ob4);
        Obiect *ob5=new Obiect("seminte cartofi",6,10,1);
        Shop.push_back(ob5);
        Obiect *ob6=new Obiect("rosie",0,10,2);
        Shop.push_back(ob6);
        Obiect *ob7=new Obiect("cartof",0,10,2);
        Shop.push_back(ob7);
        Obiect *ob8=new Obiect("morcov",0,10,2);
        Shop.push_back(ob8);
        Obiect *ob9=new Obiect("grau",0,10,2);
        Shop.push_back(ob9);
        Obiect *ob10=new Obiect("ceapa",0,10,2);
        Shop.push_back(ob10);
        Obiect *ob11=new Obiect("paduden",5,10,3);
        Shop.push_back(ob11);
        Obiect *ob12=new Obiect("duloxetina",6,10,3);
        Shop.push_back(ob12);
        Obiect *ob13=new Obiect("gabaran",4,10,3);
        Shop.push_back(ob13);
        Obiect *ob14=new Obiect("lamotrix",10,10,3);
        Shop.push_back(ob14);
        Obiect *ob15=new Obiect("cocculine",8,10,3);
        Shop.push_back(ob15);


    }
protected:
    //this is a description of what a pony role usually consists of, not just the name of the role
    std::string name;
    std::vector <Obiect*> Shop;
public:
    Role(): name() {

        create_Shop();
    }
    explicit Role(const std::string& name_): name(name_) {}
    Role(Role &other): name(other.name) {}
    Role& operator= (Role const &other)
    {
        this->name=other.name;
        return *this;
    }
    ~Role()=default;
    friend std::ostream& operator<<(std::ostream& os, const Role &ob)
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
