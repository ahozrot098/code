#include <bits/stdc++.h>
using namespace std;
int n,m,w,x,y;
int price[114514],value[114514],a[114514],dp[114514];

int find(int s){
    return a[s]==s ? s:(a[s]=find(a[s]));
}

int main() {
	scanf("%d%d%d",&n,&m,&w);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&price[i],&value[i]);
		a[i]=i;
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		int ax=find(x);
		int ay=find(y);
		if(ax!=ay){
			price[ay]+=price[ax];
			value[ay]+=value[ax];
			a[ax]=ay;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]==i){
			for(int j=w;j>=price[i];j--){
				dp[j]=max(dp[j],dp[j-price[i]]+value[i]);
			}
		}
	}
	printf("%d",dp[w]);
	return 0;
}

