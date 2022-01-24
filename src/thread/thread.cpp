#include "thread.h"
#include <pthread.h>

void* Thread::thread(void *ptr)
{
    for(int i = 0; i < 3; i++){
        sleep(1);
        cout << "这是一个线程\n";
    }
    return 0;
}

void Thread::create_thread()
{
    /*
    //定义线程的id变量,多个变量使用数组
    pthread_t tids[NUM_THREADS];
    for(int i =0; i < NUM_THREADS; i++){
        //参数依次是:创建线程id,线程参数,调用的函数,传入的函数参数
        int ret = pthread_create(&tids[i], NULL, say_hello, NULL);
        if(ret != 0){
            cout << "pthread_create error:error_code=" << ret << endl;
        }
    }
    //等各个线程退出后,进程才结束,否则进程强制结束了,线程可能还没反应过来;
    pthread_exit(NULL);
    */
}

void* Thread::say_hello(void* args)
{
    cout << "Hello Runoob!" << endl;
    return 0;
}