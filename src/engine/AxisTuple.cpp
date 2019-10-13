#include "../../include/engine/AxisTuple.h"

AxisTuple::AxisTuple(){
    negative_value = 0;
    positive_value = 0;
}
AxisTuple::AxisTuple(int nv, int pv){
    negative_value = nv;
    positive_value = pv;
}

int AxisTuple::get(int id){
    if(id < 0) return negative_value;
    if(id > 0) return positive_value;

    return -1;
}