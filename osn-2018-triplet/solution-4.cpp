#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int MAX_VAL = 1e5 + 5;

string header;
int n;
int arr[N];
int cnt[N];

void read() {
  cin >> header;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &arr[i]);
  }
}

long long work() {
  long long ret = 0;

  for (int j = 1; j <= n; j++) {
    for(int k = j+1 ; k <= n ; k++) {
      if(arr[j] != arr[k]) {
        int possible_i = (j - 1) - cnt[arr[j]] - cnt[arr[k]];
        ret += possible_i;
      }
    }

    cnt[arr[j]]++;
  }

  return ret;
}

int main() {
  read();
  printf("%lld\n", work());
  return 0;
}