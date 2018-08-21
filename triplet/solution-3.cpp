#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

string header;
int n;
int arr[N];

void read() {
  cin >> header;
  scanf("%d", &n);
  for(int i = 1 ; i <= n ; i++) {
    scanf("%d", &arr[i]);
  }
}

long long work() {
  long long ret = 0;

  for(int i = 1 ; i <= n ; i++)
    for(int j = i+1 ; j <= n ; j++)
      if(arr[i] != arr[j]) {
        for(int k = j+1 ; k <= n ; k++) {
          if(arr[i] != arr[k] && arr[j] != arr[k]) {
            ret++;
          }
        }
      }
  
  return ret;
}

int main() {
  read();
  printf("%lld\n", work());
  return 0;
}