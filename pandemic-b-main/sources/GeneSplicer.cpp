#include "GeneSplicer.hpp"



using namespace std;
namespace pandemic
{
   
    Player& GeneSplicer::discover_cure(Color c)
    {
        constexpr int five = 5;
           if (my_board.has_cure(c))
        {
            return *this;
        };
        if (cards.size() < five )
        {
            throw invalid_argument{"can't discover cure for this virus!"};
        };
        if ( !my_board.has_rs(my_city))
        {
            throw invalid_argument{"can't discover cure for this virus!"};
        };
        int counter = 0;
        set<City> throw_cards;
        for (auto card: cards)
        {
            if (counter == five) {break;};
            counter++;
            throw_cards.insert(card.first);
        };
         for (auto card: throw_cards)
        {
            cards.erase(card);
        };
        my_board.cure_this_color(c);
        return *this;
    };
        
}