#ifndef FT_CLIENT_H
# define FT_CLIENT_H

#include <signal.h>
#include "../libft/libft.h"

# define CODE_SIZE  8

void	send_msg(int pid, char *msg);
void	send_ack(int pid);
void	ack_handler(int signo, siginfo_t *info, void* context);

#endif
