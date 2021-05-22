#include <string>
#include <array>
#include <iostream>
#include <stdexcept>
#include <map>
#include <limits.h>
#include <fstream>
#include "Board.hpp"
#include <set>


using namespace std;
using namespace pandemic;

    map<City ,set<City>> cities_ni;
    map<City ,enum Color> cities_color;
    map<enum Color, bool> found_cure;
    map<City,int> sickness_level;
    map<City,bool> research_station;
    map<string, City> oof;

    
    Board::Board()
    {
        ifstream file{"cities_map.txt"};
        init_oof();
        for (auto &x:oof)
        {
            sickness_level[x.second] = 0;
            research_station[x.second] = false;
        };
        found_cure[Color::Black] = false;
        found_cure[Color::Blue] = false;
        found_cure[Color::Red] = false;
        found_cure[Color::Yellow] = false;

         
    };

    Board::~Board(){}

    bool Board::is_clean()
    {
        for (auto lev: sickness_level)
        {
            if (lev.second > 0)
            {
                return false;
            };
        };
        return true;
    };

    int& Board::operator[](City c){return sickness_level[c];};

    ostream& pandemic::operator<<(ostream &out, const Board &b)
    {
        out << "~~~~~~~~~~~~~~~~~~~ pandemic report ~~~~~~~~~~~~~~~~~~~" << endl;
        out << endl << "sickness level by cities:" << endl;
        for (auto &city : oof)
        {
            out << city.first << ":" << "   " << sickness_level[city.second] << endl;
        };
        out << endl << "cures found:" << endl;
        for (auto cure : found_cure)
        {
            if (cure.second)
            {
                if (cure.first == Color::Black)
                {
                    out << "-black" << endl;
                };
                if (cure.first == Color::Blue)
                {
                    out << "-blue" << endl;
                };
                if (cure.first == Color::Red)
                {
                    out << "-red" << endl;
                };
                if (cure.first == Color::Yellow)
                {
                    out << "-yellow" << endl;
                };

            };
        };
        out << endl << "we built research stations in the following cities:" << endl;
        for (auto &city : oof)
        {
            if (research_station[city.second])
            {
                out << city.first << endl;
            };
        };

        return out;
    }

    bool Board::my_ni(City c, City n)
    {
        set<City> nis = cities_ni[c];
        bool flag = false;
        if (nis.find(n) != nis.end()) {flag = true;};
        return flag;
    };
    
    bool Board::has_rs (City c)
    {
        return research_station[c];
    };

    void Board::build_rs(City c)
    {
        research_station[c] = true;
    };

    bool Board::has_cure(Color c)
    {
        return(found_cure[c]);
    };

    void Board::cure_this_color (Color c)
    {
        found_cure[c] = true;
    };

    int Board::get_sick_level(City c)
    {
        return sickness_level[c];
    };
    
    Color Board::get_color(City c)
    {
        return cities_color[c];
    };

    void Board::set_sick_level(City c, int i)
    {
        sickness_level[c] = i;
    };

    void Board::remove_cures()
    {
        found_cure[Color::Black] = false;
        found_cure[Color::Blue] = false;
        found_cure[Color::Red] = false;
        found_cure[Color::Yellow] = false;

    };
    
    void Board::remove_stations()
    {
        for (auto rs: research_station)
        {
            research_station[rs.first] = false;
        };
    };

    void Board::init_oof()
    {
        oof["Algiers"] = City::Algiers;
        cities_color[City::Algiers] = Color::Black;
        cities_ni[City::Algiers].insert(City::Madrid);
        cities_ni[City::Algiers].insert(City::Paris);
        cities_ni[City::Algiers].insert(City::Istanbul);
        cities_ni[City::Algiers].insert(City::Cairo);
        
        oof["Atlanta"] = City::Atlanta;
        cities_color[City::Atlanta] = Color::Blue;
        cities_ni[City::Atlanta].insert(City::Chicago);
        cities_ni[City::Atlanta].insert(City::Miami);
        cities_ni[City::Atlanta].insert(City::Washington);
        
        oof["Baghdad"] = City::Baghdad;
        cities_color[City::Baghdad] = Color::Black;
        cities_ni[City::Baghdad].insert(City::Tehran);
        cities_ni[City::Baghdad].insert(City::Istanbul);
        cities_ni[City::Baghdad].insert(City::Cairo);
        cities_ni[City::Baghdad].insert(City::Riyadh);
        cities_ni[City::Baghdad].insert(City::Karachi);
        
        oof["Bangkok"] = City::Bangkok;
        cities_color[City::Bangkok] = Color::Red;
        cities_ni[City::Bangkok].insert(City::Kolkata);
        cities_ni[City::Bangkok].insert(City::Chennai);
        cities_ni[City::Bangkok].insert(City::Jakarta);
        cities_ni[City::Bangkok].insert(City::HoChiMinhCity);
        cities_ni[City::Bangkok].insert(City::HongKong);
        
        oof["Beijing"] = City::Beijing;
        cities_color[City::Beijing] = Color::Red;
        cities_ni[City::Beijing] = {City::Shanghai, City::Seoul};
        
        oof["Bogota"] = City::Bogota;
        cities_color[City::Bogota] = Color::Yellow;
        cities_ni[City::Bogota] = {City::MexicoCity, City::Lima, City::Miami, City::SaoPaulo, City::BuenosAires};
        
        oof["BuenosAires"] = City::BuenosAires;
        cities_color[City::BuenosAires] = Color::Yellow;
        cities_ni[City::BuenosAires] = {City::Bogota, City::SaoPaulo};
        
        oof["Cairo"] = City::Cairo;
        cities_color[City::Cairo] = Color::Black;
        cities_ni[City::Cairo] = {City::Algiers, City::Istanbul, City::Baghdad, City::Khartoum, City::Riyadh};
        
        oof["Chennai"] = City::Chennai;
        cities_color[City::Chennai] = Color::Black;
        cities_ni[City::Chennai] = {City::Mumbai, City::Delhi, City::Kolkata, City::Bangkok, City::Jakarta};
        oof["Chicago"] = City::Chicago;
        cities_color[City::Chicago] = Color::Blue;
        cities_ni[City::Chicago] ={City::SanFrancisco, City::LosAngeles, City::MexicoCity, City::Atlanta, City::Montreal};
        
        oof["Delhi"] = City::Delhi;
        cities_color[City::Delhi] = Color::Black;
        cities_ni[City::Delhi] = {City::Tehran, City::Karachi, City::Mumbai, City::Chennai, City::Kolkata};
        
        oof["Essen"] = City::Essen;
        cities_color[City::Essen] = Color::Blue;
        cities_ni[City::Essen] = {City::London, City::Paris, City::Milan, City::StPetersburg};
        
        oof["HoChiMinhCity"] = City::HoChiMinhCity;
        cities_color[City::HoChiMinhCity] = Color::Red;
        cities_ni[City::HoChiMinhCity] = {City::Jakarta, City::Bangkok, City::HongKong, City::Manila};
        
        oof["HongKong"] = City::HongKong;
        cities_color[City::HongKong] = Color::Red;
        cities_ni[City::HongKong] = {City::Bangkok, City::Kolkata, City::HoChiMinhCity, City::Shanghai, City::Manila, City::Taipei};
        
        oof["Istanbul"] = City::Istanbul;
                cities_color[City::Istanbul] = Color::Black;

        cities_ni[City::Istanbul] = {City::Milan, City::Algiers, City::StPetersburg, City::Cairo, City::Baghdad, City::Moscow};
        
        oof["Jakarta"] = City::Jakarta;
                cities_color[City::Jakarta] = Color::Red;

        cities_ni[City::Jakarta] = {City::Chennai, City::Bangkok, City::HoChiMinhCity, City::Sydney};
        
        oof["Johannesburg"] = City::Johannesburg;
                cities_color[City::Johannesburg] = Color::Yellow;

        cities_ni[City::Johannesburg] = {City::Kinshasa, City::Khartoum};
        oof["Karachi"] = City::Karachi;
                cities_color[City::Karachi] = Color::Black;

        cities_ni[City::Karachi] = {City::Tehran, City::Baghdad, City::Riyadh, City::Mumbai, City::Delhi};
        oof["Khartoum"] = City::Khartoum;
                cities_color[City::Khartoum] = Color::Yellow;

        cities_ni[City::Khartoum] = {City::Cairo, City::Lagos, City::Kinshasa, City::Johannesburg};
        oof["Kinshasa"] = City::Kinshasa;
        cities_color[City::Kinshasa] = Color::Yellow;
        cities_ni[City::Kinshasa] = {City::Lagos, City::Khartoum, City::Johannesburg};
        
        oof["Kolkata"] = City::Kolkata;
        cities_color[City::Kolkata] = Color::Black;
        cities_ni[City::Kolkata] = {City::Delhi, City::Chennai, City::Bangkok, City::HongKong};
        
        oof["Lagos"] = City::Lagos;
        cities_color[City::Lagos] = Color::Yellow;
        cities_ni[City::Lagos] = {City::SaoPaulo, City::Khartoum, City::Kinshasa};
        
        oof["Lima"] = City::Lima;
        cities_color[City::Lima] = Color::Yellow;
        cities_ni[City::Lima] = {City::MexicoCity, City::Bogota, City::Santiago};
        
        oof["London"] = City::London;
        cities_color[City::London] = Color::Blue;
        cities_ni[City::London] = {City::NewYork, City::Madrid, City::Essen, City::Paris};
        
        oof["LosAngeles"] = City::LosAngeles;
        cities_color[City::LosAngeles] = Color::Yellow;
        cities_ni[City::LosAngeles] = {City::SanFrancisco, City::Chicago, City::MexicoCity, City::Sydney};
        
        oof["Madrid"] = City::Madrid;
        cities_color[City::Madrid] = Color::Blue;
        cities_ni[City::Madrid] = {City::London, City::NewYork, City::Paris, City::SaoPaulo, City::Algiers};
        
        oof["Manila"] = City::Manila;
        cities_color[City::Manila] = Color::Red;
        cities_ni[City::Manila] = {City::HongKong, City::Taipei, City::SanFrancisco, City::HoChiMinhCity, City::Sydney};
        
        oof["MexicoCity"] = City::MexicoCity;
        cities_color[City::MexicoCity] = Color::Yellow;
        cities_ni[City::MexicoCity] = {City::LosAngeles, City::Chicago, City::Miami, City::Lima, City::Bogota};
        
        oof["Miami"] = City::Miami;
        cities_color[City::Miami] = Color::Yellow;
        cities_ni[City::Miami] = {City::Atlanta, City::MexicoCity, City::Washington, City::Bogota};
        
        oof["Milan"] = City::Milan;
        cities_ni[City::Milan] = {City::Essen, City::Paris, City::Istanbul};        
        cities_color[City::Milan] = Color::Blue;

        
        oof["Montreal"] = City::Montreal;
        cities_color[City::Montreal] = Color::Blue;
        cities_ni[City::Montreal] = {City::Chicago, City::Washington, City::NewYork};
        
        oof["Moscow"] = City::Moscow;
        cities_color[City::Moscow] = Color::Black;
        cities_ni[City::Moscow] = {City::StPetersburg, City::Istanbul, City::Tehran};
        
        oof["Mumbai"] = City::Mumbai;
        cities_color[City::Mumbai] = Color::Black;
        cities_ni[City::Mumbai] = {City::Karachi, City::Delhi, City::Chennai};
        
        oof["NewYork"] = City::NewYork;
        cities_color[City::NewYork] = Color::Blue;
        cities_ni[City::NewYork] = {City::Montreal, City::Washington, City::London, City::Madrid};
        
        oof["Osaka"] = City::Osaka;
        cities_color[City::Osaka] = Color::Red;
        cities_ni[City::Osaka] ={City::Taipei, City::Tokyo};
        
        oof["Paris"] = City::Paris;
        cities_color[City::Paris] = Color::Blue;
        cities_ni[City::Paris] = {City::Algiers, City::Essen, City::Madrid, City::Milan, City::London};
        
        oof["Riyadh"] = City::Riyadh;
        cities_color[City::Riyadh] = Color::Black;
        cities_ni[City::Riyadh] = {City::Baghdad, City::Cairo, City::Karachi};
        
        oof["SanFrancisco"] = City::SanFrancisco;
        cities_color[City::SanFrancisco] = Color::Blue;
        cities_ni[City::SanFrancisco] = {City::LosAngeles, City::Chicago, City::Tokyo, City::Manila};
        
        oof["Santiago"] = City::Santiago;
        cities_color[City::Santiago] = Color::Yellow;
        cities_ni[City::Santiago] = {City::Lima};
        
        oof["SaoPaulo"] = City::SaoPaulo;
        cities_color[City::SaoPaulo] = Color::Yellow;
        cities_ni[City::SaoPaulo] = {City::Bogota, City::BuenosAires, City::Lagos, City::Madrid};
        
        oof["Seoul"] = City::Seoul;
        cities_color[City::Seoul] = Color::Red;
        cities_ni[City::Seoul] = {City::Beijing, City::Shanghai, City::Tokyo};
        
        oof["Shanghai"] = City::Shanghai;
        cities_color[City::Shanghai] = Color::Red;
        cities_ni[City::Shanghai] = {City::Beijing, City::HongKong, City::Taipei, City::Seoul, City::Tokyo};
        
        oof["StPetersburg"] = City::StPetersburg;
        cities_color[City::StPetersburg] = Color::Blue;
        cities_ni[City::StPetersburg] = {City::Essen, City::Istanbul, City::Moscow};
        
        oof["Sydney"] = City::Sydney;
        cities_color[City::Sydney] = Color::Red;
        cities_ni[City::Sydney] = {City::Jakarta, City::Manila, City::LosAngeles};
        
        oof["Taipei"] = City::Taipei;
        cities_color[City::Taipei] = Color::Red;
        cities_ni[City::Taipei] = {City::Shanghai, City::HongKong, City::Osaka, City::Manila};
        
        oof["Tehran"] = City::Tehran;
        cities_color[City::Tehran] = Color::Black;
        cities_ni[City::Tehran] = {City::Baghdad, City::Moscow, City::Karachi, City::Delhi};
        
        oof["Tokyo"] = City::Tokyo;
        cities_color[City::Tokyo] = Color::Red;
        cities_ni[City::Tokyo] = {City::Seoul, City::Shanghai, City::Osaka, City::SanFrancisco};
        
        oof["Washington"] = City::Washington;
        cities_color[City::Washington] = Color::Blue;
        cities_ni[City::Washington] = {City::Atlanta, City::NewYork, City::Montreal, City::Miami};


    };


