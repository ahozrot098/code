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

bool check(int a){
	if(a<=1||a%2==0&&a>2) return 0;
	for(int j=3;j<=sqrt(a);j+=2){
		if(a%j==0){
			return 0;
		}
	}
	return 1;
}

int main() {
	int n=read(),m=read();
	for(int i=n;i<=m;i++){
		if(check(i)) write(i),printf(" ");
	}
	return 0;
}

