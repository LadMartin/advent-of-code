#include "advent.h"
#include <map>
#include <sstream>

using namespace std;

int main() {
  auto line = string{};
  auto stacks = map<int, deque<char>>{};
  auto stacks2 = stacks;

  while (getline(cin, line)) {
    if (line.starts_with("move")) {
      static int foo = [&]{ stacks2 = stacks; return 0;}();

      int what, from, to;
      sscanf(line.c_str(), "move %d from %d to %d", &what, &from, &to);

      auto move = [to, from](auto &stacks, unsigned m, unsigned n) {
        auto &foo2 = stacks[from];
        auto &bar2 = stacks[to];
        for (; m > 0; --m) {
          for (auto i = n; i > 0; --i) {
            bar2.push_front(*(foo2.begin() + i - 1));
          }
          for (auto i = 0u; i < n; ++i) {
            foo2.pop_front();
          }
        }
      };

      move(stacks, what, 1);
      move(stacks2, 1, what);
    } else {
      for (int i = 0; i < line.size(); ++i) {
        if (line[i] == '[') {
          stacks[i / 4 + 1].push_back(line[i + 1]);
        }
      }
    }
  }

  for (const auto &stack : stacks) {
    if (stack.second.size())
      cout << stack.second.front();
  }
  cout << endl;

  for (const auto &stack : stacks2) {
    if (stack.second.size())
      cout << stack.second.front();
  }
  cout << endl;

  return 0;
}
