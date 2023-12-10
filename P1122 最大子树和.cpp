#include <bits/stdc++.h>
using namespace std;
int n,a[114514],b[114514],x,y,ans=-INT_MAX; 
vector <int> A[16005];

void dfs(int x,int l){
	b[x]=a[x];
	for(int i=0;i<A[x].size();i++){
		int t=A[x][i];
		if(t!=l){
			dfs(t,x);
			if(b[t]>0){
				b[x]+=b[t];
			}
		}
	}
}

int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		A[x].push_back(y);
		A[y].push_back(x);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++){
		ans=max(ans,b[i]);
	}
	cout<<ans;
    return 0;
}

