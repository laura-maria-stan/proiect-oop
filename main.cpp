#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Role.h"
//#include "Status.h"
#include "Pony.h"



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
    Role *role_of_pony=new Role();
//    std::cout<<*role_of_pony;
    std::cin>>nr_input;
    if(nr_input==1)
    {
        Role *role_of_pony=new Role("farmer");
        std::cout<<"You have selected "<<*role_of_pony<<"!\nThis "<<*role_of_pony<<" needs a name!\n";


    }
    else if(nr_input==2)
    {
        Role *role_of_pony=new Role("cook");
        std::cout<<"You have selected "<<*role_of_pony<<"!\nThis "<<*role_of_pony<<" needs a name!\n";
    }
    else
    {
        Role *role_of_pony=new Role("healer");
        std::cout<<"You have selected "<<*role_of_pony<<"!\nThis "<<*role_of_pony<<" needs a name!\n";
    }

    std::string input;
    std::cin>>input;
    Pony ponei=Pony(input, role_of_pony);

    std::cout<<"We wish you a warm welcome"
               ", "<<input<<"!\nGood luck "
                            "at your new job of "<<*role_of_pony<<"!\n";

}