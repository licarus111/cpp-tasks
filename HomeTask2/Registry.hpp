#pragma once
#include <vector>
#include "Errors.hpp"

template <typename T, int Cap> class Registry {
public:
  void add(const T& item) {
    if (size() >= Cap) { throw CommandError("Too many items here..."); }

    log.push_back(item);
  }

  int size() const { return static_cast<int>(log.size()); }

  const T& operator[](int pos) const { return log.at(pos); }

private:
  std::vector<T> log;
};

template <typename T, int Cap>
std::ostream& operator<<(std::ostream& os, const Registry<T, Cap>& r) {
  for (int i = 0; i < r.size(); ++i) {
    os << r[i] << "\n";
  }
  return os;
}
