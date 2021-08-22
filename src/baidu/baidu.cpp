#include "baidu.h"

const int N = 2000;
int a[N],b[N];

/*****************1 百度2021校招－铺地毯********************/
    /****题目描述
     * T组数据，T<=1000, 在长度为L的走廊铺地毯，铺n块，
     * 每块的范围是[Left_i,Right_i]), n<=1000, 问最后每个位置的地板上有多少张地毯铺在上面。
    ****/
void Baidu::puditan()
{
   	int T,L,n,x,y;
    cout << "请输入T:";
	cin>>T;
	while(T--) {
        cout << "请输入L和n:";
		//scanf("%d%d",&L,&n);
        cin >> L >> n;
		while(n--) {
            cout << "请输入x和y:";
			//scanf("%d%d",&x,&y);
            cin >> x >> y;
			a[x]+=1;
			a[y+1]-=1;
		}
		for(int i=1;i<=L;++i) {
			b[i] = b[i-1]+a[i];
		}
		for(int i=1;i<L;++i)
			printf("%d ",b[i]);
		printf("%d\n",b[L]);
	}
}

/******************2 百度2021校招－分配角色*****************************/
/****题目描述
    * T组输入，T<=100， n个人，m个角色。每个人分配一个角色，每个人的戏份的期望值为ai, 每个角色的戏份为bi。给每个人分配的角色的
    * 戏份必须不小于此人的期望值。否则无法分配。现在要求满足愿望的人数最大话，输出每个人分配的角色，如果没分配，输出-1 
****/

/****分析
    * 贪心，把人按照戏份期望升序排列，角色用平衡二叉树(STL::set)维护，从头开始，
    * 每次分配能满足期望最小的角色(set::lower_bound)，然后从树中删去这个角色。
****/
const int NN = 1000+100;
struct Node{
	int id,want,op;
	bool operator < (const Node& rhs)const{
		return want==rhs.want?id<rhs.id:want < rhs.want;
	}
}node[NN];
bool cmp(const Node& a,const Node& b) {return a.id < b.id;}
void Baidu::assign_roles()
{
    int T,m,n;
    cout << "请输入T:";
	cin>>T;
	while(T--) {
        cout << "请输入n和m:";
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i) {
			scanf("%d",&node[i].want);
			node[i].id = i;
			node[i].op = -1;
		}
		set<pair<int,int> > st;
		pair<int,int> pr;	
		for(int i=1;i<=m;++i) {
			pr.second = i;
			scanf("%d",&pr.first);
			st.insert(pr);
		}
		sort(node+1,node+1+n);
		for(int i=1;i<=n;++i) {
			pr.first = node[i].want;
			pr.second = 0;
			auto it = st.lower_bound(pr);
			if(it==st.end()) break;
			node[i].op = it->second;
			st.erase(it);
		}
		sort(node+1,node+1+n,cmp);
		for(int i=1;i<n;++i) {
			printf("%d ",node[i].op);
		}
		printf("%d\n",node[n].op);
	}

}