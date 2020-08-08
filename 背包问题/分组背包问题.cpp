/*
有 N 组物品和一个容量是 V的背包。
每组物品有若干个，同一组内的物品最多只能选一个。
每件物品的体积是 vij，价值是 wij，其中 i是组号，j 是组内编号。
求解将哪些物品装入背包，可使物品总体积不超过背包容量，且总价值最大。
输出最大价值。
输入格式
第一行有两个整数 
N，V，用空格隔开，分别表示物品组数和背包容量。
接下来有 N组数据：每组数据第一行有一个整数 Si，表示第 i个物品组的物品数量；每组数据接下来有 Si行，每行有两个整数 vij,wij，用空格隔开，分别表示第 i个物品组的第 j个物品的体积和价值；
输出格式
输出一个整数，表示最大价值。
数据范围
0<N,V≤100
0<Si≤100
0<vij,wij≤100
输入样例
3 5
2
1 2
2 4
1
3 4
1
4 5
输出样例：
8
*/


#include<iostream>
using namespace std;
const int N=101;

int f[N],v[N],w[N];
int n,m;

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)//一共n组数据
    {
        int s;
        cin>>s;
        for(int j=0;j<s;j++)//每组数据输入
        {
            cin>>v[j]>>w[j];
        }
        for(int j=m;j>=0;j--)//从后面往前面枚举体积
        {
            for(int k=0;k<s;k++)//遍历一个组选择其中一个
            {
                if(j>=v[k])
                f[j]=max(f[j],f[j-v[k]]+w[k]);
            }
        }
    }
    cout<<f[m]<<endl;
    return 0;
}
