#include <bits/stdc++.h>
using namespace std;

const int N = 205;
const int M = 202; // also serve as offset
const long long INF = 4e18;

struct State {
  int pos;
  int dst;
  int type;

  // dipaksa pq; gak kepake aslinya
  bool operator <(State other) const {
    return pos < other.pos;
  }
};

struct Edge {
  int to;
  int len;
  int type;
};

long long dist[N][2 * M][2];

vector<Edge> adj[N];
int c_o, m_o;
int c_g, m_g;
int source, target;

int n, m;
string header;

priority_queue<pair<long long, State>> pq;

void relax(long long ndis, int nxt, int ndst, int type) {
  if(ndis < dist[nxt][ndst][type]) {
    dist[nxt][ndst][type] = ndis;
    pq.push({-ndis, (State){nxt, ndst, type}});
  }
}

void expand_before_reach(int pos, int dst, int type) {
  assert(dst < M);

  long long dis = dist[pos][dst][type];

  // boleh pake ojol
  if (type == 1) {
    long long ndis = dis + c_g;
    relax(ndis, pos, dst+1, type);
  }

  // pake opang
  {
    long long ndis = dis + c_o;
    relax(ndis, pos, dst + m_o, 0);
  }
}

void expand_node(int pos, int dst, int type) {
  assert(dst == M);
  long long dis = dist[pos][dst][type];

  // pake ojol
  {
    long long ndis = dis;
    relax(ndis, pos, dst + max(m_g, m_o), 1);
  }

  // pake opang
  {
    long long ndis = dis + c_o;
    relax(ndis, pos, dst + m_o, 0);
  }
}

void expand_rollback(int pos, int dst, int type) {
  assert(dst > M);

  long long ndis = dist[pos][dst][type];
  relax(ndis, pos, dst - 1, type);
}

void expand_use_edge(int pos, int dst, int type, Edge edge) {
  assert(dst >= M);

  long long dis = dist[pos][dst][type];
  int real_dst = dst - M;
  int nxt = edge.to;
  int len = edge.len;
  int edge_type = edge.type;

  // blocked, pake ojol, dan jaraknya lebih dari maksimum
  if (edge_type == 1 && type == 1 && real_dst > m_g) {
    return;
  }

  if (real_dst >= len) {
    // kalau bablas, gak mungkin real_dst > m_g
    if(type == 1 && real_dst > m_g) {
      return;
    }

    // langsung nyampein
    {
      long long ndis = dis;
      if (type == 1) {
        ndis += 1ll * len * c_g;
      }
      int ndst = M + real_dst - len;

      relax(ndis, nxt, ndst, type);
    }

    // anggep bisa ganti tengah jalan
    // sebenernya cuma penting kalo lagi pake ojol
    {
      long long ndis = dis;
      int ndst = M - len;

      relax(ndis, nxt, ndst, type);
    }
  } else {
    long long base_dis = dis;
    if(type == 1) {
      base_dis += 1ll * c_g * real_dst;
    }

    int sisa_len = len - real_dst;
    // pake opang
    {
      long long opang_dis = base_dis + 1ll * c_o * (sisa_len / m_o);
      int opang_len = sisa_len % m_o;

      // lebih meyakinkan
      if(sisa_len >= m_o && opang_len == 0) {
        opang_len += m_o;
        opang_dis -= c_o;
      }

      // kebalik 0/1 edge_type sama type
      relax(opang_dis, nxt, M - opang_len, 1 - edge_type);
    }
    
    // pake ojol
    // mentokin sampe tepat kelar kalau pake opang
    if(edge_type == 0) {
      int to_end = min(sisa_len, m_o);
      int traverse_len = sisa_len - to_end;

      long long ojol_dis = base_dis + 1ll * c_g * traverse_len;
      relax(ojol_dis, nxt, M - to_end, 1);
    }
  }
}

void read() {
  cin >> header;

  scanf("%d %d", &n, &m);
  scanf("%d %d", &c_g, &m_g);
  scanf("%d %d", &c_o, &m_o);
  scanf("%d %d", &source, &target);

  for(int i = 0 ; i < m ; i++) {
    int x, y, k, q;
    scanf("%d %d %d %d", &x, &y, &k, &q);

    adj[x].push_back((Edge){y, k, q});
    adj[y].push_back((Edge){x, k, q});
  }
}

long long work() {
  for(int i = 0 ; i < N ; i++) {
    for(int j = 0 ; j < 2 * M ; j++) {
      dist[i][j][0] = dist[i][j][1] = INF;
    }
  }

  for(int i = 0 ; i < 2 ; i++) {
    dist[source][M][i] = 0;
    pq.push({0, (State){source, M, i}});
  }

  while(!pq.empty()) {
    long long dis = -pq.top().first;
    State cur = pq.top().second;
    pq.pop();

    int pos = cur.pos;
    int dst = cur.dst;
    int type = cur.type;

    if(dis != dist[pos][dst][type]) {
      continue;
    }

    // belom nyampe
    if(dst < M) {
      expand_before_reach(pos, dst, type);
    }
    else {
      if(dst == M) {
        expand_node(pos, dst, type);   
      }

      // mundur
      if (dst > M){
        expand_rollback(pos, dst, type);
      }

      for (Edge edge : adj[pos]) {
        expand_use_edge(pos, dst, type, edge);
      }
    }
  }

  long long ret = min(dist[target][M][0], dist[target][M][1]);
  return ret;
}

int main() {
  read();
  printf("%lld\n", work());
  return 0;
}