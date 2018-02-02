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
#define sfl(a) sf("%lld",&a)
#define sfl2(a,b) sf("%lld %lld",&a,&b)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pf printf
#define bug pf("here is bug\n")
#define pft(tc) printf("Case %d:",tc++)
#define PI (2.0*acos(0.0))
//#define PI acos(-1.0)
#define mem(a,v) memset(a,v,sizeof a)
#define pb push_back
#define xx first
#define yy second
#define mp make_pair
#define inf 99999999
#define MX 1000006
#define mod (ll) 1000000007


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

struct zz
{
    int el1,el2;
    zz() {}
    zz(int a,int c)
    {
        el1=a,el2=c;
    }
    bool friend operator<(zz a,zz b)
    {
        return  a.el1> b.el1;// sort decreasingly but increasingly for priority_queue
    }
};


int a[100005];
int p[100005];
int res[100005];
int n,m,k;
ll N,M,K;

int getind(int l,int val)
{
    int s=0;
    int e=l;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(mid<l && a[p[mid]] < val && val<=a[p[mid+1]])
        {
            return mid+1;
        }
        else if(a[p[mid]] < val)
        {
            s=mid+1;
        }
        else
        {
            e=mid-1;
        }
    }
    return -1;
}


int LIS()
{
    mem(res,-1);
    p[0]=0;
    int len=0;
    for(int j=1; j<n; j++)
    {
        if(a[p[0]]>a[j])
        {
            p[0]=j;
        }
        else if(a[p[len]]<a[j])
        {
            len++;
            p[len]=j;
            res[p[len]]=p[len-1];
        }
        else
        {
            int ind=getind(len,a[j]);
            p[ind]=j;
            res[p[ind]]=p[ind-1];
        }

    }
    return len+1;
}

int main()
{
    int t,tc=1;
    int i=0;

    sf1(n);
    for(int i=0; i<n; i++)
    {
        sf1(a[i]);
    }
    int len=LIS();
    pf("%d\n",len);
    int x=p[len-1];
    //pf("%d\n",x);
    int v=0;
    while(x!=-1)
    {
        p[v++]=a[x];
        x=res[x];
    }
    for(int i=len-1; i>=0; i--)
    {
        pf("%d\n",p[i]);
    }



    return 0;
}

/*





*/

