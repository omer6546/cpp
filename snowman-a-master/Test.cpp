#include "doctest.h"
#include "snowman.hpp"
#include <string>
#include <algorithm>
using namespace ariel;


string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}


TEST_CASE("Good snowman code") {
    CHECK(nospaces(snowman(11111111)) == nospaces("_===_\n(.,.)\n<( : )>\n( : )"));
    CHECK(nospaces(snowman(21114411)) == nospaces(" --- \n.....\n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(14114411)) == nospaces("_===_\n(. .)\n( : )\n( : )"));
    CHECK(nospaces(snowman(12111111)) == nospaces("_===_\n(...)\n<( : )>\n( : )"));
    CHECK(nospaces(snowman(13114411)) == nospaces("_===_\n(._.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(11444411)) == nospaces("_===_\n(-,-)\n( : )\n( : )"));
    CHECK(nospaces(snowman(11234411)) == nospaces("_===_\n(o,O)\n( : )\n( : )"));
    CHECK(nospaces(snowman(11434411)) == nospaces("_===_\n(-,O)\n( : )\n( : )"));
    CHECK(nospaces(snowman(11114421)) == nospaces("_===_\n(.,.)\n(] [)\n( : )"));
    CHECK(nospaces(snowman(11114431)) == nospaces("_===_\n(.,.)\n(> <)\n( : )"));
    CHECK(nospaces(snowman(11114441)) == nospaces("_===_\n(.,.)\n(   )\n( : )"));
    CHECK(nospaces(snowman(11114433)) == nospaces("_===_\n(.,.)\n(> <)\n(___)"));
    CHECK(nospaces(snowman(11114414)) == nospaces("_===_\n(.,.)\n( : )\n(   )"));
    CHECK(nospaces(snowman(11112211)) == nospaces("_===_\n/(.,.)/\n( : )\n( : )"));
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
    
}
    


TEST_CASE("Bad snowman code") {
    CHECK_THROWS_AS(snowman(1231231), std::length_error);
    CHECK_THROWS_AS(snowman(123123123), std::length_error);
    //CHECK_THROWS_AS(snowman("abcdefgh"), std::invalid_argument);
    CHECK_THROWS_AS(snowman(12345123), std::out_of_range);
    CHECK_THROWS_AS(snowman(55555555), std::out_of_range);
    CHECK_THROWS_AS(snowman(89123), std::out_of_range);
    CHECK_THROWS_AS(snowman(-2), std::out_of_range);
    CHECK_THROWS(snowman(12311231)); /*toomanyarms*/
    CHECK_THROWS(snowman(12314331)); /*toomanyarms*/
    CHECK_THROWS(snowman(12313431)); /*toomanyarms*/
}

