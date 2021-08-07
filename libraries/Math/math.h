#ifndef __MATH_H__
#define __MATH_H__

#include <iostream>

using namespace std;

class Math{
public:
    Math(){
        //constructor
    }
    ~Math(){
        //destructor
    }
    int add(int a, int b);
    int sub(int a, int b);
    int mul(int a, int b);
    int dev(int a, int b);

protected:

private:

};


#endif