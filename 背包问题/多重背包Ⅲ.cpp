/*
多重背包问题之单调队列优化：

首先是一般多重背包问题的状态转移方程，如下：

f(i,j) = max( f(i-1,j), f(i-1,j-v)+w, f(i-1,j-2*v)+2*w, ...... , f(i-1,j-s*v)+s*w );

就是轮到第i种物品时，从中选取0~s个，共s+1种选择的方法，相对于完全背包问题而言，
它就是求一段前缀的最大值（因为完全背包可以继续取到j-k*v==0为止）

对于上述状态转移方程，我们可以对j用a+bv的形式来进行表示，那么j-kv就是a+pv的表示方法

所以我们循环k∈[0,b],就可以表示j,j-v,j-2*v....j-s*v的情况了。k=0时，对应j-s*v；k=b时，对应j。

那么我们的状态转移方程就可以写成下面的形式：

f(i,a+bv) = max( f(i-1,a+bv), f(i-1,a+(b-1)v)+w, f(i-1,a+(b-2)v)+2w,....., f(i-1,a)+bw);

因为我们循环的是k，那么我们统一用带k的表达式表示max里面的每一项，即f(i-1,a+kv)+(b-k)w。(①式)

化简一下：[f(i-1,a+kv)+bw]-kw，由于bw是常量，所以在进行比较取最大值时，只需要比较f(i-1,a+kv)-kw,找到其最大值去更新

接下来我们用单调队列que去寻找这个k值，使得f(i-1,a+kv)-kw最大

*/
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;

const int N=20010;

int f[N],g[N];//f[N]是f(i)的情况，g[N]是f(i-1)的情况
int n,m;
int que[N];

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int v,w,s;
        cin>>v>>w>>s;
        memcpy(g,f,sizeof(f));
        for(int r=0;r<v;r++)//余数不同的类
        {
            int hh=0,tt=-1;
            for(int k=0;r+k*v<=m;k++)//同一类里面求max
            {
                
                if(hh<=tt&&k-que[hh]>s)//当k-que[hh]不在s里面
                {
                    hh++;
                }
                while(hh<=tt&&g[r+k*v]-k*w>=g[que[tt]*v+r]-que[tt]*w)//当前k加入队列与队尾进行比较
                {
                    tt--;
                }
                que[++tt]=k;//更新队列
                f[r+k*v]=g[que[hh]*v+r]+(k-que[hh])*w;//根据①式更新
            }
        }
    }

    cout<<f[m]<<endl;
    return 0;
}

