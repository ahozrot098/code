#include <bits/stdc++.h>
using namespace std;
int n,m,s,k;
int head[514514],dep[514514],a[514514][21];

struct node{
	int id;
	int next;
}point[514514];

void add(int x,int y){
	point[k].id =y;
	point[k].next =head[x];
	head[x]=k++;
}

void dfs(int u,int fa){
	dep[u]=dep[fa]+1;
	a[u][0]=fa;
	for(int i=1;(1<<i)<=dep[u];i++){
		a[u][i]=a[a[u][i-1]][i-1];
	}
	for(int i=head[u];i!=-1;i=point[i].next ){
		int id=point[i].id;
		if(id!=fa){
			dfs(id,u);
		} 
//		cout<<"FUCK YOU"<<endl;
	}
	
}

int lca(int x,int y){
	if(dep[x]>dep[y]) swap(x,y);
	for(int i=20;i>=0;i--){
		if(dep[x]<=dep[y]-(1<<i)) y=a[y][i];
	}
	if(x==y) return x;
	for(int i=20;i>=0;i--){
		if(a[x][i]==a[y][i]) continue;
		else{
			x=a[x][i];
			y=a[y][i];
		}
	}
	return a[x][0];
}      

int main() {
	int x,y;
	memset(head,-1,sizeof(head));
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		add(x,y),add(y,x);
	}
	dfs(s,0);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		printf("%d\n",lca(x,y));
	}
	return 0;
}

