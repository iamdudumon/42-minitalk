#include "ft_client.h"
#include <signal.h>

t_data	g_data;

int	main(int argc, char *argv[])
{
	int	pid;
	struct sigaction	sa;

	if (argc != 3)
	{
		write(1, "Wrong argument. bye bye\n", 25);
		return (0);
	}
	ft_memset(&g_data, 0, sizeof(t_data));
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ack_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pid = ft_atoi(argv[1]);
	write(1, ft_strjoin("My pid is ", ft_itoa(getpid())), 11 + 7);
	write(1, "\n", 1);
	send_ack(pid, argv[1]);
	send_msg(pid, argv[2]);
	write(1, "client측 송신 완료\n", 25);
}
