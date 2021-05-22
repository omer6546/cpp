#pragma once
#include "Color.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "Board.hpp"



using namespace std;
namespace pandemic
{
   class Scientist: public Player {
       int x;

        public:
            Scientist(Board& myBoard, City c, int i): Player(myBoard, c, "Scientist"), x(i) {}
            Player& discover_cure(Color c) override;
    };
};