#include <stdlib.h>


int ft_strlen(const char *str)
{
    int i = 0;
    while(str[i] != '\0')
        i++;
    return i;
}


char *ft_strjoin(char const *s1, char const *s2)
{
    const char *n1 = s1;
    const char *n2 = s2;

    if(!s1 || !s2)
        return NULL;
    char *str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if (!str )
        return NULL;
    int i = 0;
    while(*n1)
    {
        str[i] = *n1;
        i++;
        n1++;
    }
    while(*n2)
    {
        str[i] = *n2;
        i++;
        n2++;
    }
    str[i] = '\0';
    return str;
}




char *ft_strchr(const char *s, int c)
{
    int i = 0;

    if (!s)
        return NULL;

    while (s[i] != '\0')
    {
        if (s[i] == (char)c)
            return (char *)(s + i);
        i++;
    }

    if (c == '\0')
        return (char *)(s + i);

    return NULL;
}