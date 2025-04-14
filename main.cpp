#include <iostream>
//#include <fstream>
#include <string>
#include <vector>

#include "Role.h"
//#include "Status.h"
#include "Pony.h"
//#include "Obiect.h"
#include "Role_of_farmer.h"


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
//        std::cout<<"You have selected "<<task<<"!\nThis "<<task<<" needs a name!\n";


    }
    else if(nr_input==2)
    {
//        Role *role_of_pony=new Role("cook");
        task="chef";
//        std::cout<<"You have selected "<<task<<"!\nThis "<<task<<" needs a name!\n";
    }
    else
    {
//        Role *role_of_pony=new Role("healer");
        task="healer";

    }
    std::cout<<"You have selected "<<task<<"!\nThis "<<task<<" needs a name!\n";


    std::string input;
    std::cin>>input;
    Role *role_of_pony=new Role(task);
    Pony ponei=Pony(input, role_of_pony);

    std::cout<<"We wish you a warm welcome"
               ", "<<input<<"!\nGood luck "
                            "at your new job of "<<task<<"!\n";

    Role_of_farmer un_fermier;
    std::string produs_fermier;
    int OK_first_day=0;
    unsigned int attempts_day_one=0;
    std::cout<<"\n\n\nWelcome to your first day on the job!\n"
               "Here comes your first customer!\n"
               "   /0-      |------------------------|\n"
               "/---|       |   I want a red fruit!  |\n"
               "|   |       |________________________|\n\n\n";
    while(OK_first_day==0 && attempts_day_one!=3)
    {
        attempts_day_one++;
        std::cout<<"attempts of day one="<<attempts_day_one;
        std::cout<<"\nType what object you think the pony is referring to in order to search for it in the cabinet\n";
        std::cin>>produs_fermier;
        std::cout<<"U TYPED: "<<produs_fermier<<"\n";
        if(un_fermier.is_it_available(produs_fermier))
        {
            std::cout<<"Correct! This is exactly what your client wanted!\n"
                       "You have completed your first order!\n"
                       "Congrats!\n";
            OK_first_day=1;
        }
        else
        {
            std::cout<<"Looks like "<<produs_fermier<<" is not what your client wanted :(\n";

        }
        std::cout<<"ok first day: "<<OK_first_day<<"\n";
    }

    if(attempts_day_one==3)
    {
        std::cout<<"Your client has gotten tired and left :("
                   "\n";
    }
    else
    {
        std::cout<<"\n\nAnother customer steps into the shop\n"
                   "Press any key to take their order\n\n";
        std::string val;
        std::cin>>val;
        std::cout<<"\n\n"
                   "   /0-      |--------------------------------|\n"
                   "/---|       |   I want an orange vegetable!  |\n"
                   "|   |       |________________________________|\n\n\n";
        std::cin>>produs_fermier;
        unsigned int OK_second_day=0,attempts_day_two=0;
        while(OK_second_day==0 && attempts_day_two!=3)
        {
            attempts_day_two++;
            std::cout<<"Type what object you think the pony is referring to in order to search for it in the cabinet\n";
            std::cin>>produs_fermier;
            if(un_fermier.is_it_available(produs_fermier))
            {
                std::cout<<"Correct! This is exactly what your client wanted!\n"
                           "You have completed your first order!\n"
                           "Congrats!\n";
                OK_second_day=1;
            }
            else
            {
                std::cout<<"Looks like this is not what your client wanted :(\n";

            }
        }
        if(attempts_day_two==3)
            std::cout<<"Your client has gotten tired and left :("
                       "\n";

    }
    std::cout<<"FIRST DAY-OVER";





}