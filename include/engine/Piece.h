#include "AxisTuple.h"

// Tetravex piece containing 4 values 
using namespace std;
class Piece{
public:
    AxisTuple vertical, horizontal;
    bool placed;

    Piece(int west, int north, int east, int south);
    void setPlaced(bool _placed);
    bool isPlaced();
};