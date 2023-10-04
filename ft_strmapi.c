#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

// char *ft_strmapi(char const *s, char (*f)(unsigned int, char));

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char *new;
    size_t len;
    size_t i;
    i = 0;
    if (!s)
        return (strdup(""));
    len = strlen(s);
    new = (char *)malloc(sizeof(char) * (len + 1));
    if (!new)
        return (NULL);
    while (i < len)
    {
        new[i] = (*f)(i, s[i]);
        ++i;
    }
    new[i] = 0;
    return (new);
}

char f(unsigned int i, char c)
{
    char str;
    str = c + i;
    return (str);
}

int main(void)
{
    char *s;
    s = ft_strmapi("1234", *f);
    printf("%s", s);
    write(1, "\n", 1);
    s = ft_strmapi("", *f);
    printf("%s", s);
    return (0);
}
