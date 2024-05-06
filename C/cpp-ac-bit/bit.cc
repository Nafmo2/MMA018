#include <iostream>
#include <string>
#include <vector>
#include <cassert>
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
  int N = H + W - 2;

  for (int bit = 0; bit < (1 << N); bit++) {
    int x = 0, y = 0, now = 1;
    bool ok = true;
    for (int i = 0; i < N; i++) {
      int a = x + dx[(bit >> i) & 1];
      int b = y + dy[(bit >> i) & 1];
      if (a < 0 || b < 0 || a >= H || b >= W || G[a][b] == '#') {
        ok = false;
        break;
      }
      now += (G[a][b] == 'o' ? 1 : -1);
      if (now < 0) {
        ok = false;
        break;
      }
      x = a;
      y = b;
    }
    if (ok) ans++;
  }
  cout << ans << endl;
}
