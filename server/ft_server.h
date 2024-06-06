#include "../ft_printf/ft_printf.h"
#include <signal.h>

# define CODE_SIZE  8

typedef struct  s_msg
{
    char        binary[CODE_SIZE + 1];
    char        buf[BUFFER_SIZE];
    int         bin_len;
    int         buf_len;
    int         seg_no;
}               t_msg;

void            sigusr_handler(int signo);
unsigned char   to_char(char *binary);