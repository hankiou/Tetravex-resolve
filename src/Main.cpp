#include <iostream>
#include "../include/solver/Solver.h"
using namespace std;

int main(){
    Game game = GameGenerator::readFromFile("test_files/5x5.txt");
    Solver::sequentialBacktracking(game);
    return 0;
}