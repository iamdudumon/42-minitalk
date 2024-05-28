#include "ft_client.h"

char    *reverse_str(char *str)
{
    char    *reverse;
    size_t  len;
    size_t  i;

    len = ft_strlen(str);
    reverse = (char *)malloc(sizeof(char) * (len + 1));
    if (!reverse)
        return (0);
    i = 0;
    while (i < len)
    {
        reverse[i] = str[len - 1 - i];
        i++;
    }
    reverse[i] = '\0';
    return (reverse);
}

char    *to_binary(int c)
{
    char    *binary;
    int     i;

    binary = (char *)malloc(sizeof(char) * 9);
    if (!binary)
        return (0);
    i = 0;
    while(1)
    {
        binary[i] = c % 2 + '0';
        c /= 2;
        i++;
        if (c == 0)
            break ;
    }
    while(i < 8)
        binary[i++] = '0';
    binary[i] = '\0';
    return (reverse_str(binary));
}
