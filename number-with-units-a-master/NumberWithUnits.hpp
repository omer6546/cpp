#include <iostream>
#include <string>
#include <stdbool.h>


using namespace std;
namespace ariel{
    class NumberWithUnits{

        private:
            double val;       
            string unit; 

        public:
            NumberWithUnits(double v, string u) : val(v), unit(u) {};
            static void read_units(ifstream &units_file);
            NumberWithUnits operator+ (const NumberWithUnits &b);
            NumberWithUnits &operator+= (const NumberWithUnits &b);
            NumberWithUnits operator+ ();
            NumberWithUnits operator- (const NumberWithUnits &b);
            NumberWithUnits &operator-= (const NumberWithUnits &b);
            NumberWithUnits operator- ();
            bool operator< (const NumberWithUnits &b) const;
            bool operator<= (const NumberWithUnits &b) const;
            bool operator> (const NumberWithUnits &b) const;
            bool operator>= (const NumberWithUnits &b) const;
            bool operator== (const NumberWithUnits &b) const;
            bool operator!= (const NumberWithUnits &b) const;
            NumberWithUnits operator++(int b);
            NumberWithUnits &operator++();
            NumberWithUnits operator--(int b);
            NumberWithUnits &operator--();
            friend NumberWithUnits operator* (double n, NumberWithUnits &b);
            friend istream &operator>> (istream &in, NumberWithUnits &b);
            friend ostream &operator<< (ostream &out, const NumberWithUnits &b);


    };
};