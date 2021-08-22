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

//make时要输入用户名，否则else
int main(int arg_count, char *args[])
{
    Test test;
    /*
    //test.printf_ac();
    int man3;
    short int si = 4;
    printf("%d\n",sizeof(si));
    int a=248, b=4;
    int const c=21;
    const int *d=&a; 
    int *const e=&b;
    int const * const f =&a; 
    //*c = 32;
    //*d = 43;
    //e = &a;
    int const * const f =&a;
    d = &b;
    *e = 34;
    */
    /*
    //cout << test.f(3) << endl;
    //int a = 10, b =5;
    //test.swap_int(a,b);
    
    char*str_a = "hello world";
    char*str_b = "world hello";
    test.swap_str(str_a, str_b);
    
    
   
   char str[4][12]={"aa", "bbb", "cccc", "d"},*strp[4];
    int i;
    for(i=0;i<4;i++){
        strp[i]=str[i];
    }
    cout << strp;
    

    
    Derived stDerived;
    Base *pstBase = &stDerived;
 
    char x[10];
    printf("%d\n", pstBase->foo(100) + pstBase->foo(x));
    
    //int (*p)[3];

    //A a;
    //A b = a;
    //char str[]="S\065AB"; 
    //printf("\n%d", sizeof(str));
    //test.test_array_ptr();
    
     struct str
    {
        int a;
        char b;
    } c;
    //cout << sizeof(c.b) << endl;
    char x[10];
    cout << sizeof(x) << endl;
    

    int a = 5;
    int *p = &a;
    int *q;
    q = &a;
    cout << &p << endl;
    
    //int y = 5, x =3;
    //x*=y+8;
    //x=x*(y+8);

    
    //int y=3,x=3,z=1;
    //printf("%d %d\n",(++x,y++),z+2);
    //test.test_value();
    //char array[ ]="China";
    //cout << sizeof(array) << "\n";
    
    //cout << "sizeof(A)=" << sizeof(A) << "\n";
    
    //test.test_char();

    //float f;
    //char p;
    //int adf[3];
    //cout << "sizeof(f)=" << sizeof(f) << "\n"
        //<<"sizeof(p)=" << sizeof(p) << "\n"
        //<<"sizeof(adf)"<<sizeof(adf)<<"\n";
    
    
    //Parent parent;
    //Child1 child1;
    //child1.age();//子类可以调用父类的成员函数
    //child1.ability(); //父类和子类有同样的成员函数，用谁实例化就调用谁的成员函数
    

    /new创建类对象
     new创建类对象需要指针接收，一处初始化，多处使用
     new创建类对象使用完需delete销毁
     new创建对象直接使用堆空间，而局部不用new定义类对象则使用栈空间
     new对象指针用途广泛，比如作为函数返回值、函数参数等
     频繁调用场合并不适合new，就像new申请和释放内存一样
    
    
    //Child1 *child1 = new Child1();
    //Parent *parent = (Parent *) child1;
    //parent->Intro();

    Parent *parent; //报错因为现在Parent是一个抽象类,不能实例化。
    parent = new Child1();
    parent->Hobby();
    */
    /*****************************************/
    Baidu baidu;
    //baidu.puditan();
    //baidu.assign_roles();

    /****************************************/
    Leetcode leetcode;
    /*
    //vector<vector<int>> matrix{[1,2],[3,4]};
    //leetcode.printMatrix([[[1,2],[3,4]]);


    //string zifu = "google";
    //cout << "第一个只出现一次字符的位置是：" <<leetcode.FirstNotRepeatingChar(zifu) << "\n";


    //int node = 1243;
    //leetcode.push(node);
    //leetcode.pop();

    //leetcode.push1(2);
    //leetcode.push1(3);
    //leetcode.push1(1);
    //leetcode.push1(4);
    

    
    vector<int> pushV = {1,2,3,4,5};
    //vector<int> popV = {4,5,3,1,2};
    vector<int> popV = {5,4,3,2,1};
    bool result = leetcode.IsPOpOrder(pushV,popV);
    printf("%d\n",result);

    
    //vector<int> input = {4, 5, 1, 6, 2, 7, 3, 8};
    //int num = 4;
    //leetcode.GetLeastNumbers_Solution(input, num);
    

    
    leetcode.Insert('g');
    cout << leetcode.FirstAppearingOnce();
    leetcode.Insert('o');
    cout << leetcode.FirstAppearingOnce();
    leetcode.Insert('o');
    cout << leetcode.FirstAppearingOnce();
    leetcode.Insert('g');
    cout << leetcode.FirstAppearingOnce();
    leetcode.Insert('l');
    cout << leetcode.FirstAppearingOnce();
    leetcode.Insert('e');
    cout << leetcode.FirstAppearingOnce() << "\n";

    
    vector<int> arr = {2,3,4,2,6,2,5,1};
    unsigned num = 3;
    leetcode.maxInWindows(arr,num);
    

    
    vector<int> array({1, 2, 4, 7,8, 11, 15});
    int sum = 15;
    leetcode.FindNumberswithsum(array, sum);
    

    //int sum = 15;
    //leetcode.FindContinuousSequence(sum);

    //string str = {"newcoder. a am I"};
    //leetcode.ReverseSentence(str);

    //ListNode head = {1, 2, 3};
    //leetcode.printListFromTailToHead(head);
    
    typedef struct LNode
    {
        int data;
        struct LNode *next;
    }LNode, *LinkList2;
    LinkList2 L;
    leetcode.CreateList(L,5);
    */

    //Leetcode::ListNode* list = leetcode.CreateList(5);
    //leetcode.printList(list);
    //Leetcode::ListNode* test_listnode;
    //leetcode.printListFromTailToHead1(list);
    //leetcode.deleteDuplication(list);
    //leetcode.printList(list);
    //leetcode.printArray(leetcode.printListFromTailToHead1(list));
    //leetcode.FindKthToTail(list,1);
    //leetcode.printList(list);

    return 0;
}
