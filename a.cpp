#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e5 + 10;
LL ar[N],n,m;
bool check(LL x) {
	LL sum = 1;
	LL now=0;
	for (int i = 1;i <= n; i++){
		if (now + ar[i] <= x) now += ar[i];
		else now = ar[i], sum++;
	}
	return sum <= m;
}
int main(){
	cin >>n>>m;
	LL l=0,r=0;
	for (int i= 1;i<= n; i++){
		cin >> ar[i];
		l = max(l,ar[i]);
		r += ar[i];
	}
	LL ans = 0;
	while (l< r){
		LL mid =(l+r)>> 1;
		if (check(mid)){
			ans = mid;
			r = mid;
		}
		else
			l = mid +1;
	}
cout << ans <<"\n";
return 0;
}
