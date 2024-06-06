#include "ft_client.h"

void send_ack(int pid)
{
    kill(pid, SIGUSR1);
}

void    send_signal(int pid, char ch)
{
    int bit;

    bit = 0;
    while (bit < CODE_SIZE)
    {
        if ((ch & (1 << bit)) == 0)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        bit++;
        usleep(100);
    }
}

void    send_msg(int pid, char *msg)
{
    while (*msg != '\0')
    {
        send_signal(pid, *msg);
        msg++;
    }
    send_signal(pid, '\0');
}