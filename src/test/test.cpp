#include "test.h"

void Test::judge_value_or_add(int *p1,int *p2)
{
    cout << "p1和p2的值为：" << *p1 << "  " << *p2 << "\n";
    cout << "p1和p2的地址为：" << p1 <<"  "<< p2 << "\n";
    int p;
    //只是改变地址中的值，并没有交换地址
     p  = *p1;
    *p1 = *p2;
    *p2 = p;
    cout << "p1和p2的值为：" << *p1 << "  " << *p2 << "\n";
    cout << "p1和p2的地址为：" << p1 << "  " << p2 << "\n";
}

void Test::ptr_char()
{
    char *ptr = NULL;
    char str[] = "Hello";
    ptr = str;
    cout << "*(ptr+5)的值是："<< *(ptr+5) << "\n";
}

void Test::print()
{
    cout << x << "*" << y << "  " << "\n";
}

void Test::test_ptr(void *data)
{
    //1 将void类型指针强制转换成(unsigned)类型指针
    //2 将指针转换成数(加*)
    unsigned int value  =  *((unsigned int* ) data); 
    //printf("%u", value);
    cout << value  << "\n";
}

void Test::test_value()
{
    unsigned int value = 10;
    test_ptr(&value);
}

int Test::test_char()
{
    char ch = 'a';
    cout << "ch的字节数为："<< sizeof(ch) << endl;
    cout << "(int)cha字节数为："<<sizeof(int(ch)) << endl;
    cout << "(int)ch="<<(int)ch << endl;
    return (int)ch;
}

/**数组与指针**/
/***
 * 数组变量表示第一个地址
 * 定义指针等于数组，可以用这个指针操作数组
 * 数组＋i表示第数组中第i个数的地址
***/
void Test::test_array_ptr()
{
    int arr[8] = {1, 6, 3, 3, 8, 0, 7, 4};
    int *p = arr; //p是一个地址，*p默认是数组的第一个元素,操作p就是操作数组arr
    int ways; //求偶数的方式
    cout << "输入求偶数的方式：" << "\n";
    cin >> ways;
    switch (ways)
    {
        case 1:{
        for(int i = 0; i < 8; i++){
            if(arr[i] % 2 == 0){
                //printf("%d\n", arr[i]);
                cout << arr[i] <<  "  ";
            }
        }
            break;
        }
        case 2:{
        for(int i = 0; i < 8; i++){
            if(p[i] % 2 == 0){
                //printf("%d\n", p[i]);
                cout << p[i] << "  ";
            }
        }
            break;
        }
        case 3:{
        int i = 0;
        while(i < 8){
            if(*(p + i) % 2 == 0){ //(p+i)代表地址
                //printf("%d", *(p+i));
                cout << *(p + i) << "  ";
            }
            i++;
        }
            break;
        }
        case 4:{
        int j = 0;
        while(j < 8){
            if( *(arr + j) % 2 ==0){
                cout << ("%d", *(arr + j)) << "  ";
            }
             j++;
        }
            break;
        }
        
    }
}

void Test::swap_int(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void Test::swap_str(char*a, char*b)
{
    char*temp = a;
    a = b;
    b = temp;
}

void Test::printf_ac(){
    char  ac[]="Hello World! C Program",*p;
    for(p=ac+6;p<ac+9;p++){
        printf("%c",*p);
    }
}

/*****************1
 *  链表测试*********************************/
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
   /***********************************************************/
    
/*****************2 数学库测试******************************/
    /***
    Math cal;
    int a,b;
    cout << "pleale input a and b:" << "\n";
    cin >> a >> b;
    int sum = cal.add(a,b);
    cout << "a + b = " << sum << "\n"; 
    ***/

/******************3 2021/8/8 C++专项训练********************/
   /***
   ///////////////////////
   Test test;
   int val1 = 5;
   int val2 = 7;
   int *p1 = &val1;
   int *p2 = &val2;
   test.judge_value_or_add(p1,p2);
   
   //test.ptr_char();
    /////////////////////

   //7///
   Test t[2] = {Test(1,2), Test(3,4)};
   for(int i =0; i<2; i++)
   {
       t[i].print();
   }

    ////10////
    int x = 6,y = 3,z = 2;
    x /= SQR(y+z)/SQR(y+z);
    cout << SQR(y+z) << endl;

    ///8///
    char* sp, s[10];
    sp = "Hello";
    //s = "Hello";
    cout << sp << endl;
    ***/

/******************4 2021/8/9 C++专项训练********************/
    /***
    ///////3////////
    ofstream File1("text.txt");  
    string d("20160314"); 
    string y=d.substr(0,4); //截取函数，从下标０开始，截取四位
    int k=d.find("2");//find函数，找出数字对应下标
    int i=d.find("3"); 
    string m=d.substr(k+2,i-k); //16031
    string dd=d.substr(i+1,2);  //14
    string n=dd+m+y; //string类型相加就是在原有基础的后面直接累加
    File1<<n<<endl; 
    File1.close(); 
    
    ////////////////
    
    int *p, j, i=10;
    p = &j; //p和j同一个地址，对p操作就是对j操作
    *p = i++;  //ｉ++是先赋值后++，即p* = 10; ++i是先++再赋值，即*p=11
    int a = sizeof(i);
    int b = sizeof(*p);
    int c = sizeof(p);
    i += sizeof(i) + sizeof(*p) + sizeof(p);
    

   int a =0;
   int b = (a = -1) ? 2 : 3; // a=-1非零为真，２
   int c = (a = 0) ? 2 : 3;//　a=0为假，３
   ***/

