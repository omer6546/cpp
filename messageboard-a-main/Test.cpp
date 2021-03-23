#include "doctest.h"
#include "Board.hpp"
#include <string>
#include <algorithm>
#include <iostream>
#include "Direction.hpp"
using namespace std;
using namespace ariel;


ariel::Board testboard;

TEST_CASE("Good board code") {
    CHECK(testboard.read(0,0,Direction::Vertical,2) == "__");
    CHECK(testboard.read(0,0,Direction::Horizontal,5) == "_____");
    testboard.post(2,2,Direction::Vertical,"xyz");
    CHECK(testboard.read(2,2,Direction::Vertical,2) == "xy");
    CHECK(testboard.read(2,2,Direction::Vertical,4) == "xyz_");
    CHECK(testboard.read(1,4,Direction::Horizontal,3) == "_z_");
    testboard.post(0,4,Direction::Horizontal,"hello");
    CHECK(testboard.read(2,2,Direction::Vertical,3) == "xyl");
    CHECK(testboard.read(0,4,Direction::Horizontal,4) == "hell");//;)
    testboard.post(2,1,Direction::Vertical,"world");
    CHECK(testboard.read(0,4,Direction::Horizontal,5) == "hello");
    CHECK(testboard.read(2,1,Direction::Vertical,5) == "world");
    CHECK(testboard.read(0,3,Direction::Vertical,3) == "_h_");
    CHECK(testboard.read(5,0,Direction::Vertical,5) == "_____");
    CHECK(testboard.read(3,0,Direction::Vertical,6) == "____l_");
    CHECK(testboard.read(0,5,Direction::Vertical,6) == "__d___");
    CHECK(testboard.read(4,0,Direction::Vertical,6) == "____o_");
}
    


TEST_CASE("Bad board code") {
    CHECK_THROWS(testboard.post(-1,2,Direction::Horizontal,"2"));
    CHECK_THROWS(testboard.post(1,-2,Direction::Vertical,"2"));
    CHECK_THROWS(testboard.read(-1,2,Direction::Horizontal,2));
    CHECK_THROWS(testboard.read(1,-2,Direction::Vertical,2));
    CHECK_THROWS(testboard.read(-1,-2,Direction::Vertical,2));
    CHECK_THROWS(testboard.post(-1,-2,Direction::Vertical,"2"));  
}

