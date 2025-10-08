#include <ctime>
#include <iostream>

int get_rand_range(int min, int max) {
  return (min + rand() % (max - min + 1));
}

int main() {
  srand(time(0));

  int x;

  for (int i = 0; i < 100000; i++) {
    x = get_rand_range(1, 10);
    std::cout << x << std::endl;
  }
}
