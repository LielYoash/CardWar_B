#ifndef Player_hpp
#define Player_hpp

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include "card.hpp"
using namespace std;
using namespace ariel;

class Player
{
public:
    string name;
    int totalWins = 0;
    int totalGames = 0;
    int cardsWon = 0;
    int turnsNum = 0;
    int totalDraw = 0;
    int drawsWon = 0;
    vector<Card> cards;
    Player(string name);
    Player();
    void addTurnsNum();
    void addDraw();
    void addDrawWon();
    void addCard(Card &card);
    Card getCard();
    void addGame();
    void addCardsWon();
    void addWin();
    int stacksize();
    int cardesTaken();
    void removeCard();
    void printStats();
};

#endif /* Player_hpp */