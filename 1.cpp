//#include <bits/stdc++.h>
//using namespace std;
//double a,b,c,s;
//int main() {
//	freopen("stamp.in","r",stdin);
//	freopen("stamp.out","w",stdout);
//	cin>>a>>b>>c;
//	s=a*1000/(b+c)/60/60;
//	if(b>c) printf("%.2f",s*2);
//	else printf("%.2f",a*1000/c/3600);
//	return 0;
//}

//#include <bits/stdc++.h>
//using namespace std;
//int n,a[114514],price[114514],t,p,m,k;
//int main() {
//	freopen("price.in","r",stdin);
//	freopen("price.out","w",stdout);
//	cin>>n;
//	for(int i=0;i<n;i++) cin>>a[i];
//	cin>>t;
//	while(t--){
//		int ans=0,s=0,flag=0,f=0;
//		for(int i=0;i<n;i++) price[i]=a[i];
//		cin>>p>>m>>k;
//		price[n]=p*m;
//		sort(price,price+n+1);
//		for(int i=0;i<=n;i++){
//			if(price[i]>p*m&&flag==0){
//				if(i-2<=0){
//					cout<<"888"<<endl;
//					f=1;
//					break;
//				}
//				ans=price[i-2];
//				s=i-2;
//				break;
//			}
//		}
//		if(f==1) continue;
//		if(ans==0) cout<<"888"<<endl;
//		else if(s>=k) cout<<ans/10<<"0"<<endl;
//		else cout<<ans<<endl;
//	} 
//	return 0;
//}

//#include <bits/stdc++.h>
//using namespace std;
//int n,x,y,a[214514];
//int main() {
//	freopen("Maxmin.in","r",stdin);
//	freopen("Maxmin.out","w",stdout);
//	cin>>n>>x>>y;
//	for(int i=1;i<=n;i++) cin>>a[i];
//	for(int i=1;i<=n;i++){
//		
//	} 
//	return 0;
//}

//#include <iostream>
//#include <fstream>
//#include <deque>
//using namespace std;
//
//const int MAXN = 2e5 + 10; // �����������󳤶�
//int A[MAXN]; // ��������A
//int maxn[MAXN]; // ����ӵ�i��Ԫ�ؿ�ʼ���ҵ����ֵ
//int minn[MAXN]; // ����ӵ�i��Ԫ�ؿ�ʼ���ҵ���Сֵ
//deque<int> dq; // ����˫�˶���
//
//int main() {
////    ifstream cin("Maxmin.in"); // �������ļ�
////    ofstream cout("Maxmin.out"); // ������ļ�
//    int N, X, Y; // ������Ŀ�����ı���
//    cin >> N >> X >> Y; // ����N, X, Y
//    for (int i = 1; i <= N; i++) {
//        cin >> A[i]; // ����A[i]
//    }
//    maxn[N] = A[N]; // ��ʼ��maxn[N]
//    minn[N] = A[N]; // ��ʼ��minn[N]
//    for (int i = N - 1; i >= 1; i--) {
//        maxn[i] = max(A[i], maxn[i + 1]); // ����maxn[i]
//        minn[i] = min(A[i], minn[i + 1]); // ����minn[i]
//    }
//    long long ans = 0; // ����𰸱���������ʼ��Ϊ0
//    for (int i = 1; i <= N; i++) {
//        if (A[i] > X || A[i] < Y) { // ���A[i]����X��С��Y
//            dq.clear(); // ��ն���
//            dq.push_back(i); // ��i��Ϊ�µ���˵�
//        } else { // ����
//            dq.push_back(i); // ��i�������β��
//            while (!dq.empty() && maxn[dq.front()] > X) { // ������в�Ϊ����maxn[����ͷ��]����X
//                dq.pop_front(); // ��������ͷ��
//            }
//            while (!dq.empty() && minn[dq.front()] < Y) { // ������в�Ϊ����minn[����ͷ��]С��Y
//                dq.pop_front(); // ��������ͷ��
//            }
//            if (!dq.empty() && maxn[dq.front()] == X) { // ������в�Ϊ����maxn[����ͷ��]����X
//                ans += dq.back() - dq.front() + 1; // �����Զ���ͷ��Ϊ��˵�����������������Եĸ��������ۼӵ�����
//            }
//        }
//    }
//    cout << ans << endl; // �����
////    cin.close(); // �ر������ļ�
////    cout.close(); // �ر�����ļ�
//    return 0;
//}
//x y p q
#include <bits/stdc++.h>
using namespace std;
int n,m,p,q,ans;
int mapp[514][514];
bool flag[514][514];

void dfs(int x,int y,int p1,int q1){
	if(x==n&&y==m){
		if(mapp[x][y]==0){
			p1+=1;
		}
		else{
			q1+=1;
		}
		if(p1>=p&&q1>=q){
			ans++;
			ans%=998244353;
		}
		return ;
	}
	if(x+1<=n&&flag[x+1][y]==0){
		flag[x+1][y]=1;
		if(mapp[x+1][y]==0){
			dfs(x+1,y,p1+1,q1);
		}
		else{
			dfs(x+1,y,p1,q1+1);
		}
		flag[x+1][y]=0;
	}
	if(y+1<=m&&flag[x][y+1]==0){
		flag[x][y+1]=1;
		if(mapp[x][y+1]==0){
			dfs(x,y+1,p1+1,q1);
		}
		else{
			dfs(x,y+1,p1,q1+1);
		}
		flag[x][y+1]=0;
	}	
}

int main() {
	freopen("DragonQuest.in","r",stdin);
	freopen("DragonQuest.out","w",stdout);
	cin>>n>>m>>p>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>mapp[i][j];
		}
	}
	flag[1][1]=1;
	if(mapp[1][1]==0)
	dfs(1,1,1,0);
	else
	dfs(1,1,0,1);
	cout<<ans;
	return 0;
}
