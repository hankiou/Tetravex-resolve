#include "../engine/Game.h"
#include <string>
using namespace std;
class GameGenerator{
public:
    static Game readFromFile(string path);
};