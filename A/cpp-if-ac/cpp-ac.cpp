#include <iostream>
using namespace std;
int main() {
  int A, B, X;
  cin >> A >> B >> X;
  if (X % A == 0) {
    cout << X / A * B << endl;
  } else {
    cout << (X / A + 1) * B << endl;
  }
}
