#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD=1E9+7;

int n,k;
ll A[510];

ll kali(ll x,ll y) {
	return ((x%MOD)*(y%MOD))%MOD;
}

ll getCnt(ll x) {
	if (x<=0) return 0;
	if (x&1) return kali(x,(x+1)/2);
	return kali(x/2,x+1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string header; cin>>header;
	cin>>n>>k;
	for (int i=0;i<n;i++) cin>>A[i];
	ll ans=0;
	for (int i=0;i<n;i++) {
		ll cur=A[i];
		for (int j=i;j<n;j++) {
			if (k==2 && i==0 && j==n-1) continue;
			cur=__gcd(cur,A[j]); 
			ll temp=cur; 
			if (k==2) {
				temp=kali(temp,getCnt(i)+getCnt(n-1-j));
			}
			ans+=temp; ans%=MOD;
		}
	}
	cout<<ans<<endl;
	return 0;
}
