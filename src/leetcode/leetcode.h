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
    
    //导航：选择要测试的数据结构
    void test();

    /*************************************************数组****************************************************/
    void print_C_array(int lx, int ly, int rx, int ry, vector<vector<int> > &matrix, vector<int> ret);
    vector<int> printMatrix(vector<vector<int>> matrix);

    int FirstNotRepeatingChar(string str);

    void printArray(vector<int> array);
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
    //双指针测试
    void two_pointer_test();

    //1:两数之和 II - 输入有序数组
    vector<int> twoSum(vector<int>& numbers, int target);

    //2:两数平方和
    bool judgeSquareSum(int c);

    //3:反转字符串中的元音字母
    string reverseVowels(string s);

    //4:回文字符串
    bool validPalindrome(string s);
    bool isValid1(string s, int l, int r);

    //5:合并两个有序数组
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);

    //6:判断链表中是否存在环
    bool hasCycle(ListNode *head);

    //7:最长子序列
    string findLongestWord(string s, vector<string>& dictionary);

    vector<int> FindNumberswithsum(vector<int> array, int sum);

    vector<vector<int> > FindContinuousSequence(int sum);

    string ReverseSentence(string str);

    string LeftRotateString1(string str, int n);
    string LeftRotateString2(string str, int n);

    /****************************************双指针**********************************************/

   
    /****************************************链表***********************************************/
    //链表测试
    void listnode_test();
    //基础：创建个打印链表
    ListNode* CreateList(int count);
    void printList(ListNode* pHead);

    //1:寻找两个链表的交点
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);

    //2:反转链表
    ListNode *reverseList(ListNode* head);

    //3:合并两个有序链表
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);

    //4:删除排序链表中的重复元素
    ListNode* deleteDuplication(ListNode* pHead);

    //5:删除链表的倒数第n个节点
    ListNode* removeNthFromEnd(ListNode* head, int n);

    //6:两两交换链表中的节点
    ListNode* swapPairs(ListNode* head);

    //7:链表求和
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

    //8:回文链表
    bool isPalindrome(ListNode* head);
    ListNode* end0FirstHalf(ListNode* head);

    //9:分隔链表
    vector<ListNode*> splitListToParts(ListNode* head, int k);
    
    //10:奇偶链表
    ListNode* oddEvenList(ListNode* head);

    //11:链表排序冒泡法
    void Lsort(ListNode *head);

    //12:链表中倒数最后k个结点
    ListNode* FindKthToTail(ListNode* pHead, int k);

    //13:从尾到头打印链表
    void recur(ListNode* head);
    vector<int> printListFromTailToHead(ListNode* head);
    vector<int> printListFromTailToHead1(ListNode* head);
    /****************************************链表***********************************************/


    int findShortestSubArray(vector<int>& nums);

    void hash_test(int is_in);
    /*************************************栈和队列*******************************************/
    //栈和队列测试
    void stak_que_test();

    //４:有效的括号
    bool isValid(string s);

    //5:每日温度
    vector<int> dailyTemperatures(vector<int>& temperatures);

    //6:下一个更大元素
    vector<int> nextGreaterElements(vector<int>& nums);
    /****************************************树*******************************************/
    //树的测试
    void tree_test();
    struct TreeNode{
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0),left(nullptr),right(nullptr){}
        TreeNode(int x) : val(x),left(nullptr),right(nullptr){}
        TreeNode(int x, TreeNode *left, TreeNode *right)  : val(x),left(left),right(right){}
    };

    /*创建一个树*/
    //TreeNode* CreateTree(TreeNode* root, int val);
    /*求树的最大深度*/
    typedef struct node//节点定义
    {
        struct node *lchild;
        struct node *rchild;
        int data;
    }BiTreeNode, *BiTree;
    int sub = -1;

    void CreateBiTree(BiTree &BT); //创建树

    void PreTraverse(BiTree T); //遍历树

    int maxDepth(BiTree* root);

    static void houxubianli();

protected:

private:
    stack<int> stack1;
    stack<int> stack2;

    priority_queue<int> min_q; //大顶堆
    priority_queue<int, vector<int>, greater<int>> max_q; //小顶堆  

    queue<char> q;
    unordered_map<char, int> mp;

    vector<int> ans;

    //MyQueue myqueue;
    //MyStack mystack;
};

/***************************栈和队列*************************/
//1:用栈实现队列
class MyQueue{
public:
    MyQueue(){};

    void push(int x);

    int pop();

    int peek();

    bool empty();

private:
    stack<int> inStack, outStack;

    void in2out();

};

//2:用队列实现栈
class MyStack{
public:
    MyStack(){}

    void push(int x);

    int pop(); 

    int top();

    bool empty();

private:
    queue<int> queue1, queue2;
};

//3:最小栈
class MinStack {
public:
    MinStack(); 
    void push(int val);
    void pop();
    int top();
    int getMin();
private:
    stack<int> x_stack;
    stack<int> min_stack;
};

#endif