#include <iomanip>
#include <iostream>
double Average(const int* arr, int n) {
  double sum = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
  }
  return sum / n;
}
int Min(const int* arr, int n) {
  int min = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] < min) {
      min = arr[i];
    }
  }
  return min;
}
int Max(const int* arr, int n) {
  int max = arr[0];
  for (int i = 0; i < n; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  return max;
}
int Cold(const int *arr, int n) {
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] < 0) {
      cnt++;
    }
  }
  return cnt;
}
int main() {
  int n;
  std::cin >> n;
  int* arr = new int[n];
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }
  std::cout << std::fixed << std::setprecision(1) << Average(arr, n) << '\n';
  std::cout << Min(arr, n) << ' ' << Max(arr, n) << '\n';
  std::cout << Cold(arr, n) << '\n';

  delete[] arr;

  return 0;
}

