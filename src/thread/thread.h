#ifndef __THREAD_H__
#define __THREAD_H__

#include<iostream>
#include <bits/stdc++.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 5

using namespace std;

class Thread{
public:
    Thread(){
        //constructer
    }
    ~Thread(){
        //destructer
    }
    void *thread(void *ptr);
    void create_thread();

    void* say_hello(void* args);

protected:
private:
};

#endif