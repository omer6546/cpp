#include "doctest.h"
#include "Player.hpp"
#include <iostream>
#include <string>
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "Medic.hpp"
#include "Researcher.hpp"
#include "Scientist.hpp"
#include "Virologist.hpp"


using namespace std;
using namespace pandemic;

TEST_CASE("drive") {
    Board board;
    OperationsExpert player {board, City::Atlanta};
    CHECK_NOTHROW(player.drive(City::Chicago));
    CHECK_THROWS(player.drive(City::London));
}

TEST_CASE("fly_direct") {
    Board board;
    OperationsExpert player {board, City::Atlanta};
    player.build();
    player.take_card(City::Paris);
    CHECK_NOTHROW(player.fly_direct(City::Paris));
    CHECK_THROWS(player.fly_direct(City::London));
    Dispatcher player2 {board, City::Atlanta};
    CHECK_NOTHROW(player2.fly_direct(City::Chicago));
    CHECK_NOTHROW(player2.fly_direct(City::London));

}
TEST_CASE("fly_charter") {
    Board board;
    OperationsExpert player {board, City::Atlanta};
    player.take_card(City::Paris);
    CHECK_NOTHROW(player.fly_charter(City::Paris));
    CHECK_THROWS(player.fly_charter(City::Shanghai));
}
TEST_CASE("fly_shuttle") {
    Board board;
    OperationsExpert player {board, City::Atlanta};
    player.build();
    player.take_card(City::Atlanta);
    Dispatcher player2 {board, City::Atlanta};
    player2.build();
    CHECK_NOTHROW(player.fly_shuttle(City::Paris));
    CHECK_THROWS(player.fly_shuttle(City::London));
}

TEST_CASE("discover_cure") {
    Board board;
    OperationsExpert player {board, City::Atlanta};
    CHECK_NOTHROW(player.discover_cure(Color::Black));
    CHECK_THROWS(player.discover_cure(Color::Black));
}

TEST_CASE("treat") {
    Board board;
    board[City::Atlanta] = 3; 
    OperationsExpert player {board, City::Atlanta};
    player.build();
    player.take_card(City::Atlanta);
    player.take_card(City::Madrid);
    player.take_card(City::Paris);
    player.take_card(City::London);
    CHECK_THROWS(player.treat(City::Atlanta));
    player.take_card(City::NewYork);
    CHECK_NOTHROW(player.treat(City::Atlanta));

    Scientist player2 {board, City::Tehran, 3};
    player2.build();
    player2.take_card(City::Tehran);
    player2.take_card(City::Moscow);
    CHECK_THROWS(player2.treat(City::Tehran));
    player2.take_card(City::Baghdad);
    CHECK_NOTHROW(player2.treat(City::Tehran));
    
    Researcher player3 {board, City::Shanghai};
    player3.take_card(City::Shanghai);
    player3.take_card(City::Seoul);
    player3.take_card(City::Tokyo);
    player3.take_card(City::Beijing);
    player3.take_card(City::Taipei);
    CHECK_NOTHROW(player3.treat(City::Shanghai));

    GeneSplicer player4 {board, City::Kinshasa};
    player4.take_card(City::Kinshasa);
    player4.take_card(City::Lagos);
    player4.take_card(City::Johannesburg);
    player4.take_card(City::SaoPaulo);
    CHECK_THROWS(player4.treat(City::Kinshasa));
    player4.take_card(City::SanFrancisco);
    CHECK_THROWS(player4.treat(City::Kinshasa));
    player4.build();
    CHECK_NOTHROW(player4.treat(City::Kinshasa));
    
}
TEST_CASE("role") {
    Board board;
    OperationsExpert player {board, City::Atlanta};
    CHECK(player.role() == "OperationsExpert");
    
    
}

