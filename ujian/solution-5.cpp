#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
const int MOD = 1e9 + 7;

string header;

int n, k;
int p[N];
int a[N], b[N];

int fact[N];

void read() {
  cin >> header;
  scanf("%d %d", &n, &k);

  for (int i = 1; i <= k; i++) scanf("%d", &p[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
}

int work() {
  fact[0] = 1;
  for(int i = 1 ; i <= n ; i++) {
    fact[i] = 1ll * i * fact[i-1] % MOD;
  }

  int line = p[1];
  int up = line - 1;
  int down = n - line;
  int ret = 0;

  // line matched with line
  if(up == down) {
    ret = (ret + 1ll * fact[up] * fact[down]) % MOD;
  }

  // line matched with above
  if(up >= 1) {
    int add = 1ll * fact[up] * fact[down] % MOD;
    add = (1ll * add * up) % MOD;

    // up matched with line
    if(up == down+1) {
      ret = (ret + add) % MOD;
    }

    // down matched with line
    if(up == down) {
      ret = (ret + add) % MOD;
    }
  }

  // line matched with below
  if(down >= 1) {
    int add = 1ll * fact[up] * fact[down] % MOD;
    add = (1ll * add * down) % MOD;

    // up matched with line
    if(up == down) {
      ret = (ret + add) % MOD;
    }
    
    // down matched with line
    if(up+1 == down) {
      ret = (ret + add) % MOD;
    }
  }

  return ret;
}

int main() {
  read();
  printf("%d\n", work());
  return 0;
}