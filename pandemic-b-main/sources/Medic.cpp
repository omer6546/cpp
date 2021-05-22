#include "Medic.hpp"


using namespace std;
namespace pandemic
{
    Player& Medic::drive(City c)
    {
        if (!my_board.my_ni(my_city, c))
        {
            throw invalid_argument{"can't drive to this city, it is to far!"};
        };
        my_city = c;
        if (my_board.has_cure(my_board.get_color(c)))
        {
            my_board.set_sick_level(c,0);
        };
        return *this;
    }

    Player& Medic::fly_direct(City c)
    {
        if (cards.find(c) ==  cards.end())
        {
            throw invalid_argument{"can't fly to this city!"};
        };

        cards.erase(c);
        my_city = c;
        if (my_board.has_cure(my_board.get_color(c)))
        {
            my_board.set_sick_level(c,0);
        };
        return *this;
    }
    
    Player& Medic::fly_charter(City c)
    {
        if (cards.find(my_city) ==  cards.end())
        {
            throw invalid_argument{"can't fly to this city!"};
        };

        cards.erase(my_city);
        my_city = c;
        if (my_board.has_cure(my_board.get_color(c)))
        {
            my_board.set_sick_level(c,0);
        };
        return *this;
    }

    Player& Medic::fly_shuttle(City c)
    {
        if (!my_board.has_rs(c) && !my_board.has_rs(my_city))
        {
            throw invalid_argument{"can't fly to this city!"};
        };
        my_city = c;
        if (my_board.has_cure(my_board.get_color(c)))
        {
            my_board.set_sick_level(c,0);
        };
        return *this;
    }

    Player& Medic::treat(City c)
    {
        if (my_board.get_sick_level(c) == 0)
        {
            throw invalid_argument{"this city is healthy, nothing to treat!"};
        };    
        if (my_city != c)
        {
            throw invalid_argument{"can't treat this virus if i'm not in the city!"};
        };
        my_board.set_sick_level(c,0);
        return *this;

    };

        
}