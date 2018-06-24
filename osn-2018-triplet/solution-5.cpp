#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int MAX_VAL = 105;

string header;
int n;
int cnt[N];

void read() {
  cin >> header;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int x; scanf("%d", &x);
    cnt[x]++;
  }
}

long long work() {
  long long ret = 0;

  for(int i = 1 ; i < MAX_VAL ; i++)
    for(int j = i+1 ; j < MAX_VAL ; j++)
      for(int k = j+1 ; k < MAX_VAL ; k++) {
        ret += 1ll * cnt[i] * cnt[j] * cnt[k];
      }

  return ret;
}

int main() {
  read();
  printf("%lld\n", work());
  return 0;
}