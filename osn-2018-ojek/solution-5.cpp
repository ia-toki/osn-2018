#include <bits/stdc++.h>
using namespace std;

#define INF 4123456789012345678
#define MAX_K 10

typedef pair<long long, long long> PII;
typedef pair<PII, PII> PIIII;

int N, E, A, B;
long long C_g, M_g, C_o, M_o;
long long mem[207 * MAX_K * 2 + MAX_K + 7][207][2];
char HEADER[27];
vector<int> edge[207 * MAX_K * 2 + MAX_K + 7];
priority_queue<PIIII> pq;

int main() {
	scanf("%s", HEADER);
	scanf("%d%d", &N, &E);
	scanf("%lld%lld", &C_g, &M_g);
	scanf("%lld%lld", &C_o, &M_o);
	scanf("%d%d", &A, &B);

	for (int i = 1; i <= N; i++) {
		edge[2*MAX_K*i].push_back(2*MAX_K*i+1);
		edge[2*MAX_K*i].push_back(2*MAX_K*i+11);
		for (int j = 1; j < 9; j++) {
			edge[2*MAX_K*i+j].push_back(2*MAX_K*i+j+1);
			edge[2*MAX_K*i+MAX_K+j].push_back(2*MAX_K*i+MAX_K+j+1);
		}
	}

	for (int i = 0; i < E; i++) {
		int x, y, q;
		long long k;
		scanf("%d%d%lld%d", &x, &y, &k, &q);

		if (k == 1) {
			edge[2*MAX_K*x].push_back(2*MAX_K*y);
			edge[2*MAX_K*y].push_back(2*MAX_K*x);
		} else {
			if (q == 0) {
				edge[2*MAX_K*x+k-1].push_back(2*MAX_K*y);
				edge[2*MAX_K*y+k-1].push_back(2*MAX_K*x);
			} else {
				edge[2*MAX_K*x+MAX_K+k-1].push_back(2*MAX_K*y);
				edge[2*MAX_K*y+MAX_K+k-1].push_back(2*MAX_K*x);
			}
		}
	}

	for (int i = 1; i <= 2*MAX_K*N+2*MAX_K; i++) {
		for (int j = 0; j <= 200; j++) {
			mem[i][j][0] = INF;
			mem[i][j][1] = INF;
		}
	}

	mem[2*MAX_K*A][0][0] = 0;
	pq.push(PIIII(PII(-0, 2*MAX_K*A), PII(0, 0)));
	while (!pq.empty()) {
		PIIII tmp = pq.top();
		pq.pop();

		long long dist = -tmp.first.first;
		int pos = tmp.first.second;
		int fuel = tmp.second.first;
		int type = tmp.second.second;

		if (mem[pos][fuel][type] == dist) {
			long long new_dist;
			int new_pos;
			int new_fuel;
			int new_type;

			if (fuel == 0) {
				new_dist = dist + C_o;
				new_fuel = M_o - 1;
				new_type = 0;
				for (int i = 0; i < edge[pos].size(); i++) {
					new_pos = edge[pos][i];
					if (new_dist < mem[new_pos][new_fuel][new_type]) {
						mem[new_pos][new_fuel][new_type] = new_dist;
						pq.push(PIIII(PII(-new_dist, new_pos),PII(new_fuel, new_type)));
					}
				}

				if (pos % (2*MAX_K) < MAX_K) {
					new_dist = dist + C_g;
					new_fuel = M_g - 1;
					new_type = 1;
					for (int i = 0; i < edge[pos].size(); i++) {
						new_pos = edge[pos][i];
						if (new_dist < mem[new_pos][new_fuel][new_type]) {
							mem[new_pos][new_fuel][new_type] = new_dist;
							pq.push(PIIII(PII(-new_dist, new_pos),PII(new_fuel, new_type)));
						}
					}
				}
			} else {
				new_dist = dist;
				new_fuel = fuel - 1;
				new_type = type;
				new_pos = pos;

				if (new_dist < mem[new_pos][new_fuel][new_type]) {
					mem[new_pos][new_fuel][new_type] = new_dist;
					pq.push(PIIII(PII(-new_dist, new_pos),PII(new_fuel, new_type)));
				}

				for (int i = 0; i < edge[pos].size(); i++) {
					new_type = type;
					new_fuel = fuel - 1;
					new_dist = dist + (new_type == 0 ? 0 : C_g);
					new_pos = edge[pos][i];
					if (new_dist < mem[new_pos][new_fuel][new_type]) {
						mem[new_pos][new_fuel][new_type] = new_dist;
						pq.push(PIIII(PII(-new_dist, new_pos),PII(new_fuel, new_type)));
					}
				}
			}
		}
	}

	long long ans = mem[2*MAX_K*B][0][0];
	for(int i = 0; i <= 200; i++) {
		ans = min(ans, min(mem[2*MAX_K*B][i][0], mem[2*MAX_K*B][i][1]));
	}

	printf("%lld\n", ans);
}
