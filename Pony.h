//
// Created by stanb on 29.03.2025.
//

#include <iostream>
#include <string>
#include <vector>

#ifndef PROIECT_OOP_PONY_H
#define PROIECT_OOP_PONY_H

#include "Role.h"
#include "Status.h"
class Pony {
    private:
        std::string name;
        Role* pony_role;
        //abstract class
        Status* pony_status;
        //how hungry, healthy, happy a pony is
        //the ponies need each other to survive
    public:
        Pony()=default;
        Pony( std::string &name_, Role* pony_role_, Status* pony_status_): name(name_), pony_role(pony_role_), pony_status(pony_status_) {}
        Pony( Pony &other): name(other.name)
        {
            this->pony_role = new Role(*other.pony_role);
//            Role* pony_role= new Role(*other.pony_role); <----- aici am lasat pony_role arunat in aer.
//            In clasa Pony am obiectul this cu atributul pony_role etc. Aici CREEZ un ALT pony_role pe care il las in aer
//            De asta trebuie sa pun this->pony_role (se poate si pony_role pur si simplu dar e mai usor de inteles asa).
//            *other.pony_role se inlocuieste cu obiectul de tip Role la care pointa pony_role

            this->pony_status= new Status(*other.pony_status);
//            Status* pony_status= new Status(*other.pony_status);
        }

        Pony& operator= (Pony& other)
        {
            name=other.name;
//            pony_role=other.pony_role;
//            daca pun asa ar pointa amandoua spre aceeasi chestie
            this->pony_role= new Role(*other.pony_role);
//ca un fel de Student s1=Student("Andrei",131); (numai ca aici pun new ptc asa se face la pointeri)
            this->pony_status= new Status(*other.pony_status);
            return *this;
            //trimitem valoarea dereferentiata
        }
        //to do: self assigment la op=
        ~Pony ()
        {
            delete pony_role;
            delete pony_status;
        }
        friend std::ostream& operator<< (std::ostream& os, Pony const &ob)
        {
            os<< "The pony "<<ob.name<<" has the role of the "<<ob.pony_role<<" and the status of "<<ob.pony_status;
            return os;
        }








};





#endif //PROIECT_OOP_PONY_H
