#include "../ft_printf/ft_printf.h"
#include <signal.h>
#include <unistd.h>

void    sigusr1_handler(int signo);
void    sigusr2_handler(int signo);