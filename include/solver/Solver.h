#include "../test/GameGenerator.h"
using namespace std;
class Solver{
public:
    Solver();
    static void sequentialBacktracking(Game &game);
    void recursiveBruteforce(Game &game, int x, int y);
};