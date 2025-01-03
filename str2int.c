#include <assert.h>
#include "str2int.h"
#include "stdio.h"
int str2int(const char *str) {
  int sign = 1;
  int result = 0;

  if (*str == '-'){
    sign = -1;
    str++;
  } else if (*str == '+') {
    str++;
  }

  int count = 0;
  while (*str != '\0') {
    result = result * 10 + (*str - '0');
    count += 1;
    str++;
    assert(sign == -1 && result == -2147483648 || sign == -1 && result >= 0 && count <= 9 || sign == 1 && result >= 0);
  }
  assert(count > 0);
  return result * sign;
}