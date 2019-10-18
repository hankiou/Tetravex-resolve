#include "../../include/engine/Piece.h"

Piece::Piece(int west, int north, int east, int south){
    vertical = AxisTuple(south, north);
    horizontal = AxisTuple(west, east);
}

void Piece::setPlaced(bool _placed){
    placed = _placed;
}

bool Piece::isPlaced(){
    return placed;
}