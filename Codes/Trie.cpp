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
#define pff(x) pf("%d",x)
#define pfl(x) pf("%lld",x)
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
string a[100005];
struct trie
{

    trie *child[11];
    bool leaf;
    int pre_cnt;
    trie()
    {
        leaf=0;
        pre_cnt=0;
        for(int i=0;i<=10;i++)
        {
            child[i]=NULL;
        }
    }

};

trie *root;

trie init()
{
    root=new trie();
    root->leaf=0;
    root->pre_cnt=0;


}
void t_delete(trie *cur)
{
    for(int i=0;i<=10;i++)
    {
        if(cur->child[i]!=NULL)
        {
            t_delete(cur->child[i]);
            delete cur->child[i];
        }
    }
}


void t_insert(string word)
{
    trie *cur=root;
    cur->pre_cnt++;
    for(int i=0; i<word.length(); i++)
    {
        int k=word[i]-'0';
        if(cur->child[k]==NULL)
        {
            cur->child[k]=new trie();
        }
        cur->child[k]->pre_cnt++;
        cur=cur->child[k];

    }
    cur->leaf=1;
}

bool t_search(string word)
{
    trie *cur=root;
    for(int i=0; i<word.length(); i++)
    {
        int k=word[i]-'0';
        if(cur->child[k]==NULL)
            return 0;
        cur=cur->child[k];
    }
    return cur->leaf;
}

int cnt_pre(string word)
{
    trie *cur=root;
    for(int i=0; i<word.size(); i++)
    {
        int k=word[i]-'0';
        if(cur->child[k]==NULL)
            return 0;
        cur=cur->child[k];
    }
    return cur->pre_cnt;
}
int main()
{
    int t,tc=1;
    sf1(t);
    while(t--)
    {


    }


    return 0;
}

/*




*/


