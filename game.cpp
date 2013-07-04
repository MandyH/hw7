#include <iostream>
#include "game.h"

using namespace std;

Card::Card(int &suit, int &face):_suit(suit),_face(face) {}

int Card::suit() 
{   return this->_suit;  }

int Card::face() 
{   return this->_face;  }

void Player::deal(Player &p1, Player &p2, Player &p3, Player &p4) 
{    for (int i=0; i<4; i++) 
     {  for (int j=0; j<13; j++) 
        {  do 
           {  int again = 0;
              int giveToPlayer = rand() % 4;
              switch (giveToPlayer) 
              {  case 0:
                      if (!p1.isFull()) 
                      {  Card c(i,j);
                         p1.add(c);  } 
                      else 
                      {  again = 1;  }
                 break;
                 case 1:
                      if (!p2.isFull()) 
                      {  Card c(i,j);
                         p2.add(c);  } 
                      else 
                      {  again = 1;  }
                 break;
                 case 2:
                      if (!p3.isFull()) 
                      {  Card c(i,j);
                         p3.add(c);  } 
                      else 
                      {  again = 1;  }
                      break;
                 case 3:
                      if (!p4.isFull()) 
                      {  Card c(i,j);
                         p4.add(c);  } 
                      else 
                      {  again = 1;  }
                      break;  }  } 
              while (again);  }  }  }
       

bool Player::isFull()
{  if (_onHold==13) 
   {  return true;  } 
   else 
   {  return false;  }  }
   
bool Player::void add(Card &c)
{  if (!isFull) 
   {  _deck[_onHold] = c;
      _onHold++;  }  }

ostream& operator<<(ostream&out, const Player print)
{  for (int i = 0; i < print.i; i++)  
   {  for (int j = 0; j < print.i; j++)
        cout << print.c(i,j) << endl;  }  
   return cout;  }
