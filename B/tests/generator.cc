#include <iostream>
#include <cassert>
#include <string>
#include "testlib.h"
using namespace std;

const int MIN_N = 1;
const int MAX_N = 100000;

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    for (int t = 0; t < 10; t++) {
        ofstream of(format("02_random_%02d.in", t + 1).c_str());
        int n = rnd.next(MIN_N, MAX_N);
	string cat = "[A-Z]{"+to_string(n)+","+to_string(n)+"}";
	string s = rnd.next(cat);
        //int b = rnd.next(MIN_A, MAX_A);
        //int x = rnd.next(MIN_A, MAX_A);
        of << n << '\n' << s << '\n';
        of.close();
    }
    return 0;
}

