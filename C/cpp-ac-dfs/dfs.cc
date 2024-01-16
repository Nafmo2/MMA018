#include <iostream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int main() {
  int H, W, ans = 0;
  cin >> H >> W;
  vector<string> G(H);
  for (int i = 0; i < H; i++) {
    cin >> G[i];
  }
  int dx[] = {1, 0};
  int dy[] = {0, 1};
  stack<pair<pair<int, int>, int>> S;
  S.push({{0, 0}, 1});
  while (!S.empty()) {
    auto [xy, now] = S.top();
    auto [x, y] = xy;
    S.pop();
    for (int i = 0; i < 2; i++) {
      int a = x + dx[i], b = y + dy[i];
      if (a < 0 || b < 0 || a >= H || b >= W || G[a][b] == '#') continue;
      int next = now + (G[a][b] == 'o' ? 1 : -1);
      if (next >= 0) {
        if (a == H - 1 && b == W - 1) {
          ans++;
        } else {
          S.push({{a, b}, next});
        }
      }
    }
  }
  cout << ans << endl;
}
