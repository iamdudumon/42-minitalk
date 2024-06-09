#include "../ft_printf/ft_printf.h"
#include <signal.h>

# define CODE_SIZE  8

typedef struct	s_msg
{
	char		buf[BUFFER_SIZE];
	size_t		len;
	int			clt_pid;
}				t_msg;

void			sigusr_handler(int signo);
unsigned char	to_char(char *binary);
