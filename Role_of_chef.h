//
// Created by stanb on 06.04.2025.
//
#include <iostream>
#include <string>
#ifndef OOP_ROLE_OF_CHEF_H
#define OOP_ROLE_OF_CHEF_H
#include <vector>


#include "Role.h"

class Role_of_chef: protected Role {
private:
    std::vector <std::string> cabinet;
public:
    void show_Shop()
    {
        for(auto & i : Shop)
            std::cout<<*i;
        //dc are i referinta???
//        for(int i=0;i<Shop.size();i++)

    }
};


#endif //OOP_ROLE_OF_CHEF_H
