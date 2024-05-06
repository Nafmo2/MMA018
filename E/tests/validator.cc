#include <bits/stdc++.h>

#include "testlib.h"
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)

const int MIN_Q = 1;
const int MAX_Q = 100000;
const int MIN_N = 2;
const int MAX_N = 100000;
const int MIN_A = 1;
const int MAX_A = 1000000000;

int main(int argc, char** argv) {
  registerValidation(argc, argv);
  long long N = inf.readInt(MIN_N, MAX_N, "N");
  inf.readSpace();
  int Q = inf.readInt(MIN_Q, MAX_Q, "Q");
  ensuref(N * (N - 1) >= Q, "Too many Query");
  inf.readEoln();
  REP(i, N) {
    int A = inf.readInt(MIN_A, MAX_A, "A");
    if (i != N - 1)
      inf.readSpace();
    else
      inf.readEoln();
  }
  set<pair<int, int>> S;
  REP(i, Q) {
    int x = inf.readInt(1, N, "x");
    inf.readSpace();
    int y = inf.readInt(1, N, "y");
    S.insert({x, y});
    ensuref(x != y, format("%d-th query x == y", i).c_str());
    ensuref(S.size() - 1 == i, format("%d-th query already appeared", i).c_str());
    inf.readEoln();
  }
  ensuref(S.size() == Q, "shortage of kinds Q");
  inf.readEof();
  return 0;
}
