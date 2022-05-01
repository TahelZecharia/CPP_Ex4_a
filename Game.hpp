#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "Player.hpp"

namespace coup{

    class Game{

        std:: vector<std:: string> _players;
        int _turn;

        public:
        
        // Contruuctor:
        Game();
        
        // returns the names of the players currently active in the game.
        vector<string> players();
        
        // Print the name of the player whose turn to play now.
        string turn();
        
        // The method returns the name of the winner. 
        // If the game is still active, the method will throw an error.
        string winner();

        // Add a new player to the game:
        void addPlayer(string name);

        // Remove a player from the game:
        void removePlayer(string name);

        // The function advances the turn of the game:
        void nextTurn();
        
        // Destructor:
        ~Game();
    };
}