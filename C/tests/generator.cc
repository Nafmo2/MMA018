#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)

// begin templates
void makecase(std::ostream&, int);
void setseed(int testcase_idx) {
  // これだとテストケースを予測されやすいので seed
  // を加工するなどする必要があるかもしれない
  // long long seed = testcase_idx;
  random_device gen;
  long long seed = testcase_idx * gen();
  rnd.setSeed(seed);
}
void makecase_rime(const std::string& filename, int testcase_idx) {
  setseed(testcase_idx);
  std::ofstream ofs(filename);
  makecase(ofs, testcase_idx);
  ofs.close();
}
void makecase_yukicoder(const std::string& filename, int testcase_idx) {
  setseed(testcase_idx);
  makecase(std::cout, testcase_idx);
  std::cerr << filename << std::endl;
}
// end templates

const int MIN_N = 2;
const int MAX_N = 10;

void makecase(std::ostream& os, int testcase_idx) {
  int H = rnd.next(MIN_N, MAX_N);
  int W = rnd.next(MIN_N, MAX_N);
  os << H << ' ' << W << '\n';
  for(int i = 0; i<H; i++){
    string cat = "[ox]{" + to_string(W) + "," + to_string(W) + "}";
    string S = rnd.next(cat);
    int n = W/2;
    while(n){
      int x = rnd.next(0,3*(W-1)/2);
      if(x<W&&!(i==H-1&&x==W-1)&&S[x]=='x')S[x]='#';
      n--;
    }
    if (i == 0) S[0] = 'o';
    os << S << '\n';
  }

}

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
#ifdef IS_NOT_YUKICODER
    int case_num = 10;
    for (int t = 0; t < case_num; t++) {
      makecase_rime(format("03_random_%02d_r.in", t + 1).c_str(), t);
    }
#else
    int t;
    std::cin >> t;
    // to 0-origin
    --t;
    makecase_yukicoder(format("03_random_%02d", t + 1).c_str(), t);
#endif
    return 0;
}

