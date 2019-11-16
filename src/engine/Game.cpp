#include "../../include/engine/Game.h"
#include <stddef.h>
#include <iostream>

Game::Game(int _size){
    size = _size;
    board = new Board(size);
}

void Game::addPiece(Piece *p){
    if(stock.size() < size^2) stock.push_back(p);
}

void Game::removePiece(int x, int y){
    Piece *piece = board->getPieceAt(x, y);
    if(piece != NULL){
        board->removePiece(x, y);
        piece->setPlaced(false);
    }
}

void Game::displayBoard(){
    board->display();
}

void Game::displayStock(){
    Board::display(stock);
}

bool Game::move(Piece *p, int x, int y){
    return board->placePiece(p, x, y);
}

bool Game::stockIsEmpty(){
    for(Piece *p : stock){
        if(!p->isPlaced()) return false;
    }
    return true;
}

Game Game::copy(){
    Game gamecp(size);
    for(Piece* p : stock){
        gamecp.addPiece(new Piece(p->horizontal.get(-1), p->vertical.get(1), p->horizontal.get(1), p->vertical.get(-1)));
    }
    return gamecp;
}