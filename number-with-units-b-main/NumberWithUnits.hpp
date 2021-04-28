#include <iostream>
#include <string>
#include <map>
#include <stdbool.h>


using namespace std;
namespace ariel{
    static map<string ,map<string ,double>> m;
    class NumberWithUnits{
        
        private:
            double val;       
            string unit; 
    
        public:
            NumberWithUnits(double v, const string u);
            //~NumberWithUnits();
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
            friend NumberWithUnits operator* (double n, const NumberWithUnits &b);
            friend NumberWithUnits operator*(const NumberWithUnits &b ,double n);
            NumberWithUnits &operator*=(double n);
            friend istream &operator>> (istream &in, NumberWithUnits &b);
            friend ostream &operator<< (ostream &out, const NumberWithUnits &b);


    };
};