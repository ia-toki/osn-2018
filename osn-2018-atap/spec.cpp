#include <tcframe/spec.hpp>
#include <bits/stdc++.h>
using namespace tcframe;
using namespace std;

typedef pair<int,int> PII;

class ProblemSpec : public BaseProblemSpec {
protected:
	string HEADER = ".........", S;
	long long N = 7, span;
	int K, Q;
	vector<long long> L, R;
	vector<long long> ans;

	void InputFormat() {
		LINE(HEADER);
		LINE(S);
		LINE(K, Q);
		LINES(L, R) % SIZE(Q);
	}

	void OutputFormat() {
		LINES(ans) % SIZE(Q);
	}

	void StyleConfig() {
		
	}

	void Constraints() {
		CONS(HEADER.length() == 9);
		CONS(validHeader(HEADER));
		CONS((int)S.length() <= 1e5);
		CONS(N == (long long)S.length() * K + 1);
		CONS(consistOf(S, "AB"));
		CONS(1 <= K && K <= 1e9);
		CONS(1 <= Q && Q <= 1e5);
		CONS(eachElementLessThanOrEqual(L, R));
		CONS(eachElementInRange(L, 1, N));
		CONS(eachElementInRange(R, 1, N));
		CONS((int)L.size() == Q);
		CONS((int)R.size() == Q);
	}

	void Subtask1() {
		Points(0);
		CONS(S == "AABA");
		CONS(K == 3);
		CONS(Q == 6);
		CONS(L == vector<long long>({1, 5, 10, 1, 3, 10}));
		CONS(R == vector<long long>({4, 9, 13, 2, 5, 12}));
		CONS(HEADER[1] == '1');
	}

	void Subtask2() {
		Points(0);
		CONS(S == "AABABAABB");
		CONS(K == 11);
		CONS(Q == 7);
		CONS(L == vector<long long>({1, 1, 2, 3, 98, 99, 100}));
		CONS(R == vector<long long>({100, 1, 2, 3, 98, 99, 100}));
		CONS(HEADER[2] == '2');
	}

	void Subtask3() {
		Points(0);
		CONS(K == 1);
		CONS((int)S.length() <= 1000);
		CONS(HEADER[3] == '3');
	}

	void Subtask4() {
		Points(0);
		CONS(K == 1);
		CONS(Q == 1);
		CONS(HEADER[4] == '4');
	}

	void Subtask5() {
		Points(0);
		CONS(Q == 1);
		CONS(HEADER[5] == '5');
	}

	void Subtask6() {
		Points(0);
		CONS(S.length() <= 2);
		CONS(HEADER[6] == '6');
	}

	void Subtask7() {
		Points(0);
		CONS(eachElementSame(L, R));
		CONS(HEADER[7] == '7');
	}

	void Subtask8() {
		Points(0);
		CONS(HEADER[8] == '8');
	}

private:

	bool validHeader(const string& header) {
		for(int i = 0; i < header.length(); i++) {
			if(header[i] != '.' && header[i] != (char)(i + '0')) {
				return false;
			}
		}
		return true;
	}

	bool consistOf(const string &S, const string &validElem) {
		for(char x : S) {
			bool valid = false;
			for(char y : validElem) {
				if(x == y) {
					valid = true;
				}
			}
			if(!valid) {
				return false;
			}
		}
		return true;
	}

	bool eachElementLessThanOrEqual(const vector<long long> &A, const std::vector<long long> &B) {
		if(A.size() != B.size()) {
			return false;
		}
		for(int i = 0; i < (int)A.size(); i++) {
			if(A[i] > B[i]) {
				return false;
			}
		}
		return true;
	}

	bool eachElementSame(const vector<long long> &A, const std::vector<long long> &B) {
		if(A.size() != B.size()) {
			return false;
		}
		for(int i = 0; i < (int)A.size(); i++) {
			if(A[i] != B[i]) {
				return false;
			}
		}
		return true;
	}

	bool eachElementInRange(const vector<long long> &V, long long minV, long long maxV) {
		for(long long x : V) {
			if(x > maxV || x < minV) {
				return false;
			}
		}
		return true;
	}


};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:

	void SampleTestCase1() {
		Subtasks({8});

		Input({
			"0.......8",
			"ABB",
			"2 4",
			"1 7",
			"2 4",
			"6 7",
			"1 1"
		});

		Output({
			"7",
			"6",
			"4",
			"2"
		});
	}

	void BeforeTestCase() {
		L.clear();
		R.clear();
	}

	// open tc 1
	void TestGroup1() {
		Subtasks({1, 8});
		CASE(HEADER = ".1......8", S = "AABA", K = 3, N = (long long)S.length() * K + 1, Q = 6, 
			L = {1, 5, 10, 1, 3, 10}, R = {4, 9, 13, 2, 5, 12});
	}

	// open tc 2
	void TestGroup2() {
		Subtasks({2, 8});
		CASE(HEADER = "..2.....8", S = "AABABAABB", K = 11, N = (long long)S.length() * K + 1, Q = 7,
			L = {1, 1, 2, 3, 98, 99, 100}, R = {100, 1, 2, 3, 98, 99, 100});
	}

	void TestGroup3() {
		// |S| <= 2, K = 1, Q = 1, Li = Ri
		Subtasks({3, 4, 5, 6, 7, 8});
		CASE(HEADER = "...345678", S = "A", K = 1, N = (long long)S.length() * K + 1, Q = 1, L = {1}, R = {1});
		CASE(HEADER = "...345678", S = "B", K = 1, N = (long long)S.length() * K + 1, Q = 1, L = {1}, R = {1});

		CASE(HEADER = "...345678", S = "A", K = 1, N = (long long)S.length() * K + 1, Q = 1, L = {2}, R = {2});
		CASE(HEADER = "...345678", S = "B", K = 1, N = (long long)S.length() * K + 1, Q = 1, L = {2}, R = {2});

		CASE(HEADER = "...345678", S = "AA", K = 1, N = (long long)S.length() * K + 1, Q = 1, L = {1}, R = {1});
		CASE(HEADER = "...345678", S = "BB", K = 1, N = (long long)S.length() * K + 1, Q = 1, L = {1}, R = {1});
		CASE(HEADER = "...345678", S = "AB", K = 1, N = (long long)S.length() * K + 1, Q = 1, L = {1}, R = {1});
		CASE(HEADER = "...345678", S = "BA", K = 1, N = (long long)S.length() * K + 1, Q = 1, L = {1}, R = {1});

		CASE(HEADER = "...345678", S = "AA", K = 1, N = (long long)S.length() * K + 1, Q = 1, L = {2}, R = {2});
		CASE(HEADER = "...345678", S = "BB", K = 1, N = (long long)S.length() * K + 1, Q = 1, L = {2}, R = {2});
		CASE(HEADER = "...345678", S = "AB", K = 1, N = (long long)S.length() * K + 1, Q = 1, L = {2}, R = {2});
		CASE(HEADER = "...345678", S = "BA", K = 1, N = (long long)S.length() * K + 1, Q = 1, L = {2}, R = {2});

		CASE(HEADER = "...345678", S = "AA", K = 1, N = (long long)S.length() * K + 1, Q = 1, L = {3}, R = {3});
		CASE(HEADER = "...345678", S = "BB", K = 1, N = (long long)S.length() * K + 1, Q = 1, L = {3}, R = {3});
		CASE(HEADER = "...345678", S = "AB", K = 1, N = (long long)S.length() * K + 1, Q = 1, L = {3}, R = {3});
		CASE(HEADER = "...345678", S = "BA", K = 1, N = (long long)S.length() * K + 1, Q = 1, L = {3}, R = {3});
	}

	void TestGroup4() {
		// |S| <= 2, K = 1, Q = 1, Li < Ri
		Subtasks({3, 4, 5, 6, 8});
		CASE(HEADER = "...3456.8", S = "AA", K = 1, N = (long long)S.length() * K + 1, Q = 1, L = {1}, R = {2});
		CASE(HEADER = "...3456.8", S = "BB", K = 1, N = (long long)S.length() * K + 1, Q = 1, L = {1}, R = {2});
		CASE(HEADER = "...3456.8", S = "AB", K = 1, N = (long long)S.length() * K + 1, Q = 1, L = {1}, R = {2});
		CASE(HEADER = "...3456.8", S = "BA", K = 1, N = (long long)S.length() * K + 1, Q = 1, L = {1}, R = {2});

		CASE(HEADER = "...3456.8", S = "AA", K = 1, N = (long long)S.length() * K + 1, Q = 1, L = {1}, R = {3});
		CASE(HEADER = "...3456.8", S = "BB", K = 1, N = (long long)S.length() * K + 1, Q = 1, L = {1}, R = {3});
		CASE(HEADER = "...3456.8", S = "AB", K = 1, N = (long long)S.length() * K + 1, Q = 1, L = {1}, R = {3});
		CASE(HEADER = "...3456.8", S = "BA", K = 1, N = (long long)S.length() * K + 1, Q = 1, L = {1}, R = {3});

		CASE(HEADER = "...3456.8", S = "AA", K = 1, N = (long long)S.length() * K + 1, Q = 1, L = {2}, R = {3});
		CASE(HEADER = "...3456.8", S = "BB", K = 1, N = (long long)S.length() * K + 1, Q = 1, L = {2}, R = {3});
		CASE(HEADER = "...3456.8", S = "AB", K = 1, N = (long long)S.length() * K + 1, Q = 1, L = {2}, R = {3});
		CASE(HEADER = "...3456.8", S = "BA", K = 1, N = (long long)S.length() * K + 1, Q = 1, L = {2}, R = {3});
	}

	void TestGroup5() {
		// 3 <= |S| <= 1000, K = 1, Q = 1, Li = Ri
		Subtasks({3, 4, 5, 7, 8});
		int S_len, L_num;
		S_len = rnd.nextInt(3, 1000);
		L_num = rnd.nextInt(0, S_len);
		CASE(
			HEADER = "...345.78",
			S = generateString(S_len, L_num), K = 1, N = (long long)S.length() * K + 1, Q = 1,
			L = {rnd.nextLongLong(1, N)}, R = {L[0]}
		);

		S_len = 1000;
		L_num = rnd.nextInt(0, S_len);
		CASE(
			HEADER = "...345.78",
			S = generateString(S_len, L_num), K = 1, N = (long long)S.length() * K + 1, Q = 1,
			L = {rnd.nextLongLong(1, N)}, R = {L[0]}
		);

		S_len = rnd.nextInt(3, 1000);
		L_num = rnd.nextInt((S_len + 3) / 4, (S_len * 3) / 4);
		CASE(
			HEADER = "...345.78",
			S = generateString(S_len, L_num), K = 1, N = (long long)S.length() * K + 1, Q = 1,
			L = {rnd.nextLongLong(1, N)}, R = {L[0]}
		);

		S_len = 1000;
		L_num = rnd.nextInt((S_len + 3) / 4, (S_len * 3) / 4);
		CASE(
			HEADER = "...345.78",
			S = generateString(S_len, L_num), K = 1, N = (long long)S.length() * K + 1, Q = 1,
			L = {rnd.nextLongLong(1, N)}, R = {L[0]}
		);
	}

	void TestGroup6() {
		// 3 <= |S| <= 1000, K = 1, Q = 1, Li < Ri
		Subtasks({3, 4, 5, 8});
		int S_len, L_num;
		// random query case
		S_len = rnd.nextInt(3, 1000);
		L_num = rnd.nextInt(0, S_len);
		CASE(
			HEADER = "...345..8",
			S = generateString(S_len, L_num), K = 1, N = (long long)S.length() * K + 1, Q = 1,
			generateRandomQuery(Q, L, R);
		);

		S_len = 1000;
		L_num = rnd.nextInt(0, S_len);
		CASE(
			HEADER = "...345..8",
			S = generateString(S_len, L_num), K = 1, N = (long long)S.length() * K + 1, Q = 1,
			generateRandomQuery(Q, L, R);
		);

		S_len = rnd.nextInt(3, 1000);
		L_num = rnd.nextInt((S_len + 3) / 4, (S_len * 3) / 4);
		CASE(
			HEADER = "...345..8",
			S = generateString(S_len, L_num), K = 1, N = (long long)S.length() * K + 1, Q = 1,
			generateRandomQuery(Q, L, R);
		);

		S_len = 1000;
		L_num = rnd.nextInt((S_len + 3) / 4, (S_len * 3) / 4);
		CASE(
			HEADER = "...345..8",
			S = generateString(S_len, L_num), K = 1, N = (long long)S.length() * K + 1, Q = 1,
			generateRandomQuery(Q, L, R)	
		);

		// narrow query case
		S_len = rnd.nextInt(3, 1000);
		L_num = rnd.nextInt(0, S_len);
		CASE(
			HEADER = "...345..8",
			S = generateString(S_len, L_num), K = 1, N = (long long)S.length() * K + 1, Q = 1,
			generateNarrowQuery(Q, L, R)
		);

		S_len = 1000;
		L_num = rnd.nextInt(0, S_len);
		CASE(
			HEADER = "...345..8",
			S = generateString(S_len, L_num), K = 1, N = (long long)S.length() * K + 1, Q = 1,
			generateNarrowQuery(Q, L, R)
		);

		S_len = rnd.nextInt(3, 1000);
		L_num = rnd.nextInt((S_len + 3) / 4, (S_len * 3) / 4);
		CASE(
			HEADER = "...345..8",
			S = generateString(S_len, L_num), K = 1, N = (long long)S.length() * K + 1, Q = 1,
			generateNarrowQuery(Q, L, R)
		);

		S_len = 1000;
		L_num = rnd.nextInt((S_len + 3) / 4, (S_len * 3) / 4);
		CASE(
			HEADER = "...345..8",
			S = generateString(S_len, L_num), K = 1, N = (long long)S.length() * K + 1, Q = 1,
			generateNarrowQuery(Q, L, R)
		);

		// blocked query case
		S_len = rnd.nextInt(3, 1000);
		L_num = rnd.nextInt(0, S_len);
		CASE(
			HEADER = "...345..8",
			S = generateString(S_len, L_num), K = 1, N = (long long)S.length() * K + 1, Q = 1,
			generateBlockedQuery(Q, L, R, L_num)
		);

		S_len = 1000;
		L_num = rnd.nextInt(0, S_len);
		CASE(
			HEADER = "...345..8",
			S = generateString(S_len, L_num), K = 1, N = (long long)S.length() * K + 1, Q = 1,
			generateBlockedQuery(Q, L, R, L_num)
		);

		S_len = rnd.nextInt(3, 1000);
		L_num = rnd.nextInt((S_len + 3) / 4, (S_len * 3) / 4);
		CASE(
			HEADER = "...345..8",
			S = generateString(S_len, L_num), K = 1, N = (long long)S.length() * K + 1, Q = 1,
			generateBlockedQuery(Q, L, R, L_num)
		);

		S_len = 1000;
		L_num = rnd.nextInt((S_len + 3) / 4, (S_len * 3) / 4);
		CASE(
			HEADER = "...345..8",
			S = generateString(S_len, L_num), K = 1, N = (long long)S.length() * K + 1, Q = 1,
			generateBlockedQuery(Q, L, R, L_num)
		);

	}

	void TestGroup7() {
		// 1 <= |S| <= 2, K = 1, Q > 1, Li = Ri
		Subtasks({3, 6, 7, 8});
		CASE(HEADER = "...3..678", S = "B", K = 1, N = (long long)S.length() * K + 1, Q = 100000, L = R = generateVector(Q, 1, N));

		CASE(HEADER = "...3..678", S = "AA", K = 1, N = (long long)S.length() * K + 1, Q = 100000, L = R = generateVector(Q, 1, N));
		CASE(HEADER = "...3..678", S = "BA", K = 1, N = (long long)S.length() * K + 1, Q = 100000, L = R = generateVector(Q, 1, N));
	}

	void TestGroup8() {
		// 1 <= |S| <= 2, K = 1, Q > 1, Li <= Ri
		Subtasks({3, 6, 8});

		// Random query
		CASE(HEADER = "...3..6.8", S = "A", K = 1, N = (long long)S.length() * K + 1, Q = 100000, generateRandomQuery(Q, L, R));

		CASE(HEADER = "...3..6.8", S = "BB", K = 1, N = (long long)S.length() * K + 1, Q = 100000, generateRandomQuery(Q, L, R));
		CASE(HEADER = "...3..6.8", S = "AB", K = 1, N = (long long)S.length() * K + 1, Q = 100000, generateRandomQuery(Q, L, R));


		// Narrow query
		CASE(HEADER = "...3..6.8", S = "A", K = 1, N = (long long)S.length() * K + 1, Q = 100000, generateNarrowQuery(Q, L, R));

		CASE(HEADER = "...3..6.8", S = "AA", K = 1, N = (long long)S.length() * K + 1, Q = 100000, generateNarrowQuery(Q, L, R));
		CASE(HEADER = "...3..6.8", S = "BA", K = 1, N = (long long)S.length() * K + 1, Q = 100000, generateNarrowQuery(Q, L, R));

		// Blocked query
		CASE(HEADER = "...3..6.8", S = "B", K = 1, N = (long long)S.length() * K + 1, Q = 100000, generateBlockedQuery(Q, L, R, 1));

		CASE(HEADER = "...3..6.8", S = "AA", K = 1, N = (long long)S.length() * K + 1, Q = 100000, generateBlockedQuery(Q, L, R, 0));
		CASE(HEADER = "...3..6.8", S = "AB", K = 1, N = (long long)S.length() * K + 1, Q = 100000, generateBlockedQuery(Q, L, R, 1));
	}

	void TestGroup9() {
		// K = 1, 2 < |S| <= 1000, Q > 1, Li = Ri
		Subtasks({3, 7, 8});
		int S_len, L_num;

		S_len = 579;
		L_num = 76;
		CASE(
			HEADER = "...3...78",
			S = generateString(S_len, L_num), K = 1, N = (long long)S.length() * K + 1, Q = 100000,
			L = R = generateVector(Q, 1, N);
		);

		S_len = 846;
		L_num = 435;
		CASE(
			HEADER = "...3...78",
			S = generateString(S_len, L_num), K = 1, N = (long long)S.length() * K + 1, Q = 100000,
			L = R = generateVector(Q, 1, N);
		);
	}

	void TestGroup10() {
		// 3 <= |S| <= 1000, K = 1, Q > 1, Li < Ri
		Subtasks({3, 8});
		int S_len, L_num;
		// random query case
		S_len = rnd.nextInt(3, 1000);
		L_num = rnd.nextInt(0, S_len);
		CASE(
			HEADER = "...3....8",
			S = generateString(S_len, L_num), K = 1, N = (long long)S.length() * K + 1, Q = 100000,
			generateRandomQuery(Q, L, R)
		);

		S_len = 1000;
		L_num = rnd.nextInt(0, S_len);
		CASE(
			HEADER = "...3....8",
			S = generateString(S_len, L_num), K = 1, N = (long long)S.length() * K + 1, Q = 100000,
			generateRandomQuery(Q, L, R)
		);

		S_len = rnd.nextInt(3, 1000);
		L_num = rnd.nextInt((S_len + 3) / 4, (S_len * 3) / 4);
		CASE(
			HEADER = "...3....8",
			S = generateString(S_len, L_num), K = 1, N = (long long)S.length() * K + 1, Q = 100000,
			generateRandomQuery(Q, L, R)
		);

		S_len = 1000;
		L_num = rnd.nextInt((S_len + 3) / 4, (S_len * 3) / 4);
		CASE(
			HEADER = "...3....8",
			S = generateString(S_len, L_num), K = 1, N = (long long)S.length() * K + 1, Q = 100000,
			generateRandomQuery(Q, L, R)	
		);

		// narrow query case
		S_len = rnd.nextInt(3, 1000);
		L_num = rnd.nextInt(0, S_len);
		CASE(
			HEADER = "...3....8",
			S = generateString(S_len, L_num), K = 1, N = (long long)S.length() * K + 1, Q = 100000,
			generateNarrowQuery(Q, L, R)
		);

		S_len = 1000;
		L_num = rnd.nextInt(0, S_len);
		CASE(
			HEADER = "...3....8",
			S = generateString(S_len, L_num), K = 1, N = (long long)S.length() * K + 1, Q = 100000,
			generateNarrowQuery(Q, L, R)
		);

		S_len = rnd.nextInt(3, 1000);
		L_num = rnd.nextInt((S_len + 3) / 4, (S_len * 3) / 4);
		CASE(
			HEADER = "...3....8",
			S = generateString(S_len, L_num), K = 1, N = (long long)S.length() * K + 1, Q = 100000,
			generateNarrowQuery(Q, L, R)
		);

		S_len = 1000;
		L_num = rnd.nextInt((S_len + 3) / 4, (S_len * 3) / 4);
		CASE(
			HEADER = "...3....8",
			S = generateString(S_len, L_num), K = 1, N = (long long)S.length() * K + 1, Q = 100000,
			generateNarrowQuery(Q, L, R)
		);

		// blocked query case
		S_len = rnd.nextInt(3, 1000);
		L_num = rnd.nextInt(0, S_len);
		CASE(
			HEADER = "...3....8",
			S = generateString(S_len, L_num), K = 1, N = (long long)S.length() * K + 1, Q = 100000,
			generateBlockedQuery(Q, L, R, L_num)
		);

		S_len = 1000;
		L_num = rnd.nextInt(0, S_len);
		CASE(
			HEADER = "...3....8",
			S = generateString(S_len, L_num), K = 1, N = (long long)S.length() * K + 1, Q = 100000,
			generateBlockedQuery(Q, L, R, L_num)
		);

		S_len = rnd.nextInt(3, 1000);
		L_num = rnd.nextInt((S_len + 3) / 4, (S_len * 3) / 4);
		CASE(
			HEADER = "...3....8",
			S = generateString(S_len, L_num), K = 1, N = (long long)S.length() * K + 1, Q = 100000,
			generateBlockedQuery(Q, L, R, L_num)
		);

		S_len = 1000;
		L_num = rnd.nextInt((S_len + 3) / 4, (S_len * 3) / 4);
		CASE(
			HEADER = "...3....8",
			S = generateString(S_len, L_num), K = 1, N = (long long)S.length() * K + 1, Q = 100000,
			generateBlockedQuery(Q, L, R, L_num)
		);
	}



	void TestGroup11() {
		// K = 1, |S| > 1000, Q = 1, Li <= Ri
		Subtasks({4, 5, 7, 8});
		int S_len, L_num;

		S_len = rnd.nextInt(1001, 100000);
		L_num = rnd.nextInt(0, S_len);
		CASE(
			HEADER = "....45.78",
			S = generateString(S_len, L_num), K = 1, N = (long long)S.length() * K + 1, Q = 1,
			L = {rnd.nextLongLong(1, N)}, R = {L[0]}
		);

		S_len = 100000;
		L_num = rnd.nextInt(0, S_len);
		CASE(
			HEADER = "....45.78",
			S = generateString(S_len, L_num), K = 1, N = (long long)S.length() * K + 1, Q = 1,
			L = {rnd.nextLongLong(1, N)}, R = {L[0]}
		);

		S_len = rnd.nextInt(1001, 100000);
		L_num = rnd.nextInt((S_len + 3) / 4, (S_len * 3) / 4);
		CASE(
			HEADER = "....45.78",
			S = generateString(S_len, L_num), K = 1, N = (long long)S.length() * K + 1, Q = 1,
			L = {rnd.nextLongLong(1, N)}, R = {L[0]}
		);

		S_len = 100000;
		L_num = rnd.nextInt((S_len + 3) / 4, (S_len * 3) / 4);
		CASE(
			HEADER = "....45.78",
			S = generateString(S_len, L_num), K = 1, N = (long long)S.length() * K + 1, Q = 1,
			L = {rnd.nextLongLong(1, N)}, R = {L[0]}
		);
	}

	void TestGroup12() {
		// K = 1, |S| > 1000, Q = 1, Li <= Ri
		Subtasks({4, 5, 8});
		int S_len, L_num;

		S_len = rnd.nextInt(1001, 100000);
		L_num = rnd.nextInt(0, S_len);
		CASE(
			HEADER = "....45..8",
			S = generateString(S_len, L_num), K = 1, N = (long long)S.length() * K + 1, Q = 1,
			generateRandomQuery(Q, L, R)
		);

		S_len = 100000;
		L_num = rnd.nextInt(0, S_len);
		CASE(
			HEADER = "....45..8",
			S = generateString(S_len, L_num), K = 1, N = (long long)S.length() * K + 1, Q = 1,
			generateRandomQuery(Q, L, R)
		);
	

		S_len = rnd.nextInt(1001, 100000);
		L_num = rnd.nextInt((S_len + 3) / 4, (S_len * 3) / 4);
		CASE(
			HEADER = "....45..8",
			S = generateString(S_len, L_num), K = 1, N = (long long)S.length() * K + 1, Q = 1,
			generateRandomQuery(Q, L, R)
		);

		S_len = 100000;
		L_num = rnd.nextInt((S_len + 3) / 4, (S_len * 3) / 4);
		CASE(
			HEADER = "....45..8",
			S = generateString(S_len, L_num), K = 1, N = (long long)S.length() * K + 1, Q = 1,
			generateRandomQuery(Q, L, R)
		);

		S_len = rnd.nextInt(1001, 100000);
		L_num = rnd.nextInt(0, S_len);
		CASE(
			HEADER = "....45..8",
			S = generateString(S_len, L_num), K = 1, N = (long long)S.length() * K + 1, Q = 1,
			generateNarrowQuery(Q, L, R)
		);

		S_len = 100000;
		L_num = rnd.nextInt(0, S_len);
		CASE(
			HEADER = "....45..8",
			S = generateString(S_len, L_num), K = 1, N = (long long)S.length() * K + 1, Q = 1,
			generateNarrowQuery(Q, L, R)
		);
	

		S_len = rnd.nextInt(1001, 100000);
		L_num = rnd.nextInt((S_len + 3) / 4, (S_len * 3) / 4);
		CASE(
			HEADER = "....45..8",
			S = generateString(S_len, L_num), K = 1, N = (long long)S.length() * K + 1, Q = 1,
			generateNarrowQuery(Q, L, R)
		);

		S_len = 100000;
		L_num = rnd.nextInt((S_len + 3) / 4, (S_len * 3) / 4);
		CASE(
			HEADER = "....45..8",
			S = generateString(S_len, L_num), K = 1, N = (long long)S.length() * K + 1, Q = 1,
			generateNarrowQuery(Q, L, R)
		);

		S_len = rnd.nextInt(1001, 100000);
		L_num = rnd.nextInt(0, S_len);
		CASE(
			HEADER = "....45..8",
			S = generateString(S_len, L_num), K = 1, N = (long long)S.length() * K + 1, Q = 1,
			generateBlockedQuery(Q, L, R, L_num)
		);

		S_len = 100000;
		L_num = rnd.nextInt(0, S_len);
		CASE(
			HEADER = "....45..8",
			S = generateString(S_len, L_num), K = 1, N = (long long)S.length() * K + 1, Q = 1,
			generateBlockedQuery(Q, L, R, L_num)
		);
	

		S_len = rnd.nextInt(1001, 100000);
		L_num = rnd.nextInt((S_len + 3) / 4, (S_len * 3) / 4);
		CASE(
			HEADER = "....45..8",
			S = generateString(S_len, L_num), K = 1, N = (long long)S.length() * K + 1, Q = 1,
			generateBlockedQuery(Q, L, R, L_num)
		);

		S_len = 100000;
		L_num = rnd.nextInt((S_len + 3) / 4, (S_len * 3) / 4);
		CASE(
			HEADER = "....45..8",
			S = generateString(S_len, L_num), K = 1, N = (long long)S.length() * K + 1, Q = 1,
			generateBlockedQuery(Q, L, R, L_num)
		);

		CASE(
			HEADER = "....45..8",
			S = zebraString(S_len), K = 1, N = (long long)S.length() * K + 1, Q = 1,
			L = {1}, R = {N}
		);

		CASE(
			HEADER = "....45..8",
			S = yinyangString(S_len), K = 1, N = (long long)S.length() * K + 1, Q = 1,
			L = {1}, R = {N}
		);
	}

	void TestGroup13() {
		// K > 1, |S| <= 2, Q = 1, Li = Ri
		Subtasks({5, 6, 7, 8});

		CASE(HEADER = ".....5678", S = "A", K = 76414, N = (long long)S.length() * K + 1, Q = 1, L = R = {rnd.nextLongLong(1, N)});

		CASE(HEADER = ".....5678", S = "AA", K = 89741, N = (long long)S.length() * K + 1, Q = 1, L = R = {rnd.nextLongLong(1, N)});
		CASE(HEADER = ".....5678", S = "BA", K = 91234, N = (long long)S.length() * K + 1, Q = 1, L = R = {rnd.nextLongLong(1, N)});
	}

	void TestGroup14() {
		// K > 1, |S| <= 2, Q = 1, Li < Ri
		Subtasks({5, 6, 8});
		CASE(HEADER = ".....56.8", S = "A", K = rnd.nextInt(2, 100000), N = (long long)S.length() * K + 1, Q = 1,
			span = rnd.nextLongLong(1, N - 1), L = {rnd.nextLongLong(1, N - span)}, R = {L[0] + span});

		CASE(HEADER = ".....56.8", S = "BB", K = rnd.nextInt(2, 100000), N = (long long)S.length() * K + 1, Q = 1,
			span = rnd.nextLongLong(1, N - 1), L = {rnd.nextLongLong(1, N - span)}, R = {L[0] + span});
		CASE(HEADER = ".....56.8", S = "AB", K = rnd.nextInt(2, 100000), N = (long long)S.length() * K + 1, Q = 1,
			span = rnd.nextLongLong(1, N - 1), L = {rnd.nextLongLong(1, N - span)}, R = {L[0] + span});
	}

	void TestGroup15() {
		// Q = 1, K > 1, |S| > 2, Li = Ri
		Subtasks({5, 7, 8});
		int S_len, L_num;
		S_len = 81798;
		L_num = 10123;
		CASE(
			HEADER = ".....5.78",
			S = generateString(S_len, L_num), K = rnd.nextInt(2, 1e9), N = (long long)S.length() * K + 1, Q = 1,
			L = {rnd.nextLongLong(1, N)}, R = {L[0]}
		);
		S_len = 96248;
		L_num = 48123;
		CASE(
			HEADER = ".....5.78",
			S = generateString(S_len, L_num), K = rnd.nextInt(2, 1e9), N = (long long)S.length() * K + 1, Q = 1,
			L = {rnd.nextLongLong(1, N)}, R = {L[0]}
		);
	}

	void TestGroup16() {
		// Q = 1, K > 1, |S| > 2, Li < Ri
		Subtasks({5, 8});
		int S_len, L_num;
		S_len = 87142;
		L_num = 12345;
		CASE(
			HEADER = ".....5..8",
			S = generateString(S_len, L_num), K = rnd.nextInt(2, 1e9), N = (long long)S.length() * K + 1, Q = 1,
			span = rnd.nextLongLong(1, N - 1), L = {rnd.nextLongLong(1, N - span)}, R = {L[0] + span}
		);
		S_len = 98123;
		L_num = 49872;
		CASE(
			HEADER = ".....5..8",
			S = generateString(S_len, L_num), K = rnd.nextInt(2, 1e9), N = (long long)S.length() * K + 1, Q = 1,
			span = rnd.nextLongLong(1, N - 1), L = {rnd.nextLongLong(1, N - span)}, R = {L[0] + span}
		);
	}

	void TestGroup17() {
		// |S| <= 2, Li = Ri, Q > 1, K > 1
		Subtasks({6, 7, 8});

		CASE(HEADER = "......678", S = "B", K = 1e9, N = (long long)S.length() * K + 1, Q = 100000,
			L = R = generateVector(Q, 1, N));
		CASE(HEADER = "......678", S = "AB", K = 1e9, N = (long long)S.length() * K + 1, Q = 100000,
			L = R = generateVector(Q, 1, N));
		CASE(HEADER = "......678", S = "BB", K = 1e9, N = (long long)S.length() * K + 1, Q = 100000,
			L = R = generateVector(Q, 1, N));
	}

	void TestGroup18() {
		// |S| <= 2, Li < Ri, Q > 1, K > 1
		Subtasks({6, 8});

		CASE(HEADER = "......6.8", S = "A", K = 1e9, N = (long long)S.length() * K + 1, Q = 100000,
			generateRandomQuery(Q, L, R));
		CASE(HEADER = "......6.8", S = "AA", K = 1e9, N = (long long)S.length() * K + 1, Q = 100000,
			generateRandomQuery(Q, L, R));
		CASE(HEADER = "......6.8", S = "AB", K = 1e9, N = (long long)S.length() * K + 1, Q = 100000,
			generateRandomQuery(Q, L, R));
	}

	void TestGroup19() {
		// Li = Ri, |S| > 1000, Q > 1, K >= 1
		// Li = Ri, |S| > 2, Q > 1, K > 1
		Subtasks({7, 8});
		int S_len, L_num;

		S_len = 98174;
		L_num = 16123;
		CASE(
			HEADER = ".......78",
			S = generateString(S_len, L_num), K = rnd.nextInt(2, 1e9), N = (long long)S.length() * K + 1, Q = 100000,
			L = R = generateVector(Q, 1, N)
		);

		S_len = 98121;
		L_num = 67142;
		CASE(
			HEADER = ".......78",
			S = generateString(S_len, L_num), K = 1e9, N = (long long)S.length() * K + 1, Q = 100000,
			L = R = generateVector(Q, 1, N)
		);
	}

	void TestGroup20() {
		// Li <= Ri, |S| > 1000, Q > 1, |S| > 1000 or K >= 1
		// Li <= Ri, |S| > 2, Q > 1, |S| > 1000 or K > 1
		Subtasks({8});
		int S_len, L_num;

		// random query case
		S_len = 98567;
		L_num = 47123;
		CASE(
			HEADER = "........8",
			S = generateString(S_len, L_num), K = 987654312, N = (long long)S.length() * K + 1, Q = 100000,
			generateRandomQuery(Q, L, R)	
		);

		// narrow query case
		S_len = 97159;
		L_num = 48174;
		CASE(
			HEADER = "........8",
			S = generateString(S_len, L_num), K = 912345678, N = (long long)S.length() * K + 1, Q = 100000,
			generateNarrowQuery(Q, L, R)
		);

		// blocked query case
		S_len = 98543;
		L_num = 23141;
		CASE(
			HEADER = "........8",
			S = generateString(S_len, L_num), K = 1e9, N = (long long)S.length() * K + 1, Q = 100000,
			generateBlockedQuery(Q, L, R, L_num)
		);

		// random query case
		S_len = 98567;
		L_num = 34151;
		CASE(
			HEADER = "........8",
			S = generateString(S_len, L_num), K = 987654312, N = (long long)S.length() * K + 1, Q = 100000,
			generateRandomQuery(Q, L, R)	
		);

		// narrow query case
		S_len = 97159;
		L_num = 11234;
		CASE(
			HEADER = "........8",
			S = generateString(S_len, L_num), K = 912345678, N = (long long)S.length() * K + 1, Q = 100000,
			generateNarrowQuery(Q, L, R)
		);

		// blocked query case
		S_len = 98543;
		L_num = 49274;
		CASE(
			HEADER = "........8",
			S = generateString(S_len, L_num), K = 1e9, N = (long long)S.length() * K + 1, Q = 100000,
			generateBlockedQuery(Q, L, R, L_num)
		);
	}


private:
	string generateString(int len, int b_num) {
		string ret; ret.resize(len);
		for(int i = 0; i < b_num; i++) {
			ret[i] = 'B';
		}
		for(int i = b_num; i < len; i++) {
			ret[i] = 'A';
		}
		rnd.shuffle(ret.begin(), ret.end());
		return ret;
	}

	void generateRandomQuery(int sz, vector<long long> &L, vector<long long> &R) {
		long long x;
		for(int i = 0; i < sz; i++) {
			span = rnd.nextLongLong(1, N - 1);
			x = rnd.nextLongLong(1, N - span);
			L.push_back(x);
			R.push_back(x + span);
		}
	}

	void generateNarrowQuery(int sz, vector<long long> &L, vector<long long> &R) {
		long long x;
		for(int i = 0; i < sz; i++) {
			span = rnd.nextLongLong(0, max(N / 4 - 1, (long long)1));
			x = rnd.nextLongLong(1, N - span);
			L.push_back(x);
			R.push_back(x + span);
		}
	}

	void generateBlockedQuery(int sz, vector<long long> &L, vector<long long> &R, long long mid) {
		mid *= K; mid++;
		long long x;
		for(int i = 0; i < sz; i++) {
			if(rnd.nextInt(0, 1)) {
				span = rnd.nextLongLong(0, mid - 1);
				x = rnd.nextLongLong(1, mid - span);
			}
			else {
				span = rnd.nextLongLong(0, N - mid);
				x = rnd.nextLongLong(mid, N - span);
			}
			L.push_back(x);
			R.push_back(x + span);
		}
	}

	vector<long long> generateVector(int sz, long long low, long long hi) {
		vector<long long> ret;
		for(int i = 0; i < sz; i++) {
			ret.push_back(rnd.nextLongLong(low, hi));
		}
		return ret;
	}

	string zebraString(int sz) {
		string ret;
		ret.resize(sz);
		for(int i = 0; i < sz; i += 2) {
			ret[i] = 'A';
		}
		for(int i = 1; i < sz; i += 2) {
			ret[i] = 'B';
		}
		return ret;
	}

	string yinyangString(int sz) {
		string ret;
		ret.resize(sz);
		for(int i = 0; i < sz / 2; i++) {
			ret[i] = 'A';
		}
		for(int i = sz / 2; i < sz; i++) {
			ret[i] = 'B';
		}
		return ret;
	}
};
