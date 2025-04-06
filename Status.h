//
// Created by stanb on 31.03.2025.
//

#ifndef OOP_STATUS_H
#define OOP_STATUS_H


#include <iostream>

class Status {
private:
    int health;
    int happiness;
    int hunger;
public:
    Status() {}

    explicit Status(int health_,int happiness_,int hunger_): health(health_),happiness(happiness_),hunger(hunger_) {};

    Status(Status &other): health(other.health), happiness(other.happiness), hunger(other.hunger) {};

//    reminder ca in op= trimitem cu referinta obiectul care e returnat ca sa nu i mai facem o copie. de asta pun Status&
    Status& operator=(const Status &other)
    {
        health=other.health;
        happiness=other.happiness;
        hunger=other.hunger;
        return *this;
//        se returneaza obiectul in care am copiat chestiile, dereferentiat

    }

    friend std::ostream& operator<< (std::ostream &os, const Status &stat)
    {
        os<< "cu statusul "<< stat.health <<" sanatate, "<<stat.happiness<<" fericire si "<<100-stat.hunger<<" satietate\n";
        return os;
    }



};
//std::ostream& operator<< (std::ostream &os, Status &stat)
//{
//    os<< "cu statusul "<< stat.health <<" sanatate, "<<stat.happiness<<" fericire si "<<100-stat.hunger<<" satietate\n";
//    return os;
//}


#endif //OOP_STATUS_H
