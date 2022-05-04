#include "Player.hpp"
//#include "Assassin.hpp"

#define CoupRegCost 7
#define CoupAssCost 3

using namespace coup;


Player::Player(Game &game, const string &name, const string role){
    this->money = 0;
    this->Prole = role;
    this->Name = name;
    this->lastAction = "";
    this->game = &game;
    // after init all parameters i will add the player to the game 
    this->game->addPlayer(this);

}
string Player::role(){
    return this->Prole;
}

void Player::income(){
    if(this->game->isPlayerTurn(*this)){
        this->money++;
        this->lastAction = "income";
        //cout << this->game->currTurn << endl;
        this->game->updateTurn();
    }
    else{
        throw runtime_error("Not your turn!");
    }
}

void Player::foreign_aid(){
    if(this->game->isPlayerTurn(*this)){
        this->money+=2;
        this->lastAction = "foreign_aid";
        //cout << this->game->currTurn << endl;
        this->game->updateTurn();
    }
    else{
        throw runtime_error("Not your turn!");
    }
}

int Player::coins(){
    return this->money;
}

void Player::coup(Player & player){

}
