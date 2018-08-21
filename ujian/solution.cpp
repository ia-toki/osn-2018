#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD=1E9+7;
const int MAXN=200010;

ll F[MAXN];	//Faktorial
string header;
ll k,n;
ll P[MAXN];
ll lt[MAXN], lb[MAXN], rt[MAXN], rb[MAXN];	//Count soal/pilihan yang di atas/tengah/bawah garis perantara
bool lm[MAXN], rm[MAXN];

ll kali(ll x,ll y) {
	return ((x%MOD)*(y%MOD))%MOD;
}

inline void prework() {
	F[0]=1ll;
	for (int i=1;i<MAXN;i++) F[i]=kali(F[i-1],i);
}

ll hitung(int cur) {
	ll ret=0;
	if (!lm[cur] && !rm[cur]) {
		if (lt[cur]==rb[cur] && lb[cur]==rt[cur]) ret+=kali(F[lt[cur]],F[lb[cur]]), ret%=MOD;
		return ret;
	}
	if (lm[cur] && !rm[cur]) {
		if (lt[cur]+1==rb[cur] && lb[cur]==rt[cur]) ret+=kali(F[lt[cur]+1],F[lb[cur]]), ret%=MOD;
		if (lt[cur]==rb[cur] && lb[cur]+1==rt[cur]) ret+=kali(F[lt[cur]],F[lb[cur]+1]), ret%=MOD;
		return ret;
	}
	if (!lm[cur] && rm[cur]) {
		if (lt[cur]==rb[cur]+1 && lb[cur]==rt[cur]) ret+=kali(F[lt[cur]],F[lb[cur]]), ret%=MOD;
		if (lt[cur]==rb[cur] && lb[cur]==rt[cur]+1) ret+=kali(F[lt[cur]],F[lb[cur]]), ret%=MOD;
		return ret;
	}
	if (lm[cur] && rm[cur]) {
		if (lt[cur]==rb[cur]+1 && lb[cur]+1==rt[cur]) ret+=kali(F[lt[cur]],F[lb[cur]+1]), ret%=MOD;
		if (lt[cur]+1==rb[cur]+1 && lb[cur]==rt[cur]) ret+=kali(F[lt[cur]+1],F[lb[cur]]), ret%=MOD;
		if (lt[cur]+1==rb[cur] && lb[cur]==rt[cur]+1) ret+=kali(F[lt[cur]+1],F[lb[cur]]), ret%=MOD;
		if (lt[cur]==rb[cur] && lb[cur]+1==rt[cur]+1) ret+=kali(F[lt[cur]],F[lb[cur]+1]), ret%=MOD;
		//Inklusi Eksklusi
		if (lt[cur]==rb[cur] && lb[cur]==rt[cur]) ret-=kali(F[lt[cur]],F[lb[cur]]), ret+=MOD, ret%=MOD;
		return ret;
	}
}

int main() {
	prework();
	cin>>header;
	cin>>n>>k;
	memset(lm,false,sizeof lm);
	memset(rm,false,sizeof rm);
	for (int i=1;i<=k;i++) cin>>P[i];
	for (int i=1;i<=n;i++) {
		int l; cin>>l;
		if (i<P[l]) lt[l]++;
		else if (i>P[l]) lb[l]++;
		else lm[l]=true;
	}
	for (int i=1;i<=n;i++) {
		int r; cin>>r;
		if (i<P[r]) rt[r]++;
		else if (i>P[r]) rb[r]++;
		else rm[r]=true;
	}
	ll ans=1ll;
	for (int i=1;i<=k;i++) {
		ll temp=hitung(i);
		if (temp==0) {
			cout<<0<<endl; return 0; //Tidak ada cara yang memenuhi
		}
		ans=kali(ans,temp);
	}
	cout<<ans<<endl;
	return 0;
}
