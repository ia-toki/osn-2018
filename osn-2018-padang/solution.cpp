#include <bits/stdc++.h>
using namespace std;

using ll = long long;

namespace {

vector<pair<int, ll>> parts;
vector<ll> sum;

void pre() {
  sum.resize(static_cast<int>(parts.size()));
  for (int i = 0; i < static_cast<int>(sum.size()); i++) {
    sum[i] = parts[i].second;
    if (i > 0) {
      sum[i] += sum[i - 1];
    }
  }
}

bool init(ll A, ll B) {
  while (A || B) {
    if (B >= A && A > 0) {
      parts.emplace_back(0, B / A);
      B %= A;
    } else if (A >= B + 1) {
      parts.emplace_back(1, A / (B + 1));
      A %= B + 1;
    } else {
      break;
    }
  }
  reverse(begin(parts), end(parts));
  if (parts.empty()) {
    return false;
  }
  if (parts[0].first != 1) {
    return false;
  }
  if (A == 0 && B == 0) {
    pre();
    return true;
  } else {
    return false;
  }
}

}  // namespace

bool isPossible(long long A, long long B, int _) {
  return init(A, B);
}

std::string getSubstring(long long L, long long R) {
  L++; R++;
  if (sum.empty() || R > sum.back()) {
    return "DI LUAR BATAS";
  }
  int i = lower_bound(begin(sum), end(sum), L) - begin(sum);
  static char buf[55];
  char *cur = buf;
  while (L <= R) {
    if (sum[i] <= R) {
      while (L <= sum[i]) {
        *cur++ = parts[i].first + '0';
        L++;
      }
      i++;
    } else {
      while (L <= R) {
        *cur++ = parts[i].first + '0';
        L++;
      }
    }
  }
  return string(buf, cur);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string header;
  cin >> header;

  long long a, b;
  int q;
  cin >> a >> b >> q;

  if (!isPossible(a, b, q)) {
    puts("TIDAK MUNGKIN");
    return 0;
  }

  puts("MUNGKIN");

  for (int i = 0; i < q; i++) {
    long long l, r;
    cin >> l >> r;
    puts(getSubstring(l, r).c_str());
  }
}
