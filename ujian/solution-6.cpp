#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
const int MOD = 1e9 + 7;

string header;

int n, k;
int p[N];
int a[N], b[N];

int fact[N];
int ups_left[N], downs_left[N];
int ups_right[N], downs_right[N];

void read() {
  cin >> header;
  scanf("%d %d", &n, &k);

  for (int i = 1; i <= k; i++) scanf("%d", &p[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
}

int work() {
  fact[0] = 1;
  for (int i = 1; i <= n; i++) {
    fact[i] = 1ll * i * fact[i - 1] % MOD;
  }

  for(int i = 1 ; i <= n ; i++) {
    int idx = a[i];

    if(i < p[idx]) ups_left[idx]++;
    else downs_left[idx]++;
  }

  for(int i = 1 ; i <= n ; i++) {
    int idx = b[i];

    if(i < p[idx]) ups_right[idx]++;
    else downs_right[idx]++;
  }

  int ret = 1;
  for(int i = 1 ; i <= k ; i++) {
    if(ups_left[i] == downs_right[i] && ups_right[i] == downs_left[i]) {
      ret = 1ll * ret * fact[ups_left[i]] % MOD;
      ret = 1ll * ret * fact[downs_left[i]] % MOD;
    } else {
      ret = 0;
    }
  }

  return ret;
}

int main() {
  read();
  printf("%d\n", work());
  return 0;
}