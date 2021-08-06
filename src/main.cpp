#include <iostream>
#include <vector>
#include "include/list.h"
#include "include/datebase.h"

using namespace std;

//make时要输入用户名，否则else
int main(int arg_count, char *args[])
{
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

    return 0;
}

