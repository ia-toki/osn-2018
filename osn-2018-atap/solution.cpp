#include <bits/stdc++.h>
using namespace std;

long long N; int K;
int S_len;
char S[(int)1e5 + 5];
long long max_pos;
vector<int> leftPos, rightPos;

void precomp() {
	N = (long long)S_len * K + 1;
	for(int i = 1; i <= S_len; i++) {
		if(S[i] == 'B') {
			leftPos.push_back(i);
		}
		else {
			assert(S[i] == 'A');
			rightPos.push_back(i);
		}
	}
	max_pos = (long long)leftPos.size() * K + 1;
}

long long getAnsL(long long pos) {
	long long mul = (pos - 1) / (long long)leftPos.size();
	long long relAns = leftPos[(pos - 1) % (long long)leftPos.size()];// relative ans(in range[1, S_len])
	long long ans = mul * S_len + relAns;
	return ans;
}

long long getAnsR(long long pos) {
	long long mul = (N - pos) / (long long)rightPos.size();
	long long relAns = rightPos[(N - pos) % (long long)rightPos.size()];// relative ans(in range[1, S_len])
	long long ans = mul * S_len + relAns;
	return ans;
}

long long solve(long long L, long long R) {
	if(L <= max_pos && max_pos <= R) {
		return N;
	}
	if(R < max_pos) {
		return getAnsL(R);
	}
	return getAnsR(L);
}

int main(int argc, char** argv) {
	scanf("%s", S + 1);
	S_len = strlen(S + 1);
	int Q;
	scanf("%d %d", &K, &Q);
	precomp();
	while(Q--) {
		long long L, R;
		scanf("%lld %lld", &L, &R);
		printf("%lld\n", solve(L, R));
	}
}
