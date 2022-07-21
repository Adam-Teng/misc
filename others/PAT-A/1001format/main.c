#include <stdio.h>
#include <string.h>

int main() {
  int num[10];
  int a, b, sum;
  scanf("%d%d", &a, &b);
  sum = a + b;
  if (sum < 0) {
    printf("-");
    sum = -sum;
  }
  int len = 0;
  if (sum == 0) {
    num[len++] = 0;
  }
  while (sum) {
    num[len++] = sum % 10;
    sum /= 10;
  }
  int k;
  for (k = len - 1; k >= 0; k--) {
    printf("%d", num[k]);
    if (k > 0 && k % 3 == 0) {
      printf(",");
    }
  }
  printf("\n");
  return 0;
}
