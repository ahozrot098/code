#include <bits/stdc++.h>
using namespace std;
int mod=1e9+7,a[114514];
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9')
        x=x*10+ch-'0',ch=getchar();
    return x*f;
}

void write(int x)
{
    if(x<0)
        putchar('-'),x=-x;
    if(x>9)
        write(x/10);
    putchar(x%10+'0');
    return;
}

int f(int x){
	int sum=1;
	for(int i=1;i<=x;i++) sum=(sum*i)%mod;
	return sum%mod; 
}

int main() {
	int n=read(),q=read();
	for(int k=1;k<=q;k++){
		memset(a,0,sizeof(a));
		int s=read();
		int cnt=1,sum=0,m=s;
		for(int j=2;j<m;j++){
			while(s%j==0){
				a[cnt]++;
				sum++;
				s/=j;
			}
			cnt++;
		}
		s=f(sum);
		for(int p=1;p<cnt;p++){
			s=(s/f(a[p]))%mod;
			
		}
		write(s);
		cout<<endl;
	}
	return 0;
}


