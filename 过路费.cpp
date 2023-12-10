#include <bits/stdc++.h>
using namespace std;
int n,m,t,x,y;

struct node{
	int start;
	int end;
	int cost;
}way[11451];

int find(int k){
	return k==father[k] ? k:(father[k]=find(father[k]));
}

int main() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&way[i].start ,&way[i].end ,&way[i].cost );
	}
	
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d%d",&x,&y);
		printf("%d\n",work(x,y));
	}
	return 0;
}

