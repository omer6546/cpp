#include "Virologist.hpp"


using namespace std;
namespace pandemic
{
   
    Player& Virologist::treat(City c)
    {
        if (my_board.get_sick_level(c) == 0)
        {
            throw invalid_argument{"this city is healthy, nothing to treat!"};
        };    
        if (my_city != c && cards.find(c) == cards.end())
        {
            throw invalid_argument{"can't treat this virus if i'm not in the city!"};
        };
        if (my_board.has_cure(my_board.get_color(c)))
        {
            if (cards.find(c) != cards.end())
            {
                cards.erase(c);
            };
            my_board.set_sick_level(c,0);
            return *this;
        };
        if (cards.find(c) != cards.end())
            {
                cards.erase(c);
            };
        int x = my_board.get_sick_level(c);
        my_board.set_sick_level(c,x-1);
        return *this;
    };
        
}