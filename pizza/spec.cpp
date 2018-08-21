#include <tcframe/spec.hpp>
#include <bits/stdc++.h>
using namespace tcframe;
using namespace std;

class ProblemSpec : public BaseProblemSpec {
 protected:
  string HEADER;
  int N, S;
  vector<int> A;
  int D, J;
  vector<int> DV, JV;

  void InputFormat() {
    LINE(HEADER);
    LINE(N, S);
    LINE(A % SIZE(N));
    LINE(D, DV % SIZE(D));
    LINE(J, JV % SIZE(J));
  }

  void OutputFormat() {
  }

  void StyleConfig() {
    InteractiveEvaluator();
  }

  void Constraints() {
    CONS(HEADER.length() == 5);
    CONS(validHeader(HEADER));

    CONS(1 <= N && N <= 10);
    CONS(1 <= S && S <= 2);
    
    CONS(eachElementsBetween(A, 1, 10));

    CONS(0 <= D && D <= N);
    CONS(eachElementsBetween(DV, 1, N));
    CONS(eachElementsUnique(DV));

    CONS(0 <= J && J <= N);
    CONS(eachElementsBetween(JV, 1, N));
    CONS(eachElementsUnique(JV));
  }

  void Subtask1() {
    Points(15);

    CONS(HEADER[1] == '1');

    CONS(N == 4);
    CONS(S == 1);

    CONS(A == vector<int>({2, 4, 6, 8}));
    
    CONS(D == 2);
    CONS(DV == vector<int>({3, 4}));

    CONS(J == 2);
    CONS(JV == vector<int>({2, 4}));
  }

  void Subtask2() {
    Points(15);

    CONS(HEADER[2] == '2');

    CONS(N == 6);
    CONS(S == 1);

    CONS(A == vector<int>({1, 2, 3, 4, 5, 6}));

    CONS(D == 6);
    CONS(DV == vector<int>({1, 2, 3, 4, 5, 6}));

    CONS(J == 3);
    CONS(JV == vector<int>({4, 5, 6}));
  }

  void Subtask3() {
    Points(40);

    CONS(HEADER[3] == '3');

    CONS(S == 1);
    CONS(eachElementsEven(A));
  }

  void Subtask4() {
    Points(30);

    CONS(HEADER[4] == '4');
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
  bool eachElementsBetween(vector<int> &v,int lo,int hi) {
    return all_of(v.begin(), v.end(), [&](int x) {
      return lo <= x && x <= hi;
    });
  }

  bool eachElementsEven(vector<int> &v) {
    return all_of(v.begin(), v.end(), [](int x) {
      return x % 2 == 0;
    });
  }

  bool eachElementsUnique(vector<int> &v) {
    set<int> st;
    for(int x : v) {
      if(st.count(x)) 
        return 0;
      st.insert(x);
    }
    return 1;
  }

};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:

  void SampleTestCase1() {
    Subtasks({3, 4});

    Input({"0..34", 
           "3 1",
           "2 4 4",
           "2 3 2",
           "2 1 3"});
  }

  void SampleTestCase2() {
    Subtasks({4});

    Input({"0...4", 
           "3 1",
           "3 4 4",
           "1 1",
           "2 1 2"});
  }

  void SampleTestCase3() {
    Subtasks({3, 4});

    Input({"0..34",
           "1 1",
           "4",
           "1 1",
           "1 1"});
  }

  void SampleTestCase4() {
    Subtasks({3, 4});

    Input({"0..34",
           "1 1",
           "4",
           "1 1",
           "1 1"});
  }

  void BeforeTestCase() {
    A.clear();
    DV.clear();
    JV.clear();
  }

  void AfterTestCase() {
  }

  // open tc 1
  void TestGroup1() {
    Subtasks({1, 3, 4});

    CASE(HEADER = ".1.34",
         N = 4,
         S = 1,
         A = vector<int>({2, 4, 6, 8}),
         D = 2,
         DV = vector<int>({3, 4}),
         J = 2,
         JV = vector<int>({2, 4})
    );
  }

  // open tc 2
  void TestGroup2() {
    Subtasks({2, 4});

    CASE(HEADER = "..2.4",
         N = 6,
         S = 1,
         A = vector<int>({1, 2, 3, 4, 5, 6}),
         D = 6,
         DV = vector<int>({1, 2, 3, 4, 5, 6}),
         J = 3,
         JV = vector<int>({4, 5, 6})
    );
  }

  // open tc 3
  void TestGroup3() {
    Subtasks({3, 4});
    string header = "...34";

    for(int i = 0 ; i < 30 ; i++) {
      CASE(HEADER = header,
           N = rnd.nextInt(1, 10),
           S = 1,
           A = randomEvenArray(N, 1, 10),
           D = rnd.nextInt(0, N),
           DV = randomUniqueArray(D, 1, N),
           J = rnd.nextInt(0, N),
           JV = randomUniqueArray(J, 1, N));
    }
  }

  void TestGroup4() {
    Subtasks({4});
    string header = "....4";


    for(int i = 0 ; i < 10 ; i++) {
      CASE(HEADER = header,
           N = rnd.nextInt(1, 10),
           S = 1,
           A = randomArray(N, 1, 10),
           D = rnd.nextInt(0, N),
           DV = randomUniqueArray(D, 1, N),
           J = rnd.nextInt(0, N),
           JV = randomUniqueArray(J, 1, N));
    }

    for(int i = 0 ; i < 40 ; i++) {
      CASE(HEADER = header,
           N = rnd.nextInt(1, 10),
           S = 2,
           A = randomArray(N, 1, 10),
           D = rnd.nextInt(0, N),
           DV = randomUniqueArray(D, 1, N),
           J = rnd.nextInt(0, N),
           JV = randomUniqueArray(J, 1, N));
    }
  }


private:

  vector<int> randomUniqueArray(int n, int lo, int hi) {
    vector<int> v(hi - lo + 1);
    iota(v.begin(), v.end(), lo);
    rnd.shuffle(v.begin(), v.end());
    v.erase(v.begin() + n, v.end());

    return v;
  }

  vector<int> randomEvenArray(int n, int lo, int hi) {
    vector<int> ret(n);
    for(int &x : ret) {
      do {
        x = rnd.nextInt(lo, hi);
      } while(x % 2 == 1);
    }
    return ret;
  }

  vector<int> randomArray(int n, int lo, int hi) {
    vector<int> ret(n);
    for(int &x : ret) {
      x = rnd.nextInt(lo, hi);
    }
    return ret;
  }
};
