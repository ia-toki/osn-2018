#include <bits/stdc++.h>
using namespace std;

const string POSSIBLE = "MUNGKIN";
const string IMPOSSIBLE = "TIDAK MUNGKIN";
const string OUT_OF_BOUND = "DI LUAR BATAS";

string answer = "";

bool is_possible(long long A, long long B) {
  while (A >= 1 && B >= 0) {
    if (A > B) {
      A %= B + 1;
    } else {
      B %= A;
    }
  }
  return (A == 0 && B == 0);
}

std::string get_substring(long long L, long long R) { 
  return OUT_OF_BOUND; 
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
