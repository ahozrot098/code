#include <bits/stdc++.h>
using namespace std;
int n;
int father[114514],a[114514],s,sum;

struct node{
	int start;
	int end;
	int cost;
}price[114514];

int find(int k){
	return k==father[k] ? k:(father[k]=find(father[k]));
}

bool cmp(node a,node b){
	return a.cost <b.cost ;
}


int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		price[++s].start =i;
		price[s].end =n+1;
		price[s].cost =a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&price[++s].cost );
			price[s].start =i;
			price[s].end =j;
		}
	}
	for(int i=1;i<=n;i++){
		father[i]=i;
	}
	sort(price+1,price+s+1,cmp);
	for(int i=1;i<=s;i++){
		int ax=find(price[i].start );
		int ay=find(price[i].end );
		if(ax!=ay){
			father[ay]=ax;
			sum+=price[i].cost ;
		}
	}
	cout<<sum;
	return 0;
}

