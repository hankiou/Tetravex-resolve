#include "../test/GameGenerator.h"
#include "ThreadPool.h"
#include <chrono>
using namespace std;
class Solver{
private:
    Game* game;
    int currentPiece;
    ThreadPool tp;
public:
    chrono::high_resolution_clock::time_point start;
    Solver();
    Solver(Game* _game);
    void sequentialBacktracking();
    void recursiveBruteforce(int x, int y);
    void recursiveBruteforceP(int x, int y, Game &game);
    void parallelTreatment(int i);
    void parallelBacktracking(int threadAmount);
};