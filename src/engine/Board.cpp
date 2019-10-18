#include "../../include/engine/Board.h"
#include <string>
#include <iostream>

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

Piece* Board::getPieceAt(int x, int y){
    return grid[x][y];
}

bool Board::placable(Piece* piece, int x, int y){
    if(x < 0 || y < 0 || x > size-1 || y > size-1) return false;
    if(grid[x][y] != NULL) return false;
    for(int i : {-1, 1}){
        if(x + i >= 0 && x + i <= size-1){
            if(grid[x+i][y] != NULL){
                if(grid[x+i][y]->vertical.get(-i) != piece->vertical.get(i)) return false;
            }
        }
        if(y + i >= 0 && y + i <= size-1){
            if(grid[x][y+i] != NULL){
                if(grid[x][y+i]->horizontal.get(-i) != piece->horizontal.get(i)) return false;
            }
        }
    }

    return true;
}

void Board::placePiece(Piece* piece, int x, int y){
    if(placable(piece, x, y)){
        grid[x][y] = piece;
    }else cout << "Move impossible"<<endl;
}

void Board::display(){
    for(vector<Piece*> v : grid){
        Board::display(v);
    }
}

void Board::display(vector<Piece*> v){
    string lines[4] = {"","","",""};
    for(Piece * p : v){
        string values[4] = {"x", "x", "x", "x"};
        if(p != NULL){
            values[0] = to_string(p->horizontal.get(-1));
            values[1] = to_string(p->vertical.get(1));
            values[2] = to_string(p->horizontal.get(1));
            values[3] = to_string(p->vertical.get(-1));
        }
        lines[0] += "|---";
        lines[1] += "| "+values[1]+" ";
        lines[2] += "|"+values[0]+" "+values[3];
        lines[3] += "| "+values[2]+" ";
    }
    for(string s : lines){
        cout << s+"|" <<endl;
    }
}