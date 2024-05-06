#include <bits/stdc++.h>

#include "testlib.h"
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)

const int MIN_N = 1;
const int MAX_N = 5;
const int MIN_K = 1;
const int MAX_K = 5;
const int MIN_M = 1;
const int MAX_M = 20000;

int main(int argc, char** argv) {
  registerValidation(argc, argv);
  int N = inf.readInt(MIN_N, MAX_N, "N");
  inf.readSpace();
  int M = inf.readInt(MIN_M, MAX_M, "M");
  inf.readSpace();
  int K = inf.readInt(MIN_K, N, "K");
  inf.readEoln();
  inf.readEof();
  return 0;
}
