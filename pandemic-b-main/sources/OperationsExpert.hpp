#pragma once
#include "Color.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "Board.hpp"



using namespace std;
namespace pandemic
{
   class OperationsExpert: public Player {

        public:
            OperationsExpert(Board& b, City c): Player(b, c, "OperationsExpert") {}
            Player& build() override;

    };
}