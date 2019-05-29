#include<bits/stdc++.h>
#define maxn 200000
#define maxm 500000
using namespace std;
struct edge
{
	int a,b,len;
};
bool compare(const edge &x,const edge &y)
{
    return x.len<y.len;
}
edge e[maxm];
class UnionFind {
  std::vector<int> f;

public:
  UnionFind(int n = 0) : f(n + 1) {
    for (int i = 1; i <= n; i++) 
      f[i] = i;
  }
  int find(int x) {
    if (f[x] == x) return x;
    return f[x] = find(f[x]);
  }
  int merge(int u, int v) {
    u = find(u); v = find(v);
    if(u!=v)
	{
		if (u < v) f[v] = u; else f[u] = v;
		return 1;
	}
	return 0;
  }
};


int main()
{
	int n,m;
	cin>>n>>m;
	edge e[m];
	for(int i=0;i<m;i++)
	{
		cin>>e[i].a>>e[i].b>>e[i].len;
	}
	sort(e,e+m,compare);
	long long int sum=0;
	UnionFind u(n);
	int a,b,len;
	for(int i=0;i<m;i++)
	{
		a=e[i].a;
		b=e[i].b;
		len=e[i].len;
		if(u.find(a)!=u.find(b))
		{
			sum+=len;
			u.merge(a,b);
		}
		else
		;
	}
	cout<<sum;
	return 0;
}

/*
    discription:给定顶点数为n，边数为m的带权无向连通图G，所有顶点编号为1,2,⋯,n.求G的最小生成树的边权和。
    input:第一行两个整数 n,m (1≤n≤200000,0≤m≤500000),含义见题目描述。
          接下来的m行，每行3个整数u,v,w (1≤u,v≤n,1≤w≤10^9)表示一条连接顶点u,v,权值为w的边。
          输入数据中可能含有环边（loop, 即u=v的边）,你可以直接忽略这些边
    output:输出一个整数，表示最小生成树的权值和。

    ex: input:7 12
              1 2 9
              1 5 2
              1 6 3
              2 3 5
              2 6 7
              3 4 6
              3 7 3
              4 5 6
              4 7 2
              5 6 3
              5 7 6
              6 7 1
        output:16

    tip: union-find数据结构
*/    