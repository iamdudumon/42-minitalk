#include "../ft_printf/ft_printf.h"
#include <signal.h>

# define CODE_SIZE  8

char    *to_binary(int c);
void    send_msg(int pid, char *msg);