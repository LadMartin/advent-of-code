#include <cstdint>
#include <fstream>
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
  auto data = 0;
  auto sum = 0;
  auto max = vector<int>{};
  auto check_sum = [&]() {
    max.push_back(sum);
    sum = 0;
  };
  while (!cin.eof()) {
    if (cin.peek() == '\n') {
      cin.get();
      if (cin.peek() == '\n') {
        check_sum();
      }
    }
    cin >> data;
    sum += data;
  }

  check_sum();

  sort(max.begin(), max.end(), greater<int>{});
  max.resize(3);
  cout << std::accumulate(max.begin(),max.end(), 0) << endl;

}
