#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "Game.hpp"

namespace coup{

    class Player{

        protected:

        Game* _game;
        string _name;
        string _role;
        int _coins;
        string _lastAction;

        public:

        // Contruuctor:
        Player(Game &game, string name);
        
        // Contruuctor:
        Player(Game &game, string name, string role);
        
        // Take a coin from the coin stack:
        void income();
        
        // Take two coins from the coin stack:
        void foreign_aid();
        
        // Dismissing an opposing player from his position and thus removing him from the game:
        virtual void coup(Player &player);
        
        // The function returns the role of the player:
        void role();
        
        // The method returns how many coins the player has:
        int coins();

        // The function throws an error if it is not the player's turn:
        void turnConfirm();

        // The function updates the game that the player's turn is over:
        void endTurn(string action);

        // The function returns the player's name:
        string getName();
        
        // Destructor:
        ~Player();
    };
}
