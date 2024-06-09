#include "ft_client.h"

void	send_ack(int pid, char *s_pid)
{
	send_msg(pid, s_pid);
	pause();
}

void	send_signal(int pid, char ch)
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
		usleep(300);
	}
}

void	send_msg(int pid, char *msg)
{
	while (*msg != '\0')
	{
		send_signal(pid, *msg);
		msg++;
	}
	send_signal(pid, '\0');
}
