#include <stdio.h>
#include <stdlib.h>

int binary_search_a(int lst[], int a, int x, int y) {
  if (a <= lst[x]) {
    return x;
  } else if (a > lst[y]) {
    return y + 1;
  } else if (a == lst[y]) {
    return y;
  } else if (a <= lst[(x + y) / 2 + 1] && a > lst[(x + y) / 2]) {
    return (x + y) / 2 + 1;
  } else if (a <= lst[(x + y) / 2]) {
    return binary_search_a(lst, a, x, (x + y) / 2);
  } else {
    return binary_search_a(lst, a, (x + y) / 2 + 1, y);
  }
}

int binary_search_b(int lst[], int a, int x, int y) {
  if (a < lst[x]) {
    return x;
  } else if (a == lst[y]) {
    return y + 1;
  } else if (a >= lst[y]) {
    return y;
  } else if (a < lst[(x + y) / 2 + 1] && a >= lst[(x + y) / 2]) {
    return (x + y) / 2 + 1;
  } else if (a < lst[(x + y) / 2]) {
    return binary_search_a(lst, a, x, (x + y) / 2);
  } else {
    return binary_search_a(lst, a, (x + y) / 2 + 1, y);
  }
}

int range(int lst[], int a, int b, int len) {
  return binary_search_b(lst, b, 0, len - 1) -
         binary_search_a(lst, a, 0, len - 1);
}

int main() {
  int lst[5] = {1, 3, 7, 9, 11};
  int len = 5;
  int a = 0, b = 11;
  printf("%d\n", range(lst, a, b, len));
  return 0;
}
