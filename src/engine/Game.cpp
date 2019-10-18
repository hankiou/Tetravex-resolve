#include "../../include/engine/Game.h"
#include <stddef.h>

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
        board->placePiece(NULL, x, y);
        stock.push_back(piece);
    }
}

void Game::displayBoard(){
    board->display();
}

void Game::displayStock(){
    Board::display(stock);
}

void Game::move(int piece_id, int x, int y){
    board->placePiece(stock[piece_id], x, y);
    stock.erase(stock.begin() + piece_id);
}