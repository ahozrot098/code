#include <bits/stdc++.h>
using namespace std;
int n,m,u,v,w,sum;
int head[500005],dis[500005],vis[500005],in[500005];
queue<int> q;

struct edge {
    int v,w,fail;
    edge() {}
    edge(int _v,int _w,int _fail) {
        v=_v;
        w=_w;
        fail=_fail;
    }
}e[500005];

void add(int u,int v,int w) {
    e[sum]=edge(v,w,head[u]);
    head[u]=sum++;
}

bool dijkstra(int x){
	q.push(x);
	while(!q.empty()){
		x=q.front();
		q.pop();
		vis[x]=0;
		for(int i=head[x];~i;i=e[i].fail ){
			int v=e[i].v;
			int w=e[i].w;
			if(dis[v]<dis[x]+w) {
                dis[v]=dis[x]+w;
                if(!vis[v]){
                	q.push(v);
                	vis[v]=true;
                	++in[v];
                    if(in[v]>n+1) return 1;
                }
            }
		}
	}
	return 0;
}

int main() {
	memset(head,-1,sizeof(head));
	memset(vis,false,sizeof(vis));
    memset(dis,-1,sizeof(dis));
    memset(in,0,sizeof in);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,-w);
	}
	for(int i=1;i<=n;++i) add(0,i,0);
	vis[0]=1,dis[0]=0,in[0]=1;
	if(dijkstra(0)) printf("NO");
	else for(int i=1;i<=n;i++) printf("%d ",dis[i]);
	return 0;
}

