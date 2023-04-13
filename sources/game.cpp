#include "game.hpp"
#include "player.hpp"
#include "card.hpp"
using namespace ariel;
vector<Card> Deck;

void Game::createDeck()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 1; j < 14; j++)
        {
            if (i == 0)
            {
                Card card(j, "Hearts");
                Deck.push_back(card);
            }
            else if (i == 1)
            {
                Card card(j, "Spades");
                Deck.push_back(card);
            }
            else if (i == 2)
            {
                Card card(j, "Diamonds");
                Deck.push_back(card);
            }
            else if (i == 3)
            {
                Card card(j, "Clubs");
                Deck.push_back(card);
            }
        }
    }
};

void Game::shuffleDeck()
{
    unsigned int n = Deck.size();
    for (unsigned int i = n - 1; i > 0; i--)
    {
        unsigned int j = static_cast<unsigned int>(rand()) % (i + 1);
        Card temp = Deck[i];
        Deck[i] = Deck[j];
        Deck[j] = temp;
    }
};

void Game::dealCards()
{
    for (unsigned int i = 0; i < 52; i++)
    {
        if (i % 2 == 0)
        {
            this->player1.addCard(Deck.at(i));
        }
        else
        {
            this->player2.addCard(Deck.at(i));
        }
    }
};

Game::Game(Player &p1, Player &p2) : player1(p1), player2(p2)
{
    createDeck();
    shuffleDeck();
    dealCards();
    player1.addGame();
    player2.addGame();
    totalGames++;

    this->gameLog = "";
    this->lastTurn = "";
};

void Game::playTurn()
{
    if (&player1 == &player2)
    {
        throw invalid_argument("minimum 2 players");
    }
    if (this->player1.stacksize() == 0 || this->player2.stacksize() == 0)
    {
        throw invalid_argument("minimum 1 card");
    }
    else
    {
        Card card1 = this->player1.getCard();
        Card card2 = this->player2.getCard();
        this->player1.removeCard();
        this->player2.removeCard();
        this->totalTurns++;
        if (card1.getValue() > card2.getValue())
        {
            this->player1.addCardsWon();
            this->lastTurn = this->player1.name + " Won The Turn\n";
            this->gameLog += this->lastTurn + player1.name + "Won the Turn\n";
        }
        else if (card1.getValue() < card2.getValue())
        {
            this->player2.addCardsWon();
            this->lastTurn = this->player2.name + " Won The Turn\n";
            this->gameLog += this->lastTurn + player2.name + "Won the Turn\n";
        }
        else
        {
            while (card1.getValue() == card2.getValue())
            {
                if (this->player1.stacksize() == 0 || this->player2.stacksize() == 0)
                {
                    break;
                }
                else
                {
                    player1.addDraw();
                    player2.addDraw();
                    cards.push_back(card1);
                    cards.push_back(card2);
                    cards.push_back(this->player1.getCard());
                    cards.push_back(this->player2.getCard());
                    this->player1.removeCard();
                    this->player2.removeCard();
                    card1 = this->player1.getCard();
                    card2 = this->player2.getCard();
                    cards.push_back(card1);
                    cards.push_back(card2);
                    this->player1.removeCard();
                    this->player2.removeCard();
                    this->totalTurns++;
                    if (card1.getValue() > card2.getValue())
                    {
                        for (int i = cards.size(); i > 0; i--)
                        {
                            cards.pop_back();
                            player1.addCardsWon();
                        }
                        this->lastTurn = this->player1.name + " Won The Turn\n";
                        this->gameLog += this->lastTurn + player1.name + "Won the Turn\n";
                    }
                    else if (card1.getValue() < card2.getValue())
                    {
                        for (int i = cards.size(); i > 0; i--)
                        {
                            cards.pop_back();
                            if (i % 2 == 0)
                            {
                                player2.addCardsWon();
                            }
                        }
                        this->lastTurn = this->player2.name + " Won The Turn\n";
                        this->gameLog += this->lastTurn + player2.name + "Won the Turn\n";
                    }
                    else
                    {
                        continue;
                    }
                }
            }
            this->lastTurn = "Tie";
            this->gameLog += this->lastTurn + "Tie";
        }
    }
}

void Game::printStats()
{
    player1.printStats();
    player2.printStats();
};

void Game::printWiner()
{
    if (player1.stacksize() == 0 && player2.stacksize() == 0)
    {
        if (player1.cardesTaken() > player2.cardesTaken())
        {
            player1.addWin();
            cout << "The Winner Is: " + player1.name << endl;
        }
        else
        {
            player2.addWin();
            cout << "The Winner Is: " + player2.name << endl;
        }
    }
    else
    {
        cout << "No Winner Yet" << endl;
    }
};

string Game::printLog()
{
    cout << this->gameLog << endl;
    return gameLog;
};

string Game::printLastTurn()
{
    cout << this->lastTurn << endl;
    return lastTurn;
};

void Game::playAll()
{

    while (totalTurns < 26)
    {
        this->playTurn();
        totalTurns++;
    }
};