#include <bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<sstream>

using namespace std;

#define open  freopen("input.txt","r",stdin)
#define close  freopen ("output.txt","w",stdout)
#define db double
#define ll long long
#define ull unsigned long long
#define loop(i,a,n) for(int i=a;i<=n;i++)
#define sf scanf
#define sf1(a) sf("%d",&a)
#define sf2(a,b) sf("%d %d",&a,&b)
#define sf3(a,b,c) sf("%d %d %d",&a,&b,&c)
#define sf4(a,b,c,d) sf("%d %d %d %d",&a,&b,&c,&d)
#define sfd(a) sf("%lf",&a);
#define sfd2(a,b) sf("%lf %lf",&a,&b)
#define sfl1(a) sf("%lld",&a)
#define sfl2(a,b) sf("%lld %lld",&a,&b)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pf printf
#define rev(a) reverse(a.begin(),a.end())
#define pft(tc) printf("Case %d:",tc++)
#define PI (2.0*acos(0.0))
//#define PI acos(-1.0)
#define mem(a,v) memset(a,v,sizeof a)
#define endl '\n'
#define NL puts("")
#define pfi(a) pf("%d",a)
#define pfl(a) pf("%lld",a)
#define pb push_back
#define xx first
#define yy second
#define mp make_pair
#define bug pf("here is bug\n")


template <class T> inline T bigmod(T p,T e,T M)
{
    ll ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
}
template <class T> inline T gcd(T a,T b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
template <class T> inline T modinverse(T a,T M)
{
    return bigmod(a,M-2,M);
}   // M is prime}
template <class T> inline T bpow(T p,T e)
{
    ll ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p);
        p = (p * p);
    }
    return (T)ret;
}


//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={0,1,0,-1};int dy[]={1,0,-1,0}; //4 Direction

struct data
{
    int e1,e2;
    data() {}
    data(int a,int b)
    {
        e1=a,e2=b;
    }
    bool friend operator<(data a,data b)
    {
        return  a.e1> b.e1;// sort decreasingly but increasingly for priority_queue
    }
};

#define inf LONG_LONG_MAX
#define mod (ll) 1e9+7
#define eps 1e-6
#define MX 30007




int n,m,k;
ll N,M,K;
int val[MX];
int par[MX];
vector <int> vv[MX];
int lev[MX];
int pre[MX][25];
void dfs(int u,int p,int l)
{
    par[u]=p;
    lev[u]=l;
    loop(i,0,vv[u].size()-1)
    {
        int k=vv[u][i];
        if(k==p)
            continue;
        dfs(k,u,l+1);
    }
}


void lca_init()
{
    mem(pre,-1);
    for(int i=0; i<n; i++)
        pre[i][0]=par[i];

    for(int j=1; (1<<j)<n; j++)
    {
        for(int i=0; i<n; i++)
        {
            if(pre[i][j-1]!=-1)
            {
                pre[i][j]=pre[pre[i][j-1]][j-1];
            }
        }
    }

}

int find_lca(int u,int v)
{
    if(lev[u]<lev[v])
        swap(u,v);
    int mx=0;
    //pf("%d %d\n",lev[u],lev[v]);

    int log=1;
    while(1)
    {
        int next=log+1;
        if((1<<next)>lev[u])break;
        log++;

    }

    for(int i=log;i>=0;i--)
    {
        if(lev[u]-(1<<i)>=lev[v])
        {
            u=pre[u][i];
            mx+=val[u];
        }
    }

    if(u==v)
    {
        return mx+val[u];
    }
    mx+=val[u]+val[v];
    //pf("%d\n",mx);
    for(int i=log;i>=0;i--)
    {
        if(pre[u][i]!=-1 && pre[u][i]!=pre[v][i])
        {
            //bug;
            u=pre[u][i];
            v=pre[v][i];
            mx+=val[u]+val[v];
        }
    }
    return mx+val[pre[u][0]];

}


int main()
{

    int t,tc=1;
    sf1(t);
    while(t--)
    {
        sf1(n);
        loop(i,0,n-1)
        {
            sf1(val[i]);
        }
        loop(i,0,n-2)
        {
            int u,v;
            sf2(u,v);
            vv[u].pb(v);
            vv[v].pb(u);
        }
        dfs(0,-1,0);
        lca_init();
        sf1(m);
        pft(tc);
        NL;
        while(m--)
        {
            int x,y,q;
            sf3(q,x,y);
            if(q==0)
            {
                int res=find_lca(x,y);
                pf("%d\n",res);
            }
            else
            {
                val[x]=y;
            }
        }
        for(int i=0;i<n;i++)
        {
            vv[i].clear();
        }


    }
    return 0;
}

/*





*/


