#include <iostream>
#include "testlib.h"
using namespace std;

const int MIN_A = 1;
const int MAX_A = 1000;
int main(int argc, char** argv) {
    registerValidation(argc, argv);
    inf.readInt(MIN_A, MAX_A, "A");
    inf.readSpace();
    inf.readInt(MIN_A, MAX_A, "B");
    inf.readSpace();
    inf.readInt(MIN_A, MAX_A, "X");
    inf.readEoln();
    inf.readEof();
    return 0;
}
