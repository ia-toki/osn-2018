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

const int N = 105;

struct Edge {
  int to, dist;

  Edge() {}
  Edge(int to, int dist) : to(to), dist(dist) {}
};

struct PQEntry {
  int u, excess;
  int temporary;  // intermediate state in unblocked edge
  ll value;

  PQEntry() {}
  PQEntry(int u, int excess, bool temporary, ll value) : u(u), excess(excess), temporary(temporary), value(value) {}

  struct DefaultComparator {
    bool operator()(const PQEntry &a, const PQEntry &b) const {
      if (a.value != b.value) {
        return a.value > b.value;
      }
      // prioritize non temporary for same value entries
      if (a.temporary != b.temporary) {
        return a.temporary > b.temporary;
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
ll dist[N][2 * N][2]; // dist, excess, temporary
vector<Edge> blockedEdge[N];
vector<Edge> unblockedEdge[N];

template<typename PQ>
void relax(PQ &pq, int to, int excess, int temporary, ll value) {
  assert(temporary || excess < Mo);
  if (dist[to][excess][temporary] > value) {
    dist[to][excess][temporary] = value;
    pq.push(PQEntry(to, excess, temporary, value));
  }
}

template<typename PQ>
void processNodeBlocked(PQ &pq, int u, int excess, ll value, bool firstTimePop) {
  auto useExcess = [&](int to, int k) {
    if (excess >= k) {
      relax(pq, to, excess - k, false, value);
    } else {
      int rem = k - excess;
      ll opangCost = 1LL * (rem + Mo - 1) / Mo * Co;
      relax(pq, to, (Mo - rem % Mo) % Mo, false, value + opangCost);
    }
  };
  auto discardExcess = [&](int to, int k) {
    for (int distG = 0; distG <= Mg && distG <= k; distG++) {
      int rem = k - distG;
      ll gojekCost = 1LL * distG * Cg;
      ll opangCost = 1LL * (rem + Mo - 1) / Mo * Co;
      relax(pq, to, (Mo - rem % Mo) % Mo, false, value + gojekCost + opangCost);
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
void processNodeUnblockedNonTemporary(PQ &pq, int u, int excess, ll value) {
  relax(pq, u, excess, true, value);
  for (const Edge &e : unblockedEdge[u]) {
    if (excess >= e.dist) {
      relax(pq, e.to, excess - e.dist, false, value);
    }
  }
}

template<typename PQ>
void processNodeUnblockedTemporary(PQ &pq, int u, int excess, ll value) {
  auto doGojekStep = [&]() {
    if (excess + 1 >= 2 * N) {
      return;
    }
    relax(pq, u, excess + 1, true, value + Cg);
  };

  auto doOpangStep = [&](int to, int k) {
    int cnt = (k + Mo - 1) / Mo;
    ll stepCost = min<ll>(Co, 1LL * Mo * Cg);
    ll tripCost = cnt == 0 ? 0 : ((cnt - 1) * stepCost + Co);
    if (k % Mo == 0) {
      tripCost = min(tripCost, cnt * stepCost);
      if (cnt == 0) assert(tripCost == 0);
    }
    relax(pq, to, (Mo - k % Mo) % Mo, false, value + tripCost);
  };

  doGojekStep();
  for (const Edge &e : unblockedEdge[u]) {
    if (excess <= e.dist) {
      doOpangStep(e.to, e.dist - excess);
    }
  }
}

ll solve(int s, int t) {
  vi popped(N);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 2 * N; j++) {
      dist[i][j][0] = dist[i][j][1] = LLONG_MAX / 2;
    }
  }

  priority_queue<PQEntry, vector<PQEntry>, PQEntry::DefaultComparator> pq;
  pq.push(PQEntry(s, 0, false, 0));
  dist[s][0][0] = 0;
  while (!pq.empty()) {
    int u = pq.top().u;
    int excess = pq.top().excess;
    int temporary = pq.top().temporary;
    ll value = pq.top().value;
    if (u == t) {
      break;
    }
    pq.pop();
    if (dist[u][excess][temporary] != value) {
      continue;
    }
    if (!temporary) {
      processNodeBlocked(pq, u, excess, value, !popped[u]);
      popped[u] = true;
      processNodeUnblockedNonTemporary(pq, u, excess, value);
    } else {
      processNodeUnblockedTemporary(pq, u, excess, value);
    }
  }

  ll ans = LLONG_MAX;
  for (int i = 0; i < N; i++) {
    ans = min(ans, dist[t][i][0]);
  }

  return ans;
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
