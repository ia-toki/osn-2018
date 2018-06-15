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

  ll n = 1LL * SZ(s) * k + 1;
  int dl = 0, dr = 0;
  for (char c : s) {
    if (c == 'A') {
      dr++;
    } else {
      dl++;
    }
  }

  while (q--) {
    ll l, r;
    cin >> l >> r;
    assert(1 <= l && l <= r && r <= n);
    ll mn = min((r - 1) / dl, (n - l) / dr);
    mn = min<ll>(mn, k);  // !!!
    ll ans = 1 + mn * SZ(s);
    ll pntL = 1 + mn * dl;
    ll pntR = n - mn * dr;
    assert(pntL <= r && pntR >= pntL);
    if (mn < k) {
      for (char c : s) {
        if (c == 'A') {
          pntR--;
        } else {
          pntL++;
        }
        if (pntL > r || pntR < l) {
          break;
        }
        ans++;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
