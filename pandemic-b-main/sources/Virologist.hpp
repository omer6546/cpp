#pragma once
#include "Color.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "Board.hpp"


using namespace std;
namespace pandemic
{
   class Virologist: public Player {

        public:
            Virologist(Board& myBoard, City c): Player(myBoard, c, "Virologist") {}
            Player& treat(City c) override;
    };
};