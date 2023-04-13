#include "card.hpp"
using namespace ariel;
int value;
string type;

Card::Card(int value, string type)
{
    this->value = value;
    this->type = type;
};

Card::Card()
{
    this->value = 0;
    this->type = " ";
};

int Card::getValue()
{
    return this->value;
};

int Card::compareto(Card card)
{
    if (this->value > card.value)
    {
        return 1;
    }
    else if (this->value < card.value)
    {
        return -1;
    }
    else
    {
        return 0;
    }
};
