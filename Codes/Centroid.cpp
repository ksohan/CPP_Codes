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
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);
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
#define eps 1e-6
#define ub upper_bound // return the right most index of x<val
#define lb lower_bound // return the right most index of x<=val
#define linf 3000000000000000000ll
#define inf 2000000000


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
// inline string tostr(ll n){string str=""; while(n){str+=(n%10)+'0';n/=10;} reverse(all(str)); return str;}
// inline lll HASH(lll oldhash,lll base,int sz,int bad,int jog){lll newhash=base*(oldhash-(bad*bpow(base,(lll)sz-1)))+jog; return newhash;}

// BIT


// int mx;
// template <class T> inline void add(int id,T v,T bit[]){
	// while(id<=mx){
		// bit[id]+=v;
		// id+=id&-id;
	// }
// }
// template <class T> inline T getsum(int id,T bit[]){
	// ll sum=0;
	// while(id>0){
		// sum+=bit[id];
		// id-=id&-id;
	// }
	// return (T)sum;
// }




//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={0,1,0,-1};int dy[]={1,0,-1,0}; //4 Direction




struct data
{
    
    data() {}
    
    bool friend operator<(data a,data b)
    {
		return 0;
        
    }
};

#define MX 1000000
#define mod (ll) 1000000007

int n,m,k;
ll N,M,K;
int tot;
vector <int> adj[100005];
int done[100005],subtree[100005];
int dist[20][100005];
int ans[100005];
int par[100005],level[100005];

void dfs(int u,int p){
	tot++;
	subtree[u]=1;
	for(int i=0;i<adj[u].sz;i++){
		int v=adj[u][i];
		if(v==p || done[v]) continue;
		dfs(v,u);
		subtree[u]+=subtree[v];
	}
}

int getcenter(int u,int p){
	for(int i=0;i<adj[u].sz;i++){
		int v=adj[u][i];
		if(v==p || done[v]) continue;
		if(subtree[v]>tot/2) return getcenter(v,u);
	}
	return u;
}

void setdist(int u,int p,int cost,int lev){
	dist[lev][u]=cost;
	for(int i=0;i<adj[u].sz;i++){
		int v=adj[u][i];
		if(v==p || done[v]) continue;
		setdist(v,u,cost+1,lev);
	}
}


void decompose(int u,int p,int lev){
	tot=0;
	dfs(u,-1);
	
	int center=getcenter(u,-1);
	setdist(center,-1,0,lev);
	done[center]=1;
	par[center]=p;
	level[center]=lev;
	for(int i=0;i<adj[center].sz;i++){
		int v=adj[center][i];
		if(v==p || done[v]) continue;
		decompose(v,center,lev+1);
	}
}

void update(int u){
	
	int v=u,lev=level[u];
	while(v!=-1){
		
		ans[v]=min(ans[v],dist[lev][u]);
		v=par[v];
		lev--;
	}
}
int query(int u){
	int v=u,lev=level[u];
	int res=inf;
	while(v!=-1){
		res=min(res,ans[v]+dist[lev][u]);
		lev--;
		v=par[v];
	}
	return res;
}


int main()
{
	
    int t,tc=1;
	sf2(n,m);
	for(int i=1;i<=n-1;i++){
		int x,y;
		sf2(x,y);
		adj[x].pb(y);
		adj[y].pb(x);
	}
	
	decompose(1,-1,0);
	for(int i=1;i<=n;i++) ans[i]=inf;
	
	update(1);
	for(int i=1;i<=m;i++){
		int q,x;
		sf2(q,x);
		if(q==2){
			pfi(query(x));
			NL;
		}
		else{
			update(x);
		}
	}
    
	return 0;
}

/*



*/
