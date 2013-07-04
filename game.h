#ifndef _Poker_Card
#define _Poker_Card

#include <iostream>

using namespace std;

class Card {
private:
    int _suit;
    int _face;
public:
    Card(int =0, int =0);
    Card(Card &c);
    int suit();
    int face();
    //friend ostream& operator<<(ostream&out, const Card &c);
};

class Table {
private:
    Card _deck[4];
};

class Player {
private:
    Card _deck[13];
    int _onHold;
public:
    Player();
    bool Check();
    void add(Card &c);
    bool isFull();
    void deal(Player &p1, Player &p2, Player &p3, Player &p4);
    Card& operator[] (int);
    //friend ostream& operator<<(ostream&out, const Player &p);
};

#endif
