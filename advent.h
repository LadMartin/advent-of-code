#include <iostream>
#include <array>
#include <vector>
#include <stack>

template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, std::pair<T1,T2> p)
{
  os << p.first << " " << p.second;
  return os;
}
