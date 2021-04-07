#include <iostream>
#include <string>
#include <map>
#include "Direction.hpp"
using namespace std;
namespace ariel{
    class Board{
        private:
            map<unsigned int, map<unsigned int, char>> b;

        public:
            Board();
            ~Board();
            void post(unsigned int row, unsigned int col, enum Direction d, const string &str);
            string read(unsigned int row, unsigned int col, enum Direction d, unsigned int num);
            void show();
    };
};