#include "../ft_printf/ft_printf.h"
#include <signal.h>
#include <unistd.h>


char    *to_binary(int c);
void    send_msg(int pid, char *msg);