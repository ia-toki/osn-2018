#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;

int N, P;
char ar[MAXN][MAXN];
string UP[MAXN], DOWN[MAXN], LEFT[MAXN], RIGHT[MAXN];
int cnt[MAXN*MAXN];
int par[MAXN*MAXN];

int getIdx(string inp) {
	int ret = 0;
	for(int i = 0; i < (int)inp.size()-1; i++) {
		ret = ret*10 + inp[i] - '0';
	}
	return ret;
}

void read() {
	cin >> N >> P;
	assert(N == 100);
	for(int j = 0; j < N; j++) {
		cin >> UP[j];
	}
	for(int i = 0; i < N; i++) {
		cin >> LEFT[i] >> RIGHT[i];
	}
	for(int j = 0; j < N; j++) {
		cin >> DOWN[j];
	}
}

void fill_0() {
	for(int j = 0; j < N; j++) {
		if(UP[j] == "0" || DOWN[j] == "0") {
			for(int i = 0; i < N; i++) {
				ar[i][j] = '-';
			}
		}
	}

	for(int i = 0; i < N; i++) {
		if(LEFT[i] == "0" || RIGHT[i] == "0") {
			for(int j = 0; j < N; j++) {
				ar[i][j] = '-';
			}
		}
	}
}

void fill_M() {
	// UP
	for(int j = 0; j < N; j++) {
		if(UP[j] != "-") {
			int i = getIdx(UP[j]) - 1;
			for(int i1 = 0; i1 < i; i1++) {
				ar[i1][j] = '-';
			}
			ar[i][j] = UP[j].back();
		}
	}

	// DOWN
	for(int j = 0; j < N; j++) {
		if(DOWN[j] != "-") {
			int i = N - getIdx(DOWN[j]);
			for(int i1 = N - 1; i1 > i; i1--) {
				ar[i1][j] = '-';
			}
			ar[i][j] = DOWN[j].back();
		}
	}

	// LEFT
	for(int i = 0; i < N; i++) {
		if(LEFT[i] != "-") {
			int j = getIdx(LEFT[i]) - 1;
			for(int j1 = 0; j1 < j; j1++) {
				ar[i][j1] = '-';
			}
			ar[i][j] = LEFT[i].back();
		}
	}

	// RIGHT
	for(int i = 0; i < N; i++) {
		if(RIGHT[i] != "-") {
			int j = N - getIdx(RIGHT[i]);
			for(int j1 = N - 1; j1 > j; j1--) {
				ar[i][j1] = '-';
			}
			ar[i][j] = RIGHT[i].back();
		}
	}
}

void init_ufds() {
	for(int i = 0; i < N*N; i++) {
		par[i] = i;
	}
}

int fp(int mas) {
	if(mas == par[mas]) {
		return mas;
	}
	return par[mas] = fp(par[mas]);
}

void gabung(int a, int b) {
	int aa = fp(a), bb = fp(b);
	if(aa == bb) {
		return;
	}
	par[bb] = aa;
	cnt[aa] += cnt[bb];
	return;
}

void ufds() {
	init_ufds();

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(ar[i][j] == 'M') {
				cnt[i*N+j]++;
			}
		}
	}

	for(int i = 1; i < N; i++) {
		for(int j = 0; j < N; j++) {
			int a = (i-1)*N+j, b = i*N+j;
			if(ar[i-1][j] != '-' && ar[i][j] != '-') {
				gabung(a, b);
			}
		}
	}

	for(int i = 0; i < N; i++) {
		for(int j = 1; j < N; j++) {
			int a = i*N+j-1, b = i*N+j;
			if(ar[i][j-1] != '-' && ar[i][j] != '-') {
				gabung(a, b);
			}
		}
	}
}

void fill() {
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			int nod = i*N+j;
			int rot = fp(nod);
			if(ar[i][j] != '\0') {
				// do nothing
			}
			else if(cnt[rot]) {
				ar[i][j] = 'M';
			}
			else {
				ar[i][j] = '-';
			}
		}
	}
}

void work() {
	fill_0();
	fill_M();
	ufds();
	fill();
}

void print() {
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			cout << ar[i][j];
		} cout << "\n";
	}
}

int main(int argc, char** argv) {
	read();
	work();
	print();
}