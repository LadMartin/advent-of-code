#include <iostream>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <string_view>
#include <set>
#include <ranges>

using namespace std;

auto make_set(auto foo){
  return set<char>(begin(foo), end(foo));
}

void do_set(auto foo, auto bar, auto it_out) {
  std::ranges::set_intersection(make_set(foo), make_set(bar), it_out);
}

int main() {
  auto p1 = 0, p2 = 0, i = 0;
  auto arr = array<int, 52>()

  auto points = [](auto x) { return islower(x) ? x - 'a' + 1 : x - 'A' + 27; };

  while(cin >> lines[i % size]) {
    auto& line = lines[i % size];
    auto mid = begin(line) + (line.size() / 2);
    auto out = vector<char>{};
    do_set(string_view(begin(line), mid), string_view(mid, end(line)), back_inserter(out));
    p1 += points(out.front());

    if (i % 3 == 2){
      out.clear();
      auto out2 = vector<char>{};
      do_set(lines[0], lines[1], back_inserter(out));
      do_set(lines[2], out, back_inserter(out2));
      p2 += points(out2.front());
    }
    i++;
  }
  cout << p1 << '\n' << p2 << endl;
}

