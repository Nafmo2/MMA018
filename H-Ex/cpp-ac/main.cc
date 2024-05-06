#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
int main() {
  long long ans = 0, INF = 1e15;
  // 先にボーナスの和を入れておき，全部ボーナスを貰った状態から始める
  // ボーナスの条件を満たさなくなった場合，前借りボーナスを返却するイメージ
  long long sum = 0;
  int N, M;
  cin >> N >> M;
  vector<long long> A(N), B(M);
  mf_graph<long long> graph(N + M + 2);
  int s = N + M, t = N + M + 1;

  for (int i = 0; i < N; i++) {
    cin >> A[i];
    // こっちを切ると カードを使わない
    // s -> カード i , cap: A[i]
    graph.add_edge(s, i, A[i]);
  }
  for (int i = 0; i < M; i++) {
    cin >> B[i];
    sum += B[i];
    // こっちを切ると 前借りしたボーナス分の利益を返却する
    // ボーナス i -> t , cap: B[i]
    graph.add_edge(N + i, t, B[i]);
  }
  for (int i = 0; i < M; i++) {
    int K;
    cin >> K;
    for (int j = 0; j < K; j++) {
      int c;
      cin >> c;
      // ここは INF なので切れない / カードの条件をボーナスに流すための道
      // カード c -> ボーナス i , cap: INF
      graph.add_edge(c - 1, N + i, INF);
    }
  }
  ans = sum - graph.flow(s, t);
  cout << ans << endl;
}
