#include "leetcode.h"

void Leetcode::test()
{
    /****
     *1:双指针
     *2:数组
     *3:链表
     *4:栈和队列
     *5:树
     ****/
    cout << "请选择要测试的数据结构或算法:"<< endl
         << "1:双指针；"<<"2:数组"     << endl
         << "3:链表；"  << "4:栈和队列"<< endl
         << "5:树"     <<endl;
    int n;
    cin >> n;
    switch(n){
        case 1:
        two_pointer_test();
        break;

        case 2:
        break;

        case 3:
        listnode_test();
        break;

        case 4:
        stak_que_test();
        break;

        case 5:
        break;
    }
}

/*****************************************数组***********************************************/
/**************顺时针打印数组******************/
/***题目描述：
 * 按顺时针的方向，从外到里打印矩阵的值。下图的矩阵打印结果为：
 * 1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10
***/

/***********************************/
/***********1  2  3  4**************/
/***********5  6  7  8**************/
/***********9  10 11 12*************/
/***********13 14 15 16*************/

/***解题思路
 * 一层一层从外到里打印，观察可知每一层打印都有相同的处理步骤，
 * 唯一不同的是上下左右的边界不同了。因此使用四个变量 r1, r2, 
 * c1, c2 分别存储上下左右边界值，从而定义当前最外层。打印当
 * 前最外层的顺序：从左到右打印最上一行->从上到下打印最右一行->
 * 从右到左打印最下一行->从下到上打印最左一行。应当注意只有在 
 * r1 != r2 时才打印最下一行，也就是在当前最外层的行数大于 1 
 * 时才打印最下一行，这是因为当前最外层只有一行时，继续打印最下
 * 一行，会导致重复打印。打印最左一行也要做同样处理。
***/
void Leetcode::print_C_array(int lx, int ly, int rx, int ry, vector<vector<int> > &matrix, vector<int> ret)
{
    for(int j = ly; j < ry; ++j){
        ret.push_back(matrix[lx][j]);
    }
    for(int i = lx + 1; i <= rx; ++i){
        ret.push_back(matrix[i][ry]);
    }
    int h = rx - lx + 1;
    if(h > 1){
        for(int rj = ry -1; rj >= ly; --rj){
            ret.push_back(matrix[rx][rj]);
        }
    }
    int w = ry -ly + 1;
    if(w > 1){
        for(int ri = rx - 1; ri >= lx + 1; --ri){
            ret.push_back(matrix[ri][ly]);
        }
    }
}

//vector<vector<int>> 代表二维数组
vector<int> Leetcode::printMatrix(vector<vector<int>> matrix)
{
    vector<int> ret;
    if(matrix.empty())
    return ret;

    int lx = 0,ly = 0;
    int rx = matrix.size() - 1; //列数
    int ry = matrix[0].size() - 1;
    while(lx <= rx && ly <= ry){
        print_C_array(lx++, ly++, rx--, ry--, matrix, ret);
    }
    return ret;
}

/****************第一个只出现一次的字符位置******************/
/***题目描述
 * 在一个字符串中找到第一个只出现一次的字符，并返回它的位置。字符串只包含 ASCII 码字符。
 * Input:abacc
 * Output: b
***/
/***解题思路
 * 最直观的解法是使用 HashMap 对出现次数进行统计：字符做为 key，出现次数作为 value，
 * 遍历字符串每次都将 key 对应的 value 加 1。最后再遍历这个 HashMap 就可以找出出现次数为 1 的字符。
 * 考虑到要统计的字符范围有限，也可以使用整型数组代替 HashMap。ASCII 码只有 128 个字符，
 * 因此可以使用长度为 128 的整型数组来存储每个字符出现的次数。
***/
int Leetcode::FirstNotRepeatingChar(string str)
{
    //map<string int>,前者变现单次，后者表示出现的次数
    map<char, int> mp;
    //：是将str赋值给ch
    for(const char ch : str){
        ++mp[ch];
    }
    for(int i = 0; i < str.length(); ++i){
        if(mp[str[i]] == 1)
        return i;
    }
    return -1;
}

void Leetcode::printArray(vector<int> array)
{
    for(int i = 0; i < array.size(); i++){
        cout << array[i] << " ";
    }
    cout << endl;
}
/*****************************************数组***********************************************/


/***************************************栈/队列/堆*******************************************/

/****************用两个栈实现队列******************/
/***题目描述
 * 用两个栈来实现一个队列，完成队列的 Push 和 Pop 操作。
 * 用两个栈来实现一个队列，分别完成在队列尾部插入整数(push)
 * 和在队列头部删除整数(pop)的功能。 队列中的元素为int类型。
 * 保证操作合法，即保证pop操作时队列内已有元素
***/

/***示例
 * 输入：["PSH1","PSH2","POP","POP"]
 * 输出：1,2
***/

/***解题思路
 * in 栈用来处理入栈（push）操作，out 栈用来处理出栈（pop）操作。
 * 一个元素进入 in 栈之后，出栈的顺序被反转。当元素要出栈时，需要先
 * 进入 out 栈，此时元素出栈顺序再一次被反转，因此出栈顺序就和最开
 * 始入栈顺序是相同的，先进入的元素先退出，这就是队列的顺序。
***/
void Leetcode::push(int node)
{
    stack1.push(node);
}

int Leetcode::pop()
{
    if(stack2.empty()){
        while(!stack1.empty()){
            stack2.push(stack1.top());
            stack1.pop();
        }
    }
    int ret = stack2.top();
    cout << ret << "\n";
    stack2.pop();
    return ret;
}

/****************包含min函数的栈******************/
/***题目描述
 * 实现一个包含min()函数的栈，该方法返回当前栈中的最小值
***/
/***解题思路
 * 使用一个额外的 minStack，栈顶元素为当前栈中最小的值。
 * 在对栈进行 push 入栈和 pop 出栈操作时，同样需要对 
 * minStack 进行入栈出栈操作，从而使 minStack 栈顶元素
 * 一直为当前栈中最小的值。在进行 push 操作时，需要比较
 * 入栈元素和当前栈中最小值，将值较小的元素 push 到 minStack 中。
***/
void Leetcode::push1(int value)
{
    normal.push(value);
    if(minval.empty()){
        minval.push(value);
    }else{
        if(value <= minval.top()){
            minval.push(value);
        }else{
            minval.push(minval.top());
        }  
    }
}

void Leetcode::pop1()
{
    normal.pop();
    minval.pop();
}

int Leetcode::top()
{
    return normal.top();
}

int Leetcode::min()
{
    return minval.top();
}

/*********************栈的压入、弹出序列************************/
/***题目描述
 * 输入两个整数序列，第一个序列表示栈的压入顺序，
 * 请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。
 * 例如序列 1,2,3,4,5 是某栈的压入顺序，序列 4,5,3,2,1 是该压栈序
 * 列对应的一个弹出序列，但 4,3,5,1,2 就不可能是该压栈序列的弹出序列。
***/
/***解题思路
 * 使用一个栈来模拟压入弹出操作。每次入栈一个元素后，都要判断一下栈顶
 * 元素是不是当前出栈序列 popSequence 的第一个元素，如果是的话则执
 * 行出栈操作并将 popSequence 往后移一位，继续进行判断。
***/
bool Leetcode::IsPOpOrder(vector<int> pushV, vector<int> popV)
{
    stack<int> st;
    int i = 0, j = 0;
    while(i < pushV.size()){
        if(pushV[i] != popV[j]){
            st.push(pushV[i++]);
        }else{
            ++i, ++j;
            while(!st.empty() && st.top() == popV[j]){
                st.pop();
                ++j;
            }
        }
    }
    return st.empty();
}

/*************************最小的K个数***************************/
/***题目描述
 * 给定一个数组，找出其中最小的K个数。例如数组元素是4,5,1,6,2,7,3,8
 * 这8个数字，则最小的4个数字是1,2,3,4。
 * 0 <= k <= input.length <= 100000 <= input[i] <= 10000
***/
/***示例
 * 输入：[4,5,1,6,2,7,3,8],4
 * 返回值：[1,2,3,4]
***/
/***解题思路
 * 复杂度：O(NlogK) + O(K)
 * 特别适合处理海量数据
 * 维护一个大小为 K 的最小堆过程如下：使用大顶堆。在添加一个元素之后，
 * 如果大顶堆的大小大于 K，那么将大顶堆的堆顶元素去除，也就是将当前
 * 堆中值最大的元素去除，从而使得留在堆中的元素都比被去除的元素来得小。
 * 应该使用大顶堆来维护最小堆，而不能直接创建一个小顶堆并设置一个大小，
 * 企图让小顶堆中的元素都是最小元素。
***/
vector<int> Leetcode::GetLeastNumbers_Solution(vector<int> input, int k)
{
    vector<int> ret;
    if(k == 0 || k > input.size())
    return ret;
    sort(input.begin(), input.end()); //sort是排序函数
    return vector<int>({input.begin(), input.begin() + k});
}

/***********************数据流中的中位数************************/
/***题目描述
 * 如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数
 * 就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么
 * 中位数就是所有数值排序之后中间两个数的平均值。我们使用Insert()方法读取
 * 数据流，使用GetMedian()方法获取当前读取数据的中位数。
***/
/***示例
 * 输入：[5,2,3,4,1,6,7,0,8]
 * 返回值："5.00 3.50 3.00 3.50 3.00 3.50 4.00 3.50 4.00 "
 * 说明：数据流里面不断吐出的是5,2,3...,则得到的平均数分别为5,(5+2)/2,3... 
***/
/***解题思路
 * 中位数是指：有序数组中中间的那个数。则根据中位数可以把数组分为如下三段:
 * [0 ... median - 1], [median], [median ... arr.size() - 1]，
 * 即[中位数的左边，中位数，中位数的右边]
 * 那么，如果我有个数据结构保留[0...median-1]的数据，并且可以O(1)时间取出最大值，
 * 即arr[0...median-1]中的最大值
 * 相对应的，如果我有个数据结构可以保留[median + 1 ... arr.size() - 1] 的数据， 
 * 并且可以O(1)时间取出最小值，即arr[median + 1 ... arr.size() - 1] 中的最小值。
 * 然后，我们把[median]即中位数，随便放到哪个都可以。
 * 假设[0 ... median - 1]的长度为l_len, [median + 1 ... arr.sise() - 1]的长度为 r_len.
 * 1.如果l_len == r_len + 1, 说明，中位数是左边数据结构的最大值
 * 2.如果l_len + 1 == r_len, 说明，中位数是右边数据结构的最小值
 * 3.如果l_len == r_len, 说明，中位数是左边数据结构的最大值与右边数据结构的最小值的平均值。
 * 一个数据结构可以O(1)返回最小值的，其实就是小根堆，O(1)返回最大值的，其实就是大根堆。
 * 并且每次插入到堆中的时间复杂度为O(logn)
 * 所以，GetMedian()操作算法过程为：
 * 初始化一个大根堆，存中位数左边的数据，一个小根堆，存中位数右边的数据
 * 动态维护两个数据结构的大小，即最多只相差一个
***/
void Leetcode::Insert(int num)
{
    min_q.push(num); //试图加入到大顶堆

    //平衡一个两个堆
    max_q.push(min_q.top());
    min_q.pop();

    if(min_q.size() < max_q.size() /*&& min_q.push(max_q.top())*/){
        max_q.pop();
    }
}

double Leetcode::GetMedian()
{
    return min_q.size() > max_q.size() ? SCD(min_q.top()) : SCD(min_q.top() + max_q.top()) / 2;
}

/*******************字符流中第一个不重复的字符*******************************/
/***题目描述
 * 请实现一个函数用来找出字符流中第一个只出现一次的字符。
 * 例如，当从字符流中只读出前两个字符 "go" 时，第一个只出现一次的字符是 "g"。
 * 当从该字符流中读出前六个字符“google" 时，第一个只出现一次的字符是 "l"。
***/
/***方法：哈希＋队列
 * 哈希是将字符串的key转成整数，使用整数找到对应的value
***/
/***注：
 * 队列的push是在后面插
 * 队列的pop是从开头删除
***/
void Leetcode::Insert(char ch)
{
    //如果第一次出现，则添加到队列中
    //map只有key在map中时find = end,否则不等
    if(mp.find(ch) == mp.end()){
        q.push(ch);
    }
    //不管是不是第一次出现，都进行计数
    ++mp[ch];
}

char Leetcode::FirstAppearingOnce()
{
    while(!q.empty()){
        char ch = q.front();
        //拿出头部，如果是第一次出现，则返回
        if(mp[ch] == 1){
            return ch;
        }
        //不是第一次出现，则弹出，然后继续判断下一个头部
        else{
            q.pop();
        }
    }
    return '#';
}

/***************************滑动窗口的最大值***********************************/
/***题目描述
 * 给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
 * 例如，如果输入数组 {2, 3, 4, 2, 6, 2, 5, 1} 及滑动窗口的大小 3，
 * 那么一共存在 6 个滑动窗口，他们的最大值分别为 {4, 4, 6, 6, 6, 5}。
***/
/***解题思路
 * 用一个大顶堆，保存当前滑动窗口中的数据。滑动窗口每次移动一格，
 * 就将前面一个数出堆，后面一个数入堆。
***/
vector<int> Leetcode::maxInWindows(const vector<int>& num, unsigned int size)
{
    vector<int> ret;
    if(num.size() == 0 || size < 1 || num.size() < size){
        return ret;
    }
    int n = num.size();
    for(int i = 0; i+size-1 < n; i++){
        int j = i + size -1;
        int max_val = num[j];
        for(int k = i; k < j; ++k){
            max_val = max(max_val,num[k]);
        }
        ret.push_back(max_val);
    }
    return ret;
}

/***************************************栈/队列/堆*******************************************/


/****************************************双指针**********************************************/
void Leetcode::two_pointer_test()
{
    cout << "这是双指针的代码测试" << endl;
    cout << "请选择测试题目：";
    int num;//题号
    cin >> num;
    if(num == 1){
        cout << "第一题(两数之和 II)测试："<< endl;
        vector<int> numbers{1,2,3,4,5};
        int target= 4;
        twoSum(numbers,target);
    }else if( num == 2){
        cout << "第二题(两数平方和)测试："<< endl;
        cout << "请输入测试的数：";
        int target;
        cin >> target;
        if(judgeSquareSum(target)){
            cout << target << "是两个数的平方和！"<< endl;
        }else{
            cout << target << "不是两个数的平方和！"<< endl;
        }

    }else if(num == 3){
        cout << "第三题(反转字符串中的元音字母)测试："<< endl;
    }else if(num == 4){
        cout << "第四题(回文字符)测试："<< endl;
        cout << "请输入要测试的字符串:";
        string s;
        cin >> s;
        if(validPalindrome(s)){
            cout << s << "是回文字符串！"<< endl;
        }else{
            cout << s << "不是回文字符串！"<< endl;
        }
    }else if(num == 5){
        cout << "第五题(合并两个有序数组)测试："<< endl;
        vector<int> n1{1,2,3};
        vector<int> n2{4,5,6};
        int m = 3;
        int n = 3;
        merge(n1,m,n2,n);
    }else if(num == 6){
        cout << "第六题(判断链表中是否存在环)测试："<< endl;
        if(hasCycle(CreateList(5))){
            cout << "链表中存在环"<<endl;
        }else{
            cout << "链表中不存在环"<<endl;
        }
    }else if(num == 7){
        cout << "第七题(最长子序列)测试："<< endl;
        cout << "请输入字符串：";
        string s;
        cin >> s;
        vector<string> dictionary{"I","am", "the", "leetcode"};
        findLongestWord(s, dictionary);
    }
}

//1:两数之和 II - 输入有序数组
vector<int> Leetcode::twoSum(vector<int>& numbers, int target)
{
    int low = 0, high = numbers.size() - 1;
    while (low < high) {
        int sum = numbers[low] + numbers[high];
        if (sum == target) {
            return {low + 1, high + 1};
        } else if (sum < target) {
            ++low;
        } else {
            --high;
        }
    }
    return {-1, -1};
}

//2: 两数平方和
bool Leetcode::judgeSquareSum(int c)
{
    long left = 0;
    long right = (int)sqrt(c);
    while (left <= right) {
        long sum = left * left + right * right;
        if (sum == c) {
            return true;
        } else if (sum > c) {
            right--;
        } else {
            left++;
        }
    }
    return false;
}

/*
//3:反转字符串中的元音字母
string Leetcode::reverseVowels(string s)
{
    auto isVowel = [vowels = "aeiouAEIOU"s](char ch) {
        return vowels.find(ch) != string::npos;
    };

    int n = s.size();
    int i = 0;
    int j = n - 1;
    while(i < j){
        while(i < n && !isVowel(s[i])){
            ++i;
        }
        while(j>0 && !isVowel(s[j])){
            --j;
        }
        if(i < j){
            swap(s[i],s[j]);
            ++i;
            --j;
        }
    }
    return s;
}
*/

//4:回文字符串
bool Leetcode::validPalindrome(string s)
{
    int l = 0, r = s.size() - 1;
    while(l < r){
        if(s[l] == s[r]){
            l++;
            r--;
        }else{
            return isValid1(s,l+1,r) || isValid1(s,l,r-1);
        }
    }
    return true;
}

//5: 合并两个有序数组
void Leetcode::merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    int p1 = 0, p2 = 0;
	int sorted[6];
	int cur;
    while (p1 < m || p2 < n) {
		if (p1 == m) {
			cur = nums2[p2++];
		}
		else if (p2 == n) {
			cur = nums1[p1++];
		}
		else if (nums1[p1] < nums2[p2]) {
			cur = nums1[p1++];
		}
		else {
			cur = nums2[p2++];
		}
			sorted[p1 + p2 - 1] = cur;
		}
		for (int i = 0; i < 6; i++) {
			nums1[i] = sorted[i];
		}
}
bool Leetcode::isValid1(string s, int l, int r)
{
    while(l<r){
        if(s[l] == s[r]){
            l++;
            r--;
        }else{
            return false;
        }
    }
    return true;
}

//6:判断链表中是否存在环
bool Leetcode::hasCycle(ListNode *head){
    if(!head){
            return false;
        }
        struct ListNode *ptr1, *ptr2 = head->next;
        while(ptr1 && ptr2){
            if(ptr1 == ptr2){
                return true;
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            if(!ptr2) break;
            ptr2 = ptr2->next;
        }
        return false;
}

//7:最长子序列
string Leetcode::findLongestWord(string s, vector<string>& dictionary)
{
    string ans;
    for (string d:dictionary){
        int j = 0;
        for(int i = 0; i < s.size() && j < d.size(); i++){
            if(d[j] == s[i]){
                j++;
            }
        }
        if(j == d.size()){
            if(d.size() > ans.size()){
                ans = d;
            }else if(d.size() == ans.size()){
                ans = d < ans?d:ans;
            }
        }
    }
    return ans;
}

/***************************和为s的两个数***********************************/
/***题目描述
 * 在有序数组中找出两个数，使得和为给定的数 S。
 * 如果有多对数字的和等于 S，输出两个数的乘积最小的。
***/
/***解题思路
 * 使用双指针，一个指针指向元素较小的值，一个指针指向元素较大的值。
 * 指向较小元素的指针从头向尾遍历，指向较大元素的指针从尾向头遍历。
 * 如果两个指针指向元素的和 sum == target，那么这两个元素即为所求。
 * 如果 sum > target，移动较大的元素，使 sum 变小一些；
 * 如果 sum < target，移动较小的元素，使 sum 变大一些。
***/
vector<int> Leetcode::FindNumberswithsum(vector<int> array, int sum)
{
    if (array.empty()){
        return vector<int>();
    }
    int tmp = INT_MAX;//最大整数,用来表示最小的乘积
    pair<int, int> ret;
    int i = 0, j = array.size();
    while(i < j){
        if(array[i] + array[j - 1] == sum){
            if(array[i] * array[j - 1] < tmp){
                tmp = array[i] * array[j - 1];
                ret = {i, j -1};
            }
            ++i, --j;
        }else if(array[i] + array[j - 1] < sum){
            ++i;
        }else{
            --j;
        }
    }
    if(ret.first == ret.second){
        return vector<int>();
    }
    return  vector<int>({array[ret.first], array[ret.second]});
}

/***************************和为s的连续正数序列***********************************/
/***题目描述
 * 输出所有和为 S 的连续正数序列。例如和为 100 的连续序列有：
 * [9, 10, 11, 12, 13, 14, 15, 16]
 * [18, 19, 20, 21, 22]
***/

vector<vector<int> > Leetcode::FindContinuousSequence(int sum)
{
    vector<vector<int>> ret;
    int l = 1, r = 1;
    int tmp = 0;
    while(l < sum / 2){
        if(tmp < sum){
            tmp += r;
            ++r;
        }else if(tmp > sum){
            tmp -= l;
            ++l;
        }else{
            vector<int> ans;
            for(int k=l; k < r; ++k){
                ans.push_back(k);
            }
            ret.push_back(ans);
            tmp -= l;
            ++l;
        }
        
    }
    return ret;
}

/*****************************翻转单词顺序列*******************************/
/***题目描述
 * Input:"I am a student."
 * output:"student. a am I"
***/
string Leetcode::ReverseSentence(string str) 
{
    if(str.empty()){
        return str;
    }
    int i = 0, sz = str.size();
    while(i < sz && str[i] == ' '){
        ++i;
    }
    if(i == sz){
        return str;
    }
    string ret = "";
    string tmp = "";
    bool hasstr = false;
    for(int i = sz - 1; i >= 0; --i){
        //合并一个单词
        if(str[i] != ' '){
            tmp = str[i] + tmp;
            hasstr = true;
        }else if (str[i] == ' ' && hasstr){
            ret = ret + tmp + " ";
            tmp = " ";
            hasstr = false;
        }
    }
    if(tmp != ""){
        ret += tmp;
    }
    return ret;
}

/*******************************左旋转字符串********************************/
/***题目描述
 * 将字符串 S 从第 K 位置分隔成两个子字符串，并交换这两个子字符串的位置。
 * Input:S="abcXYZdef"
 * Output:"XYZdefabc"
***/
/***解题思路
 * 1 利用两个循环,将string分割成两个部分,左和右,然后输出右+左
 * 2 使用标准库
***/
string Leetcode::LeftRotateString1(string str, int n)
{
    string ret;
    string left, right;
    int sz = str.size();
    for(int i = 0; i < n; i++){
        left += str[i];
    }
    for(int j = n; j < sz; j++){
        right += str[j];
    }
    ret = right + left;
    return ret; 
}

string Leetcode::LeftRotateString2(string str, int n)
{
    if(n > str.size()){
        return str;
    }
    return str.substr(n) + str.substr(0, n);
}
/****************************************双指针**********************************************/


/****************************************链表***********************************************/
//链表测试
void Leetcode::listnode_test()
{
    Leetcode leetcode;
    cout << "这是链表的代码测试" << endl;
    cout << "请选择测试题目：";
    int num;//题号
    cin >> num;
    switch (num){
        case 1:
        cout << "第一题(寻找两个链表的交点)测试："<< endl;
        printList(getIntersectionNode(CreateList(5),CreateList(5)));
        break;

        case 2:
        cout << "第二题(反转链表)测试："<< endl;
        printList(reverseList(CreateList(5)));
        break;

        case 3:
        cout << "第三题(合并两个有序链表)测试："<< endl;
        printList(mergeTwoLists(CreateList(5),CreateList(5)));
        break;

        case 4:
        cout << "第四题(删除排序链表中的重复元素)测试："<< endl;
        printList(CreateList(5));
        break;

        case 5:
        cout << "第五题(删除链表的倒数第n个节点)测试："<< endl;
        cout << "请输入元素n:";
        int n;
        cin >> n;
        cout << endl;
        printList(removeNthFromEnd(CreateList(5),3));
        break;

        case 6:
        cout << "第六题(两两交换链表中的节点)测试："<< endl;
        printList(swapPairs(CreateList(4)));
        break;

        case 7:
        cout << "第七题(链表求和)测试："<< endl;
        printList(addTwoNumbers(CreateList(3), CreateList(4)));
        break;

        case 8:
        cout << "第八题测试："<< endl;
        if(isPalindrome(CreateList(5))){
            cout << "此链表是回文链表"<<endl;
        }else{
            cout << "此链表不是回文链表"<<endl;
        }
        break;

        case 9:
        cout << "第九题(分隔链表)测试："<< endl;
        cout << "请输入想把链表分割的部分" << endl;
        int k;
        cin >> k;
        splitListToParts(CreateList(5), k);
        break;

        case 10:
        cout << "第十题(奇偶链表)测试："<< endl;
        printList(oddEvenList(CreateList(5)));
        break;

        case 11:
        cout << "第十一题(链表排序冒泡法)测试："<< endl;
        Lsort(CreateList(5));
        break;

        case 12:
        cout << "第十二题(链表中倒数最后k个结点)测试："<< endl;
        cout << "请输入节点k";
        int k1;
        cin >> k;
        printList(FindKthToTail(CreateList(5), k1));
        break;

        case 13:
        cout << "第十三题(从尾到头打印链表)测试："<< endl;
        cout << "请输入选择方法几？";
        int method;
        cin >> method;
        if(method == 1){
            printListFromTailToHead(CreateList(5));
        }else if(method == 2){
            printListFromTailToHead1(CreateList(5));
        }
        break;
    }
}

//基础：创建和打印链表
Leetcode::ListNode* Leetcode::CreateList(int count)
{
    ListNode* pNode; //未串联起的单个节点
    ListNode* pHead; //要返回的节点
    ListNode* pTemp; //临时变量
    for(int i = 1; i <= count; i++){
        int num;
        cout << "请输入第" << i << "个数:";
        cin >> num;
        if(i == 1){
            //进行初始化
            pNode = new ListNode(num);
            pNode->next = NULL;
            pHead = pNode; //用这个节点将各个节点串联起来
        }else{
            pTemp = new ListNode(num); //将各个节点赋值
            pNode->next = pTemp; //将上一节点和当前节点串联起来
            pNode = pTemp;//指针处于当前节点中
        }
    }
    return pHead;
}

void Leetcode::printList(ListNode* pHead)
{
    ListNode* pTraverse = pHead;
    if(!pTraverse){
        return;
    }
    while(pTraverse){
        cout << pTraverse->val << " ";
        pTraverse = pTraverse->next;
    }
    cout << endl;
}

//1:寻找两个链表的交点
Leetcode::ListNode* Leetcode::getIntersectionNode(ListNode *headA, ListNode *headB)
{
    
    if(headA == nullptr || headB == nullptr){
        return nullptr;
    }
    ListNode *pA = headA, *pB = headB;
    while(pA != pB){
        pA = pA == nullptr ? headB : pA->next;
        pB = pB == nullptr ? headA : pB->next;
    }
    return pA;
}

//2:反转链表
Leetcode::ListNode* Leetcode::reverseList(ListNode* head)
{
    /*方法１－迭代＊／
    ／＊
    if(head == nullptr){
        return nullptr;
    }
    ListNode *pre = nullptr;
    ListNode *cur = head;
    while(cur){
        ListNode* next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
    */

   /*方法２－递归*/
   if(!head || !head->next) {
       return head; //链表为空或只有一个元素返回本身
   }
   ListNode* p = reverseList(head->next);
   head->next->next = head;
   head->next = nullptr;
   return p;
    
}

//3:合并两个有序链表
Leetcode::ListNode* Leetcode::mergeTwoLists(ListNode* list1, ListNode* list2)
{
    ListNode* preHead = new ListNode(-1);
    ListNode* prev = preHead;
    while(list1 != nullptr && list2 != nullptr){
        if(list1->val < list2->val){
            prev->next = list1;
            list1 = list1->next;
        }else{
            prev->next = list2;
            list2 = list2->next;
        }
        prev = prev->next;
    } 
    //合并后 l1 和 l2 最多只有一个还未被合并完，我们直接将链表末尾指向未合并完的链表即可
    prev->next = list1 == nullptr ? list2 : list1;
    return preHead->next;
}

/*****************************4:删除链表中的重复节点*****************************/
/***题目描述
 * 在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，
 * 返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
 * 示例:输入:{1,2,3,3,4,4,5}
 * 输出:{1,2,5}
***/
/***解题思路
 * 在遍历单链表的时候，检查当前节点与下一点是否为相同值，如果相同，
 * 继续查找祥同值的最大长度，然后指针改变指向。
 ***/
Leetcode::ListNode* Leetcode::deleteDuplication(ListNode* pHead)
{
    ListNode *vhead = new ListNode(-1);
    vhead->next = pHead;
    ListNode *pre = vhead, *cur = pHead;
    while(cur){
        if(cur->next && cur->val == cur->next->val){
            cur = cur->next;
            while(cur->next && cur->val == cur->next->val){
                cur = cur->next;
            }
            cur = cur->next;
            pre->next = cur;
        }else{
            pre = cur;
            cur = cur->next;
        }
    }
    return vhead->next;
}

//5:删除链表的倒数第n个节点
Leetcode::ListNode* Leetcode::removeNthFromEnd(ListNode* head, int n)
{
    ListNode* dummy = new ListNode(0);
    ListNode* first = head;
    ListNode* second = dummy;
    for(int i = 0; i < n; ++i){
        first = first->next;
    }
    while(first){
        first = first->next;
        second = second->next;
    }
    second->next = second->next->next;
    ListNode* ans = dummy->next;
    delete dummy;
    return ans;
}

//6:两两交换链表中的节点
Leetcode::ListNode* Leetcode::swapPairs(ListNode* head)
{
    ListNode* dummyHead = new ListNode(0);
    dummyHead->next = head;
    ListNode* temp = dummyHead;
    while(temp->next != nullptr && temp->next->next != nullptr){
        ListNode* node1 = temp->next;
        ListNode* node2 = temp->next->next;
        temp->next = node2;
        node1->next = node2->next;
        node2->next = node1;
        temp = node1;
    }
    return dummyHead->next;
}

//7:链表求和
Leetcode::ListNode* Leetcode::addTwoNumbers(ListNode* l1, ListNode* l2)
{
    stack<int> s1, s2;
    while(l1){
        s1.push(l1->val);
        l1=l1->next;
    }
    while(l2){
        s2.push(l2->val);
        l2=l2->next;
    }
    int carry = 0;
    ListNode* ans = nullptr;
    while(!s1.empty() or !s2.empty() or carry!=0){
        int a = s1.empty() ? 0 : s1.top();
        int b = s2.empty() ? 0 : s2.top();
        if(!s1.empty()) s1.pop();
        if(!s2.empty()) s2.pop();
        int cur = a + b + carry;
        carry  =cur / 10;
        cur %= 10;
        auto curnode = new ListNode(cur);
        curnode->next = ans;
        ans = curnode;
    }
    return ans;
}

//8:回文链表
bool Leetcode::isPalindrome(ListNode* head)
{
    if(head == nullptr){
        return true;
    }
    //找到前半部分链表的尾结点并反转后半部分链表
    ListNode* firstHalfEnd = end0FirstHalf(head);
    ListNode* secondHalfStart = reverseList(firstHalfEnd->next);

    //判断是否回文
    ListNode* p1 = head;
    ListNode* p2 = secondHalfStart;
    bool result = true;
    while(result && p2 != nullptr){
        if(p1->val != p2->val){
            result = false;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    //还原链表并返回结果
    firstHalfEnd->next = reverseList(secondHalfStart);
    return result;
}
Leetcode::ListNode* Leetcode::end0FirstHalf(ListNode* head)
{
    ListNode* fast = head;
    ListNode* slow = head;
    while(fast->next!=nullptr && fast->next->next != nullptr){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

//9:分隔链表
vector<Leetcode::ListNode*> Leetcode::splitListToParts(ListNode* head, int k)
{
    int n = 0;
    ListNode* temp = head;
    while(temp != nullptr){
        n++;
        temp = temp->next;
    }
    int quotient = n/k, remainder = n%k;

    //代表ｋ个空节点的数组
    vector<ListNode*> parts(k,nullptr);
    ListNode* curr = head;
    for(int i = 0; i < k && curr != nullptr; i++){
        parts[i] = curr;
        int partSize = quotient + (i < remainder ? 1 : 0);
        for(int j = 1; j < partSize; j++){
            curr = curr->next;
        }
        ListNode* next = curr->next;
        curr->next = nullptr;
        curr = next;
    }
    return parts;
}

//10:奇偶链表
Leetcode::ListNode* Leetcode::oddEvenList(ListNode* head)
{
    if(head == nullptr){
        return head;
    }
    ListNode* evenHead = head->next;
    ListNode* odd = head;//奇数节点
    ListNode* even = evenHead;//偶数节点
    while(even != nullptr && even->next != nullptr){
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}

//11:链表排序冒泡法
void Leetcode::Lsort(ListNode *head)
{
    int x = 0, t;
    Leetcode::ListNode *p, *tail, *next;//tail代表链表每次排序后未排序链表的最后一个节点
    if(head == NULL){
        return;
    }
    for(p=head; p->next!=NULL;p = p->next);
    tail = p;
    while(tail!=head){
        for(p=head;p!=tail;p=p->next){
            if(p->val > p->next->val){
                t = p->val;
                p->val = p->next->val;
                p->next->val = t;
            }
            next = p;
        }
        tail = next;
    }
}

/*****************************12:链表中倒数最后k个结点*****************************/
/***题目描述
 * 输入一个链表，输出一个链表，该输出链表包含原链表中从倒数第k个结点至尾节点的全部节点。
 * 如果该链表长度小于k，请返回一个长度为 0 的链表。
 * 示例:输入{1,2,3,4,5},1 
 * 返回值:{5}
***/
Leetcode::ListNode* Leetcode::FindKthToTail(ListNode* pHead, int k)
{
    stack<ListNode *> stack;//栈
    ListNode *answer=NULL;//返回值
    while(pHead)//全部入栈
    {
        stack.push(pHead);
        pHead=pHead->next;
    }
    if(k>stack.size()||stack.size()==0) //判断特殊值
        return answer;
    for(int i=0;i<k;i++)
    {
        answer=stack.top();
        stack.pop();
    }
    return answer;
}

/*******************************13:从尾到头打印链表********************************/
/***题目描述
 * 从尾到头反过来打印出每个结点的值。
 * input:1 2 3
 * output 3 2 1
***/
/***结题思路
 * 1 递归法
 * 使用递归先走到链表的末尾，再在回溯时将链表节点中的值加入到数组中。
 * 递归边界： head == NULL;
 * 递归阶段：一直传入head->next;
 * 回溯阶段：将值加入到数组；
***/
void Leetcode::recur(ListNode* head)
{
    if(head == NULL){//表示递归结束
        return;
    }
    recur(head->next);
    ans.push_back(head->val);//回溯将链表值加入到ans
}

vector<int> Leetcode::printListFromTailToHead(ListNode* head){
    recur(head);
    return ans;
}

vector<int> Leetcode::printListFromTailToHead1(ListNode* head)
{
    vector<int> value;
    if(head != NULL){
        value.insert(value.begin(), head->val);
        if(head->next != NULL){
            vector<int> tempVec = printListFromTailToHead1(head->next);
            value.insert(value.begin(),tempVec.begin(),tempVec.end());
        }
    }
    return value;
}
/****************************************链表***********************************************/

/****************************************栈和队列***********************************************/
//栈和队列测试
void Leetcode::stak_que_test()
{
    cout << "这是栈和队列的代码测试" << endl;
    cout << "请选择测试题目：";
    int num;//题号
    cin >> num;
    switch (num){
        case 1:
        cout << "第一题(用栈实现队列)测试："<< endl;
        /*
        myqueue1.push(1);
        myqueue1.push(2);
        myqueue1.push(5);
        myqueue1.peek();
        myqueue1.pop();
        myqueue1.empty();
        */
        break;

        case 2:
        cout << "第二题(用队列实现栈)测试："<< endl;
        /*
        mystack1.push(1);
        mystack1.push(2);
        mystack1.push(5);
        mystack1.pop();
        mystack1.top();
        */
        break;

        case 3:
        cout << "第三题(最小栈)测试："<< endl;
        MinStack minstack;
        minstack.push(-2);
        minstack.push(0);
        minstack.push(-3);
        minstack.getMin();
        minstack.pop();
        minstack.top();
        minstack.getMin();
        break;

        cout << "第四题(有效的括号)测试："<< endl;
        string s = {"{()}"};
        if(isValid(s)){
            cout << "闭合"<<endl;
        }else{
            cout << "不闭合"<<endl;
        }
        break;

        cout << "第五题(每日温度)测试："<< endl;
        vector<int> temperatures{73,74,75,71,69,72,76,73};
        dailyTemperatures(temperatures);
        break;

        cout << "第六题(下一个更大元素)测试："<< endl;
        vector<int> nums{1,2,1};
        nextGreaterElements(nums);
        break;

    }
}

//４:有效的括号
bool Leetcode::isValid(string s)
{
    int n = s.size();
    //基数不会闭合
    if(n % 2 == 1){
        return false;
    }

    unordered_map<char,char> pairs = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };
    stack<char> stk;
    for(char ch:s){
        if(pairs.count(ch)){
            if(stk.empty() || stk.top() != pairs[ch]){
                return false;
            }
            stk.pop();
        }else{
            stk.push(ch);
        }
    }
    return stk.empty();
}

//5:每日温度
vector<int> Leetcode::dailyTemperatures(vector<int>& temperatures)
{
    int n = temperatures.size();
    vector<int> ans(n);
    stack<int> s;
    for(int i = 0; i < n; ++i){
        while(!s.empty() && temperatures[i] > temperatures[s.top()]){
            int previousIndex = s.top();
            ans[previousIndex] = i - previousIndex;
            s.pop();
        }
        s.push(i);
    }
    return ans;
}

//6:下一个更大元素
vector<int> Leetcode::nextGreaterElements(vector<int>& nums)
{
    int n = nums.size();
    vector<int> ret(n,-1);
    stack<int> stk;
    for(int i = 0; i < n * 2 - 1; i++){
        while(!stk.empty() && nums[stk.top()] < nums[i % n]){
            ret[stk.top()] = nums[i % n];
            stk.pop();
        }
        stk.push(i % n);
    }
    return ret;
}
/****************************************栈和队列***********************************************/

/****************************************树***********************************************/

/*****************************重建二叉树****************************/
/***题目描述
 * 给定某二叉树的前序遍历和中序遍历，请重建出该二叉树并返回它的头结点。
 * 例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，
 * 则重建出如下图所示。
***/
/***提示:
 * 1.0 <= pre.length <= 2000
 * 2.vin.length == pre.length
 * 3.-10000 <= pre[i], vin[i] <= 10000
 * 4.pre 和 vin 均无重复元素
 * 5.vin出现的元素均出现在 pre里
 * 6.只需要返回根结点，系统会自动输出整颗树做答案对比
***/
/***示例
 * 输入:[1,2,4,7,3,5,6,8],[4,7,2,1,5,3,8,6]
 * 返回值:{1,2,3,4,#,5,6,#,7,#,#,8}
 * 说明：返回根节点，系统会输出整颗二叉树对比结果 
 * 输入:[1],[1]
 * 返回值:{1}
 * 输入:[1,2,3,4,5,6,7],[3,2,4,1,6,5,7]
 * 返回值:{1,2,5,3,4,6,7}
***/

/****************************************树***********************************************/
void Leetcode::tree_test()
{
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
    //string s = "abpcplea";
    //vector <string> d{"ale","apple","monkey","cplea"};
    //leetcode.findLongestWord(s,d);
}

int Leetcode::findShortestSubArray(vector<int>& nums)
{
const int n = nums.size();
        vector<int> cnt(50010), first(50010, -1);
        pair<int, int> ans = {0, 0};
        for(int i = 0; i < nums.size(); ++i){
            cnt[nums[i]]++;
            if(first[nums[i]] == -1) first[nums[i]] = i; // 第一次出现，做好标记
            // 当出现更大度 或者 度相同但长度更短 则更新答案
            if(cnt[nums[i]] > ans.first || (cnt[nums[i]] == ans.first && i - first[nums[i]] + 1 < ans.second)){
                ans = {cnt[nums[i]], i - first[nums[i]] + 1}; // 更新更优答案
            }
        }
        return ans.second;
}

void Leetcode::hash_test(int is_in)
{
    unordered_set <int> hash;
    cout << "输入哈希表元素的个数：" ;
    int hash_size;
    cin >> hash_size;
    cout <<endl;
    for(int i = 0; i < hash_size; i++){
        cout << "请输入第" << i+1 << "个数:";
        int temp_input;
        cin >> temp_input;
        hash.insert(temp_input);
    }

    //检测某个数是否在哈希表中

    if(hash.count(is_in)){
        cout << is_in << "在哈希表中！" << endl;
    }else{
        cout << is_in << "不在哈希表中！"<< endl;
    }


    /*
    for(int j = 0 ; j < hash.size(); j++){
        cout << hash[j];
    }
    */
    
}

/*创建一棵树*/
/*
Leetcode::TreeNode*  Leetcode::CreateTree(TreeNode* root, int val)
{
    if(root == NULL){
        root->val = val;
        return root;
    }
    if(val < root->val){
        root->left = CreateTree(root->left,val);
    }else if(val > root->val){
        root->right = CreateTree(root->right, val);
    }
    return root;
}

int Leetcode::maxDepth(TreeNode* root)
{
    //深度优先法
    if(root == nullptr){
        return 0;
    }
    return max(maxDepth(root->left),maxDepth(root->right)) + 1;
}

void Leetcode::CreateBiTree(BiTree &BT)
{
    vector<int> tree_array{3,9,0,0,20,15,0,0,7,0,0};
    if(tree_array[++sub] == 0){
        BT = NULL;
    }else{
        BT = new BiTreeNode; //新建结点
        BT->data = tree_array[sub];
        CreateBiTree(BT->lchild);//创建左子树
        CreateBiTree(BT->rchild);//创建右子树
    }
}

void Leetcode::PreTraverse(BiTree T)
{
    if(T){
        cout << T->data << ' ';
        PreTraverse(T->lchild);
        PreTraverse(T->rchild);
    }
}

void Leetcode:: houxubianli()
{

}
*/


/**********************************栈和队列*****************************************/

/***用栈实现队列***/
void MyQueue::in2out()
{   
    while(!inStack.empty()){
        //将栈的数字顺序变一下
        outStack.push(inStack.top());
        //in到out中后in中的数据弹出
        inStack.pop();
    }
}

void MyQueue::push(int x)
{
    inStack.push(x);
}

int MyQueue::pop()
{
    if(outStack.empty()){
        in2out();
    }
    int x = outStack.top();
    outStack.pop();
    return x;
}

int MyQueue::peek()
{
    if(outStack.empty()){
        in2out();
    };
    return outStack.top();
}

bool MyQueue::empty()
{
    return outStack.top() && outStack.empty();
}

void MyStack::push(int x)
{
    queue2.push(x);
        while (!queue1.empty()) {
            queue2.push(queue1.front());
            queue1.pop();
        }
        swap(queue1, queue2);
}

int MyStack::pop()
{
    int r = queue1.front();
    queue1.pop();
    return r;
}

int MyStack::top()
{
    int r = queue1.front();
    return r;
}

bool MyStack::empty()
{
    return queue1.empty();
}

//3:最小栈
MinStack::MinStack()
{
    min_stack.push(INT_MAX);
}

void MinStack::push(int val) 
{
    x_stack.push(val);
    min_stack.push(min(min_stack.top(),val));
}
    
void MinStack::pop()
{
    x_stack.pop();
    min_stack.pop();
}
    
int MinStack::top() 
{
    return x_stack.top();
}
    
int MinStack::getMin()
{
    return min_stack.top();
}