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
    void create_cabinet()
    {
        for(auto &i:Shop)
        {
            if(i->get_code()==1)
            {
                auto obj=new Obiect(*i);
                std::cout<<"obiectul de bagat in cabinet este "<<*obj<<"\n";
                cabinet_farmer.push_back(obj);
            }

        }
    }


    void show_cabinet() {
        std::cout<<"A INTRAT IN SHOW CABINET\n";
        for (auto &i: cabinet_farmer)
            std::cout <<"obiect in cab= "<<*i<<"\n";
    }

public:


    Role_of_farmer() {
        create_cabinet();
    };

    Role_of_farmer(Role_of_farmer const &other)  : Role (other) {
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








    bool is_it_available(std::string const &name_wanted_obj)
    {
        std::cout<<"A INTRAT IN IS IT AVAILABLE\n";
        show_cabinet();
        int index=-1;

                for(auto &j:cabinet_farmer)
                {
                    index++;
                    std::cout<<"THIS IS WHAT WAS SENT TO IS IT AVAILABLE:\n"<<name_wanted_obj<<"\n";
                    std::cout<<"THIS IS WHAT IS IN THE OBJECT:\n"<<j->get_name()<<"\n";

                    if(j->get_name().find(name_wanted_obj)==-1)
                    {
                        std::cout<<"we found "<<name_wanted_obj<<" in the cabinet!\n"
                                                                "type 1 to take the object from the cabinet or 0 to close the cabinet\n";
                        bool input_nr;
                        std::cin>>input_nr;
                        if(input_nr==1)
                        {

                            std::cout<<"Press 1 to give the object to the customer and press 0 to put the object back in the cabinet\n";
                            bool input_nr2;
                            std::cin>>input_nr2;
                            if(input_nr2==1)
                            {
                                unsigned int nr_objects_left_in_cabinet=j->take_one_obj_out_of_cabinet();
//                                std::string remember=j->get_name();
                                if(nr_objects_left_in_cabinet==0)
                                {
                                    cabinet_farmer.erase(cabinet_farmer.begin()+index);
                                    //a sters obiectul din cabinet
                                }
                                return true;
                            }
                            else
                            {
                                std::cout<<"you closed the cabinet\n";
                                return false;
                            }





                        }
                        else
                        {
                            std::cout<<"the object is not in the cabinet, you have to grab it from the shop next time you go! :(\n";
                            return false;
                        }


                    }
                }






        return false;

    }




};


#endif //OOP_ROLE_OF_FARMER_H
