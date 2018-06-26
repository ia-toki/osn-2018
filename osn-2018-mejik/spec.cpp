#include <tcframe/spec.hpp>
#include <bits/stdc++.h>
using namespace tcframe;
using namespace std;

typedef pair<int,int> PII;

class ProblemSpec : public BaseProblemSpec {
protected:
    int N;
    vector<string> ROW, COL;

    void InputFormat() {
        LINE(N);
        LINE(ROW % SIZE(N));
        LINE(COL % SIZE(N));
    }

    void StyleConfig() {
        CustomScorer();
        NoOutput();
    }

    void Constraints() {
        CONS(4 <= N && N <= 8);
        CONS(validClue(ROW));
        CONS(validClue(COL));
    }

    void Subtask1() {
        CONS(N == 4);
        CONS(allClues());
    }

    void Subtask2() {
        CONS(N == 5);
        CONS(onlyFirstAndLast());
    }

    void Subtask3() {
        CONS(N == 6);
        CONS(sameClues());
    }

    void Subtask4() {
        CONS(N == 7);
        CONS(onlyRows());
    }

    void Subtask5() {
        CONS(N == 8);
    }

private:
    bool validClue(const vector<string> &A) {
        if (A.size() != N) return false;

        for (int i = 0; i < N; i++) {
            if (A[i] == "-") continue;
            if (A[i][0] < '1' || A[i][0] > '9') return false;

            int len = A[i].length();
            for (int j = 1; j < len; j++) {
                if (A[i][j] < '0' || A[i][j] > '9') return false;    
            }
        }

        return true;
    }

    bool allClues() {
    	for (int i = 0; i < N; i++) {
    		if (ROW[i] == "-" || COL[i] == "-") return false;
    	}
    	return true;
    }

    bool onlyFirstAndLast() {
    	if (ROW[0] == "-" || COL[0] == "-") return false;
    	if (ROW[N-1] == "-" || COL[N-1] == "-") return false;
    	for (int i = 1; i < N-1; i++) {
    		if (ROW[i] != "-" || COL[i] != "-") return false;
    	}
    	return true;
    }

    bool sameClues() {
    	string clue = ROW[0];
    	for (int i = 0; i < N; i++) {
    		if (ROW[i] != clue || COL[i] != clue) return false;
    	}
    	return true;
    }

    bool onlyRows() {
    	for (int i = 0; i < N; i++) {
    		if (ROW[i] == "-") return false;
    	}
    	for (int i = 0; i < N; i++) {
    		if (COL[i] != "-") return false;
    	}
    	return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({ "5",
                "- 38 64 - 92",
                "15 - 67 - -"});
    }

    void BeforeTestCase() {
    	ROW.clear();
    	COL.clear();
    }


    void TestGroup1() {
        Subtasks({1});
        CASE(N = 4, ROW = {"19", "29", "39", "49"}, COL = {"10", "38", "46", "42"});
    }

    void TestGroup2() {
        Subtasks({2});
        CASE(N = 5, ROW = {"26", "-", "-", "-", "115"}, COL = {"32", "-", "-", "-", "56"});
    }

    void TestGroup3() {
        Subtasks({3});
        CASE(N = 6, ROW = {"111", "111", "111", "111", "111", "111"}, COL = {"111", "111", "111", "111", "111", "111"});
    }

    void TestGroup4() {
        Subtasks({4});
        CASE(N = 7, randomRowOnly());
    }

    void TestGroup5() {
        Subtasks({5});
        CASE(N = 8, randomAll(60));
    }

private:
	void randomRowOnly() {
		vector<int> tmp;
		for (int i = 1; i <= N*N; i++) tmp.push_back(i);
		rnd.shuffle(tmp.begin(), tmp.end());

		int ans[17][17];
		printf("\n");
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				ans[i][j] = tmp[N * i + j];
				printf("%d ", ans[i][j]);
			}
			printf("\n");
		}

		for (int i = 0; i < N; i++) {
			int sum = 0;
			for (int j = 0; j < N; j++) {
				sum += ans[i][j];
			}
			ROW.push_back(to_string(sum));
		}

		for (int i = 0; i < N; i++) {
			int sum = 0;
			for (int j = 0; j < N; j++) {
				sum += ans[j][i];
			}
			COL.push_back("-");
		}
	}

	void randomAll(int prob) {
		vector<int> tmp;
		for (int i = 1; i <= N*N; i++) tmp.push_back(i);
		rnd.shuffle(tmp.begin(), tmp.end());

		int ans[17][17];
		printf("\n");
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				ans[i][j] = tmp[N * i + j];
				printf("%d ", ans[i][j]);
			}
			printf("\n");
		}

		for (int i = 0; i < N; i++) {
			int sum = 0;
			for (int j = 0; j < N; j++) {
				sum += ans[i][j];
			}
			if (rnd.nextInt(100) < prob) ROW.push_back(to_string(sum)); else ROW.push_back("-");
		}

		for (int i = 0; i < N; i++) {
			int sum = 0;
			for (int j = 0; j < N; j++) {
				sum += ans[j][i];
			}
			if (rnd.nextInt(100) < prob) COL.push_back(to_string(sum)); else COL.push_back("-");
		}
	}
};
