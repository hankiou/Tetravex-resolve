#include "../../include/solver/ThreadPool.h"
using namespace std;

ThreadPool::ThreadPool(){}
void ThreadPool::addThread(thread* t){threads.push_back(t);}
void ThreadPool::joinThreads(){for(thread* t : threads){t->join();}}
void ThreadPool::killThreads(){

    for(thread* t : threads){
        t->~thread();}
}