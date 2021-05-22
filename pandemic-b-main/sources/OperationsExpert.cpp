#include "OperationsExpert.hpp"


using namespace std;
namespace pandemic
{
   
    Player& OperationsExpert::build()
    {
        if (my_board.has_rs(my_city))
        {
            return *this;
        };
        my_board.build_rs(my_city);
        return *this;    
    };
        
}