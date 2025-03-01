#ifndef Game_hpp
#define Game_hpp

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include "player.hpp"
#include "card.hpp"
using namespace std;
using namespace ariel;

class Game
{
    public:
        Player& player1;
        Player& player2;
        int totalTurns = 0;
        int totalGames = 0;
        int totalDraw = 0;
        string gameLog;
        string lastTurn;
        vector<Card> cards;
        Game(Player &playa1, Player &playa2);
        void dealCards();
        void createDeck();
        void playTurn();
        void printStats();
        void printWiner();
        string printLog();
        string printLastTurn();
        void playAll();
        void shuffleDeck();

};

#endif /* Game_hpp */

