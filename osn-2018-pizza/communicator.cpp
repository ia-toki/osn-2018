#include <bits/stdc++.h>
using namespace std;

int ac() {
  cerr << "AC" << endl;
  return 0;
}

int wa() {
  cerr << "WA" << endl;
  return 0;
}

int convert(string input) {
  int len = input.length();
  int tmp = 0;
  for (int i = 0; i < len; i++) {
    if ('0' <= input[i] && input[i] <= '9')
      tmp = 10 * tmp + input[i] - '0';
    else
      return -1;
  }
  return tmp;
}

int get_best_pizza(int n, int s, vector<int> &pizza, vector<bool> &dengklek_like, vector<bool> &judge_like) {
  if(s == 2) {
    // take random pizza that both like, if exist
    vector<int> choices;
    for(int i = 1 ; i <= n ; i++) {
      if(pizza[i] > 0 && judge_like[i] && dengklek_like[i]) {
        choices.push_back(i);
      }
    }

    if(!choices.empty()) {
      int idx = rand() % choices.size();
      return choices[idx];
    }
  }

  // take smallest that judge like
  for (int i = 1; i <= n; i++) {
    if (pizza[i] > 0 && judge_like[i]) {
      return i;
    }
  }

  // no pizza can be taken
  return 0;
}

int compute_k(int n, vector<int> &pizza, vector<bool> &dengklek_like, vector<bool> &judge_like) {
  int both = 0;
  int dengklek = 0;

  for(int i = 1 ; i <= n ; i++) {
    if(dengklek_like[i] && judge_like[i]) {
      both += pizza[i];
    } else if(dengklek_like[i]) {
      dengklek += pizza[i];
    }
  }

  return dengklek + (both + 1) / 2;
}

int make_verdict(int dengklek_count, int k) {
  if(dengklek_count >= k) {
    return ac();
  } else {
    return wa();
  }
}

int main(int argc, char *argv[]) {
  // fixed seed so behaviour is consistent
  srand(1072018);

  ifstream tc_in(argv[1]);

  string header;
  tc_in >> header;
  int n, s;
  tc_in >> n >> s;

  // read pizza
  vector<int> pizza(n+1, 0);
  for(int i = 1 ; i <= n ; i++) {
    tc_in >> pizza[i];
  }

  // read dengklek
  int d;
  tc_in >> d;

  vector<bool> dengklek_like(n + 1, false);
  vector<int> real_dengklek_like(d);
  for(int i = 0 ; i < d ; i++) {
    tc_in >> real_dengklek_like[i];
    dengklek_like[real_dengklek_like[i]] = true;
  }

  // read judge
  int j;
  tc_in >> j;

  vector<bool> judge_like(n + 1, false);
  vector<int> real_judge_like(j);
  for (int i = 0; i < j; i++) {
    tc_in >> real_judge_like[i];
    judge_like[real_judge_like[i]] = true;
  }

  // give info to contestant
  cout << header << "\n";
  cout << n << " " << s << "\n";
  for(int i = 1 ; i <= n ; i++) {
    printf("%d%c", pizza[i], i == n ? '\n' : ' ');
  }
  cout << d << "\n";
  for(int i = 1 ; i <= d ; i++) {
    printf("%d%c", real_dengklek_like[i-1], i == d ? '\n' : ' ');
  }
  cout << j << "\n";
  for(int i = 1 ; i <= j ; i++) {
    printf("%d%c", real_judge_like[i-1], i == j ? '\n' : ' ');
  }
  fflush(stdout);

  int last_judge = -1;
  int last_dengklek = -1;
  int dengklek_count = 0;
  int optimal_k = compute_k(n, pizza, dengklek_like, judge_like);

  string input;
  while(cin >> input) {
    int num = convert(input);
    
    if(num < 0 || num > n) return wa();
    if(num > 0 && pizza[num] == 0) return wa();
    if(num > 0 && !dengklek_like[num]) return wa();

    pizza[num]--;
    dengklek_count += (num > 0);
    last_dengklek = num;

    if(last_dengklek == 0 && last_judge == 0) {
      return make_verdict(dengklek_count, optimal_k);
    }

    last_judge = get_best_pizza(n, s, pizza, dengklek_like, judge_like);
    pizza[last_judge]--;
    cout << last_judge << endl;

    if (last_dengklek == 0 && last_judge == 0) {
      return make_verdict(dengklek_count, optimal_k);
    }
  }

  return wa();
}
