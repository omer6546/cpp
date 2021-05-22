#pragma once
#include <iostream>
#include <string>
#include <stdbool.h>
#include "Color.hpp"
#include "City.hpp"
#include <set>






using namespace std;
namespace pandemic{
    
    class Board{
                   
    
        public:
            Board();
            ~Board();
            bool is_clean();
            int& operator[](City c);
            friend ostream& operator<<(ostream &out, const Board &b);
            bool my_ni(City c, City n);
            bool has_rs (City c);
            void build_rs(City c);
            bool has_cure(Color c);
            void cure_this_color(Color c);
            int get_sick_level(City c);
            Color get_color(City c);
            void set_sick_level(City c, int i);
            static void remove_cures();
            static void remove_stations();
            static void init_oof();
    };
};