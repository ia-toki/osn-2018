#include <bits/stdc++.h>
using namespace std;

#define right is_right
#define left is_left

int n;
int ans[107][107];
char row[107][7], col[107][7];
bool flag[10007];

void die() {
    printf("WA\n");
    exit(0);
}

void live(int points, int satisfied) {
    printf("OK\n");
    printf("%d [CORRECT = %d]\n", points, satisfied);
    exit(0);
}

int main(int argc, char* argv[]) {
    FILE* in = fopen(argv[1], "r");
    FILE* out = fopen(argv[2], "r");
    FILE* con = fopen(argv[3], "r");
    
    // Read input
    fscanf(in, "%d", &n);
    for (int i = 0; i < n; i++) {
        fscanf(in, "%s", row[i]);
    }
    for (int i = 0; i < n; i++) {
        fscanf(in, "%s", col[i]);
    }
    
    // Read contestant's output
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (fscanf(con, "%d", &ans[i][j]) == EOF) die();
            if (ans[i][j] < 1 || ans[i][j] > n*n || flag[ans[i][j]]) die();
            flag[ans[i][j]] = true;
        }
    }
    int tmp;
    if (fscanf(con, "%d", &tmp) != EOF) die();

    int satisfied = 0;
    int all_clues = 0;

    // check row
    for (int i = 0; i < n; i++) {
        if (row[i][0] == '-') continue; else {
            int len = strlen(row[i]);
            int val = 0;
            for (int j = 0; j < len; j++) val = 10 * val + row[i][j] - '0';
            
            all_clues++;
            int sum = 0;
            for (int j = 0; j < n; j++) sum += ans[i][j];
            if (sum == val) satisfied++;
        }
    }

    // check col
    for (int j = 0; j < n; j++) {
        if (col[j][0] == '-') continue; else {
            int len = strlen(col[j]);
            int val = 0;
            for (int i = 0; i < len; i++) val = 10 * val + col[j][i] - '0';
            
            all_clues++;
            int sum = 0;
            for (int i = 0; i < n; i++) sum += ans[i][j];
            if (sum == val) satisfied++;
        }
    }

    // Compute points
    int points = 20 * satisfied / all_clues;
    live(points, satisfied);
}
