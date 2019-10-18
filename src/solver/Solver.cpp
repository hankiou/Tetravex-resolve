#include "../../include/solver/Solver.h"
#include <iostream>
#include <vector>

void Solver::sequentialBacktracking(Game &game){
    recursiveBruteforce(game, 0, 0);
}

void Solver::recursiveBruteforce(Game &game, int x, int y){
    if(game.stockIsEmpty()){
        game.displayBoard();
        return;
    }
    for(Piece* p : game.getStock()){
        if(!p->isPlaced()){
            if(game.move(p, x, y)){
                int nextx = x;
                int nexty = y+1;
                if(y == game.getSize()-1){
                    nextx ++;
                    nexty = 0;
                }
                recursiveBruteforce(game, nextx, nexty);
                game.removePiece(x, y);
            }
        }
    }
}