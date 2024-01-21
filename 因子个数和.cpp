#include <bits/stdc++.h>
using namespace std;
int a[1000000];
//inline int read(){
//    int x=0,f=1;
//    char ch=getchar();
//    while(ch<'0'||ch>'9')
//    {
//        if(ch=='-')
//            f=-1;
//        ch=getchar();
//    }
//    while(ch>='0' && ch<='9')
//        x=x*10+ch-'0',ch=getchar();
//    return x*f;
//}
//
//void write(int x)
//{
//    if(x<0)
//        putchar('-'),x=-x;
//    if(x>9)
//        write(x/10);
//    putchar(x%10+'0');
//    return;
//}

int main() {
	
	int n;
	int cnt1=1;
	cin>>n;
	for(int i=2;i<=n;i++){
		cnt=0;
		for(int l=1,r;l<i;l=r+1){
			r=i/(i/l);
			if(a[i/r]){
				cnt+=a[i/r];
			}
			else{
				cnt++;
			}
			
		}
		
	}
	cout<<cnt;
	return 0;
}


