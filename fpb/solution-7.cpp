#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD=1E9+7;

ll kali(ll x,ll y) {
	return ((x%MOD)*(y%MOD))%MOD;
}

int n,k;
ll A[50010];
map<ll,int> cur,temp;
vector<pair<int,ll> > FPB;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string header; cin>>header;
	cin>>n>>k;
	for (int i=0;i<n;i++) cin>>A[i];
	ll ans=0;	
	for (int i=0;i<n;i++) {
		if (i==0) cur[A[0]]=0, FPB.push_back({0,A[0]});
		else {
			temp.clear(); temp[A[i]]=i;
			for (auto data:cur) {
				ll curGCD=__gcd(data.first,A[i]);
				if (temp.count(curGCD)) temp[curGCD]=min(temp[curGCD],data.second);
				else temp[curGCD]=data.second;
			}
			cur=temp;
			FPB.clear();
			for (auto data:cur) FPB.push_back({data.second,data.first});
		}
		FPB.push_back({i+1,-1});
		for (int i=0;i<FPB.size()-1;i++) {
			ans+=kali(FPB[i].second,FPB[i+1].first-FPB[i].first); ans%=MOD;
		}
	}
	cout<<ans<<endl;
	return 0;
}
