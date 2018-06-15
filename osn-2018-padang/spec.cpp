#include <tcframe/spec.hpp>
#include <bits/stdc++.h>
using namespace tcframe;
using namespace std;

template <unsigned int N>
constexpr long long TEN = 10LL * TEN<N - 1>;

template <>
constexpr long long TEN<0> = 1;

class ProblemSpec : public BaseProblemSpec {
 protected:
  string header;
  long long A, B, Q;
  vector<long long> L, R;
        
  void InputFormat() {
    LINE(header)
    LINE(A, B, Q);
    LINES(L, R) % SIZE(Q);
  }

  void GradingConfig() {
    // TimeLimit(2);
  }

  void StyleConfig() {
    BatchEvaluator();
  }

  void Constraints() {
    CONS(static_cast<int>(header.size()) == 9);
    CONS(0 <= A && A <= TEN<15>);
    CONS(0 <= B && B <= TEN<15>);
    CONS(0 <= Q && Q <= 20000);
    CONS(eachElementBetween(L, 0, TEN<16> - 1));
    CONS(eachElementBetween(R, 0, TEN<16> - 1));
    CONS(validLR(L, R));
  }

  void Subtask1() {
    CONS(header == ".1..456.8");
    CONS(A == 3 && B == 9 && Q == 1);
    CONS(L == vi{1} && R == vi{4});
  }

  void Subtask2() {
    CONS(header == "..2..56.8");
    CONS(A == 25 && B == 3 && Q == 4);
    CONS(L == vi{0, 0, 0, 0});
    CONS(R == vi{7, 8, 9, 10});
  }

  void Subtask3() {
    // Points(9);

    CONS(0 <= A + B && A + B <= 8);
    CONS(Q == 1);
  }

  void Subtask4() {
    // Points(10);

    CONS(0 <= A + B && A + B <= 18);
    CONS(Q == 1);
  }

  void Subtask5() {
    // Points(19);

    CONS(0 <= A && A <= 2000);
    CONS(0 <= B && B <= 2000);
  }

  void Subtask6() {
    // Points(25);

    CONS(0 <= A && A <= TEN<6>);
    CONS(0 <= B && B <= TEN<6>);
  }

  void Subtask7() {
    // Points(17);
    CONS(Q == 0);
  }

  void Subtask8() {
    Points(20);
  }

 private:
  bool eachElementBetween(const vector<long long> &A, long long lo, long long hi) {
    for (long long it : A) {
      if (it < lo || it > hi) {
        return false;
      }
    }
    return true;
  }

  bool validLR(const vector<long long> &L, const vector<long long> &R) {
    for (int i = 0; i < static_cast<int>(L.size()); i++) {
      if (L[i] - R[i] > 0 || R[i] - L[i] > 50) {
        return false;
      }
    }
    return true;
  }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
 protected:
  long long stringLength_; 

  void SampleTestCase1() {
    Subtasks({5, 6, 7});

    Input({"5 2 4", "0 3", "1 2", "3 3", "0 4"});
  }

  void SampleTestCase2() {
    Subtasks({5, 6, 7});

    Input({"3 2 4", "0 3", "1 2", "3 3", "0 4"});
  }

  void BeforeTestCase() {
    L.clear(); R.clear();
  }

  // 1 <= A + B <= 8, Q = 1
  void TestGroup1() {
    Subtasks({3, 4, 5, 6, 7});
    CASE(A = 1; B = 0; Q = 1; L = {0}; R = {0});
    CASE(A = 1; B = 0; Q = 1; L = {1}; R = {1});
    CASE(A = 0; B = 1; Q = 1; L = {0}; R = {2});
    CASE(A = 1; B = 1; Q = 1; L = {0}; R = {2});
    CASE(A = 1; B = 7; Q = 1; L = {0}; R = {7});
    CASE(A = 1; B = 7; Q = 1; L = {0}; R = {8});
    CASE(A = 8; B = 0; Q = 1; L = {0}; R = {7});
    CASE(A = 8; B = 0; Q = 1; L = {0}; R = {8});
    CASE(convertSum("1001", A, B, 8); Q = 1; L = {0}; R = {3});
    CASE(convertSum("10001", A, B, 8); Q = 1; L = {0}; R = {4});

    for (int i = 0; i < 3; i++) {
      CASE(A = rnd.nextInt(0, 8); B = rnd.nextInt(0, 8 - A); Q = 1; L = {0}; R = {0});
    }
  }

  // 9 <= A + B <= 18, Q = 1
  void TestGroup2() {
    Subtasks({4, 5, 6, 7});
    CASE(convertSum("10011", A, B, 18); Q = 1; L = {0}; R = {4});
    CASE(A = 1; B = 17; Q = 1; L = {0}; R = {17});
    CASE(A = 18; B = 0; Q = 1; L = {0}; R = {17});
    CASE(A = 2; B = 16; Q = 1; L = {0}; R = {9});
    CASE(A = 8; B = 8; Q = 1; L = {0}; R = {7});

    for (int i = 0; i < 3; i++) {
      CASE(A = rnd.nextInt(0, 18); B = rnd.nextInt(0, 18 - A); Q = 1; L = {0}; R = {0});
    }
    for (int i = 0; i < 3; i++) {
      CASE(A = rnd.nextInt(0, 17); B = rnd.nextInt(0, 17 - A); Q = 1; L = {0}; R = {0});
    }
  }

  // 1 <= A, B <= 2000, Q = 0
  void TestGroup3() {
    Subtasks({5, 6, 7, 8});

    CASE(A = 0; B = 2000; Q = 0);
    CASE(A = 2000; B = 0; Q = 0);
    for (int i = 0; i < 10; i++) {
      CASE(tryGenerateSmall(A, B, 2000); Q = 0);
    }
    for (int i = 0; i < 10; i++) {
      CASE(A = rnd.nextInt(0, 2000); B = rnd.nextInt(0, 2000); Q = 0);
    }
  }

  // 2001 <= A, B <= 1e6, Q = 0
  void TestGroup4() {
    Subtasks({6, 7, 8});

    CASE(A = 0; B = 1000000; Q = 0);
    CASE(A = 1000000; B = 0; Q = 0);
    for (int i = 0; i < 5; i++) {
      CASE(tryGenerateSmall(A, B, 1000000); Q = 0);
    }
    for (int i = 0; i < 10; i++) {
      CASE(A = rnd.nextInt(0, 1000000); B = rnd.nextInt(0, 1000000); Q = 0);
    }
  }

  // 1e6 + 1 <= A, B <= 1e15, Q = 0
  void TestGroup5() {
    Subtasks({7, 8});
    for (int i = 0; i < 5; i++) {
      CASE(tryGenerateLarge(A, B, TEN<15>); Q = 0);
    }
    for (int i = 0; i < 5; i++) {
      CASE(A = rnd.nextLongLong(TEN<6> + 1, TEN<15>); B = rnd.nextLongLong(TEN<6> + 1, TEN<15>); Q = 0);
    }
  }

  // 1 <= A, B <= 2000, Q > 1
  void TestGroup6() {
    Subtasks({5, 6, 8});

    for (int i = 0; i < 10; i++) {
      CASE(stringLength_ = tryGenerateSmall(A, B, 2000); generateGT1Queries(stringLength_));
    }
    CASE(stringLength_ = tryGenerateSmall(A, B, 2000); generateGT1Queries(stringLength_, false));
    for (int i = 0; i < 10; i++) {
      CASE(A = rnd.nextInt(0, 2000); B = rnd.nextInt(0, 2000); generateGT1Queries(rnd.nextLongLong(TEN<2>, TEN<3>)));
    }
    CASE(A = rnd.nextInt(0, 2000); B = rnd.nextInt(0, 2000); generateGT1Queries(rnd.nextLongLong(TEN<2>, TEN<3>), false));
  }

  // 2001 <= A, B <= 1e6, Q > 1
  void TestGroup7() {
    Subtasks({6, 8});

    for (int i = 0; i < 5; i++) {
      CASE(stringLength_ = tryGenerateSmall(A, B, 1000000); generateGT1Queries(stringLength_));
    }
    CASE(stringLength_ = tryGenerateSmall(A, B, 1000000); generateGT1Queries(stringLength_, false));
    for (int i = 0; i < 10; i++) {
      CASE(A = rnd.nextInt(0, 1000000); B = rnd.nextInt(0, 1000000); generateGT1Queries(rnd.nextLongLong(TEN<5>, TEN<6>)));
    }
    CASE(A = rnd.nextInt(0, 1000000); B = rnd.nextInt(0, 1000000); generateGT1Queries(rnd.nextLongLong(TEN<5>, TEN<6>), false));
  }

  // 1e6 + 1 <= A, B <= 1e15, Q > 1
  void TestGroup8() {
    Subtasks({8});
    for (int i = 0; i < 5; i++) {
      CASE(stringLength_ = tryGenerateLarge(A, B, TEN<15>); generateGT1Queries(stringLength_));
    }
    CASE(stringLength_ = tryGenerateLarge(A, B, TEN<15>); generateGT1Queries(stringLength_, false));
    for (int i = 0; i < 5; i++) {
      CASE(A = rnd.nextLongLong(TEN<6> + 1, TEN<15>); B = rnd.nextLongLong(TEN<6> + 1, TEN<15>); generateGT1Queries(rnd.nextLongLong(TEN<14>, TEN<16> - 1)));
    }
    CASE(A = rnd.nextLongLong(TEN<6> + 1, TEN<15>); B = rnd.nextLongLong(TEN<6> + 1, TEN<15>); generateGT1Queries(rnd.nextLongLong(TEN<14>, TEN<16> - 1), false));
  }
 private:

  void convertSum(const string &s, long long &A, long long &B, int sumLimit) {
    assert(s[0] == '1');
    A = 1; B = 0;
    for (int i = 1; i < static_cast<int>(s.size()); i++) {
      if (s[i] == '1') {
        A += B + 1;
      } else {
        B += A;
      }
    }
    assert(A + B <= sumLimit);
  }

  void generateGT1Queries(long long len, bool small = true) {
    int cnt = small ? rnd.nextInt(2, 100) : rnd.nextInt(10000, 20000);
    Q = cnt;
    L.push_back(0);
    R.push_back(min(50LL, len - 1));
    cnt--;
    while (cnt--) {
      L.push_back(rnd.nextLongLong(0, max(0LL, len - 1 - 50)));
      R.push_back(L.back() + min(len, 50LL));
    }
  }

  int tryGenerateSmall(long long &A, long long &B, int limit) {
    string s = "1";
    A = 1;
    B = 0;
    while (A <= limit && B <= limit) {
      int next = rnd.nextInt(2);
      s += next + '0';
      if (next == 1) {
        A += B + 1;
      } else {
        B += A;
      }
    }
    if (s.back() == '1') {
      A -= B + 1;
    } else {
      B -= A;
    }
    s.pop_back();
    return static_cast<int>(s.size());
  }

  long long tryGenerateLarge(long long &A, long long &B, long long limit) {
    vector<pair<int, long long>> v;
    v.emplace_back(1, 1);
    long long len = 1;
    A = 1;
    B = 0;
    int zeroWeight = 3; // /6
    int last = 1;
    while (A <= limit && B <= limit) {
      int which = rnd.nextInt(6) < zeroWeight ? 0 : 1;
      if (which == 0) {
        long long curLimit = (limit - B + A - 1) / A;
        long long howMany = rnd.nextLongLong(1, curLimit);
        B += A * howMany;
        v.emplace_back(0, howMany);
      } else {
        long long curLimit = (limit - A + B) / (B + 1);
        long long howMany = rnd.nextLongLong(1, curLimit);
        A += (B + 1) * howMany;
        v.emplace_back(1, howMany);
      }
      len += v.back().second;
      if (last != which) {
        zeroWeight = 3;
      } else {
        if (which == 0) {
          zeroWeight--;
        } else {
          zeroWeight++;
        }
      }
    }
    if (v.back().first == 1) {
      A -= B + 1;
    } else {
      B -= A;
    }
    len--;
    return len;
  }
};
