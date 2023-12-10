#include<bits/stdc++.h>
using namespace std;
int n,m,a[214514],x,y,z;
int find(int x){
    return a[x]==x ? x:(a[x]=find(a[x]));
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) a[i]=i;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&x,&y,&z);
        if(x==1) a[find(y)]=find(z);
        else{
            if(find(y)==find(z)) printf("Y\n");
            else printf("N\n");
        }
    }
    return 0;
}
