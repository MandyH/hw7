#include <iostream>
#include "game.h"

using namespace std;

Card::Card(int suit, int face):_suit(suit),_face(face) {}  //default constructor

Card::Card(Card &c):_suit(c.suit()),_face(c.face()) {}  //copy constructor

int Card::suit() {
    return _suit;
}

int Card::face() {
    return _face;
}


Player::Player() {
    _onHold = 0;
    for (int i=0; i<13; i++)
        _deck[i] = Card();
}

void deal(Player &p1, Player &p2, Player &p3, Player &p4) {
    for (int i=0; i<4; i++) {
        for (int j=0; j<13; j++) {
            int again = 0;
            do {
                int giveToPlayer = rand() % 4;
                switch (giveToPlayer){
                    case 0:
                        if (!p1.isFull()) {
                            Card c(i,j);
                            p1.add(c);
                            break;
                        }
                    case 1:
                        if (!p2.isFull()) {
                            Card c(i,j);
                            p2.add(c);
                            break;
                        }
                    case 2:
                        if (!p3.isFull()) {
                            Card c(i,j);
                            p3.add(c);
                            break;
                        }
                    case 3:
                        if (!p4.isFull()) {
                            Card c(i,j);
                            p4.add(c);
                            break;
                        }
                    default:
                        if (!p1.isFull()) {
                            Card c(i,j);
                            p1.add(c);
                        } else if (!p2.isFull()) {
                            Card c(i,j);
                            p2.add(c);
                        } else if (!p3.isFull()) {
                            Card c(i,j);
                            p3.add(c);
                        } else if (!p4.isFull()) {
                            Card c(i,j);
                            p4.add(c);
                        }
                        break;
                }
            } while (again);
        }
    }
}


bool Player::isFull() {return _onHold==13;}

void Player::add(Card &c) {
    if (!isFull()) {
        _deck[_onHold] = c;
        _onHold++;
    }
}

Card& Player::operator[] (int i) {
    return _deck[i];
}

ostream& operator<<(ostream&out, Card &c) {
    out << "Suit: " << c.suit() << " Face: " << c.face();
    return out;
}

ostream& operator<<(ostream&out, Player &p) {
    for (int i=0; i<13; i++) {
        out << p[i] << ", ";
    }
    return out;
}
