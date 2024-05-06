#include <iostream>
#include <string>

#include "testlib.h"
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)

const int MIN_N = 4;
const int MAX_N = 200;
const int MIN_A = 1;
const int MAX_A = 10000000;
const int MIN_P = 2;
const int MAX_P = 1000000000;

int main(int argc, char** argv) {
  registerValidation(argc, argv);
  int N = inf.readInt(MIN_N, MAX_N, "N");
  inf.readSpace();
  int P = inf.readInt(MIN_P, MAX_P, "P");
  inf.readSpace();
  int Q = inf.readInt(MIN_P, MAX_P, "Q");
  ensuref(Q < P, "Q < P is not satified ");
  inf.readEoln();
  set<int> S;
  REP(i, N) {
    int x = inf.readInt(MIN_A, MAX_A, "A");
    S.insert(x);
    if (i != N - 1)
      inf.readSpace();
    else
      inf.readEoln();
  }
  ensuref(S.size() == N, "shortage of kinds A");
  inf.readEof();
  return 0;
}
