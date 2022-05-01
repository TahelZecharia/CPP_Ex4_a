#include "Player.hpp"

using namespace std;

namespace coup{

    // Contruuctor:
    Player:: Player(Game &game, string name){

        this->_game = &game;
        this->_name = name;
        this->_role = "";
        this->_coins = 0;
        this->_lastAction = "";
    }

    // Contruuctor:
    Player:: Player(Game &game, string name, string role){

        this->_game = &game;
        this->_name = name;
        this->_role = role;
        this->_coins = 0;
        this->_lastAction = "";
    }
        
    // Take a coin from the coin stack:
    void Player :: income(){

        this->turnConfirm();

        this->_coins++;

        this->endTurn("income");
    }
        
    // Take two coins from the coin stack:
    void Player :: foreign_aid(){

        this->turnConfirm();

        this->_coins+=2;

        this->endTurn("foreign_aid");
    }
        
    // Dismissing an opposing player from his position and thus removing him from the game:
    void Player :: coup(Player &player){

        this->turnConfirm();

        if (this->coins() < 7){

            throw runtime_error("There are not enough coins to make a coup (7 coins)");
        }

        this->_game->removePlayer(player._name);

        this->_coins -= 7;

        this->endTurn("coup");
    }
        
    // The function returns the role of the player:
    void Player :: role(){

        cout << this->_role << endl;
    }
        
    // The method returns how many coins the player has:
    int Player :: coins(){

        return this->_coins;
    }

    // The function throws an error if it is not the player's turn:
    void Player :: turnConfirm(){

        if (this->_game->turn() != this->_name){

            throw runtime_error("It's someone else's turn");
        }

    }

    // The function updates the game that the player's turn is over:
    void Player :: endTurn(string action){

        this->_lastAction = action;

        this->_game->nextTurn();
    }

    // The function returns the player's name:
    string Player :: getName(){

        return this->_name;
    }
        
    // Destructor:
    Player :: ~Player(){

    }
    
}