#include <iostream>
#include "../include/test/GameGenerator.h"
using namespace std;

int main(){
    Game game = GameGenerator::readFromFile("test_files/5x5.txt");
    //game.displayBoard();
    game.move(0, 0, 0);
    game.move(5, 4, 4);
    game.displayStock();
    cout<<endl;
    game.displayBoard();
    return 0;
}