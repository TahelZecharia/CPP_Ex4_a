#include "doctest.h"
#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include "Game.hpp"

using namespace coup;

#include <stdexcept>
#include <exception>
using namespace std;




TEST_CASE("Game"){

    Game game{};
    Duke duke1{game, "player 1"};
	Assassin assassin2{game, "player 2"};
	Ambassador ambassador3{game, "player 3"};
	Captain captain4{game, "player 4"};
	Contessa contessa5{game, "player 5"};

    SUBCASE("Contruuctor"){

        CHECK_THROWS(Assassin assassin(game, "player 5")); // name already exist.

        CHECK_NOTHROW(Duke duke6(game, "player 6"));
        
        CHECK_THROWS(Assassin assassin(game, "player 7")); // to much players.
    }

    SUBCASE("Game"){
        
        CHECK(duke1.coins() == 0);
        CHECK_NOTHROW(duke1.income()); 
        CHECK(duke1.coins() == 1);
        CHECK_THROWS(duke1.income());

        CHECK(assassin2.coins() == 0);
        CHECK_NOTHROW(assassin2.foreign_aid()); 
        CHECK(assassin2.coins() == 2);
        CHECK_THROWS(assassin2.income());

        CHECK(ambassador3.coins() == 0);
        CHECK_NOTHROW(ambassador3.income()); 
        CHECK(ambassador3.coins() == 1);
        CHECK_THROWS(ambassador3.income());

        CHECK(captain4.coins() == 0);
        CHECK_NOTHROW(captain4.foreign_aid()); 
        CHECK(captain4.coins() == 2);
        CHECK_THROWS(captain4.income());

        CHECK(contessa5.coins() == 0);
        CHECK_NOTHROW(contessa5.foreign_aid()); 
        CHECK(contessa5.coins() == 2);
        CHECK_THROWS(contessa5.income());

    }


}

