#pragma once
#include "Color.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "Board.hpp"



using namespace std;
namespace pandemic
{
   class FieldDoctor: public Player {

        public:
            FieldDoctor(Board& myBoard, City c): Player(myBoard, c, "FieldDoctor") {}
            Player& build() override;
    };
};