#pragma once
#include "Color.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "Board.hpp"



using namespace std;
namespace pandemic
{
   class Medic: public Player {

        public:
            Medic(Board& myBoard, City c): Player(myBoard, c, "Medic") {}
            Player& build() override;
    };
};