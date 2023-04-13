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

void Player:: addSingleCardWon()
{
    cardsWon++;
};

int Player::cardesTaken() { return cardsWon; };

int Player::stacksize() { return cards.size(); };