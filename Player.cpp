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
    this->money++;
    this->lastAction = "income";
    cout << this->game->currTurn << endl;
    this->game->updateTurn();
}

void Player::foreign_aid(){

}

int Player::coins(){
    return this->money;
}

void Player::coup(Player & player){

}
