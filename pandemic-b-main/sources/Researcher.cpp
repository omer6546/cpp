#include "Researcher.hpp"



using namespace std;
namespace pandemic
{
   
    Player& Researcher::discover_cure(Color c)
    {
        constexpr int five = 5;
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
        if (counter < five)
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