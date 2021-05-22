#include "Dispatcher.hpp"


using namespace std;
namespace pandemic
{
   
    Player& Dispatcher::fly_direct(City c)
    {
        if (my_board.has_rs(my_city) && c != my_city)
        {
            my_city = c;
            return *this;
        };
        if (cards.find(c) ==  cards.end() || c == my_city)
        {
            throw invalid_argument{"can't fly to this city!"};
        };
        cards.erase(c);
        my_city = c;
        return *this;
    };
        
}