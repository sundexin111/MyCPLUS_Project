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
    Test test;

    Baidu baidu;

    Leetcode leetcode;

    leetcode.test();
    
    return 0;
}
