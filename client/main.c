#include "ft_client.h"

int main(int argc, char *argv[])
{
    int pid;
    
    if (argc != 3)
    {
        ft_printf("잘 못 된 인자입니다. bye bye\n");
        return (0);
    }
    pid = ft_atoi(argv[1]);
    send_ack(pid, argv[1]);
    send_msg(pid, argv[2]);
    ft_printf("client측 송신 완료\n");
}