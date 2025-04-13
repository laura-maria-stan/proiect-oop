//
// Created by stanb on 06.04.2025.
//

#ifndef OOP_OBIECT_H
#define OOP_OBIECT_H
#include <iostream>
#include <string>
#include <utility>
#include <vector>


class Obiect {
private:
    std::string name;
    int price;
    int availability;
    int code;
public:
    Obiect(): price(0), availability(10), code(0) {}
    Obiect(std::string name_, int price_, int availability_, int code_): name(std::move(name_)),price(price_),availability(availability_),code(code_) {}
    Obiect(Obiect &other)= default;
    Obiect & operator=(Obiect const& other)
    {
        if(&other==this) //dc trb sa pun &other?
        {
            return *this;
        }

        name=other.name;
        price=other.price;
        availability=other.availability;
        code=other.availability;
        return *this;
    }
    friend std::ostream& operator<<(std::ostream &os, const Obiect &ob)
    {
        os<<"name product: "<<ob.name<<"\nprice:"<<ob.price<<"\nhow many are available?"<<ob.availability<<"\n";
        return os;
    }

};


#endif //OOP_OBIECT_H
