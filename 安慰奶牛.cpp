#include <bits/stdc++.h>
using namespace std;
int n,p,a[114514],father[114514],first=INT_MAX;

struct node{
	int start,end;
	int price;
}way[114514];

bool cmp(node a,node b){
	return a.price <b.price ;
}

int find(int k){
	return k==father[k] ? k:(father[k]=find(father[k]));
}

int ans(int n,int p){
	int sum=0,s=0;
	for(int i=0;i<n;i++){
		father[i]=i;
	}
	sort(way,way+p,cmp);
	for(int i=0;i<p;i++){
		int ax=find(way[i].start );
		int ay=find(way[i].end );
		if(ax!=ay){
			father[ay]=ax;
			sum+=way[i].price ;
			s++;
			if(s==n-1) break; 
		}
	}
	return sum;
}

int main() {
	scanf("%d%d",&n,&p);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(a[i]<first) first=a[i];
	}
	for(int i=0;i<p;i++){
		scanf("%d%d%d",&way[i].start ,&way[i].end ,&way[i].price );
		way[i].price = a[way[i].start-1]+a[way[i].end-1]+2*way[i].price;
	}
	printf("%d",first+ans(n,p));
	return 0;
}

