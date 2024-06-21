#include "ft_client.h"
#include <signal.h>

void	start_sending_msg(int pid, char *msg)
{
	write(1, ft_strjoin(ft_strjoin("My pid is ", ft_itoa(getpid())), "\n"), 11 + 7 + 1);
	send_ack(pid);
	send_msg(pid, msg);
	write(1, "client측 송신 완료\n", 25);
}

int	main(int argc, char *argv[])
{
	int	pid;
	struct sigaction	sa;

	if (argc != 3)
	{
		write(1, "Wrong argument. bye bye\n", 25);
		return (0);
	}
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sa.sa_sigaction = ack_handler;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	start_sending_msg(argv[1], argv[2]);
}
