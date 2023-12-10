#include <bits/stdc++.h>
using namespace std;
int n,m,u,v,w,sum,flag;
int head[500005],dis[500005],vis[500005],cnt[500005];
queue<int> q;

struct edge {
    int u,v,w;
//    edge() {}
//    edge(int _v,int _w,int _fail) {
//        v=_v;
//        w=_w;
//        fail=_fail;
//    }
}e[500005];

void add(int u,int v,int w) {
    e[++sum]={head[u],v,w};
    head[u]=sum;
}

bool spfa(int x){
	vis[x]=1,dis[x]=0,
	q.push(x);
	while(!q.empty()){
		x=q.front();
		q.pop();
		vis[x]=0;
//		cout<<"FUck";
		for(int i=head[x];i;i=e[i].u){
			int v=e[i].v;
			int w=e[i].w;
			if(dis[v]>dis[x]+w) {
                dis[v]=dis[x]+w;
                cnt[v]++;
                if(cnt[v]==n) return 0;
                if(vis[v]==0){
                    vis[v]=1;
                    q.push(v);
                }
            }
		}
	}
	return 1;
}

int main() {
    memset(dis,0x3f,sizeof(dis));
	scanf("%d%d",&n,&m);
	int s=n+1;
	for(int i=1;i<=m;i++){
		scanf("%d",&flag);
		if(flag==1){
			scanf("%d%d%d",&u,&v,&w);
			add(u,v,-w);
		}
		else if(flag==2){
			scanf("%d%d%d",&u,&v,&w);
			add(v,u,w);
		}
		else{
			scanf("%d%d%",&u,&v);
			add(u,v,0);
			add(v,u,0);
		}
	}
	for(int i=1;i<=n;++i) add(s,i,0);
	if(spfa(s)) printf("Yes");
	else printf("No");
	return 0;
}

