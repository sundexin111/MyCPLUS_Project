#ifndef __TEST_H__
#define __TEST_H__

#include <iostream>
#include <bits/stdc++.h>
#define SQR(A) A*A

using namespace std;

class Test
{
public:
    Test(){

    }

    Test(int a, int b){
        //constructer
        x = a;
        y = b;

    }
    ~Test(){
        //destructer
    }

    void judge_value_or_add(int *p1, int *p2);
    void ptr_char();
    void print();

    void test_ptr(void *data);
    void test_value();

    int test_char();

    void test_array_ptr();

    void swap_int(int a, int b);

    void swap_str(char*a, char*b);

    void printf_ac();

    int f(int n)

    {

        if(n) {
            int x = f(n - 1);
            return f(n-1) + n;
        }else {
            return n;
        }

    }

protected:
private:
    int x;
    int y;
};

class Parent{
public:
    Parent(){
        //printf("我是父亲\n");
        //Hobby();
    }

    ~Parent(){

    }

    virtual void Intro(){
        printf("我是父亲\n");
        Hobby();
    }

    virtual void Hobby(){
        printf("我喜欢打乒乓球\n");
    }

    void ability(){
        printf("我会做家具\n");
    }
    void age(){
        printf("我今年４３岁\n");
    }

    virtual void education() = 0;
};

class Child1 : public Parent{
public:
    Child1(){
        //printf("我是第一个孩子\n");
        //Hobby();
    }
    ~Child1(){

    }

    virtual void Intro(){
        printf("我是第一个孩子\n");
        Hobby();
    }
    void Hobby(){
        printf("我喜欢打篮球\n");
    }

    void ability(){
        printf("我会飞四旋翼\n");
    }

    void education(){
        printf("我是本科学历\n");
    }
};

class Child2 : public Parent{
public:
    Child2(){
        //printf("我是第二个孩子\n");
        //Hobby();
    }
    ~Child2(){

    }

    void Hobby(){
        printf("我喜欢踢足球\n");
    }
};

class A{
public:
    A(){
        //printf("1");
        cout << "1";
    }

    A(A &a){
        //printf("2");
        cout << "2";
    }

    A &operator = (const A &a){
        printf("3");
        cout << "3";
        return *this;
    }
};

class Base
{
public:
    virtual int foo(int x)
    {
        return x * 10;
    }
 
    int foo(char x[14])
    {
        return int(sizeof(x) + 10);
    }
};
 
class Derived: public Base
{
    int foo(int x)
    {
        return x * 20;
    }
 
    virtual int foo(char x[10])
    {
        return int(sizeof(x) + 20);
    }
} ;

#endif