/*
有 N件物品和一个容量是 V的背包。每件物品只能使用一次。
第 i件物品的体积是 vi，价值是 wi。
求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。
输出最大价值。
输入格式
第一行两个整数，N，V，用空格隔开，分别表示物品数量和背包容积。
接下来有 N行，每行两个整数 vi,wi，用空格隔开，分别表示第 i
件物品的体积和价值。
输出格式
输出一个整数，表示最大价值。
数据范围
0<N,V≤1000
0<vi,wi≤1000
*/

/*
01背包问题的状态转移方程：

f[i,j]=max(f[i-1][j],f[i-1][j-v[i]]+w[i])

可以从尾部往头部进行循环来将二维数组降至一维
*/

#include<iostream>
using namespace std;

const int N=1010;
int f[N];
int n,m;
int v[N],w[N];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i]>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=v[i];j--)
        {
            f[j]=max(f[j],f[j-v[i]]+w[i]);
        }
    }
    cout<<f[m]<<endl;
    return 0;
}
