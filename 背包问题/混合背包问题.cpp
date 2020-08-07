/*
有N种物品和一个容量是V的背包，物品有3类：分别可以用1次，多次，无数次
每种物品体积是vi,价值是wi，求哪些物品装入背包，在体积不超过背包容量的情况下，价值总和最大，
输出最大价值。

输入格式：
第一行N，V，空格隔开，分别代表物品的种类和背包的容积；
接下来N行，每行三个整数vi,wi,si，用空格隔开，分别表示第i种物品的体积、价值和可以用的次数

其中，si=-1代表只能用1次，si=0代表可以用无数次，si>0代表可以用si次

输出格式：
输出一个整数，即最大价值

数据范围：
0<N,V<=1000
0<vi,si<=1000
-1<=si<=1000

输入样例：
4 5
1 2 -1
2 4 1
3 4 0
4 5 2
 输出样例：
8
*/


//典型的三种背包问题三合一，只需要判断si符合哪种背包问题然后套入对应的状态转移方程即可
//注意多重背包问题需要二进制优化，否则会超时

#include<iostream>
#include<vector>
using namespace std;
const int N=1010;

int f[N];

int n,m;

int v[N],w[N],s[N];
struct Package{
    int v,w;
};
int main()
{
    cin>>n>>m;
    vector<Package> p;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i]>>w[i]>>s[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(s[i]==-1)
        {
            for(int j=m;j>=v[i];j--)
            {
                f[j]=max(f[j],f[j-v[i]]+w[i]);
            }
        }//01背包
        else if(s[i]==0)
        {
            for(int j=v[i];j<=m;j++)
            {
                f[j]=max(f[j],f[j-v[i]]+w[i]);
            }
        }//完全背包
        else
        {
            for(int k=1;k<=s[i];k*=2)
            {
                s[i]-=k;
                p.push_back({v[i]*k,w[i]*k});
            }
            if(s[i]>0)
            {
                p.push_back({v[i]*s[i],w[i]*s[i]});
            }
            
        }//多重背包
        //多重背包还需要二进制优化
        //不能无脑套公式
    }
    for(auto i:p)
            for(int j=m;j>=i.v;j--)
            {
                f[j]=max(f[j],f[j-i.v]+i.w);
            }
    //int sum=f[1];
    //for(int i=2;i<=m;i++)
    //{
    //    sum=max(sum,f[i]);
    //}
    cout<<f[m]<<endl;
    return 0;
}
