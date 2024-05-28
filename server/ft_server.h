#include "../ft_printf/ft_printf.h"
#include <signal.h>
#include <unistd.h>

# define BUFFER_SIZE 1024
# define CODE_SIZE  8

typedef struct  s_msg
{
    char        binary[CODE_SIZE + 1];
    char        buf[BUFFER_SIZE];
    int         bin_len;
    int         buf_len;
}               t_msg;

void            sigusr1_handler(int signo);
void            sigusr2_handler(int signo);
unsigned char    to_char(char *binary);