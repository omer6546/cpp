#pragma once
#include <iostream>
#include <string>
#include <stdbool.h>
#include "Color.hpp"
#include "City.hpp"




using namespace std;
namespace pandemic{
    
    class Board{
                   
    
        public:
            Board();
            ~Board();
            bool is_clean();
            int& operator[](City c);
            friend ostream& operator<<(ostream &out, const Board &b);
            void remove_cure();
    };
};