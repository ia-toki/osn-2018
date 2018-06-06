#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

string header;

int n, k;
int p[N];
int a[N], b[N];

int pos[N];

void read() {
  cin >> header;
  scanf("%d %d", &n, &k);

  for(int i = 1 ; i <= k ; i++) scanf("%d", &p[i]);
  for(int i = 1 ; i <= n ; i++) scanf("%d", &a[i]);
  for(int i = 1 ; i <= n ; i++) scanf("%d", &b[i]);
}

int work() {
  int ret = 0;
  vector<int> perm(n+1);
  iota(perm.begin()+1, perm.end(), 1);

  do {
    bool ok = true;

    for(int i = 1 ; i <= n ; i++) {
      int j = perm[i];

      if(a[i] != b[j]) {
        ok = false;
        break;
      }

      int line = a[i];

      if ((i < p[line] && j < p[line]) || (i > p[line] && j > p[line])) {
        ok = false;
        break;
      }
    }

    ret += ok;
  } while(next_permutation(perm.begin()+1, perm.end()));

  return ret;
}

int main() {
  read();
  printf("%d\n", work());
  return 0;
}