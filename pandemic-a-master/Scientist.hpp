#pragma once
#include "Color.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "Board.hpp"



using namespace std;
namespace pandemic
{
   class Scientist: public Player {

        public:
            Scientist(Board& myBoard, City c, int i): Player(myBoard, c, "Scientist") {}
            Player& build() override;
    };
};