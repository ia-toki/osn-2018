#include <bits/stdc++.h>
using namespace std;

const int N = 15;

string header;
int n, s;

int pizza[N];
bool judge_like[N];
bool dengklek_like[N];

void read() {
  cin >> header;
  cin >> n >> s;

  for(int i = 1 ; i <= n ; i++) cin >> pizza[i];

  int d; cin >> d;
  for(int i = 0 ; i < d ; i++) {
    int idx; cin >> idx;
    dengklek_like[idx] = true;
  }

  int j; cin >> j;
  for(int i = 0 ; i < j ; i++) {
    int idx; cin >> idx;
    judge_like[idx] = true;
  }
}

// optimal: take something that both like, otherwise take something dengklek like
int get_best_pizza() {
  for(int i = 1 ; i <= n ; i++) {
    if(pizza[i] > 0 && judge_like[i] && dengklek_like[i]) {
      return i;
    }
  }

  for (int i = 1 ; i <= n ; i++) {
    if (pizza[i] > 0 && dengklek_like[i]) {
      return i;
    }
  }

  return 0;
}

void work() {
  int last_judge = -1;
  int last_dengklek = -1;

  while(last_judge != 0 || last_dengklek != 0) {
    last_dengklek = get_best_pizza();
    pizza[last_dengklek]--;
    cout << last_dengklek << endl;

    if(last_judge == 0 && last_dengklek == 0) {
      break;
    }

    cin >> last_judge;
    pizza[last_judge]--;
  }

  for(int i = 1 ; i <= n ; i++) {
    assert(pizza[i] == 0 || (!dengklek_like[i] && !judge_like[i]));
  }
}

int main() {
  read();
  work();
  return 0;
}
