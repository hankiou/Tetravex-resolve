#include "../../include/test/GameGenerator.h"
#include <fstream>
#include <iostream>

Game GameGenerator::readFromFile(string path){
    int size = 0;
    std::ifstream infile(path);
    int W, N, E, S;
    infile >> size >> size;

    Game game(size);

    while(infile >> W >> N >> E >> S){
        game.addPiece(new Piece(W, N, E, S));
    }

    return game;
}