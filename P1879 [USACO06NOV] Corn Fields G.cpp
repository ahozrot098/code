#include <bits/stdc++.h>
using namespace std;
const int mod=100000000;
int f[13][1<<13-1],m,n;
int g[13];
int main() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=0,x;j<m;j++){
			scanf("%d",&x);
			g[i]=g[i]<<1|x;
		}
	}
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int s=0;s<1<<m;s++){
			if((s&s<<1)==0&&(g[i]&s)==s){
				for(int t=0;t<1<<m;t++){
					if((s&t)==0&&(t&t<<1)==0){
						f[i][s]+=f[i-1][t];
						f[i][s]%=mod;
					}
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<(1<<m);i++){
		ans=(ans+f[n][i])%mod;
	}
	printf("%d",ans);
    return 0;
}
