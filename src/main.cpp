#include <iostream>
#include <vector>
#include <string>
#include "list/list.h"
#include "database/database.h"
#include "math/math.h"
#include "test/test.h"
#include "baidu/baidu.h"
#include "leetcode/leetcode.h"

using namespace std;

struct ListNode{
    int value;
    ListNode *next;
};

//make时要输入用户名，否则else
int main(int arg_count, char *args[])
{
    //Test test;

    //Baidu baidu;

    Leetcode leetcode;
    
    Leetcode::ListNode* listA = leetcode.CreateList(5);
    //Leetcode::ListNode* listB = leetcode.CreateList(3);
    leetcode.oddEvenList(listA);
    //leetcode.splitListToParts(listA,3);
    //leetcode.addTwoNumbers(listA, listB);
    //leetcode.mergeTwoLists(listA, listB);
    //leetcode.swapPairs(listA);
    //leetcode.printList(list);
    //Leetcode::ListNode* test_listnode;
    //leetcode.printListFromTailToHead1(list);
    //leetcode.deleteDuplication(list);
    //leetcode.printList(list);
    //leetcode.printArray(leetcode.printListFromTailToHead1(list));
    //leetcode.FindKthToTail(list,1);
    //leetcode.printList(list);
    //leetcode.getIntersectionNode(listA,listB);
    //leetcode.reverseList(listA);
   // leetcode.Lsort(listA);
   
   
   /*树的测试*/
    //Leetcode::TreeNode* root = nullptr;
    //int a = 5;
    //leetcode.CreateTree(root, a);
    //建立一颗二叉树先序
    //Leetcode::BiTree T;
    //leetcode.houxubianli();
    //leetcode.CreateBiTree(T);
    //cout << "二叉树创建完成！"<<endl;
    //cout << "先序遍历二叉树为"<<endl;
    //leetcode.PreTraverse(T);
    //cout << leetcode.maxDepth(T) << endl;

    //遍历二叉树

    /*****栈和队列测试*****/
    /*
    MyQueue myqueue;
    myqueue.push(1);
    myqueue.push(2);
    myqueue.push(5);

    //返回队列开头的元素
    myqueue.peek();

    myqueue.pop();

    myqueue.empty();
    */
    /*
    MyStack mystack;
    mystack.push(1);
    mystack.push(2);
    mystack.push(5);
    mystack.pop();
    mystack.top();
    */
    //string s = "abpcplea";
    //vector <string> d{"ale","apple","monkey","cplea"};
    //leetcode.findLongestWord(s,d);

    return 0;
}
