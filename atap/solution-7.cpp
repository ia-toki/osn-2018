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
  vi prefixDl(SZ(s));
  vi prefixDr(SZ(s));
  for (int i = 0; i < SZ(s); i++) {
    char c = s[i];
    if (c == 'A') {
      dr++;
    } else {
      dl++;
    }
    prefixDr[i] = dr;
    prefixDl[i] = dl;
  }

  while (q--) {
    ll l, r;
    cin >> l >> r;
    l--; r--;
    ll lo = -1, hi = 1LL * SZ(s) * k + 1;
    while (lo + 1 < hi) {
      ll mid = (lo + hi) / 2;
      ll mult = mid / SZ(s);
      ll rem = mid % SZ(s);
      ll coveredL = dl * mult;
      ll coveredR = n - 1 - dr * mult;
      if (rem > 0) {
        coveredL += prefixDl[rem - 1];
        coveredR -= prefixDr[rem - 1];
      }
      if (coveredL <= l && l <= coveredR) {
        lo = mid;
      } else {
        hi = mid;
      }
    }
    printf("%lld\n", lo + 1);
  }
  return 0;
}
