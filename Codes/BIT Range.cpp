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
#define llu unsigned long long
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
#define pfi(x) pf("%d",x)
#define pfl(x) pf("%lld",x)
#define NL puts("")
#define bug pf("here is bug\n")
#define pft(tc) printf("Case %d:",tc++)
#define PI (2.0*acos(0.0))
//#define PI acos(-1.0)
#define mem(a,v) memset(a,v,sizeof a)
#define endl '\n'
#define pb push_back
#define xx first
#define yy second
#define mp make_pair
#define all(a) a.begin(),a.end()


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
template <class T> inline T lcm(T a,T b)
{
    return (a/gcd(a,b))*b;
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


#define inf 99999999
#define MX 1000006
#define mod (ll) 1000000007
#define eps 1e-6
#define pfa(tc) printf("Case #%d:",tc++)

struct data
{
    int el1,el2;
    data() {}
    data(int a,int c)
    {
        el1=a,el2=c;
    }
    bool friend operator<(data a,data b)
    {
        return  a.el1> b.el1;// sort decreasingly but increasingly for priority_queue
    }
};


int n,m,k;
ll N,M,K;

int B1[1000006];
int B2[1000006];
int tree[1000006];
int a[1000006];
int read(int x[],int idx)
{
    int sum = 0;
    while(idx > 0)
    {
        sum += x[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

int update(int x[],int idx, int val)
{
    while(idx <= n)
    {
        x[idx] += val;
        idx += (idx & -idx);
    }
}

int query(int b)
{
    return read(B1,b)*b-read(B2,b);
}

int query2(int i, int j)
{
    return query(j) - query(i-1);
}


void update2(int l,int r,int v)
{
    update(B1,l,v);
    update(B1,r+1,-v);
    update(B2, l, v * (l-1));
    update(B2, r + 1, -v * r);
}

int main()
{
    int t,tc=1;
    sf1(t);
    while(t--)
    {
        sf1(n);
        for(int i=1;i<=n;i++)
        {
            sf1(k);
            a[k]=i;
            tree[i]=0,B1[i]=0,B2[i]=0;
//            update(tree,i,0);
//            update(B1,i,0);
//            update(B2,i,0);
        }
        int res=0;
        for(int i=n;i>=1;i--)
        {
            int pos=query2(a[i],a[i]);
            if(a[i]-pos!=i)
            {
                res++;
                update2(a[i]+1,n,1);
            }
        }
        pfa(tc);
        pf(" %d\n",res);
    }
    return 0;
}

/*




*/


