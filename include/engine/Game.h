#include "Board.h"
using namespace std;

class Game{
private:
    int size;
    Board* board;
    vector<Piece*> stock;

public:
    Game(int _size);
    vector<Piece*> getStock(){ return stock; }
    void addPiece(Piece* p);
    void removePiece(int x, int y);
    void displayBoard();
    void move(int piece_id, int x, int y);
    void displayStock();
};