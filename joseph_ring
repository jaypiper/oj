#include<iostream>
using namespace std;

int main(){
	int n,tem;
	int ans=0;
	cin>>n;
	for(int i=1;i<n;++i){
		cin>>tem;
		ans=(ans+tem+1)%(i+1);
	}
	cout<<ans;
	system("pause");
	return 0;
}

/*
description:现在有n个人, 编号从0到n−1,站成一圈, 编号为i的人右手边是编号为i+1的人(n−1 的右手边为0). 
进行一种约瑟夫环游戏的变种.游戏一共进行n−1 轮, 一开始编号为0的人手里拿着旗子.
在第i轮(从1开始数), 手上拿着旗子的人把旗子传给他右手边的人, 一共传w[i]次, 传完之后拿着旗子的人退出队伍, 
并把旗子传给他右手边的人.问最后剩在队伍里的人是谁.
input:先读入一个 n≤10^6,接下来n−1个整数, 分别代表 wn−1,wn−2,⋯,w2,w1(1≤wi≤10^9)
*/