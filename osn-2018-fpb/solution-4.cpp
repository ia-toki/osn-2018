#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD=1E9+7;

int n,k;
ll A[510];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string header; cin>>header;
	cin>>n>>k;
	for (int i=0;i<n;i++) cin>>A[i];
	ll ans=0;
	for (int i=0;i<n;i++) {
		ll cur=A[i];
		for (int j=i;j<n;j++) {
			cur=__gcd(cur,A[j]); ans+=cur; ans%=MOD;
		}
	}
	cout<<ans<<endl;
	return 0;
}
