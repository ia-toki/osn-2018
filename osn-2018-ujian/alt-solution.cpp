#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200000;
const long long MOD = (long long)1000000007;

long long fact[MAXN + 5];
int pos[MAXN + 5];
char header[MAXN + 5];

struct Connection {
	int leftTop;
	int leftMid;
	int leftBot;
	int rightTop;
	int rightMid;
	int rightBot;
} con[MAXN + 5];

void precomp() {
	fact[0] = 1;
	for(int i = 1; i <= MAXN; i++) {
		fact[i] = ((long long)i * fact[i - 1]) % MOD;
	}
}

long long solve(int lt, int lb, int rt, int rb) {
	long long ret;
	if(lt == rb && lb == rt) {
		ret = (fact[lt] * fact[lb]) % MOD;
	}
	else {
		ret = 0;
	}
	// cout << "->" << ret;
	return ret;
}

long long inv(long long inp) {
	return ((MOD + 1) / inp) % MOD;
}

long long solveBig(int la, int lb, int lc, int ra, int rb, int rc) {
	// cout << la << " " << lb << " " << lc << " " << ra << " " << rb << " " << rc << "\n";
	long long dup = 1 << (2 - lb - rb);
	// cout << " " << dup << "\n";
	long long ret =  (((
		solve(la, lb + lc, ra, rb + rc) + solve(la, lb + lc, ra + rb, rc) +
		solve(la + lb, lc, ra, rb + rc) + solve(la + lb, lc, ra + rb, rc)) % MOD) * inv(dup)) % MOD;
	ret = (ret - solve(la, lc, ra, rc) * (lb & rb) + MOD) % MOD;
	// cout << " ==> " << ret << "\n";
	return ret;
}

int main(int argc, char** argv) {
	int N, K, X;
	scanf("%s", header);
	precomp();
	scanf("%d %d", &N, &K);
	for(int j = 1; j <= K; j++) {
		scanf("%d", pos + j);
	}
	for(int i = 1; i <= N; i++) {
		scanf("%d", &X);
		if(pos[X] > i) {
			con[X].leftTop++;
		}
		else if(pos[X] == i) {
			con[X].leftMid++;
		}
		else {
			assert(pos[X] < i);
			con[X].leftBot++;
		}
	}
	for(int i = 1; i <= N; i++) {
		scanf("%d", &X);
		if(pos[X] > i) {
			con[X].rightTop++;
		}
		else if(pos[X] == i) {
			con[X].rightMid++;
		}
		else {
			assert(pos[X] < i);
			con[X].rightBot++;
		}
	}
	long long res = 1;
	for(int j = 1; j <= K; j++) {
		res = (res * solveBig(con[j].leftTop, con[j].leftMid, con[j].leftBot,
							  con[j].rightTop,con[j].rightMid,con[j].rightBot)) % MOD;
	}
	printf("%lld\n", res);
}
