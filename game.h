#include <iostream>

using namespace std;

class Card 
{  private:
    int _suit;
    int _face;
   public:
    Card(int &suit, int &face):_suit(suit),_face(face); 
    int suit();
    int face(); }

class Table 
{  private:
    Card _deck[4];  }

class Player 
{  private:
    Card _deck[13];
    int _onHold;
   public:
    Player():_onHold(0); 
    bool Check();
    void add(Card &c);
    bool isFull(); 
    void deal(Player &p1, Player &p2, Player &p3, Player &p4);
    friend ostream& operator<<(ostream&out, const Player print);  }


