#include <iostream>
//#include <fstream>
#include <string>
#include <vector>
#include <map>

#include "Role.h"
//#include "Status.h"
#include "Pony.h"
//#include "Obiect.h"
#include "Role_of_farmer.h"
#include "Interfata.h"
#include "ext/random.hpp"


int main() {

    Interfata interfata_ponei;
    std::cout << "Welcome to Pink Pony Club!\n";
    interfata_ponei.click_any_key_to_continue();
    std::cout << "In our club, there are three types of roles:\n"
                 "*farmer\n"
                 "The farmer takes care of the crops\n"
                 "and makes sure the club has fruits\n"
                 "and vegetables!\n\n";
    interfata_ponei.click_any_key_to_continue();
    std::cout << "*cook\n"
                 "Using the fruits and vegetables\n"
                 "provided by the farmer, the cook provides\n"
                 "the club with tasty food!\n\n";
    interfata_ponei.click_any_key_to_continue();
    std::cout << "*healer\n"
                 "So much work in the kitchen or in the mud\n"
                 "can give the ponies health problems."
                 "No worries, the healer pony takes care of them,\n"
                 "with the help of medicine!\n\n\n";
    interfata_ponei.click_any_key_to_continue();
    std::cout << "Which role would you like to pick?\n"
                 "Type 1 for farmer\n"
                 "Type 2 for cook\n"
                 "Type 3 for healer\n";
    int nr_input;
    std::cin >> nr_input;
    std::string task;
    if (nr_input == 1) {
        task = "farmer";
    } else if (nr_input == 2) {
        task = "chef";
    } else {
        task = "healer";
    }
    std::cout << "You have selected " << task << "!\nThis " << task << " needs a name!"
                                                                       "\nType what you would like for the name to be:\n";


    std::string input;
    std::cin >> input;
    Role *role_of_pony = new Role(task);
    Pony ponei = Pony(input, role_of_pony);

    std::cout << "We wish you a warm welcome, "
                 << input << "!\nGood luck at your new job of " << task <<"!\n";

    if(nr_input==1)
    {
        interfata_ponei.create_random_clients_order_strings();
        Interfata::click_any_key_to_continue();
        int nr_day=1;
        if(interfata_ponei.general_day(nr_day))
        {
            if(interfata_ponei.general_day(nr_day))
                if(interfata_ponei.general_day(nr_day))
                    std::cout<<"GAME WON";
        }

    }











    return 0;
}