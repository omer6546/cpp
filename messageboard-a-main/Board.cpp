#include <string>
#include <array>
#include <iostream>
#include <stdexcept>
#include "Board.hpp"
using namespace std;
namespace ariel{
    void Board::post(int col, int row, enum Direction, string str){};
    string Board::read(int col, int row, enum Direction, unsigned int num){
        return "nothing";
    };
    void Board::show(){};
};