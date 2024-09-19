/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younajja <younajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:42:49 by younajja          #+#    #+#             */
/*   Updated: 2024/09/19 12:28:13 by younajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_time(void)
{
	struct timeval	tv;
	size_t			time;

	gettimeofday(&tv, NULL);
	time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (time);
}

void	ft_usleep(size_t time, t_data *data)
{
	size_t	diff;

	(void)data;
	diff = ft_time();
	while (1)
	{
		if (ft_time() - diff >= time)
			break ;
		usleep(50);
		if (ft_check_flag_mtx(data))
			return ;
	}
}

int	ft_limit_meals(int ac, char **av)
{
	if (ac == 6)
		return (ft_atoi(av[5]));
	return (-1);
}

int	ft_handle_cases(t_data *data)
{
	if (data->nb_philos > 1)
		return (0);
	else if (data->nb_philos == 0)
		return (1);
	else
	{
		printf("0 1 has taken a fork\n");
		ft_usleep(data->time_to_die, data);
		printf("%zu 1 died\n", data->time_to_die);
	}
	return (1);
}

void	ft_insert_philo(t_philo **philos, t_philo *curr)
{
	t_philo	*tmp;

	if (!(*philos))
	{
		*philos = curr;
		return ;
	}
	tmp = *philos;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = curr;
}
