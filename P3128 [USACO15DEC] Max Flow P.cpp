//#include <bits/stdc++.h>
//using namespace std;
//int n,k,x,y,maxn=-INT_MAX;
//int w1[500001],w2[500001],head[500001],dep[500001],a[500001][21];
//
//struct node{
//	int id;
//	int next;
//}point[1000001];
//
//void add(int x,int y){
//	point[k].id =y;
//	point[k].next =head[x];
//	head[x]=k++;
//}
//
//void dfs(int u,int fa,int d){
//	dep[u]=d;
//	a[u][0]=fa;
//
//	for(int i=head[u];~i;i=point[i].next ){
//		int id=point[i].id;
//		if(id!=fa){
//			dfs(id,u,d+1);
//		} 
////		cout<<"FUCK YOU"<<endl;
//	}
//	for(int j=1;(1<<j)<=n;++j){
//        for(int i=1;i<=n;++i){
//            if(a[i][j-1]!=-1){
//                a[i][j]=a[a[i][j-1]][j-1];
//            }
//        }
//    }
////	for(int i=1;(1<<i)<=dep[u];i++){
////		a[u][i]=a[a[u][i-1]][i-1];
////	}
//}
//int lca(int x,int y){
//	if(dep[x]>dep[y]) swap(x,y);
//	for(int i=20;i>=0;i--){
//		if(dep[x]<=dep[y]-(1<<i)) y=a[y][i];
//	}
//	if(x==y) return x;
//	for(int i=20;i>=0;i--){
//		if(a[x][i]==a[y][i]) continue;
//		else{
//			x=a[x][i];
//			y=a[y][i];
//		}
//	}
//	return a[x][0];
//}      
//
//void work(int x,int y){
//	int z=lca(x,y);
//	++w1[x];
//	++w1[y];
//	--w1[z];
//	if(a[z][0]!=-1){
//		--w1[a[z][0]];
//	}
//}
//
//void Dfs(int u,int fa){
//	w2[u]=w1[u]+1;
//	for(int i=head[u];~i;i=point[i].next ){
//		int id=point[i].id;
//		if(id!=fa){
//			Dfs(id,u);
//			w2[u]+=w2[id];
//		} 
////		cout<<"FUCK YOU"<<endl;
//	}
//	cout<<"maxn="<<w2[u]<<endl;
//	maxn=max(maxn,w2[u]);
//}
//
//int main() {
//	memset(head,-1,sizeof(head));
//	memset(a,-1,sizeof(a));
//	scanf("%d%d",&n,&k);
//	for(int i=1;i<n;i++){
//		scanf("%d%d",&x,&y);
//		add(x,y);
//		add(y,x);
//	}
//	dfs(1,-1,1);
//	for(int i=1;i<=k;i++){
//		scanf("%d%d",&x,&y);
//		work(x,y);
//	} 
//	Dfs(1,0);
//	printf("%d",maxn);
//	return 0;
//}
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=50005;
int n=0,k=0;
int head[N*2],next[N*2],to[N*2],edge=0;
int fa[N][20],depth[N],w1[N],w2[N];
int ans=0;
inline void addEdge(int u,int v) {
    to[edge]=v, next[edge]=head[u],head[u]=edge++;
    to[edge]=u,next[edge]=head[v],head[v]=edge++;
}
void dfs1(int x,int f,int d) {
    depth[x]=d;
    fa[x][0]=f;
    for (int e=head[x];~e;e=next[e]) {
        int& v=to[e];
        if (v!=f)
            dfs1(v,x,d+1);
    }    
}
inline void init() {
    for (int j=1;(1<<j)<=n;++j)
        for (int i=1;i<=n;++i)
            if (fa[i][j-1]!=-1)
                fa[i][j]=fa[fa[i][j-1]][j-1];
}
inline int lca(int u,int v) {
    if (depth[u]<depth[v])
        swap(u,v);    
    int i=0;
    for (;(1<<i)<=n;++i)
        ;
    --i;
    for (int j=i;j>=0;--j)
        if (depth[u]-(1<<j)>=depth[v])
            u=fa[u][j];
    if (u==v)
        return u;
    for (int j=i;j>=0;--j)
        if (fa[v][j]!=fa[u][j] && fa[u][j]!=-1) {
            u=fa[u][j];
            v=fa[v][j];
        }
    return fa[u][0];
}
inline void plus(int x,int y) {
    int z=lca(x,y);
    ++w1[x],++w1[y];
    --w1[z];
    if (fa[z][0]!=-1)
        --w1[fa[z][0]];
}
void dfs2(int x,int f) {
    w2[x]=w1[x];
    for (int e=head[x];~e;e=next[e]) {
        int& v=to[e];
        if (v!=f) {
            dfs2(v,x);
            w2[x]+=w2[v];
        }
    }        
    ans=max(ans,w2[x]);
}
int main(void) {
    memset(head,-1,sizeof(head));
    memset(fa,-1,sizeof(fa));
    scanf("%d %d",&n,&k);
    for (int i=1;i<=n-1;++i) {
        int u=0,v=0;
        scanf("%d %d",&u,&v);
        addEdge(u,v);
    }    
    dfs1(1,-1,1);
    init();
    while (k--) {
        int x=0,y=0;
        scanf("%d %d",&x,&y);
        plus(x,y);
    } 
    dfs2(1,-1);
    printf("%d\n",ans);
    return 0;
} 
