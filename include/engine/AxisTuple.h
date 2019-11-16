using namespace std;
// Represents two opposite values in a piece
class AxisTuple{
private:
    int negative_value, positive_value;
public:
    AxisTuple();
    AxisTuple(int nv, int pv);
    int get(int id);
};