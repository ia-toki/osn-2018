#include <bits/stdc++.h>
using namespace std;

#define INF 4123456789012345678
#define MAX_N 200
#define MAX_M 200
#define MAX_K 200

typedef pair<long long, long long> PII;
typedef pair<PII, long long> PIII;
typedef pair<PII, PII> PIIII;

int N, E, A, B;
long long C_g, M_g, C_o, M_o;
long long mem[MAX_M+7][2][MAX_M+7][2][MAX_K+7];
long long sp[MAX_N+7][MAX_M+7][2];
char HEADER[27];
vector<PIII> edge[MAX_N+7];
priority_queue<PIIII> pq;

long long DP(long long fuel_sta, long long type_sta, long long fuel_fin, long long type_fin, long long dist) {
	if (dist == 0) {
		if (fuel_sta == fuel_fin && type_sta == type_fin) return 0;
		else return INF;
	}
	if (mem[fuel_sta][type_sta][fuel_fin][type_fin][dist] != -1) return mem[fuel_sta][type_sta][fuel_fin][type_fin][dist];

	long long ans = INF;
	if (fuel_sta > 0) {
		ans = min(ans, (type_sta == 0 ? 0 : C_g) + DP(fuel_sta-1, type_sta, fuel_fin, type_fin, dist-1));
	}
	ans = min(ans, C_o + DP(M_o-1, 0, fuel_fin, type_fin, dist-1));
	ans = min(ans, C_g + DP(M_g-1, 1, fuel_fin, type_fin, dist-1));

	return mem[fuel_sta][type_sta][fuel_fin][type_fin][dist] = ans;
}

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
		for (int j = 0; j <= MAX_M; j++) {
			sp[i][j][0] = INF;
			sp[i][j][1] = INF;
		}
	}

	for (int i = 0; i <= MAX_M; i++) {
		for (int j = 0; j <= MAX_M; j++) {
			for (int k = 0; k <= MAX_K; k++) {
				mem[i][0][j][0][k] = -1;
				mem[i][0][j][1][k] = -1;
				mem[i][1][j][0][k] = -1;
				mem[i][1][j][1][k] = -1;
			}
		}
	}

	sp[A][0][0] = 0;
	pq.push(PIIII(PII(-0, A), PII(0, 0)));
	while (!pq.empty()) {
		PIIII tmp = pq.top();
		pq.pop();

		long long dist = -tmp.first.first;
		int pos = tmp.first.second;
		int fuel = tmp.second.first;
		int type = tmp.second.second;

		if (sp[pos][fuel][type] == dist) {
			// printf("%d %d %d: %lld\n", pos, fuel, type, dist);

			long long new_dist;
			int new_pos;
			int new_fuel;
			int new_type;

			for (int i = 0; i < edge[pos].size(); i++) {
				new_pos = edge[pos][i].first.first;
				int k = edge[pos][i].first.second;
				int q = edge[pos][i].second;

				if (q == 0) {
					for (int j = 0; j <= MAX_M; j++) {
						new_dist = dist + DP(fuel, type, j, 0, k);
						new_fuel = j;
						new_type = 0;
						if (new_dist < sp[new_pos][new_fuel][new_type]) {
							sp[new_pos][new_fuel][new_type] = new_dist;
							pq.push(PIIII(PII(-new_dist, new_pos), PII(new_fuel, new_type)));
						}

						new_dist = dist + DP(fuel, type, j, 1, k);
						new_fuel = j;
						new_type = 1;
						if (new_dist < sp[new_pos][new_fuel][new_type]) {
							sp[new_pos][new_fuel][new_type] = new_dist;
							pq.push(PIIII(PII(-new_dist, new_pos), PII(new_fuel, new_type)));
						}
					}
				} else {
					// still use this ojek till next node
					if (fuel >= k) {
						new_dist = dist + (type == 0 ? 0 : k * C_g);
						new_fuel = fuel - k;
						new_type = type;
						if (new_dist < sp[new_pos][new_fuel][new_type]) {
							sp[new_pos][new_fuel][new_type] = new_dist;
							pq.push(PIIII(PII(-new_dist, new_pos), PII(new_fuel, new_type)));
						}
					}
					// still use this ojek but till mid-way
					for (int i = 1; i <= min(k-1, fuel); i++) {
						new_dist = dist + (type == 0 ? 0 : i * C_g) + (k-i + M_o-1) / M_o * C_o;
						new_fuel = ((k-i) % M_o == 0 ? 0 : M_o - (k-i) % M_o);
						new_type = 0;
						if (new_dist < sp[new_pos][new_fuel][new_type]) {
							sp[new_pos][new_fuel][new_type] = new_dist;
							pq.push(PIIII(PII(-new_dist, new_pos), PII(new_fuel, new_type)));
						}
					}

					// use new ojek right at the beginning (online)
					int tmp_dist = dist;
					int tmp_fuel = M_g;
					int tmp_type = 1;
					if (tmp_fuel >= k) {
						new_dist = tmp_dist + (tmp_type == 0 ? 0 : k * C_g);
						new_fuel = tmp_fuel - k;
						new_type = tmp_type;
						if (new_dist < sp[new_pos][new_fuel][new_type]) {
							sp[new_pos][new_fuel][new_type] = new_dist;
							pq.push(PIIII(PII(-new_dist, new_pos), PII(new_fuel, new_type)));
						}
					}
					for (int i = 1; i <= min(k-1, tmp_fuel); i++) {
						new_dist = tmp_dist + (tmp_type == 0 ? 0 : i * C_g) + (k-i + M_o-1) / M_o * C_o;
						new_fuel = ((k-i) % M_o == 0 ? 0 : M_o - (k-i) % M_o);
						new_type = 0;
						if (new_dist < sp[new_pos][new_fuel][new_type]) {
							sp[new_pos][new_fuel][new_type] = new_dist;
							pq.push(PIIII(PII(-new_dist, new_pos), PII(new_fuel, new_type)));
						}
					}

					// use new ojek right at the beginning (local)
					tmp_dist = dist + C_o;
					tmp_fuel = M_o;
					tmp_type = 0;
					if (tmp_fuel >= k) {
						new_dist = tmp_dist + (tmp_type == 0 ? 0 : k * C_g);
						new_fuel = tmp_fuel - k;
						new_type = tmp_type;
						if (new_dist < sp[new_pos][new_fuel][new_type]) {
							sp[new_pos][new_fuel][new_type] = new_dist;
							pq.push(PIIII(PII(-new_dist, new_pos), PII(new_fuel, new_type)));
						}
					}
					for (int i = 1; i <= min(k-1, tmp_fuel); i++) {
						new_dist = tmp_dist + (tmp_type == 0 ? 0 : i * C_g) + (k-i + M_o-1) / M_o * C_o;
						new_fuel = ((k-i) % M_o == 0 ? 0 : M_o - (k-i) % M_o);
						new_type = 0;
						if (new_dist < sp[new_pos][new_fuel][new_type]) {
							sp[new_pos][new_fuel][new_type] = new_dist;
							pq.push(PIIII(PII(-new_dist, new_pos), PII(new_fuel, new_type)));
						}
					}
				}
			}
		}
	}

	long long ans = sp[B][0][0];
	for(int i = 0; i <= MAX_M; i++) {
		ans = min(ans, min(sp[B][i][0], sp[B][i][1]));
	}

	printf("%lld\n", ans);
}
