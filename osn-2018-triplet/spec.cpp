#include "tcframe/runner.hpp"
using namespace tcframe;

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100000;
const int MAX_VAL = 100000;

class ProblemSpec : public BaseProblemSpec {
protected:
  string HEADER;
  int N;
  vector<int> A;
  long long ANS;

  void InputFormat() {
    LINE(HEADER);
    LINE(N);
    LINE(A % SIZE(N));
  }

  void OutputFormat() {
    LINE(ANS);
  }

  void Constraints() {
    CONS(HEADER.length() == 7);
    CONS(validHeader(HEADER));

    CONS(3 <= N && N <= MAX_N);
    CONS(eachElementBetween(A, 1, MAX_VAL));
  }

  void Subtask1() {
    // Points(7);
    CONS(HEADER[1] == '1');
    CONS(N == 10);
    CONS(A == vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}));
  }

  void Subtask2() {
    // Points(7);
    CONS(HEADER[2] == '2');

    CONS(N == 15);
    CONS(A == vector<int>({5, 4, 5, 4, 4, 2, 1, 3, 3, 5, 3, 5, 2, 4, 5}));
  }

  void Subtask3() {
    // Points(7);
    CONS(HEADER[3] == '3');

    CONS(N <= 100);
  }

  void Subtask4() {
    // Points(7);
    CONS(HEADER[4] == '4');

    CONS(N <= 2000);
  }

  void Subtask5() {
    // Points(7);
    CONS(HEADER[5] == '5');

    CONS(eachElementBetween(A, 1, 100));
  }

  void Subtask6() {
    // Points(7);
    CONS(HEADER[6] == '6');
  }

 private:

  bool validHeader(string header) {
    for(int i = 0 ; i < header.length() ; i++) {
      if(header[i] != '.' && header[i] != i + '0') {
        return false;
      }
    }

    return true;
  }
  
  bool eachElementBetween(vector<int> &v, int lo, int hi) {
    for(int x : v) {
      if(x < lo || x > hi) {
        return false;
      }
    }

    return true;
  }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:

  void SampleTestCase1() {
    Subtasks({3, 4, 5, 6});

    Input({"0..3456",
           "4", 
           "1 4 1 2"});

    Output({"2"});
  }

  // open tc 1
  void TestGroup1() {
    Subtasks({1, 3, 4, 5, 6});

    CASE(HEADER = ".1.3456",
         N = 10,
         A = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
  }

  // open tc 2
  void TestGroup2() {
    Subtasks({2, 3, 4, 5, 6});

    CASE(HEADER = "..23456",
         N = 15,
         A = {5, 4, 5, 4, 4, 2, 1, 3, 3, 5, 3, 5, 2, 4, 5});
  }

  // N <= 100, A_i <= 100
  void TestGroup3() {
    Subtasks({3, 4, 5, 6});
    string header = "...3456";

    CASE(HEADER = header, N = 3, A = {1, 1, 1});
    CASE(HEADER = header, N = 100, A = randomArray(N, 1, 100));
    CASE(HEADER = header, N = 100, A = randomArray(N, 1, 10));
    CASE(HEADER = header, N = 100, A = randomArrayWithMajority(N, 1, 100));
    CASE(HEADER = header, N = 100, A = permutationArray(N));

    for (int i = 0; i < 2; i++) {
      CASE(HEADER = header,
           N = rnd.nextInt(50, 100),
           A = randomArray(N, 1, rnd.nextInt(1, 100)));

      CASE(HEADER = header,
           N = rnd.nextInt(50, 100),
           A = randomArrayWithMajority(N, 1, 100));

      CASE(HEADER = header,
           N = rnd.nextInt(50, 100), 
           A = permutationArray(N));
    }
  }

  // 100 < N <= 2000, A_i <= 100
  void TestGroup4() {
    Subtasks({4, 5, 6});
    string header = "....456";

    CASE(HEADER = header, N = 101, A = randomArray(N, 41, 43));
    CASE(HEADER = header, N = 2000, A = randomArray(N, 1, 100));
    CASE(HEADER = header, N = 2000, A = randomArray(N, 1, 10));
    CASE(HEADER = header, N = 2000, A = randomArrayWithMajority(N, 1, 100));

    for (int i = 0; i < 2; i++) {
      CASE(HEADER = header,
           N = rnd.nextInt(1000, 2000),
           A = randomArray(N, 1, 100));

      CASE(HEADER = header,
           N = rnd.nextInt(1000, 2000),
           A = randomArrayWithMajority(N, 1, 100));
    }
  }

  // 2000 < N <= 100000, A_i <= 100
  void TestGroup5() {
    Subtasks({5, 6});
    string header = ".....56";

    CASE(HEADER = header, N = 2001, A = randomArray(N, 1, 42));
    CASE(HEADER = header, N = 100000, A = randomArray(N, 1, 100));
    CASE(HEADER = header, N = 100000, A = randomArray(N, 1, 10));
    CASE(HEADER = header, N = 100000, A = randomArrayWithMajority(N, 1, 100));

    for (int i = 0; i < 2; i++) {
      CASE(HEADER = header, 
           N = rnd.nextInt(50000, 100000),
           A = randomArray(N, 1, 100));

      CASE(HEADER = header, 
           N = rnd.nextInt(50000, 100000),
           A = randomArrayWithMajority(N, 1, 100));
    }
  }

  // N <= 100, A_i > 100
  void TestGroup6() {
    Subtasks({3, 4, 6});
    string header = "...34.6";

    CASE(HEADER = header, N = 3, A = {666, 777, 4242});
    CASE(HEADER = header, N = 100, A = randomArray(N, 1, 100000));
    CASE(HEADER = header, N = 100, A = randomArray(N, 110, 120));
    CASE(HEADER = header, N = 100, A = randomArrayWithMajority(N, 1, 100000));

    for (int i = 0; i < 2; i++) {
      CASE(HEADER = header,
           N = rnd.nextInt(50, 100),
           A = randomArray(N, 1, rnd.nextInt(1, 100000)));

      CASE(HEADER = header,
           N = rnd.nextInt(50, 100),
           A = randomArrayWithMajority(N, 1, 100000));
    }
  }

  // 100 < N <= 2000, A_i > 100
  void TestGroup7() {
    Subtasks({4, 6});
    string header = "....4.6";

    CASE(HEADER = header, N = 101, A = randomArray(N, 1, 100000));
    CASE(HEADER = header, N = 2000, A = randomArray(N, 1, 100000));
    CASE(HEADER = header, N = 2000, A = randomArray(N, 50000, 50010));
    CASE(HEADER = header, N = 2000, A = randomArrayWithMajority(N, 1, 100000));
    CASE(HEADER = header, N = 2000, A = permutationArray(N));

    for (int i = 0; i < 2; i++) {
      CASE(HEADER = header,
           N = rnd.nextInt(1000, 2000),
           A = randomArray(N, 1, 100000));

      CASE(HEADER = header,
           N = rnd.nextInt(1000, 2000),
           A = randomArrayWithMajority(N, 1, 100000));

      CASE(HEADER = header,
           N = rnd.nextInt(1000, 2000), 
           A = permutationArray(N));
    }
  }

  // 2000 < N <= 100000, A_i > 100
  void TestGroup8() {
    Subtasks({6});
    string header = "......6";

    CASE(HEADER = header, N = 2001, A = randomArray(N, 1, 100000));
    CASE(HEADER = header, N = 100000, A = randomArray(N, 101, 102));
    CASE(HEADER = header, N = 100000, A = randomArray(N, 1, 100000));
    CASE(HEADER = header, N = 100000, A = randomArray(N, 4242, 4262));
    CASE(HEADER = header, N = 100000, A = randomArrayWithMajority(N, 1, 100000));
    CASE(HEADER = header, N = 100000, A = permutationArray(N));

    for(int i = 0 ; i < 2 ; i++) {
      CASE(HEADER = header,
           N = rnd.nextInt(50000, 100000),
           A = randomArray(N, 1, 100000));

      CASE(HEADER = header,
           N = rnd.nextInt(50000, 100000),
           A = randomArrayWithMajority(N, 1, 100000));

      CASE(HEADER = header,
           N = rnd.nextInt(50000, 100000),
           A = permutationArray(N));
    }
  }

  // void TestCases() {
  //   CASE(N = MIN_N, A = {1});

  //   // max case
  //   CASE(N = MAX_N, A = randomArray(N, N, N));
  //   CASE(N = MAX_N, A = randomArray(N, 1, N));
  //   CASE(N = MAX_N, A = randomArray(N, 1, 10));
  //   CASE(N = MAX_N, A = randomArrayWithMajority(N, 1, N));
  //   CASE(N = MAX_N, A = permutationArray(N));

  //   for(int i = 0 ; i < 2 ; i++) {
  //     CASE(N = rnd.nextInt(MAX_N / 2, MAX_N),
  //          A = randomArray(N, 1, min(N, 100)));

  //     CASE(N = rnd.nextInt(MAX_N / 2, MAX_N),
  //          A = randomArrayWithMajority(N, 1, N));

  //     CASE(N = rnd.nextInt(MAX_N / 2, MAX_N),
  //          A = permutationArray(N));
  //   }
  // }

private:
  vector<int> randomArray(int n, int lo, int hi) {
    vector<int> ret(n);

    for(int &x : ret) {
      x = rnd.nextInt(lo, hi);
    }

    return ret;
  }

  vector<int> randomArrayWithMajority(int n, int lo, int hi) {
    vector<int> ret = randomArray(n, lo, hi);

    int occ = rnd.nextInt((n + 1) / 2, n);
    int major = rnd.nextInt(lo, hi);

    for(int i = 0 ; i < occ ; i++) {
      ret[i] = major;
    }

    rnd.shuffle(ret.begin(), ret.end());

    return ret;
  }

  vector<int> permutationArray(int n) {
    vector<int> ret(n);

    iota(ret.begin(), ret.end(), 1);
    rnd.shuffle(ret.begin(), ret.end());

    return ret;
  }
};
