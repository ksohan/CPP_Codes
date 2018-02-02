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
#define sz size()
#define sf scanf
#define sf1(a) sf("%d",&a)
#define sf2(a,b) sf("%d %d",&a,&b)
#define sf3(a,b,c) sf("%d %d %d",&a,&b,&c)
#define sf4(a,b,c,d) sf("%d %d %d %d",&a,&b,&c,&d)
#define sfd(a) sf("%lf",&a)
#define sfd2(a,b) sf("%lf %lf",&a,&b)
#define sfd3(a,b,c) sf("%lf %lf %lf",&a,&b,&c)
#define sfl1(a) sf("%lld",&a)
#define sfl2(a,b) sf("%lld %lld",&a,&b)
#define sfl3(a,b,c) sf("%lld %lld %lld",&a,&b,&c)

#define pii pair<int,int>
#define pll pair<ll,ll>

#define pf printf
#define pfi(x) pf("%d",x)
#define pfl(x) pf("%lld",x)
#define pf1(x) pf("%d\n",x)
#define pf2(x,y) pf("%d %d\n",x,y)
#define pf3(x,y,z) pf("%d %d %d\n",x,y,z)
#define pfl1(x) pf("%lld\n",x)
#define pfl2(x,y) pf("%lld %lld\n",x,y)
#define pfl3(x,y,z) pf("%lld %lld %lld\n",x,y,z)

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

//inline ll toint(string s){ll sum=0; for(int i=0;i<LEN(s);i++) sum=sum*10+(s[i]-'0'); return sum;}
//inline string tostr(ll n){string str=""; while(n){str+=(n%10)+'0';n/=10;} reverse(all(str)); return str;}
// inline lll HASH(lll oldhash,lll base,int sz,int bad,int jog){lll newhash=base*(oldhash-(bad*bpow(base,(lll)sz-1)))+jog; return newhash;}

// BIT

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



// int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
// int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
int dx[]={0,1,0,-1};int dy[]={1,0,-1,0}; //4 Direction


#define eps 1e-6
#define ub upper_bound // return the right most index of x<val
#define lb lower_bound // return the right most index of x<=val
#define linf 3000000000000000000ll
#define inf 999999999
#define MX 400
#define mod (ll) 998244353


struct data
{    
    data() {}
    
    bool friend operator<(data a,data b)
    {
		return 0;
        
    }
};

struct Edge {
    int u,v,cap,next;
    int cost;
    Edge() {}
    Edge(int a,int b,int c,int d,int e) {
        u=a,v=b,cap=c,cost=d,next=e;
    }
};


struct MFMC{
	int src,sink,tot,NE;
	int head[MX+10],par[MX+10];
	int dis[MX+10];
	bool chk[MX+10];
	Edge edge[2*MX*MX];
	
	MFMC(){}
	MFMC(int _src,int _snk,int _tot){
		src=_src,sink=_snk,tot=_tot;
		NE=0;
		for(int i=0;i<=MX;i++){
			head[i]=-1;
		}
	}
	
	void addEdge(int u,int v,int cap,int cost) {
    edge[NE]=Edge(u,v,cap,cost,head[u]);
    head[u]=NE++;
    edge[NE]=Edge(v,u,0,-cost,head[v]);
    head[v]=NE++;
}

	int spfa(){
		queue<int>Q;
		for(int i=0; i<=tot; i++) par[i]=-1,chk[i]=false,dis[i]=inf;
		Q.push(src);
		dis[src]=0;
		chk[src]=true;
		while(!Q.empty()) {
			int u=Q.front();
			Q.pop();
			chk[u]=false;
			for(int i=head[u]; i!=-1; i=edge[i].next) {
				int v=edge[i].v;
				int w=edge[i].cost;
				if(edge[i].cap>0 && dis[v]>dis[u]+w) {
					dis[v]=dis[u]+w;
					par[v]=i;
					if(!chk[v]) {
						chk[v]=true;
						Q.push(v);
					}
				}
			}
		}
		if(par[sink]==-1) return 0;
		int cap=inf;
		for(int i=par[sink]; i!=-1; i=par[edge[i].u]) cap=min(cap,edge[i].cap);
		for(int i=par[sink]; i!=-1; i=par[edge[i].u]) edge[i].cap-=cap,edge[i^1].cap+=cap;
		return cap;
	}

	pair<int,int> mfmc() {
		int ret=0;
		int flow=0;
		while(true) {
			int cap=spfa();
			if(cap==0) break;
			flow+=cap;
			ret+=(cap*dis[sink]);
		}
		return make_pair(flow,ret);
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
