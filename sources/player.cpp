#include "player.hpp"
#include "card.hpp"
using namespace ariel;

string name;
vector<Card> cards;

Player::Player(string name)
{
    this->name = name;
};

Player::Player()
{
    this->name = "Player";
};

void Player::addCard(Card &card)
{
    this->cards.push_back(card);
};

Card Player::getCard()
{
    return cards.back();
};

void Player::removeCard()
{
    cards.pop_back();
};

void Player::addGame()
{
    totalGames++;
};

void Player::addWin()
{
    totalWins++;
};

void Player::addCardsWon()
{
    cardsWon = cardsWon + 2;
};

void Player::addTurnsNum()
{
    turnsNum++;
};

void Player::addDraw()
{
    totalDraw++;
};

void Player::addDrawWon()
{
    drawsWon++;
};

void Player::printStats()
{
    cout << "Player name: " << name << endl;
    cout << "Total games: " << totalGames << endl;
    cout << "Total wins: " << totalWins << endl;
    cout << "Win rate: " << (totalWins / totalGames) * 100 << "%" << endl;
    cout << "Total draws: " << totalDraw << endl;
    cout << "Total draws won: " << drawsWon << endl;
    if (totalDraw == 0)
    {
        cout << "Draw win rate: " << 0 << "%" << endl;
    }
    else
    {
        cout << "Draw win rate: " << (drawsWon / totalDraw) * 100 << "%" << endl;
    }
    cout << "Total cards won: " << cardsWon << endl;
    cout << "Total turns: " << turnsNum << endl;
};

int Player::cardesTaken() { return cardsWon; };

int Player::stacksize() { return cards.size(); };