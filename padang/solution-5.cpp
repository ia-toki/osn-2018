#include <bits/stdc++.h>
using namespace std;

const string POSSIBLE = "MUNGKIN";
const string IMPOSSIBLE = "TIDAK MUNGKIN";
const string OUT_OF_BOUND = "DI LUAR BATAS";

const int MAXN = 2000;

string answer = "";

int dp[MAXN + 5][MAXN + 5];
long long A, B;

int jahja(int a, int b) {
  if (a > A || b > B) {
    return 0;
  }
  if (a == A && b == B) {
    return 1;
  }
  int &ret = dp[a][b];
  if (ret >= 0) {
    return ret;
  }
  return jahja(a + 1 + b, b) | jahja(a, a + b);
}

void bt(int a, int b) {
  if (a == A && b == B) {
    return;
  }
  if (jahja(a + 1 + b, b)) {
    answer += '1';
    bt(a + 1 + b, b);
  } else {
    answer += '0';
    bt(a, a + b);
  }
}

bool is_possible(long long A, long long B) {
  ::A = A;
  ::B = B;
  memset(dp, -1, sizeof(dp));
  if (jahja(1, 0)) {
    answer = "1";
    bt(1, 0);
    return true;
  } else {
    return false;
  }
}

string get_substring(long long L, long long R) {
  if (0 <= L && R < answer.size()) {
    return answer.substr(L, R - L + 1);
  } else {
    return OUT_OF_BOUND;
  }
}

int main() {
  string header;
  long long a, b;
  int q;

  cin >> header;
  scanf("%lld %lld %d", &a, &b, &q);

  if (is_possible(a, b)) {
    printf("%s\n", POSSIBLE.c_str());
  } else {
    printf("%s\n", IMPOSSIBLE.c_str());
    return 0;
  }

  for (int i = 0; i < q; i++) {
    long long l, r;
    scanf("%lld %lld", &l, &r);

    printf("%s\n", get_substring(l, r).c_str());
  }

  return 0;
}
