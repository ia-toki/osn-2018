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
  for(int i = 1 ; i <= n ; i++) {
    pos[a[i]] = i;
  }

  for(int j = 1 ; j <= n ; j++) {
    int line = b[j];
    int i = pos[line];

    if((i < p[line] && j < p[line]) ||
       (i > p[line] && j > p[line])) {
         return 0;
       }
  }

  return 1;
}

int main() {
  read();
  printf("%d\n", work());
  return 0;
}