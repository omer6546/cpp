#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <stdbool.h>
#include "NumberWithUnits.hpp"

using namespace std;
namespace ariel{
    
    NumberWithUnits::NumberWithUnits(double v,const string u)
    {
        if(m.find(u) == m.end()){
            throw invalid_argument{"unit not found"};
            }
            this->val = v;
            this->unit = u;
    };

    void NumberWithUnits::read_units(ifstream &units_file)
    {
        string line;
        
        while (getline(units_file, line))
        {
            string word1, word2, strval;
            ulong i = 2;
            while (line.at(i) != ' ')
            {
                word1 += line.at(i);
                i++;
            };
            while (line.at(i) == ' ' || line.at(i) == '=')
            {
                i++;
            };
            while (isdigit(line.at(i)))
            {

                strval += line.at(i);
                i++;
            };
            double dobval = atof(strval.c_str());
            i++;
            while (i<line.length())
            {
                word2 += line.at(i);
                i++;
            };
            m[word1][word2] = dobval;
            m[word2][word1] = 1/dobval;
            
            
            for (auto map: m[word1])
            {
                if (map.first != word1 && map.first != word2)
                {
                    m[word2][map.first] = m[word2][word1] * map.second;
                    m[map.first][word2] = 1/(m[word2][word1] * map.second);

                };
            };
            for (auto map: m[word2])
            {
                if (map.first != word1 && map.first != word2)
                {
                    m[word1][map.first] = m[word1][word2] * map.second;
                    m[map.first][word1] = 1/(m[word1][word2] * map.second);
                }
            };
            for (auto map: m)
            {
                for (auto layer2: map.second)
                {
                    for (auto layer3: m[layer2.first])
                    {
                        
                        if (layer3.first != map.first && m[map.first].find(layer3.first) ==  m[map.first].end() /*&& m[layer3.first].find(map.first) != m[layer3.first].end()*/)
                        {   
                            m[map.first][layer3.first] = layer3.second * m[map.first][layer2.first];
                            m[layer3.first][map.first] = 1/(layer3.second * m[map.first][layer2.first]);
                        };
                    };
                };
            };
        };
    };

    double convertunit(double newval, const string a, const string b)
    {
        if (a==b)
        {
            return newval;
        };
        if (m[a].find(b) != m[a].end())
        {
            return newval*m[a][b];
        };
        throw invalid_argument{"cannot convert units"};
    };
    
    NumberWithUnits NumberWithUnits::operator+(const NumberWithUnits &b)
    {
        double v = convertunit(b.val, b.unit, this->unit);
        return NumberWithUnits(v+this->val, this->unit);
    };
    NumberWithUnits &NumberWithUnits::operator+= (const NumberWithUnits &b)
    {
        double v = convertunit(b.val, b.unit, this->unit);
        this->val += v;
        return *this;
    };
    NumberWithUnits NumberWithUnits::operator+ (){return *this;};
    NumberWithUnits NumberWithUnits::operator- (const NumberWithUnits &b)
    {
        double v = convertunit(b.val, b.unit, this->unit);
        return NumberWithUnits(v-this->val, this->unit);
    };
    NumberWithUnits &NumberWithUnits::operator-= (const NumberWithUnits &b)
    {
        double v = convertunit(b.val, b.unit, this->unit);
        this->val -= v;
        return *this;
    };
    NumberWithUnits NumberWithUnits::operator- (){return NumberWithUnits((-1)*this->val, this->unit);;};
    bool NumberWithUnits::operator< (const NumberWithUnits &b) const
    {
        double v = convertunit(b.val, b.unit, this->unit);
        return this->val < v;
    };
    bool NumberWithUnits::operator<= (const NumberWithUnits &b) const
    {
        double v = convertunit(b.val, b.unit, this->unit);
        return (this->val < v || this->val == v);
    };
    bool NumberWithUnits::operator> (const NumberWithUnits &b) const 
    {
        double v = convertunit(b.val, b.unit, this->unit);
        return this->val > v;
    };
    bool NumberWithUnits::operator>= (const NumberWithUnits &b) const
    {
        double v = convertunit(b.val, b.unit, this->unit);
        return (this->val > v || this->val == v);
    };
    bool NumberWithUnits::operator== (const NumberWithUnits &b) const
    {
        double v = convertunit(b.val, b.unit, this->unit);
        return (this->val == v);
    };
    bool NumberWithUnits::operator!= (const NumberWithUnits &b) const
    {
        double v = convertunit(b.val, b.unit, this->unit);
        return (this->val != v);
    };
    NumberWithUnits NumberWithUnits::operator++(int b)
    {
        return NumberWithUnits((this->val)+b, this->unit);
    };
    NumberWithUnits &NumberWithUnits::operator++()
    {
        this ->val++;
        return *this;
    };
    NumberWithUnits NumberWithUnits::operator--(int b)
    {
        return NumberWithUnits((this->val)-b, this->unit);
    };
    NumberWithUnits &NumberWithUnits::operator--()
    {
        this ->val--;
        return *this;
    };   
    NumberWithUnits operator*(double n, const NumberWithUnits &b)
    {
        return NumberWithUnits(b.val*n, b.unit);
    };
    NumberWithUnits operator*(const NumberWithUnits &b ,double n)
    {
        return NumberWithUnits(n*b.val, b.unit);
    };
    NumberWithUnits& NumberWithUnits:: operator*=(double n)
    {
        this->val *= n;
        return *this;
    }
    istream &operator>> (istream &in, NumberWithUnits &b)
    {
        int i = 0;
        return (in >> i);
    };
    ostream &operator<< (ostream &out, const NumberWithUnits &b)
    {
        out << b.val << "[" << b.unit << "]";
        return out;
    };
};

/*
int main(int argc, char** argv) {
    ifstream units_MyFile{"units.txt"};
    ariel::NumberWithUnits::read_units(units_MyFile);
    ariel::NumberWithUnits a(1, "m");
    ariel::NumberWithUnits b(1, "km");
    ariel::NumberWithUnits g(5, "g");
    cout << 5*a << endl;
    cout << a*5 << endl;
    cout << a+g << endl;
}*/