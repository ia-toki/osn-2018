#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define mp make_pair
#define mt(a, b, c) mp(mp(a, b), c)

const int MAXN = 499;
const int xx[] = {1, 0, -1, 0};
const int yy[] = {0, 1, 0, -1};

string UP[MAXN], DOWN[MAXN], LEFT[MAXN], RIGHT[MAXN];

int N, P;
char ar[MAXN][MAXN];
queue<pair<pair<int, int>, char> > qq;

bool valid(int x, int y) {
	return min(x, y) >= 0 && max(x, y) < N;
}

int getIdx(string inp) {
	int ret = 0;
	for(int i = 0; i < (int)inp.size()-1; i++) {
		ret = ret*10 + inp[i] - '0';
	}
	return ret;
}


void read() {
	cin >> N >> P;
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

void fill_MB() {
	// UP
	for(int j = 0; j < N; j++) {
		if(UP[j] != "-" && UP[j] != "0") {
			int i = getIdx(UP[j]) - 1;
			for(int i1 = 0; i1 < i; i1++) {
				ar[i1][j] = '-';
			}
			ar[i][j] = UP[j].back();
		}
	}

	// DOWN
	for(int j = 0; j < N; j++) {
		if(DOWN[j] != "-" && DOWN[j] != "0") {
			int i = N - getIdx(DOWN[j]);
			for(int i1 = N - 1; i1 > i; i1--) {
				ar[i1][j] = '-';
			}
			ar[i][j] = DOWN[j].back();
		}
	}

	// LEFT
	for(int i = 0; i < N; i++) {
		if(LEFT[i] != "-" && LEFT[i] != "0") {
			int j = getIdx(LEFT[i]) - 1;
			for(int j1 = 0; j1 < j; j1++) {
				ar[i][j1] = '-';
			}
			ar[i][j] = LEFT[i].back();
		}
	}

	// RIGHT
	for(int i = 0; i < N; i++) {
		if(RIGHT[i] != "-" && RIGHT[i] != "0") {
			int j = N - getIdx(RIGHT[i]);
			for(int j1 = N - 1; j1 > j; j1--) {
				ar[i][j1] = '-';
			}
			ar[i][j] = RIGHT[i].back();
		}
	}
}

void dfs(int i, int j) {
	for(int k = 0; k < 4; k++) {
		int ii = i + xx[k];
		int jj = j + yy[k];
		if(valid(ii, jj) && ar[ii][jj] == '\0') {
			ar[ii][jj] = ar[i][j];
			dfs(ii, jj);
		}
	}
}

void bfs() {
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			for(int k = 0; k < 4; k++) {
				int ii = i + xx[k];
				int jj = j + yy[k];
				if(valid(ii, jj) && ar[ii][jj] == '\0') {
					ar[ii][jj] = ' ';
				}
			}
		}
	}

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j += (N - 1)) {
			if(ar[i][j] == '\0') {
				ar[i][j] = ' ';
			}
		}
	}

	for(int i = 0; i < N; i += (N - 1)) {
		for(int j = 0; j < N; j++) {
			if(ar[i][j] == '\0') {
				ar[i][j] = ' ';
			}
		}
	}

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(ar[i][j] == 'M' || ar[i][j] == 'B') {
				qq.push(mt(i, j, ar[i][j]));
			}
		}
	}

	pair<pair<int, int>, char> dep;
	char kar;
	int nex, ney;
	while(!qq.empty()) {
		dep = qq.front(); qq.pop();
		kar = dep.s;
		for(int k = 0; k < 4; k++) {
			nex = dep.f.f + xx[k];
			ney = dep.f.s + yy[k];
			if(!valid(nex, ney) || ar[nex][ney] != ' ') {
				continue;
			}
			ar[nex][ney] = kar;
			qq.push(mt(nex, ney, kar));
		}
	}

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(ar[i][j] == 'M' || ar[i][j] == 'B') {
				dfs(i, j);
			}
		}
	}

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(ar[i][j] == '\0' || ar[i][j] == ' ') {
				ar[i][j] = '-';
			}
		}
	}
}

void work() {
	fill_0();
	fill_MB();
	bfs();
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