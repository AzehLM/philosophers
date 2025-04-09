#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

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

void	cleanup(t_data *data)
{
	int	i;

	if (data == NULL)
		return ;
	if (data->forks != NULL)
	{
		i = 0;
		while (i < data->nb_philos)
		{
			pthread_mutex_destroy(&data->forks[i].gatekeeper);
			i++;
		}
		free (data->forks);
	}
	if (data->philo != NULL)
	{
		i = 0;
		while (i < data->nb_philos)
		{
			pthread_mutex_destroy(&data->philo[i].eater_mutex);
			i++;
		}
		free (data->philo);
	}
	// destroy le mutex de print ?
	// meme chose pour le moniteur de la simulation
}
