
#include "Player.hpp"
//#define five  5


using namespace std;
namespace pandemic{
    constexpr int five = 5;

    Player& Player::drive(City c)
    {
        
        
        if (!my_board.my_ni(my_city, c))
        {
            throw invalid_argument{"can't drive to this city, it is too far!"};
        };
        my_city = c;
        return *this;
    }

    Player& Player::fly_direct(City c)
    {
        if (cards.find(c) ==  cards.end() || c == my_city)
        {
            throw invalid_argument{"can't fly to this city!"};
        };

        cards.erase(c);
        my_city = c;
        return *this;
    }
    
    Player& Player::fly_charter(City c)
    {
        if (cards.find(my_city) ==  cards.end() || c == my_city)
        {
            throw invalid_argument{"can't fly to this city!"};
        };

        cards.erase(my_city);
        my_city = c;
        return *this;
    }

    Player& Player::fly_shuttle(City c)
    {
        if ( !(my_board.has_rs(c) && my_board.has_rs(my_city)) || c == my_city)
        {
            throw invalid_argument{"can't fly to this city!"};
        };
        my_city = c;
        return *this;
    }

    Player& Player::build()
    {
        if (my_board.has_rs(my_city))
        {
            return *this;
        };
        if (cards.find(my_city) ==  cards.end())
        {
            throw invalid_argument{"can't build a research station in this city!"};
        };
        my_board.build_rs(my_city);
        cards.erase(my_city);
        return *this;
    }

    Player& Player::discover_cure(Color c)
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
        if (counter >= five && my_board.has_rs(my_city))
        {
            for (auto card: throw_cards)
            {
                cards.erase(card);
            };
            my_board.cure_this_color(c);
            return *this;
        };
        throw invalid_argument{"can't discover cure for this virus!"};
    }
    
    Player& Player::treat(City c)
    {
        if (my_board.get_sick_level(c) == 0)
        {
            throw invalid_argument{"this city is healthy, nothing to treat!"};
        };    
        if (my_city != c)
        {
            throw invalid_argument{"can't treat this virus if i'm not in the city!"};
        };
        if (my_board.has_cure(my_board.get_color(c)))
        {
            my_board.set_sick_level(c,0);
            return *this;
        };
        int x = my_board.get_sick_level(c);
        my_board.set_sick_level(c,x-1);
        return *this;
    }
    
    string Player::role(){return this->my_role;}
    
    Player& Player::take_card(City c)
    {
        if (cards.find(c) ==  cards.end())
        {
            cards[c] = my_board.get_color(c);
        };
        return *this;
    }

    void Player::remove_cards()
    {
        cards.clear();
    }

}


    
    
    