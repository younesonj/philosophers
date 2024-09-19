/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younajja <younajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:43:08 by younajja          #+#    #+#             */
/*   Updated: 2024/09/19 12:01:03 by younajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_routine_monitor(void *arg)
{
	t_philo	*philo;
	t_philo	*curr;
	int		time;

	time = 0;
	philo = (t_philo *)arg;
	curr = philo;
	while (!ft_check_flag_mtx(philo->data))
	{
		pthread_mutex_lock(&philo->eat_mutex);
		if (ft_time() - curr->first_eat > curr->data->time_to_die)
		{
			pthread_mutex_lock(&curr->data->check_died);
			philo->data->flag = 1;
			time = ft_time() - philo->data->time;
			pthread_mutex_unlock(&curr->data->check_died);
			(usleep(2000), printf("%d %d died\n", time, philo->id));
		}
		pthread_mutex_unlock(&philo->eat_mutex);
		curr = curr->next;
		if (!curr)
			curr = philo;
		usleep(200);
	}
	return (NULL);
}

void	ft_free_mutex(t_philo *philo, pthread_mutex_t *forks,
		pthread_t *threads)
{
	pthread_mutex_destroy(&philo->data->check_died);
	while (philo)
	{
		pthread_mutex_destroy(philo->first_fork);
		pthread_mutex_destroy(&philo->eat_mutex);
		philo = philo->next;
	}
	free(forks);
	free(threads);
}

void	free_list(t_philo **list)
{
	t_philo	*curr;
	t_philo	*aux;

	if (!(*list))
		return ;
	curr = *list;
	while (curr != NULL)
	{
		aux = curr->next;
		free(curr);
		curr = aux;
	}
	*list = NULL;
}

void	ft_simulation(t_data **data, t_philo **philos, int limit)
{
	pthread_mutex_t	*forks;
	t_philo			*philo;
	pthread_t		*threads;
	pthread_t		tracker;
	int				i;

	if (ft_handle_cases(*data))
		return ;
	forks = ft_init_forks_and_philos(data, philos, limit);
	if (!forks)
		return ;
	philo = *philos;
	threads = malloc(sizeof(pthread_t) * (*data)->nb_philos);
	i = 0;
	while (philo)
	{
		pthread_create(&threads[i++], NULL, ft_routine_philo, (void *)philo);
		philo = philo->next;
	}
	pthread_create(&tracker, NULL, ft_routine_monitor, (void *)*philos);
	i = 0;
	while (i < (*data)->nb_philos)
		pthread_join(threads[i++], NULL);
	pthread_join(tracker, NULL);
	ft_free_mutex(*philos, forks, threads);
}

int	main(int ac, char **av)
{
	int		limit_meals;
	t_data	*data;
	t_philo	*philo;

	if (ac < 5 || ac > 6 || check_digit(av) || check_overflow(ac, av))
		return (write(1, "Error\n", 6), 1);
	data = init_data(av);
	limit_meals = ft_limit_meals(ac, av);
	if (!data)
		return (1);
	philo = NULL;
	ft_simulation(&data, &philo, limit_meals);
	free_list(&philo);
	free(data);
	return (0);
}
