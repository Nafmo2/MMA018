#include <iostream>
#include <string>
#include "testlib.h"
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)

const int MIN_N = 2;
const int MAX_N = 10;

int main(int argc, char** argv) {
    registerValidation(argc, argv);
    int H = inf.readInt(MIN_N, MAX_N, "H");
    inf.readSpace();
    int W = inf.readInt(MIN_N, MAX_N, "W");
    inf.readEoln();
    REP(i,H){
        string cat = "[ox#]{"+to_string(W)+","+to_string(W)+"}";
        string s = inf.readToken(cat, "S");
        if(i==0)
            ensuref(s[0]=='o',"(0,0) not o");
        if(i==H-1)
            ensuref(s[W-1]!='#',"(H,W) is #");
        inf.readEoln();
    }
    inf.readEof();
    return 0;
}
