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
#define lll unsigned long long
#define loop(i,a,n) for(int i=a;i<=n;i++)
#define sf scanf
#define sf1(a) sf("%d",&a)
#define sf2(a,b) sf("%d %d",&a,&b)
#define sf3(a,b,c) sf("%d %d %d",&a,&b,&c)
#define sf4(a,b,c,d) sf("%d %d %d %d",&a,&b,&c,&d)
#define sfd(a) sf("%lf",&a)
#define sfd2(a,b) sf("%lf %lf",&a,&b)
#define sfl1(a) sf("%lld",&a)
#define sfl2(a,b) sf("%lld %lld",&a,&b)
#define sfl3(a,b,c) sf("%lld %lld %lld",&a,&b,&c)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pf printf
#define pfi(x) pf("%d",x)
#define pfl(x) pf("%lld",x)
#define NL puts("")
#define bug(x) cerr<<"Check it "<<x<<endl
#define pft(tc) printf("Case %d:",tc++)
#define pft2(tc) printf("Case #%d:",tc++)
#define PI (2.0*acos(0.0))
//#define PI acos(-1.0)
#define mem(a,v) memset(a,v,sizeof a)
#define endl '\n'
#define pb push_back
#define xx first
#define yy second
#define mp make_pair
#define all(a) a.begin(),a.end()
#define HASH1 (lll) 101949101
#define HASH2 (lll) 104282401
#define HASH3 (lll) 701393107
#define LEN(a) a.length()
#define sz size()
#define ITERATE(x,it) for(typeof(x.begin()) it=x.begin();it!=x.end();it++)
#define RITERATE(x,it) for(typeof(x.rbegin()) it=x.rbegin();it!=x.rend();it++)



//BIGMOD
template <class T> inline T bigmod(T p,T e,T M)
{
    ll ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
}
template <class T> inline T gcd(T a,T b){
    if(b==0)return a;
    return gcd(b,a%b);
}
template <class T> inline T lcm(T a,T b){
    return (a/gcd(a,b))*b;
}
template <class T> inline T modinverse(T a,T M){
    return bigmod(a,M-2,M);
}   // M is prime}
template <class T> inline T bpow(T p,T e){
    ll ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p);
        p = (p * p);
    }
    return (T)ret;
}

// BIT
// Define mx


// inline void add(int id,ll v,ll bit[]){
	// while(id<=mx){
		// bit[id]+=v;
		// id+=id&-id;
	// }
// }
// inline ll getsum(int id,ll bit[]){
	// ll sum=0;
	// while(id>0){
		// sum+=bit[id];
		// id-=id&-id;
	// }
	// return sum;
// }




//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={0,1,0,-1};int dy[]={1,0,-1,0}; //4 Direction


#define eps 1e-6
#define ub upper_bound // return the right most index of x<val
#define lb lower_bound // return the right most index of x<=val
#define linf 3000000000000000000ll
#define inf 999999999
#define MX 1000000
#define mod (ll) 1000000007


struct data
{

    data() {}

    bool friend operator<(data a,data b)
    {
        // return  a.one> b.one;// sort decreasingly but increasingly for priority_queue
    }
};



struct edge {
    int a,b;
    int flow,cap;
    edge(int _a,int _b,int _c,int _d) {
        a=_a,b=_b,cap=_c,flow=_d;
    }
};

struct Dinitz {
    int s,t,d[401],ptr[401];
    vector<edge> e;
    vector<int> g[401];

    void AddEdge(int a,int b,int cap) {
        edge e1=edge(a,b,cap,0);
        edge e2=edge(b,a,0,0);

        g[a].pb(e.sz);
        e.pb(e1);

        g[b].pb(e.sz);
        e.pb(e2);
    }

    bool Bfs() {

        queue<int> q;
        q.push(s);
        mem(d,-1);
        d[s]=0;

        while(!q.empty()&& d[t]==-1) {
            int u=q.front(); q.pop();

            for(int i=0;i<g[u].sz;i++) {
                int id=g[u][i];
                int v=e[id].b;

                if(d[v]==-1&&e[id].flow<e[id].cap) {
                    q.push(v);
                    d[v]=d[u]+1;
                }
            }
        }
        return d[t]!=-1;
    }

    int Dfs(int v,int flow) {
        if(!flow)   return 0;
        if(v==t)    return flow;

        for(;ptr[v]<g[v].sz;ptr[v]++) {
            int id=g[v][ ptr[v] ];
            int to=e[id].b;

            if(d[to]!=d[v]+1)       continue;

            int pushed=Dfs(to,min( flow,e[id].cap-e[id].flow ));

            if(pushed) {
                e[id].flow+=pushed;
                e[id^1].flow-=pushed;
                return pushed;
            }
        }
        return 0;
    }

    int dinitz() {
        int flow=0;
        while(1) {
            if(!Bfs()) break;

            mem(ptr,0);

            while(int pushed=Dfs(s,inf)) {
                flow+=pushed;
                if(pushed==0) break;
            }
        }
        return flow;
    }

    Dinitz(int _s,int _t) {
        s=_s,t=_t;
    }
};


int n,m,k;
ll N,M,K;

int main()
{

    int t,tc=1;


	return 0;
}

/*



*/
