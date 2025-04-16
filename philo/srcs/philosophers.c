/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 08:16:11 by gueberso          #+#    #+#             */
/*   Updated: 2025/04/16 08:16:12 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	memset(&data, 0, sizeof(t_data));
	if (parser(ac, av, &data) == -1)
		return (EXIT_FAILURE);
	if (init_simulation(&data) == -1)
		return (EXIT_FAILURE);
	if (simulation_start(&data) == -1)
	{
		cleanup(&data);
		return (EXIT_FAILURE);
	}
	monitor_philos(&data);
	cleanup(&data);
	return (EXIT_SUCCESS);
}
