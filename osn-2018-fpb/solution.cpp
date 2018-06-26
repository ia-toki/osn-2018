#include <bits/stdc++.h>
using namespace std;

const int N = 50005;
const int K = 25;
const int MOD = 1e9 + 7;

int gcd(int x, int y) {
  return y == 0 ? x : gcd(y, x % y);
}

int ways[K][N][2];
int ways_sum[K][N];

string header;
int arr[N];
int n, k;

int solve_ways(int left, int pos, int type) {
  if(left < 0) return 0;
  if(pos == 0) return left == 0;

  int &ret = ways[left][pos][type];
  if(ret != -1) return ret;

  // not taking this one
  ret = solve_ways(left, pos-1, 0);

  // start new
  ret = (ret + solve_ways(left-1, pos-1, 1)) % MOD;
  // continue from prev
  if(type == 1) {
    ret = (ret + solve_ways(left, pos-1, 1)) % MOD;
  }

  ret %= MOD;
  return ret;
}

int get_sum(int k, int l, int r) {
  int ret = ways_sum[k][r];
  if(l > 0) ret = (ret - ways_sum[k][l-1] + MOD) % MOD;

  return ret;
}

void read() {
  cin >> header;
  scanf("%d %d", &n, &k);

  for(int i = 1 ; i <= n ; i++) {
    scanf("%d", &arr[i]);
  }
}

void prepare() {
  memset(ways, -1, sizeof ways);

  for(int i = 0 ; i <= k ; i++) {
    ways_sum[i][0] = (i == 0);

    for(int j = 1 ; j <= n ; j++) {
      ways_sum[i][j] = ways_sum[i][j-1] + solve_ways(i, j, 0);
      ways_sum[i][j] %= MOD;
    }
  }
}

int work() {
  vector<pair<int, int>> ranges;
  int ret = 0;

  for(int i = 1 ; i <= n ; i++) {
    vector<pair<int, int>> new_ranges;
    new_ranges.push_back({arr[i], i});

    for(pair<int, int> it : ranges) {
      int nval = gcd(it.first, arr[i]);
      new_ranges.push_back({nval, it.second});
    }

    sort(new_ranges.begin(), new_ranges.end());

    vector<pair<int, int>> tmp_ranges = {new_ranges[0]};

    for(int j = 1 ; j < new_ranges.size() ; j++) {
      // new val with minimum pos
      if(new_ranges[j].first != new_ranges[j-1].first) {
        tmp_ranges.push_back(new_ranges[j]);
      }
    }
    
    new_ranges = tmp_ranges;
    int lst = i;
    int right_part = n - i;

    // iterate from highest gcd to lowest gcd
    for(int j = new_ranges.size()-1 ; j >= 0 ; j--) {
      int val = new_ranges[j].first;
      int pos = new_ranges[j].second;

      // brute force k for left to partition
      for(int k_left = 0 ; k_left < k ; k_left++) {
        int left_ways = get_sum(k_left, pos-1, lst-1);
        int right_ways = solve_ways(k - k_left - 1, right_part, 0);

        int adds = 1ll * left_ways * right_ways % MOD;
        adds = 1ll * adds * val % MOD;

        ret = (ret + adds) % MOD;
      }

      lst = pos - 1;
    }

    ranges = new_ranges;
  }

  return ret;
}

int main() {
  read();
  prepare();
  printf("%d\n", work());
  return 0;
}