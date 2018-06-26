#include <bits/stdc++.h>
using namespace std;

#define right is_right
#define left is_left

int n, p, q;
char up[507][7], down[507][7], left[507][7], right[507][7];
char ans[507][507];

void die() {
    printf("WA\n");
    exit(0);
}

void live(int points, int q) {
    printf("OK\n");
    printf("%d Q = %d\n", points, q);
    exit(0);
}

void flood(int x, int y, int ch) {
    ans[x][y] = '-';
    if (x > 0 && ans[x-1][y] == ch) flood(x-1, y, ch);
    if (y > 0 && ans[x][y-1] == ch) flood(x, y-1, ch);
    if (x < n-1 && ans[x+1][y] == ch) flood(x+1, y, ch);
    if (y < n-1 && ans[x][y+1] == ch) flood(x, y+1, ch);
}

int main(int argc, char* argv[]) {
    FILE* in = fopen(argv[1], "r");
    FILE* out = fopen(argv[2], "r");
    FILE* con = fopen(argv[3], "r");
    
    // Read input
    fscanf(in, "%d%d", &n, &p);
    for (int i = 0; i < n; i++) {
        fscanf(in, "%s", up[i]);
    }
    for (int i = 0; i < n; i++) {
        fscanf(in, "%s%s", left[i], right[i]);
    }
    for (int i = 0; i < n; i++) {
        fscanf(in, "%s", down[i]);
    }
    
    // Read contestant's output
    for (int i = 0; i < n; i++) {
        if (fscanf(con, "%s", ans[i]) == EOF) die();
        if (strlen(ans[i]) != n) die();
        for (int j = 0; j < n; j++) {
            if (ans[i][j] != 'M' && ans[i][j] != 'B' && ans[i][j] != '-') die();
        }
    }
    if (fscanf(con, "%s", ans[n]) != EOF) die();

    // Check left
    for (int i = 0; i < n; i++) {
        if (left[i][0] == '-') continue;
        if (left[i][0] == '0') {
            for (int j = 0; j < n; j++) {
                if (ans[i][j] != '-') die();
            }
        } else {
            int len = strlen(left[i]);
            int val = 0;
            for (int j = 0; j < len-1; j++) val = 10 * val + left[i][j] - '0';
            for (int j = 0; j < val-1; j++) {
                if (ans[i][j] != '-') die();
            }
            int j = val-1;
            if (ans[i][j] != left[i][len-1]) die();
        }
    }

    // Check right
    for (int i = 0; i < n; i++) {
        if (right[i][0] == '-') continue;
        if (right[i][0] == '0') {
            for (int j = 0; j < n; j++) {
                if (ans[i][n-1-j] != '-') die();
            }
        } else {
            int len = strlen(right[i]);
            int val = 0;
            for (int j = 0; j < len-1; j++) val = 10 * val + right[i][j] - '0';
            for (int j = 0; j < val-1; j++) {
                if (ans[i][n-1-j] != '-') die();
            }
            int j = val-1;
            if (ans[i][n-1-j] != right[i][len-1]) die();
        }
    }

    // Check up
    for (int i = 0; i < n; i++) {
        if (up[i][0] == '-') continue;
        if (up[i][0] == '0') {
            for (int j = 0; j < n; j++) {
                if (ans[j][i] != '-') die();
            }
        } else {
            int len = strlen(up[i]);
            int val = 0;
            for (int j = 0; j < len-1; j++) val = 10 * val + up[i][j] - '0';
            for (int j = 0; j < val-1; j++) {
                if (ans[j][i] != '-') die();
            }
            int j = val-1;
            if (ans[j][i] != up[i][len-1]) die();
        }
    }

    // Check down
    for (int i = 0; i < n; i++) {
        if (down[i][0] == '-') continue;
        if (down[i][0] == '0') {
            for (int j = 0; j < n; j++) {
                if (ans[n-1-j][i] != '-') die();
            }
        } else {
            int len = strlen(down[i]);
            int val = 0;
            for (int j = 0; j < len-1; j++) val = 10 * val + down[i][j] - '0';
            for (int j = 0; j < val-1; j++) {
                if (ans[n-1-j][i] != '-') die();
            }
            int j = val-1;
            if (ans[n-1-j][i] != down[i][len-1]) die();
        }
    }

    // Compute regions
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (ans[i][j] != '-') {
                q++;
                flood(i, j, ans[i][j]);
            }
        }
    }

    // Compute points
    int points;
    if (q < p) points = 11;
    else if (q == p) points = 10;
    else if (1 <= q - p && q - p <= 40) points = 10 - sqrt(2 * (q - p));
    else if (q - p > 40) points = 0;
    
    live(points, q);
}
