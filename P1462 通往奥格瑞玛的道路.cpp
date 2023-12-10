#include <bits/stdc++.h>
using namespace std;
using P=pair<int,int>;
int n,m,b,u,v,w,sum,l,r,mid,check;
int f[10005],head[10005],dis[10005],ed[10005];

priority_queue<P,vector<P>,greater<P>> q;

struct edge{
	int u,v,w;
}e[100005];

void add(int u,int v,int w){
	e[++sum].u =head[u];
	e[sum].v =v;
	e[sum].w =w;
	head[u]=sum;
}

bool dijkstra(int x){
	if(x<f[1]) return 0;
	for(int i=1;i<=n;i++){
		dis[i]=1e9;
	}
	memset(ed,0,sizeof(ed));
	dis[1]=0;
	q.push(make_pair(0,1));
	while(!q.empty()){
		int now=q.top().second,next;
		q.pop();
		if(ed[now]) continue;
		ed[now]=1;
		next=head[now];
		while(next){
//			cout<<"Dick";
			if(f[e[next].v]<=x&&ed[e[next].v]==0&&dis[now]+e[next].w<dis[e[next].v])
			{dis[e[next].v]=dis[now]+e[next].w;
			q.push(make_pair(dis[e[next].v],e[next].v));}
			next=e[next].u; 
		}
	}	
	if(dis[n]<=b){
		return 1;
	}
	return 0;
}

int main() {
	scanf("%d%d%d",&n,&m,&b);
	for(int i=1;i<=n;i++) scanf("%d",&f[i]);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	if(dijkstra(INT_MAX)==0){
		printf("AFK");
		return 0;
	} 
	l=0,r=INT_MAX;
	while(l<=r){
		mid=(l+r)>>1;
		if(dijkstra(mid)){
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	printf("%d",l);
	return 0;
}

