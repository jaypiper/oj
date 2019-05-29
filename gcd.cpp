#include<iostream>
#include<stack>
using namespace std;
int gcd(int a1,int a2){
	int g=1;
	while(a1!=a2){
 		if(!(a1&1)&&!(a2&1)){
 			g*=2;
 			a1/=2;
 			a2/=2;
 		}
 		else if(!(a1%2)) a1/=2;
 		else if(!(a2%2)) a2/=2;
		else if(a1>a2) a1=a1-a2;
 		else a2=a2-a1;
 	}
 	return g*a1;
 }
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	char c;
	int inp;
	stack<int>num1;
	stack<int>num2;
	stack<int>g1;
	stack<int>g2;
	for(int i=0;i<n;++i){
		cin>>c;
		if(c=='+'){
			cin>>inp;
			num2.push(inp);
			if(g2.empty()) g2.push(inp);
			else g2.push(gcd(g2.top(),inp));
		}
		else if(c=='-'){
			if(!num1.empty()){
				num1.pop();
				g1.pop();
			}
			else{
				while(!num2.empty()){
					num1.push(num2.top());
					if(!g1.empty()) g1.push(gcd(g1.top(),num2.top()));
					else g1.push(num2.top());
					num2.pop();
					g2.pop();
				}
				num1.pop();
				g1.pop();
			}
		}
		else {
			if(g1.empty()) cout<<g2.top()<<endl;
			else if(g2.empty()) cout<<g1.top()<<endl;
			else cout<<gcd(g1.top(),g2.top())<<endl;
		}
	}

 	return 0;
}
/*
给定一个集合S，初始为空，现在你要处理以下3种操作:

+x : 向集合中添加一个数x≤10^9, 保证对于任何一个y∈S,都有y<x

−: 删掉集合S中值最小的数

? 询问集合SSS中所有数的最大公约数(greatest common divisor)

*/