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

const int MOD = 1e9 + 7;

int add(int a, int b) {
  if ((a += b) >= MOD) {
    a -= MOD;
  }
  return a;
}

int mul(int a, int b) {
  return 1LL * a * b % MOD;
}

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

void fix(vector<pii> &t) {
  int newSize = 0;
  for (int i = 0; i < SZ(t); i++) {
    if (newSize == 0 || t[i].fi != t[newSize - 1].fi) {
      t[newSize++] = t[i];
    } else {
      t[newSize - 1].se = t[i].se;
    }
  }
  t.resize(newSize);
}

VV<pair<int, pii>> precompute(const vi &a) {
  int n = SZ(a);
  VV<pair<int, pii>> ret(n);
  vector<pii> tmp;
  for (int i = n - 1; i >= 0; i--) {
    for (pii &j : tmp) {
      j.fi = gcd(j.fi, a[i]);
      assert(j.fi > 0);
    }
    tmp.emplace_back(a[i], i);
    fix(tmp);
    int last = n;
    for (int j = 0; j < SZ(tmp); j++) {
      ret[i].emplace_back(tmp[j].fi, pii(tmp[j].se, last - 1));
      last = tmp[j].se;
    }
  }
  debug {
    for (int i = 0; i < n; i++) {
      printf("%d:", i);
      for (const auto &it : ret[i]) {
        printf(" [%d,(%d,%d)]", it.fi, it.se.fi, it.se.se);
      }
      puts("");
    }
  }
  return ret;
}

VV<int> calcPartition(int n, int k) {
  VVV<int> dp(n + 1, VV<int>(k + 1, vi(2, 0)));
  dp[0][0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= k; j++) {
      dp[i + 1][j][0] = add(dp[i + 1][j][0], dp[i][j][0]);
      dp[i + 1][j][0] = add(dp[i + 1][j][0], dp[i][j][1]);
      if (j > 0) {
        dp[i + 1][j][1] = add(dp[i + 1][j][1], dp[i][j][1]);
      }
      if (j + 1 <= k) {
        dp[i + 1][j + 1][1] = add(dp[i + 1][j + 1][1], dp[i][j][0]);
        dp[i + 1][j + 1][1] = add(dp[i + 1][j + 1][1], dp[i][j][1]);
      }
    }
  }
  VV<int> partition(n + 1, vi(k + 1, 0));
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      partition[i][j] = add(dp[i][j][0], dp[i][j][1]);
    }
  }
  return partition;
}

int solve(int n, int k, const vi &a, const VV<pair<int, pii>> &compressedGcdTable, const VV<int> &partition) {
  VV<int> partitionSum(n + 1, vi(k + 1, 0));
  for (int i = 0; i <= k; i++) {
    partitionSum[0][i] = partition[0][i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      partitionSum[i][j] = add(partition[i][j], partitionSum[i - 1][j]);
    }
  }
  auto query = [&](int l, int r, int k) {
    return add(partitionSum[r][k], MOD - (l > 0 ? partitionSum[l - 1][k] : 0));
  };
  int ret = 0;
  for (int i = 0; i < n; i++) {
    int last = i;
    for (const auto &it : compressedGcdTable[i]) {
      int g = it.fi;
      int l = it.se.fi;
      int r = it.se.se;
      int leftRem = i;
      int rightRemL = n - 1 - r;
      int rightRemR = n - 1 - l;
      for (int assignLeft = 0; assignLeft <= k - 1; assignLeft++) {
        int ways = mul(partition[leftRem][assignLeft], query(rightRemL, rightRemR, k - 1 - assignLeft));
        ret = add(ret, mul(g, ways));
      }
    }
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string _; cin >> _;
  int n, k;
  cin >> n >> k;
  vi a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  auto compressedGcdTable = precompute(a);
  VV<int> partition = calcPartition(n, k);
  cout << solve(n, k, a, compressedGcdTable, partition) << endl;
  return 0;
}
