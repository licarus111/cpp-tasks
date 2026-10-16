#include <iostream>
void Clear(char (&board)[5][10]) {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 10; j++) {
      board[i][j] = ' ';
    }
  }
}
bool Put(char (&board)[5][10]) {
  int x;
  int y;
  char c;
  std::cin >> x >> y >> c;
  if (x < 0 || x >= 10 || y < 0 || y >= 5) {
    return false;
  }
  board[y][x] = c;
  return true;
}
bool Text(char (&board)[5][10]) {
  int x;
  int y;
  char word[20];
  std::cin >> x >> y >> word;
  int len = 0;
  while (word[len] != '\0') {
    len++;
  }

  if (y < 0 || y >= 5 || x < 0 || x + len - 1 >= 10) {
    return false;
  }

  for (int i = 0; i < len; i++) {
    board[y][x + i] = word[i];
  }
  return true;
}
void Print(const char (&board)[5][10]) {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 10; j++) {
      std::cout << board[i][j];
    }
    std::cout << '\n';
  }
}
bool Eq(const char* a, const char* b) {
  while (*a && *a == *b) {
    a++;
    b++;
  }
  return *a == *b;
}
int main() {
  char board[5][10];
  Clear(board);
  char cmd[20];
  while (std::cin >> cmd) {
    if (Eq(cmd, "quit")) {
      return 0;
    }
    if (Eq(cmd, "clear")) {
      Clear(board);
    } else if (Eq(cmd, "put")) {
      if (!Put(board)) {
        std::cout << "error" << '\n';
      }
    } else if (Eq(cmd, "text")) {
      if (!Text(board)) {
        std::cout << "error" << '\n';
      }
    } else if (Eq(cmd, "print")) {
      Print(board);
    }

  }
  return 0;
}
