#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char *ft_itoa(int n)
{
  int num;
  int count;
  char *str;
  num = n;
  count = 0;
  while (num != 0)
  {
    count++;
    num = num / 10;
  }

  count = count + (n <= 0);
  str = (char *)malloc(sizeof(char) * (count + 1));
  if (!str)
    return (str);
  if (n == 0)
  {
    str[0] = '\0';
    str[1] = '\0';
    return (str);
  }
  str[count] = '\0';
  if (n < 0)
    str[0] = '-';
  while (n != 0)
  {
    str[--count] = (n % 10) * (2 * (n > 0) - 1) + '0';
    n = n / 10;
  }
  return (str);
}

int main(void){
  printf("%s", ft_itoa(0));
  printf("%s\n", ft_itoa(+987654321));
  printf("%s\n", ft_itoa(-123456789));
  printf("%s\n", ft_itoa(2147483647));
  printf("%s\n", ft_itoa(-2147483647 - 1));
  return 0;
}