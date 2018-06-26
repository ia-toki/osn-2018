#include <bits/stdc++.h>
using namespace std;

const string POSSIBLE = "MUNGKIN";
const string IMPOSSIBLE = "TIDAK MUNGKIN";
const string OUT_OF_BOUND = "DI LUAR BATAS";

string answer = "";

bool is_alternating(string S) {
  if (S[0] != '1') {
    return false;
  }
  for (int i = 1; i < S.size(); ++i) {
    if (S[i] == S[i - 1]) {
      return false;
    }
  }
  return true;
}

bool check_string(string S, long long A, long long B) {
  for (int i = 0; i < (1 << S.size()); ++i) {
    string T = "";
    for (int j = 0; j < S.size(); ++j) {
      if (i & (1 << j)) {
        T += S[j];
      }
    }
    if (is_alternating(T)) {
      if (T.size() % 2 == 1) {
        --A;
      } else {
        --B;
      }
    }
  }
  return (A == 0 && B == 0);
}

bool is_possible(long long A, long long B) {
  int N = A + B;
  for (int i = 0; i < (1 << N); ++i) {
    string S = "";
    for (int j = 0; j < N; ++j) {
      if (i & (1 << j)) {
        S += '0';
      } else {
        S += '1';
      }
    }
    if (check_string(S, A, B)) {
      int non_zero = 0;
      while (S[non_zero] == '0') {
        ++non_zero;
      }
      answer = S.substr(non_zero, S.size() - non_zero);
      return true;
    }
  }
  return false;
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

  if(is_possible(a, b)) {
    printf("%s\n", POSSIBLE.c_str());
  } else {
    printf("%s\n", IMPOSSIBLE.c_str());
    return 0;
  }

  for(int i = 0 ; i < q ; i++) {
    long long l, r;
    scanf("%lld %lld", &l, &r);

    printf("%s\n", get_substring(l, r).c_str());
  }

  return 0;
}
