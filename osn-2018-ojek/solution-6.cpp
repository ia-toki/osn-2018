#include <bits/stdc++.h>
using namespace std;

#define INF 4123456789012345678
#define MAX_N 100
#define MAX_M 10

typedef pair<long long, long long> PII;
typedef pair<PII, long long> PIII;
typedef pair<PII, PII> PIIII;

int N, E, A, B;
long long C_g, M_g, C_o, M_o;
long long sp[MAX_N+7][MAX_M+7][2];
char HEADER[27];
vector<PIII> edge[MAX_N+7];
priority_queue<PIIII> pq;

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

	sp[A][0][0] = 0;
	pq.push(PIIII(PII(-0, A), PII(0, 0)));
	while (!pq.empty()) {
		PIIII tmp = pq.top();
		pq.pop();

		long long dist = -tmp.first.first;
		long long pos = tmp.first.second;
		long long fuel = tmp.second.first;
		long long type = tmp.second.second;

		if (sp[pos][fuel][type] == dist) {
			//printf("%d %d %d: %lld\n", pos, fuel, type, dist);

			long long new_dist;
			long long new_pos;
			long long new_fuel;
			long long new_type;

			for (int i = 0; i < edge[pos].size(); i++) {
				new_pos = edge[pos][i].first.first;
				long long k = edge[pos][i].first.second;
				long long q = edge[pos][i].second;

				if (q == 0) {
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
						// always go local
						new_dist = dist + (type == 0 ? 0 : i * C_g) + (k-i + M_o-1) / M_o * C_o;
						new_fuel = ((k-i) % M_o == 0 ? 0 : M_o - (k-i) % M_o);
						new_type = 0;
						if (new_dist < sp[new_pos][new_fuel][new_type]) {
							sp[new_pos][new_fuel][new_type] = new_dist;
							pq.push(PIIII(PII(-new_dist, new_pos), PII(new_fuel, new_type)));
						}

						// always go online
						new_dist = dist + (type == 0 ? 0 : i * C_g) + (k-i) * C_g;
						new_fuel = ((k-i) % M_g == 0 ? 0 : M_g - (k-i) % M_g);
						new_type = 1;
						if (new_dist < sp[new_pos][new_fuel][new_type]) {
							sp[new_pos][new_fuel][new_type] = new_dist;
							pq.push(PIIII(PII(-new_dist, new_pos), PII(new_fuel, new_type)));
						}

						// go local and online in the end
						long long k_local = (k-i) / M_o * M_o;
						long long k_online = (k-i) % M_o;
						new_dist = dist + (type == 0 ? 0 : i * C_g) + k_local / M_o * C_o + k_online * C_g;
						new_fuel = (k_online % M_g == 0 ? 0 : M_g - k_online % M_g);
						new_type = 1;
						if (new_dist < sp[new_pos][new_fuel][new_type]) {
							sp[new_pos][new_fuel][new_type] = new_dist;
							pq.push(PIIII(PII(-new_dist, new_pos), PII(new_fuel, new_type)));
						}
					}

					// always go local
					new_dist = dist + (k + M_o-1) / M_o * C_o;
					new_fuel = (k % M_o == 0 ? 0 : M_o - k % M_o);
					new_type = 0;
					if (new_dist < sp[new_pos][new_fuel][new_type]) {
						sp[new_pos][new_fuel][new_type] = new_dist;
						pq.push(PIIII(PII(-new_dist, new_pos), PII(new_fuel, new_type)));
					}

					// always go online
					new_dist = dist + k * C_g;
					new_fuel = (k % M_g == 0 ? 0 : M_g - k % M_g);
					new_type = 1;
					if (new_dist < sp[new_pos][new_fuel][new_type]) {
						sp[new_pos][new_fuel][new_type] = new_dist;
						pq.push(PIIII(PII(-new_dist, new_pos), PII(new_fuel, new_type)));
					}

					// go local and online in the end
					long long k_local = k / M_o * M_o;
					long long k_online = k % M_o;
					new_dist = dist + (type == 0 ? 0 : i * C_g) + k_local / M_o * C_o + k_online * C_g;
					new_fuel = (k_online % M_g == 0 ? 0 : M_g - k_online % M_g);
					new_type = 1;
					if (new_dist < sp[new_pos][new_fuel][new_type]) {
						sp[new_pos][new_fuel][new_type] = new_dist;
						pq.push(PIIII(PII(-new_dist, new_pos), PII(new_fuel, new_type)));
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
					long long tmp_dist = dist;
					long long tmp_fuel = M_g;
					long long tmp_type = 1;
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
