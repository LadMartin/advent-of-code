#include "advent.h"

using namespace std;

int main() {

  pair<int, int> x,y,p;

  auto is_in = [](auto n, auto r) {
    return n >= r.first && n <= r.second;
  };

  auto check = [](auto x, auto y){
    return x.first <= y.first && x.second >= y.second;
  };

  char dummy;
  while(cin >> x.first >>dummy>>x.second >>dummy>> y.first>> dummy>> y.second)
  {
    auto c2 = is_in(x.first, y) || is_in(x.second, y);
    auto c1 = check(x, y) || check(y,x);

    p.first += c1;
    p.second += c1 || c2;
  }
  cout << p << endl;
  return 0;
}
