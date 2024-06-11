#include "ft_client.h"
#include <signal.h>
#include <unistd.h>

void	ack_handler(int signo, siginfo_t *info, void* context)
{
	// if (signo == SIGUSR2)
	// {

	// }
}

void	send_ack(int pid, char *s_pid)
{
	kill(pid, SIGUSR1);
	pause();
}

void	send_character(int pid, char ch)
{
	int bit;

	bit = -1;
	while (++bit < CODE_SIZE)
	{
		if ((ch & (1 << bit)) == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		pause();
	}
}

void	send_msg(int pid, char *msg)
{
	while (*msg != '\0')
	{
		send_character(pid, *msg);
		msg++;
	}
	send_character(pid, '\0');
}
