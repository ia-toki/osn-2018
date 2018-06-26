#include <bits/stdc++.h>
using namespace std;

#define right isright
#define left isleft
#define EMPTY ' '
#define WALL '#'
#define INNER_WALL '@'
#define M_BORDER 'm'
#define B_BORDER 'b'
#define CONFLICT_BORDER '?'

typedef pair<int, int> PII;

int n, p;
char up[507][17], down[507][17], left[507][17], right[507][17];
char ans[507][507];


void read() {
	scanf("%d%d",&n,&p);
	for (int i = 0; i < n; i++) {
		scanf("%s", up[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%s%s", left[i], right[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%s", down[i]);
	}
}

void debug() {
	printf("\n\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%c", ans[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}

void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans[i][j] = EMPTY;
		}
	}
}

void generateBase() {
	for (int i = 0; i < n; i++) {
		if (up[i][0] == '0') {
			for (int j = 0; j < n; j++) ans[j][i] = WALL;
		} else if (up[i][0] != '-') {
			int len = strlen(up[i]);
			int val = 0;
			for (int j = 0; j < len-1; j++) {
				val = 10 * val + up[i][j] - '0';
			}
			for (int j = 0; j < val-1; j++) ans[j][i] = WALL;
			ans[val-1][i] = up[i][len-1];
		}

		if (left[i][0] == '0') {
			for (int j = 0; j < n; j++) ans[i][j] = WALL;
		} else if (left[i][0] != '-') {
			int len = strlen(left[i]);
			int val = 0;
			for (int j = 0; j < len-1; j++) {
				val = 10 * val + left[i][j] - '0';
			}
			for (int j = 0; j < val-1; j++) ans[i][j] = WALL;
			ans[i][val-1] = left[i][len-1];
		}

		if (down[i][0] == '0') {
			for (int j = 0; j < n; j++) ans[n-1-j][i] = WALL;
		} else if (down[i][0] != '-') {
			int len = strlen(down[i]);
			int val = 0;
			for (int j = 0; j < len-1; j++) {
				val = 10 * val + down[i][j] - '0';
			}
			for (int j = 0; j < val-1; j++) ans[n-1-j][i] = WALL;
			ans[n-val][i] = down[i][len-1];
		}

		if (right[i][0] == '0') {
			for (int j = 0; j < n; j++) ans[i][n-1-j] = WALL;
		} else if (right[i][0] != '-') {
			int len = strlen(right[i]);
			int val = 0;
			for (int j = 0; j < len-1; j++) {
				val = 10 * val + right[i][j] - '0';
			}
			for (int j = 0; j < val-1; j++) ans[i][n-1-j] = WALL;
			ans[i][n-val] = right[i][len-1];
		}
	}
}

bool isWall(int x, int y) {
	if (x < 0 || x >= n) return true;
	if (y < 0 || y >= n) return true;
	return (ans[x][y] == WALL);	
}

bool isEmpty(int x, int y) {
	if (x < 0 || x >= n) return false;
	if (y < 0 || y >= n) return false;
	return (ans[x][y] == EMPTY);	
}

bool isConflict(int x, int y) {
	if (x < 0 || x >= n) return false;
	if (y < 0 || y >= n) return false;
	return (ans[x][y] == CONFLICT_BORDER);	
}

bool isM(int x, int y) {
	if (x < 0 || x >= n) return false;
	if (y < 0 || y >= n) return false;
	return (ans[x][y] == 'M' || ans[x][y] == M_BORDER);	
}

bool isB(int x, int y) {
	if (x < 0 || x >= n) return false;
	if (y < 0 || y >= n) return false;
	return (ans[x][y] == 'B' || ans[x][y] == B_BORDER);
}

void fillEmpty() {
	bool flag[507][507];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			flag[i][j] = false;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!flag[i][j] && ans[i][j] != WALL) {
				vector<PII> visit;
				bool anyLetter = false;
				int pos = 0;

				flag[i][j] = true;
				visit.push_back(PII(i ,j));
				while (pos < visit.size()) {
					PII tmp = visit[pos++];
					int x = tmp.first;
					int y = tmp.second;
					if (!isWall(x+1, y) && !flag[x+1][y]) {flag[x+1][y] = true; visit.push_back(PII(x+1, y));}
					if (!isWall(x-1, y) && !flag[x-1][y]) {flag[x-1][y] = true; visit.push_back(PII(x-1, y));}
					if (!isWall(x, y+1) && !flag[x][y+1]) {flag[x][y+1] = true; visit.push_back(PII(x, y+1));}
					if (!isWall(x, y-1) && !flag[x][y-1]) {flag[x][y-1] = true; visit.push_back(PII(x, y-1));}
					
					if (ans[x][y] == 'M' || ans[x][y] == 'B') anyLetter = true;
				}

				if (!anyLetter) {
					for (pos = 0; pos < visit.size(); pos++) {
						PII tmp = visit[pos];
						int x = tmp.first;
						int y = tmp.second;
						ans[x][y] = INNER_WALL;
					}
				}
			}
		}
	}
}

void joinBorder() {
	bool flag[507][507];
	int toColor[507][507];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			flag[i][j] = false;
			toColor[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!flag[i][j] && (ans[i][j] == 'M' || ans[i][j] == 'B')) {
				vector<PII> visit;
				PII posStart = PII(i, j); 
				PII rightHandStart;
				char lastLetter = ans[i][j];

				if (isWall(i+1, j)) rightHandStart = PII(i+1, j);
				if (isWall(i-1, j)) rightHandStart = PII(i-1, j);
				if (isWall(i, j+1)) rightHandStart = PII(i, j+1);
				if (isWall(i, j-1)) rightHandStart = PII(i, j-1);

				PII pos = posStart;
				PII rightHand = rightHandStart;
				
				do {
					int x = pos.first;
					int y = pos.second;

					if (ans[x][y] != 'M' && ans[x][y] != 'B') visit.push_back(pos);
					flag[x][y] = true;

					if (rightHand == PII(x-1, y)) {
						if (isWall(x, y-1)) {
							rightHand = PII(x, y-1);
						} else {
							rightHand = pos;
							pos = PII(x, y-1);
						}
					} else if (rightHand == PII(x, y+1)) {
						if (isWall(x-1, y)) {
							rightHand = PII(x-1, y);
						} else {
							rightHand = pos;
							pos = PII(x-1, y);
						}
					} else if (rightHand == PII(x+1, y)) {
						if (isWall(x, y+1)) {
							rightHand = PII(x, y+1);
						} else {
							rightHand = pos;
							pos = PII(x, y+1);
						}
					} else if (rightHand == PII(x, y-1)) {
						if (isWall(x+1, y)) {
							rightHand = PII(x+1, y);
						} else {
							rightHand = pos;
							pos = PII(x+1, y);
						}
					}

					x = pos.first;
					y = pos.second;

					if (ans[x][y] == 'M' || ans[x][y] == 'B') {
						if (lastLetter == ans[x][y]) {
							for (int k = 0; k < visit.size(); k++) {
								toColor[visit[k].first][visit[k].second] |= (ans[x][y] == 'M' ? 1 : 2);
							}
						}

						lastLetter = ans[x][y];
						visit.clear();
					}
				} while (pos != posStart || rightHand != rightHandStart);

				int x = pos.first;
				int y = pos.second;
				if (ans[x][y] == 'M' || ans[x][y] == 'B') {
					if (lastLetter == ans[x][y]) {
						for (int k = 0; k < visit.size(); k++) {
							toColor[visit[k].first][visit[k].second] |= (ans[x][y] == 'M' ? 1 : 2);
						}
					}

					lastLetter = ans[x][y];
					visit.clear();
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (toColor[i][j] == 1) ans[i][j] = M_BORDER;
			if (toColor[i][j] == 2) ans[i][j] = B_BORDER;
			if (toColor[i][j] == 3) ans[i][j] = CONFLICT_BORDER;
		}
	}
}

int countRegion() {
	int region = 0;
	bool flag[507][507];
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			flag[i][j] = false;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!flag[i][j] && (ans[i][j] == 'M' || ans[i][j] == 'B')) {
				vector<PII> visit;
				int pos = 0;

				region++;
				flag[i][j] = true;
				visit.push_back(PII(i ,j));
				while (pos < visit.size()) {
					PII tmp = visit[pos++];
					int x = tmp.first;
					int y = tmp.second;
					
					if (ans[i][j] == 'M') {
						if (isM(x+1, y) && !flag[x+1][y]) {flag[x+1][y] = true; visit.push_back(PII(x+1, y));}
						if (isM(x-1, y) && !flag[x-1][y]) {flag[x-1][y] = true; visit.push_back(PII(x-1, y));}
						if (isM(x, y+1) && !flag[x][y+1]) {flag[x][y+1] = true; visit.push_back(PII(x, y+1));}
						if (isM(x, y-1) && !flag[x][y-1]) {flag[x][y-1] = true; visit.push_back(PII(x, y-1));}
					}
					if (ans[i][j] == 'B') {
						if (isB(x+1, y) && !flag[x+1][y]) {flag[x+1][y] = true; visit.push_back(PII(x+1, y));}
						if (isB(x-1, y) && !flag[x-1][y]) {flag[x-1][y] = true; visit.push_back(PII(x-1, y));}
						if (isB(x, y+1) && !flag[x][y+1]) {flag[x][y+1] = true; visit.push_back(PII(x, y+1));}
						if (isB(x, y-1) && !flag[x][y-1]) {flag[x][y-1] = true; visit.push_back(PII(x, y-1));}
					}
				}
			}
		}
	}

	return region;
}

void resolveConflict() {
	bool flag[507][507];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			flag[i][j] = false;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!flag[i][j] && ans[i][j] == CONFLICT_BORDER) {
				vector<PII> visit;
				int pos = 0;

				flag[i][j] = true;
				visit.push_back(PII(i ,j));
				while (pos < visit.size()) {
					PII tmp = visit[pos++];
					int x = tmp.first;
					int y = tmp.second;
					if (isConflict(x+1, y) && !flag[x+1][y]) {flag[x+1][y] = true; visit.push_back(PII(x+1, y));}
					if (isConflict(x-1, y) && !flag[x-1][y]) {flag[x-1][y] = true; visit.push_back(PII(x-1, y));}
					if (isConflict(x, y+1) && !flag[x][y+1]) {flag[x][y+1] = true; visit.push_back(PII(x, y+1));}
					if (isConflict(x, y-1) && !flag[x][y-1]) {flag[x][y-1] = true; visit.push_back(PII(x, y-1));}
				}

				for (int k = 0; k < visit.size(); k++) {
					ans[visit[k].first][visit[k].second] = M_BORDER;
				}
				int withM = countRegion();

				for (int k = 0; k < visit.size(); k++) {
					ans[visit[k].first][visit[k].second] = B_BORDER;
				}
				int withB = countRegion();

				if (withM < withB) {
					for (int k = 0; k < visit.size(); k++) {
						ans[visit[k].first][visit[k].second] = M_BORDER;
					}
				}
			}
		}
	}
}

void fillInner() {
	bool flag[507][507];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			flag[i][j] = false;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!flag[i][j] && ans[i][j] == EMPTY) {
				vector<PII> visit;
				int pos = 0;

				flag[i][j] = true;
				visit.push_back(PII(i ,j));
				while (pos < visit.size()) {
					PII tmp = visit[pos++];
					int x = tmp.first;
					int y = tmp.second;
					if (isEmpty(x+1, y) && !flag[x+1][y]) {flag[x+1][y] = true; visit.push_back(PII(x+1, y));}
					if (isEmpty(x-1, y) && !flag[x-1][y]) {flag[x-1][y] = true; visit.push_back(PII(x-1, y));}
					if (isEmpty(x, y+1) && !flag[x][y+1]) {flag[x][y+1] = true; visit.push_back(PII(x, y+1));}
					if (isEmpty(x, y-1) && !flag[x][y-1]) {flag[x][y-1] = true; visit.push_back(PII(x, y-1));}
				}

				for (int k = 0; k < visit.size(); k++) {
					ans[visit[k].first][visit[k].second] = M_BORDER;
				}
				int withM = countRegion();

				for (int k = 0; k < visit.size(); k++) {
					ans[visit[k].first][visit[k].second] = B_BORDER;
				}
				int withB = countRegion();

				if (withM < withB) {
					for (int k = 0; k < visit.size(); k++) {
						ans[visit[k].first][visit[k].second] = M_BORDER;
					}
				}
			}
		}
	}
}

int write() {
	int region = 0;
	bool flag[507][507];
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			flag[i][j] = false;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!flag[i][j] && (ans[i][j] == 'M' || ans[i][j] == 'B')) {
				vector<PII> visit;
				int pos = 0;

				region++;
				flag[i][j] = true;
				visit.push_back(PII(i ,j));
				while (pos < visit.size()) {
					PII tmp = visit[pos++];
					int x = tmp.first;
					int y = tmp.second;
					
					if (ans[i][j] == 'M') {
						if (isM(x+1, y) && !flag[x+1][y]) {flag[x+1][y] = true; visit.push_back(PII(x+1, y));}
						if (isM(x-1, y) && !flag[x-1][y]) {flag[x-1][y] = true; visit.push_back(PII(x-1, y));}
						if (isM(x, y+1) && !flag[x][y+1]) {flag[x][y+1] = true; visit.push_back(PII(x, y+1));}
						if (isM(x, y-1) && !flag[x][y-1]) {flag[x][y-1] = true; visit.push_back(PII(x, y-1));}
					}
					if (ans[i][j] == 'B') {
						if (isB(x+1, y) && !flag[x+1][y]) {flag[x+1][y] = true; visit.push_back(PII(x+1, y));}
						if (isB(x-1, y) && !flag[x-1][y]) {flag[x-1][y] = true; visit.push_back(PII(x-1, y));}
						if (isB(x, y+1) && !flag[x][y+1]) {flag[x][y+1] = true; visit.push_back(PII(x, y+1));}
						if (isB(x, y-1) && !flag[x][y-1]) {flag[x][y-1] = true; visit.push_back(PII(x, y-1));}
					}
				}

				for (int k = 0; k < visit.size(); k++) {
					ans[visit[k].first][visit[k].second] = (ans[i][j] == 'M' ? 'M' : 'B');
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (ans[i][j] == 'M' || ans[i][j] == 'B') printf("%c", ans[i][j]); else printf("-");
		}
		printf("\n");
	}
	return region;
}

int main() {
	read();
	init();
	generateBase();
	//debug();
	fillEmpty();
	//debug();
	joinBorder();
	//debug();
	resolveConflict();
	fillInner();
	
	int total_region = write();
	assert(total_region == p);
}
