//#include <bits/stdc++.h>
//using namespace std;
//using P=pair<int,int>;
//int n,m,s;
//int vs[200005],dis[200005];
//vector<P> g[200005];
//priority_queue<P,vector<P>,greater<P>> q;
//
//void dijkstra(int s){
//	memset(dis+1,63,n<<2);
//	q.push({dis[s]=0,s});
//	while(!q.empty()){
//		int x=q.top().second;
//		q.pop();
//		if(vs[x]) continue;
//		vs[x]=true;
//		for (auto & [y, w] : g[x])
//			if(!vs[y]&&dis[y]>dis[x]+w)
//				q.push({dis[y]=dis[x]+w,y});
//	}
//}
//
//int main(){
//	int x,y,w;
//	ios_base::sync_with_stdio(false);
//	scanf("%d%d%d",&n,&m,&s);
//	for(int i=0;i<m;i++){
//		cin>>x>>y>>w;
//		g[x].push_back({y,w});
//	}
//	dijkstra(s);
//	for(int i=1;i<=n;i++){
//		cout<<dis[i]<<' '; 
//	}
//	return 0;
//}

#include <bits/stdc++.h>
using namespace std;
int n,m,s,u,v,w,sum;
int h[400010],dis[200005],pd[400010];

struct edge {
	int next;
	int to;
	int w;
}e[200005];

struct node{
	int p;
	int dist;
	bool operator <(const node& x)const{
		return x.dist<dist;
	}
};

priority_queue<node> q;

void add(int u,int v,int w){
	e[++sum]=edge{h[u],v,w};
	h[u]=sum;
}

void dijkstra(int s){
	dis[s]=0;
	q.push(node{s,0});
	while(!q.empty()){
		node now,next;
		now=q.top();
		q.pop();
		if(pd[now.p]) continue;
		pd[now.p]=true;
		for(int i=h[now.p];i;i=e[i].next){
			int y=e[i].to ;
			if(dis[y]>(long long)dis[now.p]+e[i].w ){
				dis[y]=dis[now.p]+e[i].w;
				if(!pd[y]){
					q.push(node{y,dis[y]});
				}
			}
		}
	}
}

int main(){
	memset(pd,false,sizeof(pd));
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
	}
	fill(dis+1,dis+1+n,1e9);
	dijkstra(s);
	for(int i=1;i<n;i++){
		cout<<dis[i]<<" ";
	}
	cout<<dis[n];
	return 0;
}

