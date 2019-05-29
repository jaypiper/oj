#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
using namespace std;
const long long ansm=1e9+7;
const long long inpm=1e6;
int main(){
	int t,n;
	long long p,q,x,y,z;
	cin>>t;
	for(int l=0;l<t;++l){
		cin>>n>>p>>q>>x>>y>>z;
		vector<long long>num(inpm+1);
		vector<long long>counting(inpm+1,0);
		num[1]=p;
		num[2]=q;
		++counting[p];
		++counting[q];
		for(int i=3;i<=n;++i){
			num[i]=(x*num[i-2]+y*num[i-1]+z)%inpm+1;
			++counting[num[i]];
		}
		for(int i=1;i<=inpm;++i) counting[i]+=counting[i-1];
		vector<long long>tnum(n+1);
		vector<long long>tpos(n+1);
		for(int i=n;i>0;--i){
			tnum[counting[num[i]]]=num[i];
			tpos[counting[num[i]]]=i;
			--counting[num[i]];
		}
		vector<long long>new_num(n+2,-1),left(n+2,0),right(n+2,0),d(n+2,0),max(n+2,0),c(n+2,0);
		__int128 ans=0; //111
		for(int i=n;i>0;--i){
			long long k=tpos[i];
			new_num[k]=tnum[i];
			if(new_num[k-1]==-1&&new_num[k+1]==-1){
				left[k]=k;
				right[k]=k;
				d[k]=tnum[i];
				max[k]=tnum[i];
			}
			else if(new_num[k-1]==-1&&new_num[k+1]!=-1){
				right[k]=right[k+1];
				left[k]=k;
				d[k]=tnum[i]|d[k+1];
				left[right[k]]=k;
				max[k]=max[k+1];//1111111111
				d[right[k]]=d[k];
				
			}
			else if(new_num[k+1]==-1&&new_num[k-1]!=-1){
				left[k]=left[k-1];
				right[k]=k;
				right[left[k]]=k;
				d[k]=tnum[i]|d[k-1];
				max[k]=max[k-1];
				d[left[k]]=d[k];
			}
			else{
				left[k]=left[k-1];
				right[k]=right[k+1];
				left[right[k]]=left[k];
				right[left[k]]=right[k];
				d[k]=d[k-1]|tnum[i]|d[k+1];
				d[left[k]]=d[k];
				d[right[k]]=d[k];
				if(max[k-1]>max[k+1]) {
					max[k]=max[k-1];
					max[left[k]]=max[k];
					max[right[k]]=max[k];
				}
				else {
					max[k]=max[k+1];
					max[left[k]]=max[k];
					max[right[k]]=max[k];
				}
			}
				__int128 tem=(__int128)(max[k]-tnum[i])*(__int128)tnum[i]*(__int128)d[k]*(__int128)(right[k]-left[k]+1);
				if(tem>ans) ans=tem;
		}
		printf("%d\n",ans%ansm);
	}

	return 0;
}
/*
给定n个数的数组a1,a2...an

V(i,j)=(A(i,j)×B(i,j)−B(i,j)^2)×C(i,j)×D(i,j),1≤i≤j≤n
A:ai...aj 中最大值
B:最小值
C:j-i+1
D:ai|...|aj (或运算)
​​ 
输出V(i,j)的最大值对10^9+7取模后的结果。

注意是最大值取模，而不是取模后的最大值。

*/