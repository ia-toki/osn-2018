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

  if (s == "AA") {
    s = "A";
    k *= 2;
  } else if (s == "BB") {
    s = "B";
    k *= 2;
  }

  ll n = 1LL * SZ(s) * k + 1;

  while (q--) {
    ll l, r;
    cin >> l >> r;
    l--; r--;
    ll ans = -1;
    if (s == "A") {
      ans = n - 1 - l;
    } else if (s == "B") {
      ans = r;
    } else if (s == "AB" || s == "BA") {
      ll mid = n / 2;
      if (l <= mid && mid <= r) {
        ans = k * 2;
      } else {
        if (l > mid) {
          ans = k * 2 - 2LL * (l - mid);
          ans += s == "BA";
        } else if (r < mid) {
          ans = k * 2 - 2LL * (mid - r);
          ans += s == "AB";
        } else {
          assert(false);
        }
      }
    } else {
      assert(false);
    }
    assert(ans != -1);
    cout << min<ll>(k * SZ(s), ans) + 1 << '\n';
  }
  return 0;
}
