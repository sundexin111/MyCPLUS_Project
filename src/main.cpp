#include <iostream>
#include <vector>
#include "list/list.h"
#include "database/database.h"
#include "math/math.h"

using namespace std;

//make时要输入用户名，否则else
int main(int arg_count, char *args[])
{
    /*****************1 链表测试*********************/
    /***
    List list;
    Database data;

    if(arg_count > 1){
        list.name = string(args[1]);
        list.mainList = data.read();
        list.find_userList();
        list.print_menu();
        data.write(list.mainList);
    }else{
        cout << "Username not supplied.. exiting the program" << endl;
    }
    ***/
   /***********************************************/
    
    /*****************2 数学库测试*****************/
    /***/
    Math cal;
    int a,b;
    cout << "pleale input a and b:" << "\n";
    cin >> a >> b;
    int sum = cal.add(a,b);
    cout << "a + b = " << sum << "\n"; 
    /***/

    return 0;
}

