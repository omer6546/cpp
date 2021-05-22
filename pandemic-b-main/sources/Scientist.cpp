#include "Scientist.hpp"


using namespace std;
namespace pandemic
{
   
    Player& Scientist::discover_cure(Color c)
    {
        if (my_board.has_cure(c))
        {
            return *this;
        };
        int counter = 0;
        set<City> throw_cards;
        for (auto card: cards)
        {
            if (card.second == c)
            {
                counter++;
                throw_cards.insert(card.first);
            }; 
        };
        if (counter < x || !my_board.has_rs(my_city))
        {
            throw invalid_argument{"can't discover cure for this virus!"};
        };
        for (auto card: throw_cards)
        {
            cards.erase(card);
        };
        my_board.cure_this_color(c);
        return *this;
    };
        
}