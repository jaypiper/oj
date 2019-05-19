#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>
using namespace std;
struct dot
{
	double x;
	double y;
};
double compare_max(double a1,double a2,double a3)           //比较新的两边和原始最大值的大小
{
	if(a1>=a2&&a1>=a3) return a1;
	else if(a2>=a1&&a2>=a3) return a2;
	else if(a3>=a1&&a3>=a2) return a3;
}
double distan(dot dot1,dot dot2)         //计算两点距离
{
	return pow(dot1.x-dot2.x,2)+pow(dot1.y-dot2.y,2);
}
double area(dot dot1,dot dot2,dot dot3){     //求三角形面积，从而求出最大距离
  return abs(dot1.x*dot2.y+dot2.x*dot3.y+dot3.x*dot1.y-dot2.x*dot1.y-dot3.x*dot2.y-dot1.x*dot3.y);
}
int main()
{
   int n;
  cin>>n;
  vector<dot>store(n);
  int beg=0,opp=0;     //记录下开始位置和开始位置的对面位置，以01作为初始边
  double max=0;                 
  for(int i=0;i<n;i++)             
  {
       cin>>store[i].x>>store[i].y;
  }
  for(int i=2;i<n;i++){   
    if(area(store[0],store[1],store[i])>=area(store[0],store[1],store[(i+1)%n])){
      opp=i;
      break;
    }
  }
  max=compare_max(max,distan(store[0],store[opp]),distan(store[1],store[opp]));
  ++beg;
  for(;beg<n;++beg){     //每次转动一条边，判断转动后opp位置，计算当前最大距离
      for(int j=0;j<n;++j){
         if(area(store[beg],store[(1+beg)%n],store[(opp+j)%n])>area(store[beg],store[(beg+1)%n],store[(opp+j+1)%n])){
          opp=opp+j;
          break;
         }
      }
      max=compare_max(max,distan(store[beg],store[opp%n]),distan(store[(beg+1)%n],store[opp%n])); 
  }
    cout<<setiosflags(ios::fixed)<<setprecision(15)<<sqrt(max);  
    return 0;
} 

/* description:给定一个凸多边形，求多边形边界上的两点，使它们之间的距离最大。输出这个最大距离

input:第一行一个整数n (3≤n≤100000)，表示多边形的点数。接下来的n行，每行有两个整数x,y (∣x∣,∣y∣≤10^9)，
表示多边形的一个顶点。多边形的顶点以逆时针顺序给出。输入数据保证输入的点构成凸多边形，输入点中无两点重
合，无三点共线。

output:一行，表示答案。

ex: input:  4
            0 0
            1 0
            1 1
            0 1
    outout: 1.414213562373095
*/
