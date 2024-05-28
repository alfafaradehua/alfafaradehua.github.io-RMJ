#include <iostream>
#include <cmath>

#include <string>
#include <vector>
#include "Account.h"
using namespace std;

//https://en.cppreference.com/w/cpp/header
//https://en.cppreference.com/w/cpp/header/cstdlib


using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
// function prototypes

class Player
{
    public:
    string player_name{"Player"};
    int hp{10};
    int xp{0};
    
    void talk (string text_to_say)
    {
        cout << player_name << " says " << text_to_say << endl;
    };

    bool is_dead();
};


class PlayerGold
{
    public:
    string player_name;
    double balance{0};

    void deposit (double amount)
    {
        balance += amount; 
        cout << "New balance is " << balance << endl;
    };
    void withdraw (double amount)
    {
        balance -= amount;
        cout << "New balance is " << balance << endl;
    };
};


int main()
{
    Player Goblin;
    Goblin.player_name = "Goober";
    Player Hero;
    Hero.player_name = "Bryan";
    PlayerGold Goblin_gold;
    PlayerGold Hero_gold;
    Hero.talk("I am a hero");
    Player players[] {Goblin, Hero};
    vector <Player> player_vec{Goblin};
    player_vec.push_back(Hero);


    Player *enemy = new Player();
    (*enemy).player_name="Bandit";

    PlayerGold *enemyGold = new PlayerGold();
    (*enemyGold).player_name="Bandit";
    (*enemyGold).balance=100;

    (*enemy).talk("Arrgh");
    enemy->talk("Your end is nigh!");
    
    Hero_gold.deposit(1);
    Hero_gold.deposit(2); 
    Hero_gold.deposit(3);
    (*enemyGold).withdraw(100);
    
    
    delete enemy;

    
}