#include "ft_client.h"

void    send_signal(int pid, char *binary)
{
    while (*binary)
    {
        if (*binary == '0')
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        usleep(500);
        binary++;
    }
}

void    error_handler()
{

}


void    send_msg(int pid, char *msg)
{
    char    *binary;
    
    while (*msg != '\0')
    {
        binary = to_binary(*msg);
        if (!binary)
            error_handler();
        send_signal(pid, binary);
        free(binary);
        msg++;
    }
    send_signal(pid, "00000000");
}