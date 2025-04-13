//
// Created by stanb on 06.04.2025.
//

#ifndef OOP_ROLE_OF_FARMER_H
#define OOP_ROLE_OF_FARMER_H
#include "Role.h"
#include <iostream>
#include "Obiect.h"
#include <vector>

class Role_of_farmer: protected Role {
private:
    std::vector<Obiect *> cabinet_farmer;
public:
    void show_cabinet() {
        for (auto &i: cabinet_farmer)
            std::cout << *i;
    }

    Role_of_farmer(): cabinet_farmer({nullptr}) {/*e bine???*/};

    explicit Role_of_farmer(std::vector<Obiect *> &cabinet_farmer_) : cabinet_farmer(
            cabinet_farmer_) { cabinet_farmer_.clear(); }

    Role_of_farmer(Role_of_farmer &other) {
        for(auto const &i: other.cabinet_farmer)
        cabinet_farmer.push_back(new Obiect(*i));
    }

    Role_of_farmer &operator=(Role_of_farmer const &other)
    {
        if(&other==this) //dc trb sa pun &other?
        {
            return *this;
        }

        for(auto const &i: other.cabinet_farmer)
        {
            cabinet_farmer.push_back(new Obiect(*i));
        }
        return *this;
    }

    ~Role_of_farmer()
    {
        cabinet_farmer.clear();
    }


};


#endif //OOP_ROLE_OF_FARMER_H
