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

long long f(long long l, long long r){
	l--;
	return (r+1)*r/2-(l+1)*l/2;
}

int main() {
	long long n,k,sum,cnt=0;
	cin>>n>>k;
	for(long long l=1,r;l<=min(n,k);l=r+1){
		r=min(n,k/(k/l));
		cnt+=(k/l)*f(l,r);
	}
	cout<<k*n-cnt;
	return 0;
}

//
//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//long long ans, k, n, check;
//long long f(long long l, long long r){
//	l--;
//	return (r+1)*r/2-(l+1)*1/2;
//}
//int main(){
//	scanf("%lld%lld",&n,&k);
//	for(long long i=1,last;i <= min(n,k);i=last+1){
//		last=min(n,k/(k/i));
//		ans+=(k/i)*f(i,last);
//	}	
//	printf("%lld\n",k*n-ans);
//}
