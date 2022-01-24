#ifndef __TEST_H__
#define __TEST_H__

#include <iostream>
#include <bits/stdc++.h>
#define SQR(A) A*A

using namespace std;

class Test
{
public:
    Test() {

    } 
    /*
    Test(int a):bb(a)
    {
        aa += 1;
    }
    */
    /*
    Test(string s){
        str = s;
        cout << "Test create\n";
    }
    */

    /*
    Test(int a, int b){
        //constructer
        x = a;
        y = b;

    }
    */
    

    ~Test(){
        //destructer
        cout << "Test delete:" << str << endl;
    }

    void judge_value_or_add(int *p1, int *p2);
    void ptr_char();
    void print();
    void print() const; //属于函数重载
    static void print1();//静态成员函数

    void test_ptr(void *data);
    void test_value();

    int test_char();

    void test_array_ptr();

    void swap_int(int a, int b);

    void swap_str(char*a, char*b);

    void printf_ac();

    void test_const();

    //定义几个const参数的重载函数
    void function_const(const int Var);//指Var在函数内不能被重新赋值,为常值
    void function_const(const char* Var);//参数指针所指向的内容为常量不可变
    void function_const(char* const Var);//指针本身为常量不可变

    //测试智能指针
    string& getStr(){return str;}
    void setStr(string s){str = s;}
    void print2(){cout << str << endl;}

    int foo(int a, int b);

    //const int &r;

protected:
private:
    int x;
    int y;
    static int aa;//静态数据成员的声明
    static const int count;//常量静态数据成员(可以在构造函数中初始化)
    //const int bb;//常量数据成员
    string str;

    //const int a;
    //static const int b;
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
/*
//使用类模板实现两个数的最大值
template<typename T>
class Compare{
public:
    Compare(T i, T j)
    {
        x = i;
        y = j;
    }

    T max();

private:
    T x,y;
};
*/
int Test::aa = 0;//静态成员定义+初始化
const int Test::count = 25;//静态常量成员定义+初始化

/*******************类模板Stack使用举例*********************/
const int size = 10;
template<class T>
class Stack{
public:
    void init()
    {
        tos = 0;
    }
    void push(T ob)//声明成员函数push原型,函数参数类型为T类型
    {
        if(tos == size){
            cout << "Stack is full" << endl;
            return;
        }
        stack[tos] = ob;
        tos++;
    }
    T pop()//声明成员函数pop的原型,返回值为T类型 
    {
        if(tos == 0){
            cout << "Stack is empty" << endl;
            return 0;
        }
        tos--;
        return stack[tos];
    }
private:
    T stack[size]; //数组类型为T,既是自可取任意类型
    int tos;
};

/***********weak_ptr测试**********/
class F;
class E{
public:
    shared_ptr<F> pf_;
    ~E(){
        cout << "E delete\n";
    }
};

class F{
public:
    shared_ptr<E> pe_;
    ~F(){
        cout << "B delete\n";
    }
};

void fun2()
{
    shared_ptr<F> pf(new F());
    shared_ptr<E> pe(new E());
    pf->pe_ = pe;
    pe->pf_ = pf;
    cout << pf.use_count() << endl;
    cout << pe.use_count() << endl;

}

/*
//用于智能指针测试
unique_ptr<Test> fun()
{
    return unique_ptr<Test>(new Test("789"));
}
*/

#endif
