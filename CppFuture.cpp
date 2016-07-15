

#include <Poco/Thread.h>

#include "Poco/Runnable.h"
#include "Poco/Thread.h"
#include <iostream>

using Poco::Runnable;
using Poco::Thread;


class MyThread: public Poco::Runnable
{
public:
    MyThread(const std::string& arg1, int* arg2):
        _arg1(arg1),
        _arg2(arg2)
    {
    }

    void run()
    {
        Thread::sleep(300);
        *_arg2 = 20;
    }

private:
    std::string _arg1;
    int* _arg2;
};

int* createThread(){
    int *a = new int;
    MyThread* mt = new MyThread("foo", a);
    Thread* t = new Thread;
    t->start(*mt);
    return a;
}

//...
int main(){
    int *my_int = createThread();
    Thread::sleep(1000);
    std::cout<<"Before terminating main, my_int is  : "<<*my_int<<std::endl;
}