#include <iostream>
#include <string>
#include <stdbool.h>
#include "NumberWithUnits.hpp"

using namespace std;
namespace ariel{
    void NumberWithUnits::read_units(ifstream &units_file){};
    NumberWithUnits NumberWithUnits::operator+(const NumberWithUnits &b){return *this;};
    NumberWithUnits &NumberWithUnits::operator+= (const NumberWithUnits &b){return *this;};
    NumberWithUnits NumberWithUnits::operator+ (){return *this;};
    NumberWithUnits NumberWithUnits::operator- (const NumberWithUnits &b){return *this;};
    NumberWithUnits &NumberWithUnits::operator-= (const NumberWithUnits &b){return *this;};
    NumberWithUnits NumberWithUnits::operator- (){return *this;};
    bool NumberWithUnits::operator< (const NumberWithUnits &b) const{return false;};
    bool NumberWithUnits::operator<= (const NumberWithUnits &b) const{return false;};
    bool NumberWithUnits::operator> (const NumberWithUnits &b) const{return false;};
    bool NumberWithUnits::operator>= (const NumberWithUnits &b) const{return false;};
    bool NumberWithUnits::operator== (const NumberWithUnits &b) const{return false;};
    bool NumberWithUnits::operator!= (const NumberWithUnits &b) const{return false;};
    NumberWithUnits NumberWithUnits::operator++(int b){return *this;};
    NumberWithUnits &NumberWithUnits::operator++(){return *this;};
    NumberWithUnits NumberWithUnits::operator--(int b){return *this;};
    NumberWithUnits &NumberWithUnits::operator--(){return *this;};   
    NumberWithUnits operator*(double n, NumberWithUnits &b)
    {
        NumberWithUnits stam(2000, "USD");
        return stam;
    };
    istream &operator>> (istream &in, NumberWithUnits &b)
    {
        int i = 0;
        return (in >> i);
    };
    ostream &operator<< (ostream &out, const NumberWithUnits &b){return (out << "stam");};
};