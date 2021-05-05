#pragma once
#include "Color.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "Board.hpp"



using namespace std;
namespace pandemic
{
   class GeneSplicer: public Player {

        public:
            GeneSplicer(Board& myBoard, City c): Player(myBoard, c, "GeneSplicer") {}
            Player& build() override;
    };
};