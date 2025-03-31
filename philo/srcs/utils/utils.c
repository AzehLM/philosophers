#include <stdio.h>
#include <unistd.h>

#include "philo.h"

void	util(int param)
{
	dprintf(STDERR_FILENO, "%d\n", param - 1);
}
