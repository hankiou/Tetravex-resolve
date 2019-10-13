#include "../../include/engine/Board.h"

Board::Board(int _size){
    size = _size;
    for(int i = 0; i < size; i++){
        vector<Piece*> line;
        for(int j = 0; j < size; j++){
            line.push_back(NULL);
        }
        grid.push_back(line);
    }
}

int Board::getSize(){
    return size;
}

bool Board::placable(Piece* piece, int x, int y){
    if(x < 0 || y < 0 || x > size || y > size) return false;
    if(grid[x][y] != NULL) return false;
    for(int i : {-1, 1}){
        if(grid[x+i][y] != NULL){
            if(grid[x+i][y]->vertical.get(-i) != piece->vertical.get(i)) return false;
        }
        if(grid[x][y+1] != NULL){
            if(grid[x][y+1]->horizontal.get(-i) != piece->horizontal.get(i)) return false;
        }
    }

    return true;
}

void Board::placePiece(Piece* piece, int x, int y){
    if(placable(piece, x, y)){
        grid[x][y] = piece;
    }
}