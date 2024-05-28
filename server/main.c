#include "ft_server.h"

t_msg   msg;

int main()
{
    int i;
    int pid;

    pid = getpid();
    ft_printf("server pid: %d\n", pid);

    signal(SIGUSR1, sigusr_handler);
    signal(SIGUSR2, sigusr_handler);
    ft_memset(&msg, 0, sizeof(t_msg));
    i = 0;
    while(1)
    {
        sleep(1);
    }
}