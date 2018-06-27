#include <bits/stdc++.h>
using namespace std;

#define INF 4123456789012345678

typedef pair<long long, long long> PII;
typedef pair<PII, long long> PIII;

int N, E, A, B;
long long C_g, M_g, C_o, M_o;
long long mem[207];
char HEADER[27];
vector<PIII> edge[207];
priority_queue<PII> pq;

int main() {
	scanf("%s", HEADER);
	scanf("%d%d", &N, &E);
	scanf("%lld%lld", &C_g, &M_g);
	scanf("%lld%lld", &C_o, &M_o);
	scanf("%d%d", &A, &B);

	for (int i = 0; i < E; i++) {
		int x, y, q;
		long long k;
		scanf("%d%d%lld%d", &x, &y, &k, &q);

		edge[x].push_back(PIII(PII(y, k), q));
		edge[y].push_back(PIII(PII(x, k), q));
	}

	for (int i = 1; i <= N; i++) {
		mem[i] = INF;
	}

	mem[A] = 0;
	pq.push(PII(-0, A));
	while (!pq.empty()) {
		PII tmp = pq.top();
		pq.pop();

		long long dist = -tmp.first;
		int pos = tmp.second;

		if (mem[pos] == dist) {
			for (int i = 0; i < edge[pos].size(); i++) {
				int next = edge[pos][i].first.first;
				long long k = edge[pos][i].first.second;
				int q = edge[pos][i].second;

				long long new_dist = dist;
				if (q == 0) {
					new_dist += k * min(C_g, C_o);
				} else {
					new_dist += min(C_g, C_o) + (k - 1) * C_o;
				}

				if (new_dist < mem[next]) {
					mem[next] = new_dist;
					pq.push(PII(-new_dist, next));
				}
			}
		}
	}

	printf("%lld\n", mem[B]);
}
