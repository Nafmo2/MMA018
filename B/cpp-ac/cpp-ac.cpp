#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
  int N;
  string S;
  cin >> N >> S;
  vector<int> v(26);
  for (int i = 0; i < N; i++) {
    v[S[i] - 'A']++;
  }
  for (auto x : v) {
    cout << x;
  }
  cout << endl;
}
