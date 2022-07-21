#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) { return *((int *)a) - *((int *)b); }

int binary_search_a(int lst[], int a, int x, int y) {
  if (a <= lst[x]) {
    return x;
  } else if (a > lst[y]) {
    return y + 1;
  } else if (a == lst[y]) {
    return y;
  } else if (a <= lst[(x + y) / 2 + 1] && a > lst[(x + y) / 2]) {
    return (x + y) / 2;
  } else if (a <= lst[(x + y) / 2]) {
    return binary_search_a(lst, a, x, (x + y) / 2);
  } else {
    return binary_search_a(lst, a, (x + y) / 2 + 1, y);
  }
}

int binary_search_b(int lst[], int a, int x, int y) {
  if (a < lst[x]) {
    return x;
  } else if (a == lst[x]) {
    return x + 1;
  } else if (a >= lst[y]) {
    return y + 1;
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
  int m, n;
  scanf("%d %d", &m, &n);
  int lst[m];
  int i = 0;
  for (i = 0; i < m; i++) {
    scanf("%d", &lst[i]);
  }
  qsort(lst, m, sizeof(int), cmp);
  int a, b, x;
  for (i = 0; i < n; i++) {
    scanf("%d %d", &a, &b);
    x = range(lst, a, b, m);
    printf("%d\n", x);
  }
  return 0;
}
