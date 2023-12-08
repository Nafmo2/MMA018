#include <iostream>
#include <string>
#include "testlib.h"
using namespace std;

const int MIN_N = 1;
const int MAX_N = 100000;
int main(int argc, char** argv) {
    registerValidation(argc, argv);
    int n = inf.readInt(MIN_N, MAX_N, "N");
    inf.readEoln();
    string cat = "[A-Z]{"+to_string(n)+","+to_string(n)+"}";
    inf.readToken(cat, "S");
    inf.readEoln();
    inf.readEof();
    return 0;
}
