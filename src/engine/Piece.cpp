#include "../../include/engine/Piece.h"

Piece::Piece(int west, int north, int east, int south){
    vertical = AxisTuple(south, north);
    horizontal = AxisTuple(west, east);
}