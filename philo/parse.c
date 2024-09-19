/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younajja <younajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:43:02 by younajja          #+#    #+#             */
/*   Updated: 2024/09/19 12:01:26 by younajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_digit(char **strs)
{
	int	i;
	int	j;

	i = 1;
	while (strs[i])
	{
		j = 0;
		while (strs[i][j])
		{
			if (!(strs[i][j] >= '0' && strs[i][j] <= '9'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	res;
	int	prev;

	i = 0;
	res = 0;
	prev = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		prev = res;
		res = res * 10 + str[i] - 48;
		if (prev != res / 10)
			return (-1);
		i++;
	}
	return (res);
}

int	check_overflow(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_atoi(av[i]) == -1)
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_flag_mtx(t_data *data)
{
	int	res;

	pthread_mutex_lock(&data->check_died);
	res = data->flag;
	pthread_mutex_unlock(&data->check_died);
	return (res);
}

void	check_and_print(t_philo *philo, char *str)
{
	if (ft_check_flag_mtx(philo->data))
		return ;
	printf("%zu %d %s\n", ft_time() - philo->data->time, philo->id, str);
}
