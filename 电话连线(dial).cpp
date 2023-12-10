#include <bits/stdc++.h>
using namespace std;
int n,flag;
int a[114][114],last[114],vis[114],cost[114],head[114],tail[114],sum,cnt;
void work(){
	vis[1]=1;
	sum=0,cnt=0;
	for(int i=1;i<=n;i++){
		cost[i]=a[1][i];
		last[i]=1;
	}
	for(int i=1;i<n;i++){
		int minn=INT_MAX;
		for(int j=1;j<=n;j++){
			if(!vis[j]&&cost[j]<minn){
				minn=cost[j];
				flag=j;
			}
		}
		if(minn){
			head[cnt]=last[flag];
			tail[cnt++]=flag;
		}
		sum+=minn;
		vis[flag]=1;
		for(int j=1;j<=n;j++){
			if(!vis[j]&&cost[j]>a[flag][j]){
				cost[j]=a[flag][j];
				last[j]=flag;
			}
		}
	}
}
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	work();
	printf("%d\n%d",cnt,sum);
	return 0;
}


