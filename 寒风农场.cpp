#include <bits/stdc++.h>
using namespace std;

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

int main() {
	long long T=read(),a,n,cnt=0;
	while(a=read(),n=read()){
		for(long long l=1,r;l<=n;l=r+1){
			r=n/(n/l);
			cnt+=(r-l+1)*(a+(a%n)*(l+r)/2);
			cnt%=n;
		}
		if(cnt==0) cout<<"YES"<<endl; 
		else cout<<"NO"<<endl;
	}
	return 0;
}

