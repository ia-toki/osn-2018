#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int MAX_VAL = 1e5 + 5;

string header;

long long dp[MAX_VAL][3];
int cnt[N];
int n;

void read() {
    cin >> header;
    scanf("%d", &n);

    for(int i = 1 ; i <= n ; i++) {
        int x; scanf("%d", &x);
        cnt[x]++;
    }
}

long long solve(int val, int use) {
    if(use == 3) {
        return 1;
    }

    if(val == MAX_VAL) {
        return 0;
    }

    long long &ret = dp[val][use];
    if(ret != -1) {
        return ret;
    }

    // skip this value
    ret = solve(val+1, use);
    // take one element with this value
    ret = (ret + 1ll * cnt[val] * solve(val+1, use+1));

    return ret;
}

long long work() {
    memset(dp, -1, sizeof dp);
    return solve(1, 0);
}

int main() {
    read();
    printf("%lld\n", work());
    return 0;
}
