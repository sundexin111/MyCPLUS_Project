#include "leetcode.h"

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

string LeftRotateString2(string str, int n)
{
    if(n > str.size()){
        return str;
    }
    return str.substr(n) + str.substr(0, n);
}

/****************************************双指针**********************************************/


/****************************************链表***********************************************/

/*******************************从尾到头打印链表********************************/
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

void Leetcode::printArray(vector<int> array)
{
    for(int i = 0; i < array.size(); i++){
        cout << array[i] << " ";
    }
    cout << endl;
}

/*****************************删除链表中的重复节点*****************************/
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

/*****************************链表中倒数最后k个结点*****************************/
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

/****************************************链表***********************************************/