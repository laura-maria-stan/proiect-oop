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
    int price=0;
    int availability=10;
    int code=0;
public:
    Obiect(): name() {}
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
    std::string get_name()
    {
        return name;
    }
    int get_code() const
    {
        return code;
    }

    unsigned int take_one_obj_out_of_cabinet()
    {
        availability--;
        return availability;
    }

};


#endif //OOP_OBIECT_H
