/*
有 N种物品和一个容量是 V的背包。第 i种物品最多有 si件，每件体积是 vi，价值是 wi。
求解将哪些物品装入背包，可使物品体积总和不超过背包容量，且价值总和最大。
输出最大价值。
输入格式
第一行两个整数，N，V，用空格隔开，分别表示物品种数和背包容积。接下来有 N行，每行三个整数 vi,wi,si，
用空格隔开，分别表示第 i种物品的体积、价值和数量。
输出格式
输出一个整数，表示最大价值。
数据范围
0<N≤1000
0<V≤2000
0<vi,wi,si≤2000
提示：
本题考查多重背包的二进制优化方法。
输入样例
4 5
1 2 3
2 4 1
3 4 3
4 5 2
输出样例：
10
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
const int N=2010;

int f[N];
int n,m;

struct Package{
    int v,m;
};
int main()
{
    cin>>n>>m;
    vector<Package> p;
    for(int i=1;i<=n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        for(int k=1;k<=c;k*=2)
        {
            c-=k;
            p.push_back({a*k,b*k});
        }
        if(c>0)
        {
            p.push_back({c*a,b*c});
        }
    }
    for(auto i:p)
    {
        for(int j=m;j>=i.v;j--)
        {
            f[j]=max(f[j],f[j-i.v]+i.m);
        }
    }
    cout<<f[m]<<endl;
    return 0;
}
