#include "ft_client.h"
#include <signal.h>
#include <unistd.h>

extern t_data	g_data;

void	ft_kill(int pid, int signo)
{
	if (kill(pid, signo) == -1)
	{
		write(1, "SIUSR Error, Non-existend Pid\n", 31);
		exit(1);
	}
}

void	ack_handler(int signo, siginfo_t *info, void* context)
{
	if (signo != g_data.signal)
	{
		g_data.error = 1;
	}
}

void	send_ack(int pid)
{
	ft_kill(pid, SIGUSR1);
	pause();
	// usleep(300);
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
			ft_kill(pid, SIGUSR1);
		}
		else
		{
			g_data.signal = SIGUSR2;
			ft_kill(pid, SIGUSR2);
		}
		pause();
		// usleep(300);
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
