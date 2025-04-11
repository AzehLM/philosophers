#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

#include "common.h"
#include "philo.h"

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	usleep_enhanced(long long ms)
{
	long long	start;
	long long	elapsed;

	start = get_time();
	while (1)
	{
		elapsed = get_time() - start;
		if (elapsed >= ms)
			break ;
		usleep(100);
	}
}
