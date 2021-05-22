#pragma once
#include <iostream>
#include <string>
#include <map>
#include <stdbool.h>
#include "City.hpp"
#include "Board.hpp"



using namespace std;
namespace pandemic{
    
    class Player{
        
        protected:
           map <City, enum Color> cards;
           Board &my_board;
           City my_city;
           string my_role;
    
        public:
            Player(Board &b, City c, string s): my_board(b), my_city(c), my_role(s) {};
            virtual Player& drive(City c);
            virtual Player& fly_direct(City c);
            virtual Player& fly_charter(City c);
            virtual Player& fly_shuttle(City c);
            virtual Player& build();
            virtual Player& discover_cure(Color c);
            virtual Player& treat(City c);
            virtual string role();
            Player& take_card(City c);
            void remove_cards();
           
    };
}