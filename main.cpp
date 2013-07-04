#include <iostream>
#include "game.h"

using namespace std;

int main(int argc, const char * argv[])
{
    Player p1, p2, p3, p4;
    
    deal(p1, p2, p3, p4);
    
    cout << "Player 1: \n" << p1 << endl;
    cout << "\n\nPlayer 2: \n" << p2 << endl;
    cout << "\n\nPlayer 3: \n" << p3 << endl;
    cout << "\n\nPlayer 4: \n" << p4 << endl;
    
    return 0;
}
