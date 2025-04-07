#include <limits.h>

#include "common.h"
#include "philo.h"

/**
 * Decision a prendre ici :
 * Est-ce que j'accepte aussi les negatifs ? Je vois pas l'interet
 * Est-ce que j'accepte des nombres > INT_MAX ? Je vois pas l'interet non plus
 * Est-ce que j'accepte les signes ? Je vois pas l'interet -> Pourquoi avoir -X philos ? Pourquoi avoir un temps negatif ? Pourquoi accepter + si on n'accepte pas -
 * Est-ce que j'accepte les white_spaces ? Pourquoi pas
 * Est-ce que je rend le code plus propre en important isspace de la libft ? Pourquoi pas
 */
int	atou(const char *str)
{
	unsigned long	num;
	int				i;

	num = 0;
	i = 0;
	if (!str || !*str)
		return (-1);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	if (!str[i] || str[i] < '0' || str[i] > '9')
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

int	literal_check(char **av)
{
	static int	i = 1;
	int			j;

	while (av[i])
	{
		j = 0;
		while (av[i][j] && av[i][j] == ft_isdigit(av[i]))
	}
}

int	check_params_value(char **av, t_data *data)
{
	if (data->nb_philos <= 0 || data->tt_die <= 0 || data->tt_eat <= 0 \
		|| data->tt_sleep <= 0 || data->nb_meal < 0)
	{
		printf("error message, probably range error");
		return (-1);
	}
	literal_check(av);
	return (0);
}

/**
 * Next step: creer la structure principale qui stock les donnees, en commencant par le parsing des arguments.
 *
 */
int	parser(int ac, char **av, t_data * data)
{
	if (ac != 5 || ac != 6)
	{
		if (ac < 5)
			printf(MISSING_ARGS);
		else
			printf(TOO_MANY_ARGS);
		return (-1);
	}
	data->nb_philos = atou(av[1]);
	data->tt_die = atou (av[2]);
	data->tt_eat = atou(av[3]);
	data->tt_sleep = atou(av[4]);
	if (ac == 6)
		data->nb_meal = atou(av[5]);
	else
		data->nb_meal = 0;
	if (check_params_value(data) == -1)
		return (-1);
	if (/* si ac different de 4 ou 5 (5 ou 6),on degage*/)
	//Si c'est pas le cas on convertis chaque valeur,
	if (/*il y a un 6e arg on le convertis*/)
	// check si une de ces valeurs est a -1, si c'est le cas message d'erreur de parsing general
	// en renvoie au main, si erreur il y a on renvoie -1 apres le message d'erreur.
}
