#include "../../include/solver/Solver.h"
#include <iostream>
#include <vector>

void Solver::sequentialBacktracking(Game &game){
    
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
                int nexty = y;
                if(x == game.getSize()-1){
                    nextx = 0;
                    nexty ++;
                }
                recursiveBruteforce(game, nextx, nexty);
                game.removePiece(x, y);
            }
        }
    }
}