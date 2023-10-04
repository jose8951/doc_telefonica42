#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void ft_striteri(char *s, void (*f)(unsigned int, char *))
{
    unsigned int i;
    i = 0;
    if (!s || !f)
        return;

    while (s[i])
    {
        (*f)(i, s + i);
        i++;
    }
}

void aplicar(unsigned int i, char *s)
{
    *s += i;
}

int main(void)
{
    char s[] = "0000000000";
    ft_striteri(s, aplicar);
    printf("%d", !strcmp(s, "0123456789"));
}