#include <bits/stdc++.h>
using namespace std;

typedef pair<long long, long long> PII;

int N, E, A, B;
long long C_g, M_g, C_o, M_o;
bool flag[207];
char HEADER[27];
vector<int> edge[207];
queue<PII> que;

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

		edge[x].push_back(y);
		edge[y].push_back(x);
	}

	flag[A] = true;
	que.push(PII(A, 0));
	do {
		PII tmp = que.front();
		que.pop();

		if (tmp.first == B) {
			printf("%lld\n", tmp.second);
			break;
		} else {
			for (int i = 0; i < edge[tmp.first].size(); i++) {
				int next = edge[tmp.first][i];
				if (!flag[next]) {
					flag[next] = true;
					que.push(PII(next, tmp.second + 1));
				}
			}
		}
	} while (true);
}
