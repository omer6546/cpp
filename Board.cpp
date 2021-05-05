#include <string>
#include <array>
#include <iostream>
#include <stdexcept>
#include <map>
#include <limits.h>
#include <fstream>
#include "Board.hpp"

using namespace std;
using namespace pandemic;

    map<City ,City(*)[6]> cities_ni;
    map<City ,enum Color> cities_color;
    map<enum Color ,bool> found_cure;
    map<City,int> sickness_level;
    map<City,bool> research_station;
    map<string, City> oof;

    
    Board::Board(){};
    Board::~Board(){}
    bool Board::is_clean(){return false;};
    int& Board::operator[](City c){return sickness_level[c];};
    ostream& pandemic::operator<<(ostream &out, const Board &b){{return (out << "stam");};}
    
    void init_cities(ifstream &city_list)
    {
        string line;
        while (getline(city_list, line))
        {
            string name, color;
            string ni[6];
            for (ulong l=0; l<6 ;l++)
            {
                ni[l] = "null";
            };
            int n = 0;
            ulong i = 0;
            while (line.at(i) != ' ')
            {
                name += line.at(i);
                i++;
            };
            i++;
            while (line.at(i) != ' ')
            {
                color += line.at(i);
                i++;
            };
            i++;
            for (ulong j=i; j<line.length(); j++)
            {
                if (line.at(j) != ' ')
                {
                    ni[n]+= line.at(j);
                };
                if (line.at(j) == ' ')
                {
                    n++;
                };
            };
            City builder[6];
            int b_count = 0;
            for (int l=0; l<6 ;l++)
            {
                if (ni[l] == "null") break;
                builder[l] = oof[ni[l]];
            };
            City x = oof[name];
            cities_ni[x] = &builder;
            if (color == "Yellow")
            {
                cities_color[x] = Color::Yellow;
            };
            if (color == "Red")
            {
                cities_color[x] = Color::Red;
            };
            if (color == "Black")
            {
                cities_color[x] = Color::Black;
            };
            if (color == "Blue")
            {
                cities_color[x] = Color::Blue;
            };
            sickness_level[x] = 0;
            research_station[x] = 0;
            
        };
    
    };

    void remove_cure()
    {
        for (auto lev: found_cure)
        {
            lev.second = false;
        };
    };
    
    void init_oof()
    {
        oof["Algiers"] = City::Algiers;
        oof["Atlanta"] = City::Atlanta;
        oof["Baghdad"] = City::Baghdad;
        oof["Bangkok"] = City::Bangkok;
        oof["Beijing"] = City::Beijing;
        oof["Bogota"] = City::Bogota;
        oof["BuenosAires"] = City::BuenosAires;
        oof["Cairo"] = City::Cairo;
        oof["Chennai"] = City::Chennai;
        oof["Chicago"] = City::Chicago;
        oof["Delhi"] = City::Delhi;
        oof["Essen"] = City::Essen;
        oof["HoChiMinhCity"] = City::HoChiMinhCity;
        oof["HongKong"] = City::HongKong;
        oof["Istanbul"] = City::Istanbul;
        oof["Jakarta"] = City::Jakarta;
        oof["Johannesburg"] = City::Johannesburg;
        oof["Karachi"] = City::Karachi;
        oof["Khartoum"] = City::Khartoum;
        oof["Kinshasa"] = City::Kinshasa;
        oof["Kolkata"] = City::Kolkata;
        oof["Lagos"] = City::Lagos;
        oof["Lima"] = City::Lima;
        oof["London"] = City::London;
        oof["LosAngeles"] = City::LosAngeles;
        oof["Madrid"] = City::Madrid;
        oof["Manila"] = City::Manila;
        oof["MexicoCity"] = City::MexicoCity;
        oof["Miami"] = City::Miami;
        oof["Milan"] = City::Milan;
        oof["Montreal"] = City::Montreal;
        oof["Moscow"] = City::Moscow;
        oof["Mumbai"] = City::Mumbai;
        oof["NewYork"] = City::NewYork;
        oof["Osaka"] = City::Osaka;
        oof["Paris"] = City::Paris;
        oof["Riyadh"] = City::Riyadh;
        oof["SanFrancisco"] = City::SanFrancisco;
        oof["Santiago"] = City::Santiago;
        oof["SaoPaulo"] = City::SaoPaulo;
        oof["Seoul"] = City::Seoul;
        oof["Shanghai"] = City::Shanghai;
        oof["StPetersburg"] = City::StPetersburg;
        oof["Sydney"] = City::Sydney;
        oof["Taipei"] = City::Taipei;
        oof["Tehran"] = City::Tehran;
        oof["Tokyo"] = City::Tokyo;
        oof["Washington"] = City::Washington;
    };

