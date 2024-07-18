/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younajja <younajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:42:05 by younajja          #+#    #+#             */
/*   Updated: 2024/07/18 10:57:14 by younajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *routine(void   *data_philo)
{
    t_philo *philo = (t_philo *)data_philo;

    return (NULL);
}

int     simulation(t_data *data)
{
    if (data->nb_philo == 1 || data->limit_meals == 0)
        return (1);
    
    int i = 0;
    while (i < data->nb_philo)
    {
        if (pthread_create(&data->philosophers->thread_id, NULL, &routine, &data->philosophers[i]))
            return (1);
        i++;
    }
}