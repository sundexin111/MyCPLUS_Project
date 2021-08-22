#ifndef __THREAD_H__
#define __THREAD_H__

#include<iostream>
#include <bits/stdc++.h>
#include <pthread.h>
#include <unistd.h>

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
    int create_thread();

protected:
private:
};

#endif