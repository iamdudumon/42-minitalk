#include "ft_server.h"

t_msg   msg;

int main()
{
    int pid;

    pid = getpid();
    ft_printf("server pid: %d\n", pid);

    signal(SIGUSR1, sigusr_handler);
    signal(SIGUSR2, sigusr_handler);
    ft_memset(&msg, 0, sizeof(t_msg));
    while (1)
        pause();
}