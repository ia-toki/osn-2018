#include <bits/stdc++.h>
#include <tcframe/runner.hpp>
using namespace tcframe;
using namespace std;

const int MAX_VAL = 100000;

class ProblemSpec : public BaseProblemSpec {
 protected:
  string HEADER;
  int N, K;
  vector<int> A;
  int ANS;

  void InputFormat() {
    LINE(HEADER);
    LINE(N, K);
    LINE(A % SIZE(N));
  }

  void OutputFormat() { LINE(ANS); }

  void Constraints() {
    CONS(HEADER.length() == 10);
    CONS(validHeader(HEADER));

    CONS(1 <= N && N <= 50000);
    CONS(1 <= K && K <= min(N, 20));
    CONS(eachElementBetween(A, 1, MAX_VAL));
  }

  void Subtask1() {
    // Points(7);

    CONS(HEADER[1] == '1');
    CONS(N == 9);
    CONS(K == 1);
    CONS(A == vector<int>({30, 15, 3, 48, 24, 8, 12, 100, 52}));
  }

  void Subtask2() {
    // Points(9);

    CONS(HEADER[2] == '2');
    CONS(N == 9);
    CONS(K == 3);
    CONS(A == vector<int>({1, 1, 1, 1, 1, 1, 1, 1, 1}));
  }

  void Subtask3() {
    // Points(9);

    // CONS(HEADER[3] == '3');
    CONS(N <= 10);
  }

  void Subtask4() {
    // Points(10);

    // CONS(HEADER[4] == '4');
    CONS(N <= 500);
    CONS(K == 1);
  }

  void Subtask5() {
    // Points(13);

    // CONS(HEADER[5] == '5');
    CONS(N <= 500);
    CONS(K <= 2);
  }

  void Subtask6() {
    // Points(23);

    // CONS(HEADER[6] == '6');
    CONS(N <= 500);
  }

  void Subtask7() {
    // Points(29);
    // CONS(HEADER[7] == '7');

    CONS(K == 1);
  }

  void Subtask8() {
    // Points(29);
    // CONS(HEADER[8] == '8');

    CONS(eachElementBetween(A, A[0], A[0]));
  }

  void Subtask9() {
    // Points(29);
    // CONS(HEADER[9] == '9');
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
  bool eachElementBetween(const vector<int> &A, int lo, int hi) {
    return all_of(A.begin(), A.end(), [&](int x) {
      return lo <= x && x <= hi;
    });
  }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
 protected:
  void SampleTestCase1() {
    Subtasks({3, 5, 6, 9});

    Input({"0..3.56..9", 
           "3 2",
           "6 4 5"});
    Output({"44"});
  }

  void BeforeTestCase() {
    A.clear();
  }

  // open tc 1
  void TestGroup1() {
    Subtasks({1, 3, 4, 5, 6, 7, 9});

    string header = ".1.34567.9";
    CASE(HEADER = header,
         N = 9,
         K = 1,
         A = {30, 15, 3, 48, 24, 8, 12, 100, 52});
  }

  // open tc 2
  void TestGroup2() {
    Subtasks({2, 3, 6, 8, 9});

    string header = "..23..6.89";
    CASE(HEADER = header,
         N = 9,
         K = 3,
         A = {1, 1, 1, 1, 1, 1, 1, 1, 1});
  }

  // N <= 10, K = 1, A_i same
  void TestGroup3() {
    Subtasks({3, 4, 5, 6, 7, 8, 9});

    string header = "...3456789";
    
    generateSameValuedCases(header, 1, 10, 1, 1);
  }

  // N <= 10, K = 1, A_i not same
  void TestGroup4() {
    Subtasks({3, 4, 5, 6, 7, 9});

    string header = "...34567.9";

    generateDifferentValuedCases(header, 1, 10, 1, 1);
  }

  // N <= 10, K = 2, A_i same
  void TestGroup5() {
    Subtasks({3, 5, 6, 8, 9});

    string header = "...3.56.89";

    generateSameValuedCases(header, 2, 10, 2, 2);
  }

  // N <= 10, K = 2, A_i not same
  void TestGroup6() {
    Subtasks({3, 5, 6, 9});

    string header = "...3.56..9";

    generateDifferentValuedCases(header, 2, 10, 2, 2);
  }

  // N <= 10, K > 2, A_i same
  void TestGroup7() {
    Subtasks({3, 6, 8, 9});

    string header = "...3..6.89";

    generateSameValuedCases(header, 3, 10, 3, 10);
  }

  // N <= 10, K > 2, A_i not same
  void TestGroup8() {
    Subtasks({3, 6, 9});

    string header = "...3..6..9";

    generateDifferentValuedCases(header, 3, 10, 3, 10);
  }

  // 11 <= N <= 500, K = 1, A_i same
  void TestGroup9() {
    Subtasks({4, 5, 6, 7, 8, 9});

    string header = "....456789";

    generateSameValuedCases(header, 11, 500, 1, 1);
  }

  // 11 <= N <= 500, K = 1, A_i not same
  void TestGroup10() {
    Subtasks({4, 5, 6, 7, 9});

    string header = "....4567.9";

    generateDifferentValuedCases(header, 11, 500, 1, 1);
  }

  // 11 <= N <= 500, K = 2, A_i same
  void TestGroup11() {
    Subtasks({5, 6, 8, 9});

    string header = ".....56.89";

    generateSameValuedCases(header, 11, 500, 2, 2);
  }

  // 11 <= N <= 500, K = 2, A_i not same
  void TestGroup12() {
    Subtasks({5, 6, 9});

    string header = ".....56..9";

    generateDifferentValuedCases(header, 11, 500, 2, 2);
  }

  // 11 <= N <= 500, K > 2, A_i same
  void TestGroup13() {
    Subtasks({6, 8, 9});

    string header = "......6.89";

    generateSameValuedCases(header, 11, 500, 3, 20);
  }

  // 11 <= N <= 500, K > 2, A_i not same
  void TestGroup14() {
    Subtasks({6, 9});

    string header = "......6..9";

    generateDifferentValuedCases(header, 11, 500, 3, 20);
  }

  // 501 <= N <= 50000, K = 1, A_i same
  void TestGroup15() {
    Subtasks({7, 8, 9});

    string header = ".......789";

    generateSameValuedCases(header, 501, 50000, 1, 1);
  }

  // 501 <= N <= 50000, K = 1, A_i not same
  void TestGroup16() {
    Subtasks({7, 9});

    string header = ".......7.9";

    generateDifferentValuedCases(header, 501, 50000, 1, 1);
  }

  // 501 <= N <= 50000, K >= 2, A_i same
  void TestGroup17() {
    Subtasks({8, 9});

    string header = "........89";

    generateSameValuedCases(header, 501, 50000, 2, 20);
  }

  // 501 <= N <= 50000, K >= 2, A_i not same
  void TestGroup18() {
    Subtasks({9});

    string header = ".........9";

    generateDifferentValuedCases(header, 501, 50000, 2, 20);
  }

 private:

  void generateDifferentValuedCases(string header, int minN, int maxN, int minK, int maxK) {
    vector<pair<int, int>> partition = {{1, 1}, {2, 2}, {5, 10}, {1, 20}};

    // min max cases
    if(minN != 1) {
      CASE(HEADER = header,
           N = minN,
           K = minK,
           A = randomArray(N, 1, MAX_VAL));
    }
    CASE(HEADER = header,
         N = maxN,
         K = maxK,
         A = randomArray(N, 1, MAX_VAL));

    CASE(HEADER = header,
         N = maxN,
         K = rnd.nextInt(minK, maxK),
         A = funnyWorstRange(N, 2));

    CASE(HEADER = header,
         N = maxN,
         K = rnd.nextInt(minK, maxK),
         A = funnyWorstRange(N, rnd.nextInt(2, 20)));
    // end min max cases

    // pattern cases
    // kalo maxN <= 10 gak ngefek pattern-nya jadi gausah
    if(maxN > 10) {
      CASE(HEADER = header,
           N = maxN,
           K = maxK,
           A = repeatedMonotoneDivisorArray(N, rnd.nextInt(1, 100), 1 << 16));
      CASE(HEADER = header,
           N = maxN,
           K = maxK,
           A = monotoneDivisorArray(N, 1 << 16));
      
      for(auto partRange : partition) {
        int lo = partRange.first;
        int hi = partRange.second;
        int part = rnd.nextInt(lo, hi);

        CASE(HEADER = header,
             N = rnd.nextInt(minN, maxN),
             K = rnd.nextInt(minK, maxK),
             A = generatePatternArray(N, part));

        CASE(HEADER = header,
             N = maxN,
             K = maxK,
             A = generatePatternArray(N, part));
        
        CASE(HEADER = header,
             N = rnd.nextInt(maxN / 2, maxN),
             K = rnd.nextInt(max(minK, maxK / 2), maxK),
             A = generatePatternArray(N, part));
      }
    }
    // end of pattern cases

    // start of random cases
    CASE(HEADER = header,
         N = maxN,
         K = min(N, rnd.nextInt(minK, maxK)),
         A = randomArray(N, 1, MAX_VAL));

    for(auto partRange : partition) {
        int lo = partRange.first;
        int hi = partRange.second;
        int part = rnd.nextInt(lo, hi);

        CASE(HEADER = header,
             N = rnd.nextInt(minN, maxN),
             K = min(N, rnd.nextInt(minK, maxK)),
             A = generateRandomPartitionArray(N, part, 1, MAX_VAL));
        
        CASE(HEADER = header,
             N = rnd.nextInt(maxN / 2, maxN),
             K = min(N, rnd.nextInt(max(minK, maxK / 2), maxK)),
             A = generateRandomPartitionArray(N, part, 1, MAX_VAL));
      }
    // end of random cases
  }

  void generateSameValuedCases(string header, int minN, int maxN, int minK, int maxK) {
    CASE(HEADER = header,
         N = minN,
         K = minK,
         A = randomSameArray(N));
    
    CASE(HEADER = header,
         N = maxN,
         K = maxK,
         A = randomSameArray(N));
    
    CASE(HEADER = header,
         N = maxN,
         K = min(N, rnd.nextInt(minK, maxK)),
         A = randomSameArray(N));

    CASE(HEADER = header,
         N = rnd.nextInt(maxN / 2, maxN),
         K = min(N, rnd.nextInt(minK, maxK)),
         A = randomSameArray(N));
      
    CASE(HEADER = header,
         N = rnd.nextInt(maxN / 2, maxN),
         K = min(N, rnd.nextInt(max(minK, maxK / 2), maxK)),
         A = randomSameArray(N));
  }

  // utils

  int getRandomNumberDivisible(int lo, int hi, int divisor) {
    lo = (lo + divisor - 1) / divisor;
    hi = hi / divisor;
    hi = min(hi, lo + 5);
    assert(lo <= hi);

    return divisor * rnd.nextInt(lo, hi);
  }

  vector<int> getRandomChanceFactor(int n) {
    vector<int> ret(n);
    for(int &it : ret) it = rnd.nextInt(1, 10);
    for(int i = 1 ; i < n ; i++) ret[i] += ret[i-1];
    return ret;
  }

  // end of utils

  // start mathsy stuff

  vector<int> getPrimeFactorsOf(int n) {
    vector<int> ret;

    for(int i = 2 ; i * i <= n ; i++) {
      while(n % i == 0) {
        ret.push_back(i);
        n /= i;
      }
    }

    if(n != 1) {
      ret.push_back(n);
    }

    return ret;
  }

  vector<pair<int, int>> getNumbersSortedByPrimeCount(int lmt) {
    vector<pair<int, int>> ret;
    
    for(int i = 1 ; i <= lmt ; i++) {
      ret.push_back({i, getPrimeFactorsOf(i).size()});
    }
    sort(ret.begin(), ret.end(), [](pair<int, int> a, pair<int, int> b) {
      return a.second > b.second;
    });

    return ret;
  }

  // end of mathsy stuff

  // start of pattern array generators

  vector<int> funnyWorstRange(int n, int factor) {
    vector<int> ret;
    
    int cur = 1;
    while (ret.size() < n && cur <= MAX_VAL) {
      ret.push_back(cur);
      cur *= factor;
    }
    cur /= factor;

    while(ret.size() < n) {
      ret.push_back(cur);
    }

    if(rnd.nextInt(2)) {
      reverse(ret.begin(), ret.end());
    }

    return ret;
  }

  vector<int> monotoneDivisorArray(int n, int lcm) {
    vector<int> primes = getPrimeFactorsOf(lcm);
    rnd.shuffle(primes.begin(), primes.end());
    primes.insert(primes.begin(), 1);

    vector<int> chance = getRandomChanceFactor(primes.size());

    vector<int> sizes = vector<int>(primes.size(), 0);
    for(int i = 0 ; i < n ; i++) {
      int val = rnd.nextInt(1, chance.back());
      int idx = lower_bound(chance.begin(), chance.end(), val) - chance.begin();
      sizes[idx]++;
    }

    vector<int> ret;
    int mul = 1;
    for(int i = 0 ; i < primes.size() ; i++) {
      mul *= primes[i];

      for(int j = 0 ; j < sizes[i] ; j++) {
        int val = getRandomNumberDivisible(1, MAX_VAL, mul);
        ret.push_back(val);
      }
    }

    // monotone decreasing
    if(rnd.nextInt(2)) {
      reverse(ret.begin(), ret.end());
    }

    return ret;
  }

  vector<int> repeatedMonotoneDivisorArray(int n, int repetition, int lcm) {
    vector<int> chance = getRandomChanceFactor(repetition);
    vector<int> sizes = vector<int>(repetition, 0);
    for (int i = 0; i < n; i++) {
      int val = rnd.nextInt(1, chance.back());
      int idx = lower_bound(chance.begin(), chance.end(), val) - chance.begin();
      sizes[idx]++;
    }

    vector<int> ret;
    for(int i = 0 ; i < repetition ; i++) {
      vector<int> cur = monotoneDivisorArray(sizes[i], lcm);
      ret.insert(ret.end(), cur.begin(), cur.end());
    }

    return ret;
  }

  vector<int> generatePatternArray(int n, int partition) {
    vector<pair<int, int>> nums = getNumbersSortedByPrimeCount(MAX_VAL);

    vector<int> chance = getRandomChanceFactor(partition);
    vector<int> sizes = vector<int>(partition, 0);
    
    for (int i = 0; i < n; i++) {
      int val = rnd.nextInt(1, chance.back());
      int idx = lower_bound(chance.begin(), chance.end(), val) - chance.begin();
      sizes[idx]++;
    }

    vector<int> ret;
    for(int i = 0 ; i < partition ; i++) {
      int num = nums[rnd.nextInt(20)].first;
      vector<int> cur;

      if(rnd.nextInt(4)) {
        cur = monotoneDivisorArray(sizes[i], num);    
      } else {
        int repetition = rnd.nextInt(1, 10);
        cur = repeatedMonotoneDivisorArray(sizes[i], repetition, num);
      }

      ret.insert(ret.end(), cur.begin(), cur.end());
    }

    distort(ret);
    return ret;
  }

  // end of pattern array generators

  // start of pure random array generators
  vector<int> randomArrayCommonDivisor(int n, int lo, int hi, int divisor) {
    vector<int> ret(n);
    for(int &it : ret) it = getRandomNumberDivisible(lo, hi, divisor);
    return ret;
  }
  
  vector<int> randomArray(int n, int lo, int hi) {
    vector<int> ret(n);
    for(int &it : ret) it = rnd.nextInt(lo, hi);
    return ret;
  }

  vector<int> randomSameArray(int n, int val = -1) {
    if(val == -1) {
      val = rnd.nextInt(1, MAX_VAL);
    }

    return randomArray(n, val, val);
  }

  vector<int> generateRandomPartitionArray(int n, int partition, int lo, int hi) {
    vector<int> chance = getRandomChanceFactor(partition);
    vector<int> sizes = vector<int>(partition, 0);

    for (int i = 0; i < n; i++) {
      int val = rnd.nextInt(1, chance.back());
      int idx = lower_bound(chance.begin(), chance.end(), val) - chance.begin();
      sizes[idx]++;
    }

    vector<int> ret;
    for(int i = 0 ; i < partition ; i++) {
      int num = rnd.nextInt(lo, min(hi, 1000));
      vector<int> cur = randomArrayCommonDivisor(sizes[i], lo, hi, num);
      ret.insert(ret.end(), cur.begin(), cur.end());
    }

    return ret;
  }
  // end of pure random array generators

  // start of distortion
  void distort(vector<int> &v, int cTime = 10, int rTime = 10) {
    distortCopyValue(v, cTime);
    distortRandomValue(v, rTime, 1, MAX_VAL);
  }

  void distortCopyValue(vector<int> &v, int distortion) {
    for(int i = 0 ; i < distortion ; i++) {
      int a = rnd.nextInt(v.size());
      int b = rnd.nextInt(v.size());

      v[a] = v[b];
    }
  }

  void distortRandomValue(vector<int> &v, int distortion, int lo, int hi) {
    for(int i = 0 ; i < distortion ; i++) {
      int a = rnd.nextInt(v.size());
      v[a] = rnd.nextInt(lo, hi);
    }
  }
  // end of distortion
};
