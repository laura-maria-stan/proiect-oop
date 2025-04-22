#include <iostream>
//#include <fstream>
#include <string>
#include <vector>

#include "Role.h"
//#include "Status.h"
#include "Pony.h"
//#include "Obiect.h"
#include "Role_of_farmer.h"
#include "Interfata.h"


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
        interfata_ponei.click_any_key_to_continue();

        Role_of_farmer our_farmer;


        std::cout << "\n\n\nWelcome to your first day on the job!\n";
        interfata_ponei.click_any_key_to_continue();
        std::cout << "Here comes your first customer!\n"
                     "   /0-      |------------------------|\n"
                     "/---|       |   I want a red fruit!  |\n"
                     "|   |       |________________________|\n\n\n";

        interfata_ponei.click_any_key_to_continue();
        std::cout<<"Before you try to guess, take a look at the cabinet:\n";
        our_farmer.show_cabinet();
        interfata_ponei.click_any_key_to_continue();


        std::cout << "###TYPE WHAT OBJECT YOU THINK THE CLIENT IS REFERRING TO IN ORDER TO\n"
                     "   SEARCH FOR IT IN THE CABINET: ###\n";


        int OK=1,attempts=0;
        std::string input1;
        while(OK==1 && attempts !=3)
        {

            attempts++;
            std::cin>>input1;
            if(our_farmer.is_it_available(input1))
            {
                if(input1=="tomato")
                {
                    std::cout<<"Congrats! Your order was successful!\n";
                    OK=0;
                }
                else
                {
                    std::cout<<"This is not what your client wanted\n";

                }

            }
            if(attempts!=3 && OK!=0)
            {
                std::cout<<"rn attempts e "<<attempts<<"\n";
                std::cout<<"Type your next guess: ";
            }
        }
        if(attempts==3 && OK!=0)
        {
            std::cout<<"Your customer has gotten tired and left :(\nFIRST DAY=FAILED";
        }
        else if(OK==0)
        {
            std::cout<<"CONGRATS!\nFIRST DAY=SUCCESSFUL";
        }

    }








//    while (OK_first_day == 0 && attempts_day_one != 3) {
//        attempts_day_one++;
//        std::cin >> produs_fermier;
//        std::cout << "U TYPED: " << produs_fermier << "\n";
//        un_fermier.show_cabinet();
//        int check = un_fermier.is_it_available(produs_fermier);
////        std::cout << " a trms in is it available de la variabila check care este: "<< check<<"\n";
//        if (check==1) {
//            std::cout << "###CORRECT!"
//                         "   THIS IS EXACTLY WHAT YOUR CLIENT WANTED###\n"
//                         "###CONGRATS, YOU HAVE COMPLETED YOUR FIRST ORDER###!\n";
//            OK_first_day = 1;
//            un_fermier.take_one_obj_out_of_cabinet(produs_fermier);
//        } else if (check==0)
//        {
//            std::cout << "###WRONG GUESS, " << produs_fermier << " IS NOT WHAT YOUR CLIENT WANTED###\n"
//                                                                 "###PUT THE OBJECT BACK AND TRY AGAIN###\n";
//        }
//        else if (check == -1)
//        {
//            std::cout<<" ###WRONG GUESS, "<<produs_fermier <<" IS NOT AN ITEM IN YOUR CABINET###\n"
//                                                             "### LOOK CLOSER AT THE OBJECTS IN THE CABINET AND TRY AGAIN ####\n";
//            un_fermier.show_cabinet();
//
//        }
//        else
//        {
//            std::cout<<"You closed the cabinet"
//        }
////        std::cout<<"ok first day: "<<OK_first_day<<"\n";
//    }
//
//    if (attempts_day_one == 3) {
//        std::cout << "###YOUR CLIENT HAS GOTTEN TIRED AND LEFT###"
//                     "\n";
//    } else {
//        std::cout << "\n\n###ANOTHER CUSTOMER STEPS INTO THE SHOP###\n"
//                     "###PRESS ANY KEY TO TAKE THEIR ORDER###\n\n";
//        std::string val;
//        std::cin >> val;
//        std::cout << "\n\n"
//                     "   /0-      |--------------------------------|\n"
//                     "/---|       |   I want an orange vegetable!  |\n"
//                     "|   |       |________________________________|\n\n\n";
//        std::cin >> produs_fermier;
//        unsigned int OK_second_day = 0, attempts_day_two = 0;
//
//        std::cout << "###TYPE WHAT OBJECT YOU THINK THE CLIENT IS REFERRING TO IN ORDER TO\n"
//                     "   SEARCH FOR IT IN THE CABINET ###\n";
//        while (OK_second_day == 0 && attempts_day_two != 3) {
//            attempts_day_two++;
//            std::cin >> produs_fermier;
//            std::cout << "U TYPED: " << produs_fermier << "\n";
//            un_fermier.show_cabinet();
//            int check = un_fermier.is_it_available(produs_fermier);
//            std::cout << "functia: " << un_fermier.is_it_available(produs_fermier) << "\n";
//            if (check) {
//                std::cout << "###CORRECT!"
//                             "   THIS IS EXACTLY WHAT YOUR CLIENT WANTED###\n"
//                             "###CONGRATS, YOU HAVE COMPLETED YOUR FIRST ORDER###!\n";
//                OK_second_day = 1;
//                un_fermier.take_one_obj_out_of_cabinet(produs_fermier);
//            }
//            else if (check==0)
//            {
//                std::cout << "###WRONG GUESS, " << produs_fermier << " IS NOT WHAT YOUR CLIENT WANTED###\n"
//                                                                     "###PUT THE OBJECT BACK AND TRY AGAIN###\n";
//            }
//            else
//            {
//                std::cout<<" ###WRONG GUESS, "<<produs_fermier <<" IS NOT AN ITEM IN YOUR CABINET###\n"
//                                                                 "### LOOK CLOSER AT THE OBJECTS IN THE CABINET AND TRY AGAIN ####\n";
//
//            }
////        std::cout<<"ok first day: "<<OK_first_day<<"\n";
//
//
//            if (attempts_day_two == 3) {
//                std::cout << "###YOUR CLIENT HAS GOTTEN TIRED AND LEFT###"
//                             "\n";
//            }
//
//        }
//
//
//    }
    return 0;
}