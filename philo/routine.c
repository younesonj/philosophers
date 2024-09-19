/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younajja <younajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:42:43 by younajja          #+#    #+#             */
/*   Updated: 2024/09/19 12:30:05 by younajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_takes_forks(t_philo *philo)
{
	if (philo->id % 2)
	{
		pthread_mutex_lock(philo->first_fork);
		check_and_print(philo, "has taken a fork");
		pthread_mutex_lock(philo->second_fork);
		check_and_print(philo, "has taken a fork");
		return ;
	}
	pthread_mutex_lock(philo->second_fork);
	check_and_print(philo, "has taken a fork");
	pthread_mutex_lock(philo->first_fork);
	check_and_print(philo, "has taken a fork");
}

void	ft_eat(t_philo **philo)
{
	check_and_print(*philo, "is eating");
	pthread_mutex_lock(&(*philo)->eat_mutex);
	(*philo)->first_eat = ft_time();
	pthread_mutex_unlock(&(*philo)->eat_mutex);
	ft_usleep((*philo)->data->time_to_eat, (*philo)->data);
}

void	ft_sleeping(t_philo *philo)
{
	check_and_print(philo, "is sleeping");
	ft_usleep(philo->data->time_to_sleep, philo->data);
	check_and_print(philo, "is thinking");
}

void	*ft_routine_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(2000);
	while (philo->limit_meals != 0 && !ft_check_flag_mtx(philo->data))
	{
		ft_takes_forks(philo);
		ft_eat(&philo);
		pthread_mutex_unlock(philo->first_fork);
		pthread_mutex_unlock(philo->second_fork);
		ft_sleeping(philo);
		if (philo->limit_meals != -1)
			philo->limit_meals--;
		if (philo->limit_meals == 0)
		{
			pthread_mutex_lock(&philo->data->check_died);
			philo->data->flag = 1;
			pthread_mutex_unlock(&philo->data->check_died);
		}
		usleep(300);
	}
	return (NULL);
}
