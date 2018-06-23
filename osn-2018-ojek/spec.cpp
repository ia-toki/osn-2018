#include <tcframe/spec.hpp>
#include <bits/stdc++.h>
using namespace tcframe;
using namespace std;

using ll = long long;

#define SZ(a) ((int)(a).size())

template<int N>
constexpr ll TEN = 10LL * TEN<N - 1>;

template<>
constexpr ll TEN<0> = 1LL;

class ProblemSpec : public BaseProblemSpec {
 protected:
  string HEADER;
  int N, M;
  int S, T;
  int Cg, Mg, Co, Mo;
  vector<int> U, V, K, X;

  void InputFormat() {
    LINE(HEADER);
    LINE(N, M);
    LINE(Cg, Mg);
    LINE(Co, Mo);
    LINE(S, T);
    LINES(U, V, K, X) % SIZE(M);
  }

  void StyleConfig() {
    // InteractiveEvaluator();
  }

  void Constraints() {
    CONS(HEADER.length() == 8);
    CONS(2 <= N && N <= 100);
    CONS(N - 1 <= M && M <= N * (N - 1) / 2);
    CONS(1 <= S && S <= N);
    CONS(1 <= T && T <= N);
    CONS(S != T);
    CONS(1 <= Cg && Cg <= TEN<8>);
    CONS(1 <= Mg && Mg <= 100);
    CONS(1 <= Co && Co <= TEN<8>);
    CONS(1 <= Mo && Mo <= 100);
    CONS(validEdgeEndpoints());
    CONS(validEdgeCosts(1, TEN<8>));
    CONS(validBlockedValues());
    CONS(connected());
  }

  void Subtask1() {
    CONS(HEADER[1] == '1');

    vector<int> check_u = {1, 2, 3, 4};
    vector<int> check_v = {2, 3, 4, 5};
    vector<int> check_k = {1, 100, TEN<5>, TEN<8>};
    vector<int> check_x = {0, 0, 1, 0};

    CONS(HEADER == ".1....67" && N == 5 && M == 4 && Cg == 3 && Mg == 3 &&
         Co == 10 && Mo == 4 && S == 1 && T == 5 && U == check_u &&
         V == check_v && K == check_k && X == check_x);
  }

  void Subtask2() {
    CONS(HEADER[2] == '2');

    vector<int> check_u = {1, 1, 2, 2, 3, 3, 4, 3, 5, 6, 7, 6, 8, 7, 9};
    vector<int> check_v = {4, 2, 3, 4, 4, 5, 5, 8, 6, 7, 5, 8, 9, 9, 10};
    vector<int> check_k = {4, 1, 2, 2, 2, 2, 2, 9, 1, 1, 1, 3, 3, 3, 4};
    vector<int> check_x = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0};

    CONS(HEADER == "..2.4567" && N == 10 && M == 15 && Cg == 3 && Mg == 1 &&
         Co == 5 && Mo == 1 && S == 1 && T == 10 && U == check_u &&
         V == check_v && K == check_k && X == check_x);
  }

  void Subtask3() {
    CONS(HEADER[3] == '3');

    CONS(Cg == 1);
    CONS(Co == 1);
    CONS(Mg == 1);
    CONS(Mo == 1);
    CONS(validEdgeCosts(1, 1));
  }

  void Subtask4() {
    CONS(HEADER[4] == '4');

    CONS(Mg == 1);
    CONS(Mo == 1);
  }

  void Subtask5() {
    CONS(HEADER[5] == '5');

    CONS(validEdgeCosts(1, 10));
  }

  void Subtask6() {
    CONS(HEADER[6] == '6');

    CONS(Mg <= 10);
    CONS(Mo <= 10);
  }

  void Subtask7() {
    CONS(HEADER[7] == '7');
  }

 private:

  bool validEdgeEndpoints() {
    for (int i = 0; i < M; i++) {
      if (U[i] == V[i]) {
        return false;
      }
    }
    return all_of(begin(U), end(U), [&](int u) { return 1 <= u && u <= N; }) &&
        all_of(begin(V), end(V), [&](int u) { return 1 <= u && u <= N; });
  }

  bool validEdgeCosts(int lb, int ub) {
    return all_of(begin(K), end(K), [lb, ub](int k) { return lb <= k && k <= ub; });
  }

  bool validBlockedValues() {
    return all_of(begin(X), end(X), [](int x) { return x == 0 || x == 1; });
  }

  bool connected() {
    vector<vector<int>> adj(N);
    for (int i = 0; i < M; i++) {
      adj[U[i] - 1].push_back(V[i] - 1);
      adj[V[i] - 1].push_back(U[i] - 1);
    }
    queue<int> q;
    vector<int> visited(N);
    q.push(S - 1);
    visited[S - 1] = true;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int v : adj[u]) {
        if (!visited[v]) {
          visited[v] = true;
          q.push(v);
        }
      }
    }
    return find(begin(visited), end(visited), false) == end(visited);
  }

};

class TestSpec : public BaseTestSpec<ProblemSpec> {
 protected:

  void SampleTestCase1() {
    Subtasks({6, 7});

    Input({ "0.....67",
            "6 6",
            "2 6",
            "4 2",
            "5 2",
            "1 2 14 1",
            "1 3 4 0",
            "3 4 8 0",
            "4 2 12 0",
            "5 6 1 0",
            "6 1 1 0"});
  }

  void SampleTestCase2() {
    Subtasks({5, 6, 7});

    Input({ "0....567",
            "7 9",
            "1 2",
            "2 1",
            "1 7",
            "1 2 1 1",
            "2 3 1 1",
            "3 1 1 1",
            "3 4 1 1",
            "4 5 1 1",
            "5 3 1 1",
            "5 6 1 1",
            "6 7 1 1",
            "7 5 1 1"});
  }

  void SampleTestCase3() {
    Subtasks({5, 7});

    Input({ "0....5.7",
            "2 1",
            "100 3",
            "1 100",
            "1 2",
            "1 2 6 1"});
  }

  void BeforeTestCase() {
    U.clear();
    V.clear();
    K.clear();
    X.clear();
  }

  void AfterTestCase() {
    S++;
    T++;
    for (int &i : U) i++;
    for (int &i : V) i++;
  }


  // open tc 1
  void TestGroup1() {
    Subtasks({1, 6, 7});

    CASE(HEADER = ".1....67",
         N = 5, M = 4,
         Cg = 3, Mg = 3,
         Co = 10, Mo = 4,
         S = 0, T = 4,
         U = {0, 1, 2, 3},
         V = {1, 2, 3, 4},
         K = {1, 100, TEN<5>, TEN<8>},
         X = {0, 0, 1, 0});
  }

  // open tc 2
  void TestGroup2() {
    Subtasks({2, 4, 5, 6, 7});

    CASE(HEADER = "..2.4567",
         N = 10, M = 15,
         Cg = 3, Mg = 1,
         Co = 5, Mo = 1,
         S = 0, T = 9,
         U = {0, 0, 1, 1, 2,
               2, 3, 2, 4, 5,
               6, 5, 7, 6, 8},
         V = {3, 1, 2, 3, 3,
               4, 4, 7, 5, 6,
               4, 7, 8, 8, 9},
         K = {4, 1, 2, 2, 2,
               2, 2, 9, 1, 1,
               1, 3, 3, 3, 4},
         X = {1, 0, 0, 0, 0,
               0, 0, 0, 0, 0,
               0, 1, 0, 0, 0});
  }

  // Cg = Co = Mg = Mo = 1, dist = 1
  void TestGroup3() {
    Subtasks({3, 4, 5, 6, 7});

    const string header = "...34567";

    CASE(HEADER=header; cheapGojek(2, 100, 1, 1, 1, 1, 1, 1));
    CASE(HEADER=header; cheapOpang(2, 100, 1, 1, 1, 1, 1, 1));

    commonGraph(header, true, true, 1, 1, 1, 55, 100, 1, 1);
    commonGraph(header, true, true, 1, 1, 1, 55, 100, 1, 1);
  }
    
  // Mg = Mo = 1, 1 <= dist <= 10
  void TestGroup4() {
    Subtasks({4, 5, 6, 7});

    const string header = "....4567";

    CASE(HEADER=header; cheapGojek(2, 100, 1, TEN<8>, 1, 1, 1, 10));
    CASE(HEADER=header; cheapOpang(2, 100, 1, TEN<8>, 1, 1, 1, 10));
    CASE(HEADER=header; maxDistanceGraph(100, 10, 1); Cg = TEN<8>; Mg = 1; Co = TEN<8>; Mo = 1);

    commonGraph(header, false, true, 2, 1, 1, 55, 100, 1, 10);
    commonGraph(header, false, true, 2, 1, 1, 55, 100, 1, 10);
  }
    
  // Mg = Mo = 1, 11 <= dist <= 1e8
  void TestGroup5() {
    Subtasks({4, 6, 7});

    const string header = "....4.67";

    CASE(HEADER=header; maxDistanceGraph(100, TEN<8>, 1); Cg = TEN<8>; Mg = 1; Co = TEN<8>; Mo = 1);
    CASE(HEADER=header; cheapGojek(2, 20, 1, TEN<8>, 1, 1, 11, 20));
    CASE(HEADER=header; cheapGojek(2, 100, 1, TEN<8>, 1, 1, 11, TEN<8>));
    CASE(HEADER=header; cheapGojek(2, 100, 1, TEN<8>, 1, 1, TEN<6>, TEN<8>));
    CASE(HEADER=header; cheapOpang(2, 20, 1, TEN<8>, 1, 1, 11, 20));
    CASE(HEADER=header; cheapOpang(2, 100, 1, TEN<8>, 1, 1, 11, TEN<8>));
    CASE(HEADER=header; cheapOpang(2, 100, 1, TEN<8>, 1, 1, TEN<6>, TEN<8>));

    commonGraph(header, false, true, 2, 1, 1, 75, 100, 11, 100);
    commonGraph(header, false, true, 2, 1, 1, 50, 75, 201, TEN<8>);
  }
    
  // Mg > 1 atau Mo > 1, dua2nya <= 10, 1 <= dist <= 10
  void TestGroup6() {
    Subtasks({5, 6, 7});

    const string header = ".....567";

    CASE(HEADER=header; trickyUnblockedGojekOpang(1));
    CASE(HEADER=header; fullHeavyGraph(100, 100, 1, 10, 0.5));
    CASE(HEADER=header; cheapGojek(2, 100, 1, TEN<8>, 2, 10, 1, 10));
    CASE(HEADER=header; cheapOpang(2, 100, 1, TEN<8>, 2, 10, 1, 10));
    CASE(HEADER=header; coveredByOpang(1, 100, 1, TEN<8>, 2, 10, 1, 10));

    commonGraph(header, false, false, 2, 2, 10, 50, 100, 1, 10);
  }

  // Mg > 1 atau Mo > 1, dua2nya <= 10, 11 <= dist <= 1e8
  void TestGroup7() {
    Subtasks({6, 7});

    const string header = "......67";

    CASE(HEADER=header; trickyUnblockedGojekOpang(2));
    CASE(HEADER=header; fullHeavyGraph(100, 100, TEN<6>, TEN<8>, 0.5));
    CASE(HEADER=header; cheapGojek(2, 20, 1, TEN<8>, 2, 10, 11, 20));
    CASE(HEADER=header; cheapGojek(2, 100, 1, TEN<8>, 2, 10, 11, TEN<8>));
    CASE(HEADER=header; cheapGojek(2, 100, 1, TEN<8>, 2, 10, TEN<6>, TEN<8>));
    CASE(HEADER=header; cheapOpang(2, 20, 1, TEN<8>, 2, 10, 11, 20));
    CASE(HEADER=header; cheapOpang(2, 100, 1, TEN<8>, 2, 10, 11, TEN<8>));
    CASE(HEADER=header; cheapOpang(2, 100, 1, TEN<8>, 2, 10, TEN<6>, TEN<8>));

    commonGraph(header, false, false, 2, 2, 10, 75, 100, TEN<2> + 1, TEN<8>);
    commonGraph(header, false, false, 2, 2, 10, 50, 100, TEN<6>, TEN<8>);
  }

  // Mg > 10 atau Mo > 10, dist <= 10
  void TestGroup8() {
    Subtasks({5, 7});

    const string header = ".....5.7";

    CASE(HEADER=header; cheapGojek(2, 100, 1, TEN<8>, 20, 100, 1, 10));
    CASE(HEADER=header; cheapOpang(2, 100, 1, TEN<8>, 20, 100, 1, 10));
    CASE(HEADER=header; coveredByOpang(1, 100, 1, TEN<8>, 11, 100, 1, 10));

    commonGraph(header, false, false, 10, 10, 50, 100, 100, 1, 10);
  }

  // Mg > 10 atau Mo > 10, 11 <= dist <= 1e8
  void TestGroup9() {
    Subtasks({7});

    const string header = ".......7";

    CASE(HEADER=header; cheapGojek(2, 20, 1, TEN<8>, 20, 100, 11, 20));
    CASE(HEADER=header; cheapGojek(2, 100, 1, TEN<8>, 20, 100, 11, TEN<8>));
    CASE(HEADER=header; cheapGojek(2, 100, 1, TEN<8>, 20, 100, TEN<6>, TEN<8>));
    CASE(HEADER=header; cheapOpang(2, 20, 1, TEN<8>, 20, 100, 11, 20));
    CASE(HEADER=header; cheapOpang(2, 100, 1, TEN<8>, 20, 100, 11, TEN<8>));
    CASE(HEADER=header; cheapOpang(2, 100, 1, TEN<8>, 20, 100, TEN<6>, TEN<8>));
    CASE(HEADER=header; coveredByOpang(1, 100, 1, TEN<8>, 11, 100, 11, TEN<8>));

    commonGraph(header, false, false, 10, 10, 100, 100, 100, 11, TEN<8>);
    commonGraph(header, false, false, 10, 10, 100, 100, 100, TEN<6>, TEN<8>);
  }

 private:

  void coveredByOpang(int minN, int maxN, int minC, int maxC, int minM, int maxM, int minK, int maxK) {
    int maxChainLength = min({maxN - 1, maxM / minK});
    N = maxChainLength + 1;
    assert(N > 1);
    M = N - 1;
    S = 0;
    T = N - 1;
    Cg = maxC; Mg = minM;
    Co = minC; Mo = maxM;
    for (int i = 1; i < N; i++) {
      U.push_back(i - 1);
      V.push_back(i);
      K.push_back(minK);
      X.push_back(rnd.nextInt(0, 1));
    }
    int addN = rnd.nextInt(0, maxN - N);
    int oldN = N;
    N += addN;
    for (int i = oldN; i < N; i++) {
      for (int j = 0; j < i; j++) {
        if (rnd.nextInt(0, 2) == 2) {
          U.push_back(i - 1);
          V.push_back(i);
          K.push_back(rnd.nextInt(minK, maxK));
          X.push_back(rnd.nextInt(0, 1));
        }
      }
    }
    M = SZ(U);
  }

  void cheapGojek(int minN, int maxN, int minC, int maxC, int minM, int maxM, int minK, int maxK) {
    N = rnd.nextInt(minN, maxN);
    // create base tree
    set<pair<int, int>> inserted;
    for (int i = 1; i < N; i++) {
      U.push_back(rnd.nextInt(0, i - 1));
      V.push_back(i);
      K.push_back(rnd.nextInt(minK, maxK));
      X.push_back(rnd.nextInt(0, 1));
      inserted.emplace(U.back(), V.back());
    }
    for (int i = 0; i < N; i++) {
      for (int j = i + 1; j < N; j++) {
        if (!inserted.count(make_pair(i, j)) && rnd.nextInt(0, 1)) {
          U.push_back(i);
          V.push_back(j);
          K.push_back(rnd.nextInt(minK, maxK));
          X.push_back(0);
        }
      }
    }
    M = SZ(U);
    if (maxC == 1) {
      Cg = Co = 1;
    } else {
      Cg = rnd.nextInt(1, 100);
      Co = rnd.nextInt(75, 99) * maxM;
    }
    Mg = rnd.nextInt(minM, maxM);
    Mo = maxM;
    S = 0;
    T = N - 1;
  }

  void cheapOpang(int minN, int maxN, int minC, int maxC, int minM, int maxM, int minK, int maxK) {
    N = rnd.nextInt(minN, maxN);
    // create base tree
    set<pair<int, int>> inserted;
    for (int i = 1; i < N; i++) {
      U.push_back(rnd.nextInt(0, i - 1));
      V.push_back(i);
      K.push_back(rnd.nextInt(minK, maxK));
      X.push_back(rnd.nextInt(0, 1));
      inserted.emplace(U.back(), V.back());
    }
    for (int i = 0; i < N; i++) {
      for (int j = i + 1; j < N; j++) {
        if (!inserted.count(make_pair(i, j)) && rnd.nextInt(0, 1)) {
          U.push_back(i);
          V.push_back(j);
          K.push_back(rnd.nextInt(minK, maxK));
          X.push_back(rnd.nextInt(0, 1));
        }
      }
    }
    M = SZ(U);
    if (maxC == 1) {
      Cg = Co = 1;
    } else {
      Cg = rnd.nextInt(1, 100);
      Co = rnd.nextInt(1, 15) * maxM;
    }
    Mg = rnd.nextInt(minM, maxM);
    Mo = maxM;
    S = 0;
    T = N - 1;
  }

  void trickyUnblockedGojekOpang(int type) {
    N = 2;
    M = 1;
    S = 0;
    T = 1;
    U = {0};
    V = {1};
    X = {0};
    if (type == 1) {
      Cg = 2;
      Mg = 2;
      Co = 9;
      Mo = 7;
      K = {10};
    } else if (type == 2) {
      Co = TEN<8> - TEN<7> - TEN<7> - TEN<6>;
      Mo = 3;
      Cg = TEN<7>;
      Mg = 2;
      K = {TEN<8>};
    } else {
      assert(false);
    }
  }

  void randomizeCM(bool allOneC, bool allOneM, int minLargeC, int minLargeM, int maxM) {
    Cg = 1; Mg = 1;
    Co = 1; Mo = 1;
    if (!allOneC) {
      while (Cg == 1 && Co == 1) {
        if (rnd.nextInt(0, 1)) Cg = rnd.nextInt(minLargeC, TEN<8>);
        if (rnd.nextInt(0, 1)) Co = rnd.nextInt(minLargeC, TEN<8>);
        if (rnd.nextInt(0, 3) == 3) Cg = rnd.nextInt(TEN<7>, TEN<8>);
        if (rnd.nextInt(0, 3) == 3) Co = rnd.nextInt(TEN<7>, TEN<8>);
      }
    }
    if (!allOneM) {
      while (Mg == 1 && Mo == 1) {
        if (rnd.nextInt(0, 1)) Mg = rnd.nextInt(minLargeM, maxM);
        if (rnd.nextInt(0, 1)) Mo = rnd.nextInt(minLargeM, maxM);
      }
    }
  }

  void randomTree(int minN, int maxN, int minK, int maxK) {
    N = rnd.nextInt(minN, maxN);
    M = N - 1;
    S = 0; T = N - 1;
    for (int i = 1; i < N; i++) {
      U.push_back(i);
      V.push_back(rnd.nextInt(0, i - 1));
      K.push_back(rnd.nextInt(minK, maxK));
      X.push_back(rnd.nextInt(0, 1));
    }
  }

  void randomGraphSmall(int minK, int maxK) {
    int toComplete = N * (N - 1) / 2 - M;
    int addEdge = min(toComplete, 10);
    while (addEdge--) {
      M++;
      U.push_back(rnd.nextInt(0, N - 2));
      V.push_back(rnd.nextInt(U.back() + 1, N - 1));
      K.push_back(rnd.nextInt(minK, maxK));
      X.push_back(rnd.nextInt(0, 1));
    }
  };

  void randomGraphLarge(int minK, int maxK) {
    int toComplete = N * (N - 1) / 2 - M;
    int addEdge = rnd.nextInt(toComplete / 2, 3 * toComplete / 4);
    while (addEdge--) {
      M++;
      U.push_back(rnd.nextInt(0, N - 2));
      V.push_back(rnd.nextInt(U.back() + 1, N - 1));
      K.push_back(rnd.nextInt(minK, maxK));
      X.push_back(rnd.nextInt(0, 1));
    }
  };

  void randomStar(int minN, int maxN, int minK, int maxK) {
    N = rnd.nextInt(minN, maxN);
    M = N - 1;
    S = 0;
    T = rnd.nextInt(0, N - 1);
    for (int i = 1; i < N; i++) {
      U.push_back(0);
      V.push_back(i);
      K.push_back(rnd.nextInt(minK, maxK));
      X.push_back(rnd.nextInt(0, 1));
    }
  };

  void commonGraph(string header, bool allOneC, bool allOneM, int minLargeC, int minLargeM, int maxM, int minN, int maxN, int minK, int maxK) {
    CASE(HEADER=header; randomizeCM(allOneC, allOneM, minLargeC, minLargeM, maxM); randomTree(minN, maxN, minK, maxK));
    CASE(HEADER=header; randomizeCM(allOneC, allOneM, minLargeC, minLargeM, maxM); randomTree(minN, maxN, minK, maxK));
    CASE(HEADER=header; randomizeCM(allOneC, allOneM, minLargeC, minLargeM, maxM); randomTree(minN, maxN, minK, maxK); randomGraphLarge(minK, maxK));
    CASE(HEADER=header; randomizeCM(allOneC, allOneM, minLargeC, minLargeM, maxM); randomTree(minN, maxN, minK, maxK); randomGraphSmall(minK, maxK));
    CASE(HEADER=header; randomizeCM(allOneC, allOneM, minLargeC, minLargeM, maxM); randomTree(minN, maxN, minK, maxK); randomGraphSmall(minK, maxK));
    CASE(HEADER=header; randomizeCM(allOneC, allOneM, minLargeC, minLargeM, maxM); randomStar(minN, maxN, minK, maxK));
  }

  void fullHeavyGraph(int minN, int maxN, int minK, int maxK, double probQ0) {
    int limQ0 = round(probQ0 * 100);
    N = rnd.nextInt(minN, maxN);
    M = N * (N - 1) / 2;
    for (int i = 0; i < N; i++) {
      for (int j = i + 1; j < N; j++) {
        U.push_back(i);
        V.push_back(j);
        K.push_back(rnd.nextInt(minK, maxK));
        X.push_back(rnd.nextInt(1, 100) <= limQ0 ? 0 : 1);
      }
    }
  }

  void maxDistanceGraph(int n, int maxK, int x) {
    N = n;
    M = N - 1;
    for (int i = 1; i < N; i++) {
      U.push_back(i - 1);
      V.push_back(i);
      K.push_back(maxK);
      X.push_back(x);
    }
  }
};


