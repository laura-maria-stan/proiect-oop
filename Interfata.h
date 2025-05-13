//
// Created by stanb on 21.04.2025.
//
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "Role.h"
#include "Role_of_farmer.h"
#include "ext/random.hpp"
#ifndef OOP_INTERFATA_H
#define OOP_INTERFATA_H



class Interfata {
private:
    std::map <std::string, std::vector <std::string>> phrases;
    std::vector<std::string> keys;

public:
    static void click_any_key_to_continue()
    {

        std::string input_any_key;
        std::cout<<"(press any key+enter to continue)\n";
        std::cin>>input_any_key;

    }
    void create_random_clients_order_strings()
    {
        using Random = effolkronium::random_static;
        auto val = Random::get( );
        // val is random number in [ Random::min( ), Random::max ] range
        //using library random
        phrases["tomato"].push_back("I want a red fruit");
        phrases["tomato"].push_back("I'd like a solanum lycopersicum");
        phrases["tomato"].push_back("What's the thing ketchup is made of? I'd like one of these");
        phrases["tomato"].push_back("I'd like an edible berry that is eaten as a vegetable");
        phrases["tomato"].push_back("I'd like a round, red fruit with a lot of seeds, eaten cooked or uncooked as a vegetable, for example in salads or sauces");
        phrases["tomato"].push_back("I'd like a.. Love Apple");
        phrases["cucumber"].push_back("I'd like a green vegetable please!");
        phrases["cucumber"].push_back("I want one cucumis sativus!");
        phrases["cucumber"].push_back("One creepy plant please! Sorry, creeping plant");
        phrases["cucumber"].push_back("The thing I want is green");
        phrases["cucumber"].push_back("I'm having a spa day. Give me something to put on my eyelids!");
        phrases["onion"].push_back("I need a vegetable that will make me cry!");
        phrases["onion"].push_back("I'd like something with lots of layers");
        phrases["onion"].push_back("One Allium cepa please!");
        phrases["onion"].push_back("New York City is known as the Big Apple. Before having that nickname, it was known by a different nickname. I'd like one of these");
        phrases["onion"].push_back("You use a knife to slice its head and weep beside it when it's dead... One of those please!");
        phrases["onion"].push_back("Give me a vegetable that smells bad");
        phrases["carrot"].push_back("I'm dressing up as a bunny. Give me something to suit my costume!");
        phrases["carrot"].push_back("One Daucus Carota");
        phrases["carrot"].push_back("One of those things that make your skin orange");
        phrases["carrot"].push_back("Give me a vegetable that will help my eyesight!");
        phrases["carrot"].push_back("One vegetable that's not a potato, a cucumber or an onion");
        phrases["potato"].push_back("One round underground vegetable please");
        phrases["potato"].push_back("One round underground vegetable please");
        phrases["potato"].push_back("One round underground vegetable please");
        phrases["potato"].push_back("One Solanum tuberosum!");
    }


    std::string generate_request(std::string &the_order)
    {
        using Random = effolkronium::random_static;
        for (const auto& pair : phrases)
            keys.push_back(pair.first);
        std::string randomKey = *Random::get(keys);
        //dereferentiat ptc get intoarce un iterator not the value itself
        the_order=randomKey;
        return *Random::get(phrases[randomKey]);

    }

    bool general_day(int &number_day)
    {
        Role_of_farmer our_farmer;

        int index_customer=0;
        bool success=false;
        while(index_customer>=number_day+2)
        {
            index_customer++;
            std::cout<<"A customer is here!";
            click_any_key_to_continue();
            std::string clients_order;
            std::cout<<generate_request(clients_order);
            click_any_key_to_continue();
            std::cout<<"Before you try to guess, take a look at the cabinet:\n";
            our_farmer.show_cabinet();
            click_any_key_to_continue();




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
                    if(input1==clients_order)
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
                    std::cout<<"attempts left: "<<3-attempts<<"\n";
                    std::cout<<"Type your next guess: ";
                }
            }
            if(attempts==3 && OK!=0)
            {
                std::cout<<"Your customer has gotten tired and left :(\nFIRST DAY=FAILED";
                success=false;
            }
            else if(OK==0)
            {
                std::cout<<"CONGRATS!\nFIRST DAY=SUCCESSFUL";
                success=true;
            }
        }
        number_day++;
        return success;
    }





};


#endif //OOP_INTERFATA_H
