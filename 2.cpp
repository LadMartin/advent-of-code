#include "advent.h"
using namespace std;

int main() {
  char a, b;
  auto score1 = 0;
  auto score2 = 0;
  constexpr auto t = array{3,1,2,3,1};
  while (cin >> a >> b) {
    int bar = b - 'X'; // 0, 1, 2
    int foo = a - 'A'; // 0, 1, 2
    score2 += 3 * bar + t[foo + bar];

    int x = bar - foo; 
    auto signum = [](int n){ return (abs(n) > 1 ? (n < 0 ? 1 : -1)  : n);};
    score1 += 3 * signum(x) + foo; 
  }
  cout << score1 << endl;
  cout << score2 << endl;
  return 0;
}

