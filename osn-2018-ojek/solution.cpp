#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define ALL(a) begin(a), end(a)
#define SZ(a) ((int)(a).size())

#ifdef __DEBUG
#define debug if (true)
#else
#define debug if (false)
#endif

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

template <typename T> using V = vector<T>;
template <typename T> using VV = vector<V<T>>;
template <typename T> using VVV = vector<VV<T>>;

const int N = 205;

struct Edge {
  int to, dist;

  Edge() {}
  Edge(int to, int dist) : to(to), dist(dist) {}
};

struct PQEntry {
  int u, excess;
  ll value;

  PQEntry() {}
  PQEntry(int u, int excess, ll value) : u(u), excess(excess), value(value) {}

  struct DefaultComparator {
    bool operator()(const PQEntry &a, const PQEntry &b) const {
      if (a.value != b.value) {
        return a.value > b.value;
      }
      if (a.excess != b.excess) {
        return a.excess < b.excess;
      }
      return a.u > b.u;
    }
  };
};

int n, m;
int Cg, Mg, Co, Mo;
ll dist[N][N];
vector<Edge> blockedEdge[N];
vector<Edge> unblockedEdge[N];

template<typename PQ>
void relax(PQ &pq, int to, ll value, int excess) {
  if (dist[to][excess] > value) {
    dist[to][excess] = value;
    pq.push(PQEntry(to, excess, value));
  }
}

template<typename PQ>
void processNodeBlocked(PQ &pq, int u, int excess, ll value, bool firstTimePop) {
  auto useExcess = [&](int to, int k) {
    if (excess >= k) {
      relax(pq, to, value, excess - k);
    } else {
      int rem = k - excess;
      relax(pq, to, value + 1LL * (rem + Mo - 1) / Mo * Co, (Mo - rem % Mo) % Mo);
    }
  };
  auto discardExcess = [&](int to, int k) {
    for (int distG = 0; distG <= Mg && distG <= k; distG++) {
      int rem = k - distG;
      relax(pq, to, value + 1LL * distG * Cg + 1LL * (rem + Mo - 1) / Mo * Co, (Mo - rem % Mo) % Mo);
    }
  };
  for (const Edge &e : blockedEdge[u]) {
    useExcess(e.to, e.dist);
    if (firstTimePop) {
      discardExcess(e.to, e.dist);
    }
  }
}

template<typename PQ>
void processNodeUnblocked(PQ &pq, int u, int excess, ll value) {
  auto useGojek = [&](int to, int k) {
    relax(pq, to, value + 1LL * k * Cg, 0);
  };
  auto useOpang = [&](int to, int k) {
    int cnt = (k + Mo - 1) / Mo;
    assert(cnt > 0);
    relax(pq, to, value + 1LL * cnt * Co, (Mo - k % Mo) % Mo);
    {
      int coveredByOpang = (cnt - 1) * Mo;
      int coveredByGojek = k - coveredByOpang;
      if (coveredByGojek <= Mg) {
        assert(coveredByOpang >= 0 && coveredByGojek > 0);
        relax(pq, to, value + 1LL * (cnt - 1) * Co + 1LL * coveredByGojek * Cg, 0);
      }
    }
  };
  for (const Edge &e : unblockedEdge[u]) {
    if (excess >= e.dist) {
      relax(pq, e.to, value, excess - e.dist);
      continue;
    }
    int rem = e.dist - excess;
    useGojek(e.to, rem);
    useOpang(e.to, rem);
  }
}

ll solve(int s, int t) {
  vi popped(N);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      dist[i][j] = LLONG_MAX / 2;
    }
  }

  priority_queue<PQEntry, vector<PQEntry>, PQEntry::DefaultComparator> pq;
  pq.push(PQEntry(s, 0, 0));
  dist[s][0] = 0;
  while (!pq.empty()) {
    int u = pq.top().u;
    int excess = pq.top().excess;
    ll value = pq.top().value;
    if (u == t) {
      break;
    }
    pq.pop();
    if (dist[u][excess] != value) {
      continue;
    }
    processNodeBlocked(pq, u, excess, value, !popped[u]);
    popped[u] = true;
    processNodeUnblocked(pq, u, excess, value);
  }
  return *min_element(begin(dist[t]), end(dist[t]));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string _; cin >> _;

  cin >> n >> m;
  cin >> Cg >> Mg >> Co >> Mo;
  int s, t; cin >> s >> t; s--; t--;

  for (int i = 0; i < m; i++) {
    int u, v, k, x;
    cin >> u >> v >> k >> x;
    u--; v--;
    if (!x) {
      unblockedEdge[u].push_back(Edge(v, k));
      unblockedEdge[v].push_back(Edge(u, k));
    } else {
      blockedEdge[u].push_back(Edge(v, k));
      blockedEdge[v].push_back(Edge(u, k));
    }
  }

  cout << solve(s, t) << endl;
  return 0;
}
