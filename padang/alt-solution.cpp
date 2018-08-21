#include <bits/stdc++.h>
using namespace std;

typedef pair<long long, char> PIC;

vector<PIC> S;
long long len;

bool buildString(long long A, long long B) {
	if (A == 0 && B == 0) {
		return true;
		
	} else if (A == 0 && B > 0) {
		return false;
	
	} else if (B >= A) {
		long long tmp = B / A;
		S.push_back(PIC(tmp, '0'));
		len += tmp;
		return buildString(A, B % A);
		
	} else if (A > B) {
		long long tmp = A / (B + 1);
		S.push_back(PIC(tmp, '1'));
		len += tmp;
		return buildString(A % (B + 1), B);
	}
}

string getSubstring(long long L, long long R) {
	if (R >= len) return "DI LUAR BATAS";
	
	string res = "";
	for (long long i = L; i <= R; i++) {
		long long pos = len;
		for (int j = 0; j < S.size(); j++) {
			pos -= S[j].first;
			if (pos <= i) {
				res += S[j].second;
				break;
			}
		}
	}
	return res;
}

int main() {
    char header[107];
    long long A, B, Q;

    scanf("%s", header);
    scanf("%lld%lld%lld", &A, &B, &Q);
    
    if (!buildString(A, B)) {
        printf("TIDAK MUNGKIN\n");
    } else {
        printf("MUNGKIN\n");
        for (int i = 0; i < Q; i++) {
            long long L, R;
            scanf("%lld%lld", &L, &R);
            cout << getSubstring(L, R) << endl;
        }
    }
}
