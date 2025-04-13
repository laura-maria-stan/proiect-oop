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
        auto *ob1=new Obiect("seminte rosii",10,10,1);
        Shop.push_back(ob1);
        auto *ob2=new Obiect("seminte grau",2,10,1);
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
    std::vector <Obiect*> Objects_Pony_Is_Holding;
    Obiect* first_object_on_back{};
    Obiect* second_object_on_back{};

    void show_Shop()
    {
        for(auto const & i : Shop)
            std::cout<<*i;
        //dc are i referinta???
//        for(int i=0;i<Shop.size();i++)

    }




public:
    Role(): name(),Shop{}, Objects_Pony_Is_Holding{} {
        create_Shop();
        first_object_on_back={};
        second_object_on_back={};
    }
    explicit Role(std::string  name_, std::vector <Obiect*> &Shop_,std::vector <Obiect*> &Objects_Pony_Is_Holding_, Obiect* first_object_on_back_, Obiect* second_object_on_back_): name(std::move(name_)),Shop(Shop_),Objects_Pony_Is_Holding(Objects_Pony_Is_Holding_) {
        this->first_object_on_back=new Obiect(*first_object_on_back_);
        // dereferentierea este importanta ptc vreau sa trm VALOAREA nu pointerul
        this->second_object_on_back=new Obiect(*second_object_on_back_);

        Shop_.clear();
        Objects_Pony_Is_Holding_.clear();
        //e bine??????
    }

    explicit Role(Role &other): name(other.name)
    {


        for(auto const &i: other.Shop)
        {
            Shop.push_back(new Obiect(*i));
        }

        for(auto const &j: other.Objects_Pony_Is_Holding)
        {
            Objects_Pony_Is_Holding.push_back(new Obiect(*j));
        }

        first_object_on_back=new Obiect(*other.first_object_on_back);
        second_object_on_back=new Obiect(*other.second_object_on_back);



    }
    Role& operator= (Role const &other)
    {
        if(&other==this) //dc trb sa pun &other?
        {
            return *this;
        }

        this->name=other.name;
        for(auto const &i: other.Shop)
        {
            Shop.push_back(new Obiect(*i));
        }

        for(auto const &j: other.Objects_Pony_Is_Holding)
        {
            Objects_Pony_Is_Holding.push_back(new Obiect(*j));
        }

        first_object_on_back=new Obiect(*other.first_object_on_back);
        second_object_on_back=new Obiect(*other.second_object_on_back);


        return *this;



    }
    ~Role()
    {
        Shop.clear();
        Objects_Pony_Is_Holding.clear();
        delete first_object_on_back;
        delete second_object_on_back;
    }
    friend std::ostream& operator<<(std::ostream& os, const Role &ob)
    {
//        os<<"the role of "<<ob.name;
        os<<"role name: "<<ob.name<<"1st obj on back: "<<*ob.first_object_on_back<<"2nd obj on back: "<<*ob.second_object_on_back<<"\n";
        os<<"shop:\n";
        for(auto const &i:ob.Shop)
            os<<*i<<" ";
        os<<"objects pony is holding:\n";
        for(auto const &i:ob.Objects_Pony_Is_Holding)
            os<<*i<<" ";

        return os;
    }


};

//std::ostream& operator<<(std::ostream& os, Role &ob)
//{
//    os<<"the role of "<<ob.name;
//    return os;
//}


#endif //OOP_ROLE_H
