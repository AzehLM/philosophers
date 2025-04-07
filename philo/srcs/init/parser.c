#include <limits.h>
#include <stdio.h>

#include "common.h"
#include "philo.h"

static int	atoi_strict(const char *str)
{
	unsigned long	num;
	int				i;

	num = 0;
	i = 0;
	if (!str || !*str)
		return (-1);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		if (num > INT_MAX)
			return (-1);
		i++;
	}
	if (str[i])
		return (-1);
	return ((int)num);
}

static inline int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

static int	literal_check(char **av)
{
	static int	i = 1;
	int			j;

	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j]) == 0)
			{
				printf(LITERAL_ARGS);
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static int	check_params_validity(char **av, t_data *data)
{
	if (literal_check(av) == -1)
		return (-1);
	if (data->nb_philos <= 0 \
		|| data->tt_die <= 0 || data->tt_eat <= 0 \
		|| data->tt_sleep <= 0 || data->nb_meal < 0)
	{
		printf(OOR_ARGS);
		return (-1);
	}
	return (0);
}

int	parser(int ac, char **av, t_data *data)
{
	if (ac != 5 && ac != 6)
	{
		if (ac < 5)
			printf(MISSING_ARGS);
		else
			printf(TOO_MANY_ARGS);
		return (-1);
	}
	data->nb_philos = atoi_strict(av[1]);
	data->tt_die = atoi_strict (av[2]);
	data->tt_eat = atoi_strict(av[3]);
	data->tt_sleep = atoi_strict(av[4]);
	if (ac == 6)
		data->nb_meal = atoi_strict(av[5]);
	else
		data->nb_meal = 0;
	if (check_params_validity(av, data) == -1)
		return (-1);
	return (0);
}
