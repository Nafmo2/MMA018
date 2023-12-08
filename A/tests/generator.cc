#include <iostream>
#include "testlib.h"
using namespace std;

const int MIN_A = 1;
const int MAX_A = 1000;

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    for (int t = 0; t < 10; t++) {
        ofstream of(format("02_random_%02d.in", t + 1).c_str());
        int a = rnd.next(MIN_A, MAX_A);
        int b = rnd.next(MIN_A, MAX_A);
        int x = rnd.next(MIN_A, MAX_A);
        of << a << ' ' << b <<" "<< x << '\n';
        of.close();
    }
    return 0;
}

