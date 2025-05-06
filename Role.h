//
// Created by stanb on 29.03.2025.
//
#include <iostream>
#include <string>
#ifndef OOP_ROLE_H
#define OOP_ROLE_H
#include <utility>
#include <vector>
#include "Obiect.h"

class Role {
private:
    void create_Shop()
    {
        auto *ob1=new Obiect("tomato seeds",10,10,1);
        Shop.push_back(ob1);
        auto *ob2=new Obiect("cucumber seeds",2,10,1);
        Shop.push_back(ob2);
        auto *ob3=new Obiect("onion seeds",6,10,1);
        Shop.push_back(ob3);
        auto *ob4=new Obiect("carrot seeds",5,10,1);
        Shop.push_back(ob4);
        auto *ob5=new Obiect("potato seeds",6,10,1);
        Shop.push_back(ob5);
        auto ob6=new Obiect("tomato", 0, 10, 2);
        Shop.push_back(ob6);
        auto *ob7=new Obiect("potato",0,10,2);
        Shop.push_back(ob7);
        auto *ob8=new Obiect("carrot",0,10,2);
        Shop.push_back(ob8);
        auto *ob9=new Obiect("cucumber",0,10,2);
        Shop.push_back(ob9);
        auto *ob10=new Obiect("onion",0,10,2);
        Shop.push_back(ob10);
        auto *ob11=new Obiect("paduden",5,10,3);
        Shop.push_back(ob11);
        auto *ob12=new Obiect("duloxetina",6,10,3);
        Shop.push_back(ob12);
        auto *ob13=new Obiect("gabaran",4,10,3);
        Shop.push_back(ob13);
        auto *ob14=new Obiect("lamotrix",10,10,3);
        Shop.push_back(ob14);
        auto *ob15=new Obiect("cocculine",8,10,3);
        Shop.push_back(ob15);


    }
protected:
    //this is a description of what a pony role usually consists of, not just the name of the role
    std::string name;
    std::vector <Obiect*> Shop;
    Obiect* first_object_on_back=nullptr;
    Obiect* second_object_on_back=nullptr;
//
//    void show_Shop()
//    {
//        for(auto const & i : Shop) ////dc are i referinta??? PTC: ca să nu se facă o copie; e drept că în cazul pointerilor nu contează
//            std::cout<<*i;
//
//    }
//L AM COMENTAT CA FACEA FITE CPPCHECK




public:
    Role(): name()  {
        create_Shop();
    }
    explicit Role(std::string  name_): name(std::move(name_)) {
    }

    Role(Role const &other): name(other.name)
    {

        for(auto const &i: other.Shop)  // cppcheck-suppress constVariableReference
        {
            Shop.push_back(new Obiect(*i));
        }
//
//        for(auto const &j: other.Objects_Pony_Is_Holding)
//        {
//            Objects_Pony_Is_Holding.push_back(new Obiect(*j));
//        }

        if(other.first_object_on_back!=nullptr)
            first_object_on_back=new Obiect(*other.first_object_on_back);

        if(other.second_object_on_back!=nullptr)
            second_object_on_back=new Obiect(*other.second_object_on_back);



    }
    Role& operator= (Role const &other)
    {
        if(&other==this) //dc trb sa pun &other? PTC: this este pointer; vrem să comparăm adresele ca să vedem dacă e vorba de același obiect
        {
            return *this;
        }

        this->name=other.name;
        for(auto const &i: other.Shop) // cppcheck-suppress constVariableReference
        {
            Shop.push_back(new Obiect(*i));
        }
//
//        for(auto const &j: other.Objects_Pony_Is_Holding)
//        {
//            Objects_Pony_Is_Holding.push_back(new Obiect(*j));
//        }

        first_object_on_back=new Obiect(*other.first_object_on_back);
        second_object_on_back=new Obiect(*other.second_object_on_back);


        return *this;



    }
    ~Role()
    {
        for(unsigned int i=0;i<Shop.size();i++)
        {
            delete Shop[i];
        }



//        Objects_Pony_Is_Holding.clear();
        delete first_object_on_back;
        delete second_object_on_back;
    }
    friend std::ostream& operator<<(std::ostream& os, const Role &ob)
    {
//        os<<"the role of "<<ob.name;
        os<<"role name: "<<ob.name<<"1st obj on back: "<<*ob.first_object_on_back<<"2nd obj on back: "<<*ob.second_object_on_back<<"\n";
        os<<"shop:\n";
        for(auto const &i:ob.Shop) // cppcheck-suppress constVariableReference
            os<<*i<<" ";
//        os<<"objects pony is holding:\n";
//        for(auto const &i:ob.Objects_Pony_Is_Holding)
//            os<<*i<<" ";

        return os;
    }


};

//std::ostream& operator<<(std::ostream& os, Role &ob)
//{
//    os<<"the role of "<<ob.name;
//    return os;
//}


#endif //OOP_ROLE_H
