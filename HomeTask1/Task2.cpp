#include <iostream>
void Deposit(int& sum) {
  int k;
  std::cin >> k;
  if (k <= 0) {
    std::cout << "error" << '\n';
    return;
  }
  sum += k;
}
void Withdraw(int & sum) {
  int k;
  std::cin >> k;
  if (k <= 0 || k > sum) {
    std::cout << "error" << '\n';
    return;
  }
  sum -= k;
}
void Balance(int& sum) {
  std::cout << sum << '\n';
}
void Reset(int& sum) {
  sum = 0;
}
void Inc(int& sum) {
  sum++;
}
bool eq(const char* a, const char* b) {
  while (*a && *a == *b) {
    a++;
    b++;
  }
  return *a == *b;
}

int main() {
  int sum = 0;
  const char* names[] = {"deposit", "withdraw", "balance", "reset", "inc"};
  void (*funcs[])(int&) = {Deposit, Withdraw, Balance, Reset, Inc};

  char cmd[20];
  while (std::cin >> cmd) {
    if (eq(cmd, "stop")) {
      break;
    }
    int check = 0;
    for (int i = 0; i < 5; i++) {
      if (eq(cmd ,names[i])) {
        funcs[i](sum);
        check = 1;
        break;
      }
    }
    if (check == 0) {
      std::cout << "error" << '\n';
    }
  }
  return 0;
}
