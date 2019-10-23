#include <vector>
#include <stack>
#include <thread>
#include <mutex>
using namespace std;

class ThreadPool{

    vector<thread*> threads;

public:
    mutex m;
    ThreadPool();
    void addThread(thread* t);
    void joinThreads();
    void killThreads();
};