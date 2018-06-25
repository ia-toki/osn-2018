#include <bits/stdc++.h>
using namespace std;

#define INF 4123456789012345678
#define MAX_N 100
#define MAX_M 100

typedef pair<long long, long long> PII;
typedef pair<PII, long long> PIII;
typedef pair<PII, PII> PIIII;

long long N, E, A, B;
long long C_g, M_g, C_o, M_o;
long long sp[MAX_N+7][MAX_M+7][2];
char HEADER[27];
vector<PIII> edge[MAX_N+7];
priority_queue<PIIII> pq;

int main() {
	scanf("%s", HEADER);
	scanf("%lld%lld", &N, &E);
	scanf("%lld%lld", &C_g, &M_g);
	scanf("%lld%lld", &C_o, &M_o);
	scanf("%lld%lld", &A, &B);

	for (long long i = 0; i < E; i++) {
		long long x, y, q;
		long long k;
		scanf("%lld%lld%lld%lld", &x, &y, &k, &q);

		edge[x].push_back(PIII(PII(y, k), q));
		edge[y].push_back(PIII(PII(x, k), q));
	}

	for (long long i = 1; i <= N; i++) {
		for (long long j = 0; j <= MAX_M; j++) {
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
			// printf("%lld %lld %lld: %lld\n", pos, fuel, type, dist);

			long long new_dist;
			long long new_pos;
			long long new_fuel;
			long long new_type;

			for (long long ii = 0; ii < edge[pos].size(); ii++) {
				new_pos = edge[pos][ii].first.first;
				long long k = edge[pos][ii].first.second;
				long long q = edge[pos][ii].second;

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

					// not using this ojek or still use this ojek but till mid-way
					for (long long i = 0; i <= min(k-1, fuel); i++) {
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

						// go online and local in the end
						k_online = (k-i) / M_g * M_g;
						k_local = (k-i) % M_g;
						new_dist = dist + (type == 0 ? 0 : i * C_g) + k_online * C_g + (k_local + M_o-1) / M_o * C_o;
						new_fuel = (k_local % M_o == 0 ? 0 : M_o - k_local % M_o);
						new_type = 0;
						if (new_dist < sp[new_pos][new_fuel][new_type]) {
							sp[new_pos][new_fuel][new_type] = new_dist;
							pq.push(PIIII(PII(-new_dist, new_pos), PII(new_fuel, new_type)));
						}
					}

					// using all the fuels, then iterate the ending of local
					if (fuel < k) {
						for (long long i = -M_o; i <= M_o; i++) {
							long long k_local = (k-fuel) / M_o * M_o;
							long long k_online = (k-fuel) % M_o;

							k_local -= i;
							k_online += i;
							if (k_local <= 0 || k_online < 0) continue;

							new_dist = dist + (type == 0 ? 0 : fuel * C_g) + k_online * C_g + (k_local + M_o-1) / M_o * C_o;
							new_fuel = (k_local % M_o == 0 ? 0 : M_o - k_local % M_o);
							new_type = 0;
							if (new_dist < sp[new_pos][new_fuel][new_type]) {
								sp[new_pos][new_fuel][new_type] = new_dist;
								pq.push(PIIII(PII(-new_dist, new_pos), PII(new_fuel, new_type)));
							}
						}

						for (long long i = 1; i < M_o; i++) {
							long long k_local = i;
							long long k_online = (k-fuel-i);

							if (k_local <= 0 || k_online < 0) continue;

							new_dist = dist + (type == 0 ? 0 : fuel * C_g) + k_online * C_g + (k_local + M_o-1) / M_o * C_o;
							new_fuel = (k_local % M_o == 0 ? 0 : M_o - k_local % M_o);
							new_type = 0;
							if (new_dist < sp[new_pos][new_fuel][new_type]) {
								sp[new_pos][new_fuel][new_type] = new_dist;
								pq.push(PIIII(PII(-new_dist, new_pos), PII(new_fuel, new_type)));
							}
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
					for (long long i = 1; i <= min(k-1, fuel); i++) {
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
					for (long long i = 1; i <= min(k-1, tmp_fuel); i++) {
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
					for (long long i = 1; i <= min(k-1, tmp_fuel); i++) {
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
	for(long long i = 0; i <= MAX_M; i++) {
		ans = min(ans, min(sp[B][i][0], sp[B][i][1]));
	}

	printf("%lld\n", ans);
}
