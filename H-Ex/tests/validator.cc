#include <bits/stdc++.h>

#include "testlib.h"
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
using ll = long long;

const int MIN_N = 1;
const int MAX_N = 100;
const int MIN_M = 1;
const int MAX_M = 100;
const int MIN_A = 1;
const int MAX_A = 1000000000;
const int MIN_B = 1;
const int MAX_B = 1000000000;
const int MIN_C = 1;
const int MAX_C = 100;

int main(int argc, char** argv) {
  registerValidation(argc, argv);
  int N = inf.readInt(MIN_N, MAX_N, "N");
  inf.readSpace();
  int M = inf.readInt(MIN_M, MAX_M, "M");
  inf.readEoln();
  vector<int> A(N), B(M);
  REP(i, N) {
    A[i] = inf.readInt(MIN_A, MAX_A, "A");
    if (i != N - 1)
      inf.readSpace();
    else
      inf.readEoln();
  }
  REP(i, M) {
    B[i] = inf.readInt(MIN_B, MAX_B, "B");
    if (i != M - 1)
      inf.readSpace();
    else
      inf.readEoln();
  }
  ensure(A.size() == N);
  ensure(B.size() == M);

  REP(i, M) {
    set<int> kinds;
    int K = inf.readInt(1, N, "K");
    ensuref(1 <= K && K <= N, format("{}-th case unsatisfied: 1 <= K <= N").c_str());
    inf.readSpace();
    int prev = 0;
    REP(j, K) {
      int c = inf.readInt(MIN_C, MAX_C, "c");
      ensure(1 <= c && c <= N);
      ensuref(prev < c, format("{}-th case unsatisfied: C_{} >= C_{}", i, i - 1, i).c_str());
      prev = c;
      kinds.insert(c);
      if (j != K - 1)
        inf.readSpace();
      else
        inf.readEoln();
    }
    ensuref(kinds.size() == K, format("{}-th case unsatisfied: lack of the number of C", i).c_str());
  }
  inf.readEof();
  return 0;
}
