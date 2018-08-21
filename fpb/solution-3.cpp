#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD=1E9+7;

int n,k;
ll A[20];
ll ans=0;

void f(int pos,int sisa,ll ret) {
	if (sisa<0) return;
	if (pos==n) {
		if (sisa==0) ans+=ret, ans%=MOD;
		return;
	}
	f(pos+1,sisa,ret);
	ll cur=A[pos];
	for (int i=pos;i<n;i++) {
		cur=__gcd(cur,A[i]);
		f(i+1,sisa-1,(ret+cur)%MOD);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string header; cin>>header;
	cin>>n>>k;
	for (int i=0;i<n;i++) cin>>A[i];
	f(0,k,0);
	cout<<ans<<endl;
	return 0;
}
