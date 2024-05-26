#include "ft_server.h"

int main()
{
    int i;
    int pid;

    pid = getpid();
    ft_printf("server pid: %d\n", pid);

    signal(SIGUSR1, sigusr1_handler);
    signal(SIGUSR2, sigusr2_handler);
    i = 0;
    while(1)
    {
        sleep(1);
        // ft_printf("time: %d\n", i++);
    }
}