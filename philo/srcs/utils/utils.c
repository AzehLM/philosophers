#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

#include "common.h"
#include "philo.h"

time_t	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	usleep_enhanced(time_t ms)
{
	time_t	start;
	time_t	elapsed;

	start = get_time();
	while (1)
	{
		elapsed = get_time() - start;
		if (elapsed >= ms)
			break ;
		usleep(100);
	}
}

void print_status(t_philo *philo, char *status)
{
	time_t	current_time;

	pthread_mutex_lock(&philo->data->mutex_printing);
	pthread_mutex_lock(&philo->data->mutex_sim_state);
	if (philo->data->sim_state == SIM_ON)
	{
		current_time = get_time() - philo->data->start;
		printf("%ld %d %s\n", current_time, philo->id, status);
	}
	pthread_mutex_unlock(&philo->data->mutex_sim_state);
	pthread_mutex_unlock(&philo->data->mutex_printing);
}
