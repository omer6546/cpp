#include <iostream>
#include <string>
#include "Direction.hpp"
using namespace std;
namespace ariel{
    class Board{
        public:
            void post(int col, int row, enum Direction, string str);
            string read(int col, int row, enum Direction, unsigned int num);
            void show();
    };
};