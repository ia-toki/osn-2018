#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD=1E9+7;

int n,k;
ll A[50010];
ll DP[50010][30][3];
ll PS[50010][30];

ll kali(ll x,ll y) {
	return ((x%MOD)*(y%MOD))%MOD;
}

ll f(int cur,int sisa,bool ambil) {
	if (cur<0 || sisa<0) return 0;
	ll &ret=DP[cur][sisa][ambil];
	if (cur==0) return ret=(sisa==0);
	if (ret!=-1) return ret;
	if (ambil) return ret=(f(cur-1,sisa,true)+f(cur,sisa,false))%MOD;
	return ret=(f(cur-1,sisa-1,true)+f(cur-1,sisa,false))%MOD;
}

inline void prework() {
	memset(DP,-1,sizeof DP); memset(PS,0,sizeof PS);
	for (int i=0;i<k;i++) {
		PS[0][i]=f(0,i,false);
		for (int j=1;j<n;j++) PS[j][i]=(PS[j-1][i]+f(j,i,false))%MOD;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string header; cin>>header; 
	cin>>n>>k; 
	for (int i=0;i<n;i++) cin>>A[i];
	prework();
	ll ans=0;
	for (int i=0;i<n;i++) {
		for (int j=0;j<k;j++) {
			ll query;
			if (k-1-j==0) query=1;
			else if (i==n-1) query=0;
			else query=f(n-i-1,k-1-j,false);
			ans+=kali(kali(A[0],PS[i][j]),query); ans%=MOD;
		}
	}
	cout<<ans<<endl;
	return 0;
}
