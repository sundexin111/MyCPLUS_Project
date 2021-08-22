#include "thread.h"

void* Thread::thread(void *ptr)
{
    for(int i = 0; i < 3; i++){
        sleep(1);
        cout << "这是一个线程\n";
    }
    return 0;
}

/*
int Thread::create_thread()
{
    pthread_t id;
    int ret = pthread_create(&id, NULL, thread,NULL);
    if(ret){
        cout << "创建线程错误.\n";
        return 1;
    }
    for(int i = 0; i < 3; i++){
        cout << "这是主程序.\n";
        sleep(1);
    }
    pthread_join(id, NULL);
    return 0;
}
*/