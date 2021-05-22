#include "FieldDoctor.hpp"


using namespace std;
namespace pandemic
{
   
    Player& FieldDoctor::treat(City c)
    {
        if (my_board.get_sick_level(c) == 0 )
        {
            throw invalid_argument{"this city is healthy, nothing to treat!"};
        };    
        if (my_city == c || my_board.my_ni(my_city, c))
        {
            if (my_board.has_cure(my_board.get_color(c)))
            {
                my_board.set_sick_level(c,0);
                return *this;
            };
            int x = my_board.get_sick_level(c);
            my_board.set_sick_level(c,x-1);
            return *this;
        };
        throw invalid_argument{"can't treat this virus if i'm not in/near the city!"};
    };
        
}
