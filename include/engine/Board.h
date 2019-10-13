#include <vector>
#include "Piece.h"
using namespace std;
class Board{
private:
    int size;
    vector<vector<Piece*>> grid;

public:
    Board(int _size);
    int getSize();
    Piece* getPieceAt(int x, int y);
    bool placable(Piece* piece, int x, int y);
    void placePiece(Piece* piece, int x, int y);
};