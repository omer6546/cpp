#include "doctest.h"
#include "NumberWithUnits.hpp"
#include <iostream>
#include <string>

using namespace std;
using namespace ariel;

TEST_CASE("Good units code") {
    NumberWithUnits g(1, "g");
    NumberWithUnits g2(2, "g");
    CHECK((g<g2) == true);
    CHECK((g<=g2) == true);
    CHECK((g>g2) == false);
    CHECK((g>=g2) == false);
    CHECK((g2+g) == g);
    CHECK((g2-g) == g);
    CHECK((-g2) == g);
    CHECK((g++) == g);
    CHECK((g2--) == g);
    CHECK((3*g) == g);
}
    


TEST_CASE("Bad units code") {
    CHECK_THROWS(NumberWithUnits unit_cm(1, "Cm"));
    CHECK_THROWS(NumberWithUnits unit_cm(1, "SEc"));
    CHECK_THROWS(NumberWithUnits unit_cm(1, "usd"));
    CHECK_THROWS(NumberWithUnits unit_cm(1, "stam"));
    CHECK_THROWS(NumberWithUnits unit_cm(1, "CM"));
    NumberWithUnits m(1, "m");
    NumberWithUnits sec(1, "sec");
    CHECK_THROWS(cout << (m+sec) << endl);
    CHECK_THROWS(cout << (m-sec) << endl);
    CHECK_THROWS(cout << (m<sec) << endl);
    CHECK_THROWS(cout << (m>sec) << endl);
    CHECK_THROWS(cout << (m==sec) << endl);
}