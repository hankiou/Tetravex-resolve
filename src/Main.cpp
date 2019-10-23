#include <iostream>
#include "../include/solver/Solver.h"
using namespace std;

int main(){
    Game game = GameGenerator::readFromFile("test_files/7x7.txt");
    Solver* solver = new Solver(&game);
    solver->parallelBacktracking(20);
    return 0;
}