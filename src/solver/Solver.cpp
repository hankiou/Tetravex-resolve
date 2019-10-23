#include "../../include/solver/Solver.h"
#include <iostream>
#include <chrono>
#include <ctime>
#include <vector>

Solver::Solver(){

}

Solver::Solver(Game* _game){
    game = _game;
    currentPiece = 0;
}

void Solver::sequentialBacktracking(){

    start = chrono::high_resolution_clock::now(); 
    recursiveBruteforce(0, 0);
}

void Solver::recursiveBruteforce(int x, int y){
    if(game->stockIsEmpty()){
        cout << "resolved in " << chrono::duration_cast<chrono::duration<double>>(chrono::high_resolution_clock::now() - start).count() << "s"<<endl;;
        game->displayBoard();
        exit(0);
        return;
    }
    for(Piece* p : game->getStock()){
        if(!p->isPlaced()){
            if(game->move(p, x, y)){
                int nextx = x;
                int nexty = y+1;
                if(y == game->getSize()-1){
                    nextx ++;
                    nexty = 0;
                }
                recursiveBruteforce(nextx, nexty);
                game->removePiece(x, y);
            }
        }
    }
}

void Solver::recursiveBruteforceP(int x, int y, Game &gamecp){
    if(gamecp.stockIsEmpty()){
        cout << "resolved in " << chrono::duration_cast<chrono::duration<double>>(chrono::high_resolution_clock::now() - start).count() << "s"<<endl;;
        gamecp.displayBoard();
        tp.killThreads();
        return;
    }
    for(Piece *p : gamecp.getStock()){
        if(!p->isPlaced()){
            if(gamecp.move(p, x, y)){
                int nextx = x;
                int nexty = y+1;
                if(y == gamecp.getSize()-1){
                    nextx ++;
                    nexty = 0;
                }
                recursiveBruteforceP(nextx, nexty, gamecp);
                gamecp.removePiece(x, y);
            }
        }
    }
}

void Solver::parallelTreatment(int threadId){
    Game gamecp = game->copy();
    while(currentPiece < game->getStock().size()){
        gamecp.removePiece(0,0);
        gamecp.move(gamecp.getStock()[currentPiece], 0, 0);
        tp.m.lock();
        currentPiece++;
        tp.m.unlock();
        recursiveBruteforceP(0, 1 , gamecp);
    }
}

void Solver::parallelBacktracking(int threadAmount){
    for(int i = 0; i < threadAmount; i++){
        tp.addThread(new thread(&Solver::parallelTreatment, this, i));
    }
    start = chrono::high_resolution_clock::now(); 
    tp.joinThreads();
    
}