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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string header;
  cin >> header;

  string s;
  cin >> s;
  int k, q;
  cin >> k >> q;

  int n = SZ(s) * k + 1;
  vi h(n + 1);
  h[0] = 1;
  h[n] = -1;
  int l = 0, r = n - 1;
  for (int it = 0; it < k; it++) {
    for (char c : s) {
      if (c == 'A') {
        h[l]++;
        h[r]--;
        r--;
      } else {
        h[l + 1]++;
        h[r + 1]--;
        l++;
      }
    }
  }

  for (int i = 1; i < n; i++) {
    h[i] += h[i - 1];
  }

  while (q--) {
    int l, r;
    cin >> l >> r;
    l--; r--;
    assert(0 <= l && l <= r && r < n);
    printf("%d\n", *max_element(h.begin() + l, h.begin() + r + 1));
  }
  return 0;
}
