#include "ft_client.h"
#include <signal.h>

t_data	g_data;

int	main(int argc, char *argv[])
{
	int	pid;
	struct sigaction	handler;

	if (argc != 3)
	{
		ft_printf("잘 못 된 인자입니다. bye bye\n");
		return (0);
	}
	ft_memset(&g_data, 0, sizeof(t_data));
	handler.sa_flags = SA_SIGINFO;
	handler.sa_sigaction = ack_handler;
	sigaction(SIGUSR1, &handler, NULL);
	sigaction(SIGUSR2, &handler, NULL);
	pid = ft_atoi(argv[1]);
	ft_printf("My pid is %d\n", getpid());
	send_ack(pid, argv[1]);
	send_msg(pid, argv[2]);
	ft_printf("client측 송신 완료\n");
}
