#include "ft_client.h"
#include <signal.h>
#include <unistd.h>

extern t_data	g_data;

void	ack_handler(int signo, siginfo_t *info, void* context)
{
	if (signo != g_data.signal)
	{
		g_data.error = 1;
	}
}

void	send_ack(int pid, char *s_pid)
{
	kill(pid, SIGUSR1);
	pause();
}

int	send_character(int pid, char ch)
{
	int bit;

	bit = -1;
	g_data.error = 0;
	while (++bit < CODE_SIZE)
	{
		if ((ch & (1 << bit)) == 0)
		{
			g_data.signal = SIGUSR1;
			if (kill(pid, SIGUSR1) == -1)
				ft_printf("SIGUSR1 Error\n");
		}
		else
		{
			g_data.signal = SIGUSR2;
			if (kill(pid, SIGUSR2) == -1)
				ft_printf("SIGUSR2 Error\n");
		}
		pause();
	}
	return (g_data.error);
}

void	send_msg(int pid, char *msg)
{
	while (*msg != '\0')
	{
		// if (send_character(pid, *msg))
		// {
		// 	ft_printf("error~\n");
		// 	while (send_character(pid, 21));
		// 	continue ;
		// }
		send_character(pid, *msg);
		msg++;
	}
	send_character(pid, '\0');
}
