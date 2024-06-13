#include "../ft_printf/ft_printf.h"
#include <signal.h>

# define CODE_SIZE  8

typedef struct	s_data
{
	int	signal;
	int	error;

}				t_data;

void	send_msg(int pid, char *msg);
void	send_ack(int pid, char *s_pid);
void	ack_handler(int signo, siginfo_t *info, void* context);
