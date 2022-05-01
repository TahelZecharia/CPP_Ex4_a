#pragma once

#include "Player.hpp"

namespace coup{

    class Ambassador : public Player{

    public:

    // Contruuctor:  
    Ambassador(Game &game, string name);

    // The func transfer coin from one player to another player in addition.
    void transfer(Player &p1, Player &p2);
    
    // The ambassador can prevent a theft.
    void block(Player &p);
    
    // Destructor:
    ~Ambassador();
    
    };  
}