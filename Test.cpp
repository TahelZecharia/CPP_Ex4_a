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
    Duke duke{game, "player 1"};
	Assassin assassin{game, "player 2"};
	Ambassador ambassador{game, "player 3"};
	Captain captain{game, "player 4"};
	Contessa contessa{game, "player 5"};
    Duke duke{game, "player 6"};

    SUBCASE("Bad Input"){

        // check that exception is thrown if the dimensions of the matrix are incorrect.
        CHECK_THROWS((Assassin assassin{game, "player 7"}));


    }
}