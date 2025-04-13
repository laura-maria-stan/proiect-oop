#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Role.h"
//#include "Status.h"
#include "Pony.h"
#include "Obiect.h"



int main()
{

    std::cout<<"Welcome to Pink Pony Club!\n"
               "In our club, there are three types of roles:\n"
               "*farmer\n"
               "The farmer takes care of the crops\n"
               "and makes sure the club has fruits\n"
               "and vegetables!\n\n"
               "*cook\n"
               "Using the fruits and vegetables\n"
               "provided by the farmer, the cook provides\n"
               "the club with tasty food!\n\n"
               "*healer\n"
               "So much work in the kitchen or in the mud\n"
               "can give the ponies health problems."
               "No worries, the healer pony takes care of them,\n"
               "with the help of medicine!\n\n\n"
               "Which role would you like to pick?\n"
               "Type 1 for farmer\n"
               "Type 2 for cook\n"
               "Type 3 for healer\n";
    int nr_input;
//    Role *role_of_pony=new Role();
//    std::cout<<*role_of_pony;
    std::cin>>nr_input;
    std::string task;
    if(nr_input==1)
    {
//        Role *role_of_pony=new Role("farmer");
        task="farmer";
        std::cout<<"You have selected "<<task<<"!\nThis "<<task<<" needs a name!\n";


    }
    else if(nr_input==2)
    {
//        Role *role_of_pony=new Role("cook");
        task="chef";
        std::cout<<"You have selected "<<task<<"!\nThis "<<task<<" needs a name!\n";
    }
    else
    {
//        Role *role_of_pony=new Role("healer");
        task="healer";
        std::cout<<"You have selected "<<task<<"!\nThis "<<task<<" needs a name!\n";
    }

    std::vector <Obiect*> v1_shop={};
    auto *ob=new Obiect("ob",0,10,0);
    std::vector <Obiect*> v2_objects_pony_is_holding={ob};
    Obiect* v3_first_obj_on_back=ob, *v4_second_obj_on_back=ob;

    Role *role_of_pony=new Role("", v1_shop, v2_objects_pony_is_holding, v3_first_obj_on_back, v4_second_obj_on_back);
    
    std::cout<<*role_of_pony;

    std::string input;
    std::cin>>input;
    Pony ponei=Pony(input, role_of_pony);

    std::cout<<"We wish you a warm welcome"
               ", "<<input<<"!\nGood luck "
                            "at your new job of "<<*role_of_pony<<"!\n";

}