#include "ft_client.h"

int main(int argc, char *argv[])
{
    int pid;
    
    if (argc != 3)
        return (0);
    pid = ft_atoi(argv[1]);
    send_msg(pid, argv[2]);
    ft_printf("client측 송신 완료\n");
}