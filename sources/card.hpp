#ifndef Card_hpp
#define Card_hpp

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

namespace ariel
{
    class Card
    {
    public:
        int value;
        string type;
        Card(int value, string type);
        Card();
        int getValue();
        int compareto(Card card);
    };
}
#endif /* Card_hpp */