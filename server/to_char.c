#include "ft_server.h"

unsigned char   to_char(char *binary)
{
    int c;
    int two;
    int i;

    c = 0;
    two = 1;
    i = 7;
    while (i >= 0)
    {
        if (binary[i] == '1')
            c += two;
        i--;
        two *= 2;
    }
    return (c);
}