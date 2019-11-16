#include "Board.h"
using namespace std;

class Game{
private:
    int size;
    Board* board;
    vector<Piece*> stock;

public:
    Game();
    Game(int _size);
    vector<Piece*> getStock(){ return stock; }
    int getSize(){return size;}
    void addPiece(Piece* p);
    void removePiece(int x, int y);
    void displayBoard();
    bool move(Piece *p, int x, int y);
    void displayStock();
    bool stockIsEmpty();
    Game copy();
};