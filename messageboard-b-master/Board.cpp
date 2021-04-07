#include <string>
#include <array>
#include <iostream>
#include <stdexcept>
#include <map>
#include <limits.h>
#include "Board.hpp"
using namespace std;
namespace ariel{
    unsigned int rowsmax;
    unsigned int rowsmin;
    unsigned int colsmax;
    unsigned int colsmin;

    Board::Board()
        {
            rowsmin = INT_MAX;
            rowsmax = 0;
            colsmin = INT_MAX;
            colsmax = 0;
        };
    Board::~Board(){}

    void Board::post(unsigned int row, unsigned int col, enum Direction d, const string &str)
    {   
        if (d == Direction::Horizontal)
        {
            for(unsigned int i=0; i<str.length(); i++)
            {
                b[row][col + i] = str[i];
            }
            rowsmin = min(rowsmin,row);
            rowsmax = max(rowsmax,row);
            colsmin = min(colsmin,col);
            colsmax = max((col + unsigned(str.length())), colsmax);
            
        }
        else
        {
            for(unsigned int i=0; i<str.length(); i++)
            {
                b[row + i][col] = str[i];
            }  
            rowsmin = min(rowsmin,row);
            rowsmax = max((row + unsigned(str.length())), rowsmax);
            colsmin = min(colsmin,col);
            colsmax = max(colsmin,col);
        }
        
    }
    string Board::read(unsigned int row, unsigned int col, enum Direction d, unsigned int num){
        string ans;
        for(unsigned int i=0; i<num; i++)
        {
            if (d == Direction::Horizontal)
            {
                
                if(b[row][col+i] == 0)
                {
                    ans += "_";
                }
                else
                {
                    ans += b[row][col+i];
                }
            }
            else
            {
                if(b[row+i][col] == 0)
                {
                    ans += "_";
                }
                else
                {
                    ans += b[row+i][col];
                }
            }
        }
        return ans;
    }
    void Board::show()
    {
        unsigned int display_rows = (rowsmax - rowsmin) + 1;
        unsigned int display_cols = (colsmax - colsmin) ;
        for(unsigned int i = 0; i<display_rows; i++)
        {
            for(unsigned int j = 0; j<display_cols; j++)
            {
                if(b[i][j] != 0)
                {
                    cout << b[i][j];
                }
                else
                {
                    cout << "_";
                }
                
            }
            cout << endl;
        }
    }
}


