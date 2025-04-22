//
// Created by stanb on 06.04.2025.
//

#ifndef OOP_ROLE_OF_FARMER_H
#define OOP_ROLE_OF_FARMER_H
#include "Role.h"
#include <iostream>
#include "Obiect.h"
#include <vector>
#include "Interfata.h"
#include <cstring>

class Role_of_farmer: protected Role {
private:
    std::vector<Obiect *> cabinet_farmer;
    void create_cabinet()
    {
//        std::cout<<"CREEAZA CABINETUL\n";
        for(auto &i:Shop)
        {
            if(i->get_code()==1)
            {
                auto obj=new Obiect(*i);
//                std::cout<<"obiectul de bagat in cabinet este "<<*obj<<"\n";
                cabinet_farmer.push_back(obj);
            }

        }
    }


public:


    Role_of_farmer() {
        create_cabinet();
    };

    Role_of_farmer(Role_of_farmer const &other)  : Role (other) {
        for(auto const &i: other.cabinet_farmer) // cppcheck-suppress constVariableReference
        cabinet_farmer.push_back(new Obiect(*i));

    }

    Role_of_farmer &operator=(Role_of_farmer const &other)
    {
        if(&other==this) //dc trb sa pun &other?
        {
            return *this;
        }

        for(auto const &i: other.cabinet_farmer) // cppcheck-suppress constVariableReference
        {
            cabinet_farmer.push_back(new Obiect(*i));
        }
        return *this;
    }

    ~Role_of_farmer()
    {
        for(unsigned int i=0;i<cabinet_farmer.size();i++)
            delete cabinet_farmer[i];
    }


    void show_cabinet() {
        std::cout<<"-------THE CABINET-------\n";
        for (auto &i: cabinet_farmer)
            std::cout <<*i<<"\n";
        std::cout<<"-------------------------\n";
    }

    void take_one_obj_out_of_cabinet(std::string const &wanted_object)
    {
        int index = -1;
        int ERASE=0,poz=0;
        Obiect *alt_pointer;
        for (auto &i: cabinet_farmer)
        {
            index++;
            if (i->get_name() == wanted_object)
//            {
//                i = *cabinet_farmer.end();
//            }
                if (i->get_availability() == 1) {

                    alt_pointer = cabinet_farmer[index];
                    ERASE = 1;
                    poz = index;
                    //a sters obiectul din cabinet
//
                    //e bine????

                }
        }
                if(ERASE==1)
                {
                    cabinet_farmer.erase(cabinet_farmer.begin() + poz);
                    alt_pointer->decrease_availability();
                    delete alt_pointer;
                }





    }






    bool is_it_available(std::string const &name_wanted_obj) {
        Interfata interf_in_is_it_available;
        std::cout << "Searching for " << name_wanted_obj << " in the cabinet...\n";
        interf_in_is_it_available.click_any_key_to_continue();
        for (auto &j: cabinet_farmer)
        {

//
//            std::string first_part_of_string;
//            std::string copy=j->get_name();
//            std::string *ptr=&copy;
//            std::cout<<"nume seeds= "<<copy<<"\n";
//            first_part_of_string= strtok(copy," ");
//
//        }

            if (j->get_name().find(name_wanted_obj)!=std::string::npos)
                    {
                        std::cout<<"###WE FOUND "<<name_wanted_obj<<" IN THE CABINET!###\n"
                                                                "Type 1 to take the object from the cabinet or 0 to search for another item from the cabinet\n";
                        bool input_nr;
                        std::cin>>input_nr;
                        if(input_nr==1)
                        {

                            std::cout<<"Press 1 to give the object to the customer or press 0 to open the cabinet again and search for another item\n";
                            bool input_nr2;
                            std::cin>>input_nr2;
                            if(input_nr2==1)
                            {
                                take_one_obj_out_of_cabinet(name_wanted_obj);

                                return true;
                            }
                            else
                            {
                                std::cout<<"You placed "<<name_wanted_obj<<" back in the cabinet\n";
                                return false;
                            }





                        }
                        else
                        {
                            std::cout<<"You placed "<<name_wanted_obj<<" back in the cabinet\n";
                            return false;
                        }



                    }



        }
        std::cout<<"Sorry, we couldnt find "<<name_wanted_obj<<" in the cabinet\n";
        return false;








    }




};


#endif //OOP_ROLE_OF_FARMER_H
