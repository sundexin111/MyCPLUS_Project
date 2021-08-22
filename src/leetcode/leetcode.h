#ifndef __LEETCODE_H__
#define __LEETCODE_H__
#include <iostream>
#include <bits/stdc++.h>

//static_cast为强制类型转换
//所以SCD代表强制类型转换
#define SCD static_cast<double>

using namespace std;

class Leetcode{
public:
    Leetcode(){
        //constructer
    }
    ~Leetcode(){
        //destructer
    }

    /*************************************************数组****************************************************/
    void print_C_array(int lx, int ly, int rx, int ry, vector<vector<int> > &matrix, vector<int> ret);
    vector<int> printMatrix(vector<vector<int>> matrix);

    int FirstNotRepeatingChar(string str);

    /*************************************************数组****************************************************/


    /**********************************************栈/队列/堆**************************************************/
    void push(int node);
    int pop();

    stack<int> normal, minval;
    void push1(int val);
    void pop1();
    int top();
    int min();

    bool IsPOpOrder(vector<int> pushV, vector<int> popV);

    vector<int> GetLeastNumbers_Solution(vector<int> input, int k);

    void Insert(int num);
    double GetMedian();

    void Insert(char ch);
    char FirstAppearingOnce();

    vector<int> maxInWindows(const vector<int>& num, unsigned int size);

    /**********************************************栈/队列/堆**************************************************/


    /****************************************双指针**********************************************/
    vector<int> FindNumberswithsum(vector<int> array, int sum);

    vector<vector<int> > FindContinuousSequence(int sum);

    string ReverseSentence(string str);

    string LeftRotateString1(string str, int n);
    string LeftRotateString2(string str, int n);
    /****************************************双指针**********************************************/

   
    /****************************************链表***********************************************/
    /***结构体
     * 类比于类:
     * struct后相当于类的名字
     * 但是具体应用时,类易于类的对象实例化
     * 结构体也要实例化,下述定义中没有实例化,相当于只定义了类的名字
     * 也可以在定义时实例化
    ***/
    struct ListNode{
        int val;
        struct ListNode *next;
        ListNode(int x):
            val(x), next(NULL){
            }
    };
    vector<int> printListFromTailToHead(ListNode* head);
    vector<int> printListFromTailToHead1(ListNode* head);

    ListNode* CreateList(int count);
    void printList(ListNode* pHead);
    void printArray(vector<int> array);

    ListNode* deleteDuplication(ListNode* pHead);

    ListNode* FindKthToTail(ListNode* pHead, int k);

    /****************************************链表***********************************************/

protected:

private:
    stack<int> stack1;
    stack<int> stack2;

    priority_queue<int> min_q; //大顶堆
    priority_queue<int, vector<int>, greater<int>> max_q; //小顶堆  

    queue<char> q;
    unordered_map<char, int> mp;

    vector<int> ans;

    void recur(ListNode* head);

    /*
    typedef struct LNode{
        int data;
        struct LNode *next;
    };
    */

};

#endif