#include "philo.h"

// size_t	get_current_time(void)
// {
// 	struct timeval	time;

// 	gettimeofday(&time, NULL);
// 	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
// }

// size_t  get_time(int d)
// {
//     struct timeval tv;

//     gettimeofday(&tv, NULL);

//     if (d == 1) //sec
//         return (tv.tv_sec + (tv.tv_usec / 1000000));
//     else if (d == 2) // ms
//         return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
//     else if (d == 3) // micro
//         return ((tv.tv_sec * 1000000) + tv.tv_usec);
//     return (42);
// }

// int wait_threads_crtd(t_data   *data)
// {
//     int res;
//     pthread_mutex_lock(&data->data_mutex);
//     res = data->all_phl_crt;
//     pthread_mutex_unlock(&data->data_mutex);
//     return (res);
// }

// int is_finished(t_data *data)
// {
//     int res = 0;
//     pthread_mutex_lock(&data->data_mutex);
//     res = data->end;
//     pthread_mutex_unlock(&data->data_mutex);
//     return (res);
// }

// int check_is_finished(size_t usec, t_data *data)
// {
//     size_t  start = get_time(3);// micro-second

//     while (/* condition */)
//     {
//         if (is_finished(data))
//     }
    
// }

// void    *routine(void   *data_philo)
// {
//     t_philo *philo;

//     philo = (t_philo *)data_philo;
    
//     while (wait_threads_crtd(&philo->data) == 1)
//         ;
    

//     while (is_finished(&philo->data) == 1)
//     {
//         if (philo->full == 0)
//             break;
//     }
// }


// int insert_philos(t_data *data)
// {
//     int i = 0;
//     while (i < data->nb_philo)
//     {
//         if (pthread_create(&data->philosophers[i].thread_id, NULL, &routine
//             , &data->philosophers[i]) != 0);
//             return (write(1, "Error in pthread_create function", 32));
        
//     }

//     data->time_start = get_time(2);

//     pthread_mutex_lock(&data->data_mutex);
//     data->all_phl_crt = 0;
//     pthread_mutex_unlock(&data->data_mutex);



//     i = 0;
//     while (i < data->nb_philo)
//     {
//         if (pthread_join(data->philosophers[i].thread_id, NULL) != 0);
//             return (write(1, "Error in pthread_create function", 32));
//         i++;
//     }


        
// }


int main (int ac, char **av)
{
    t_data      data;

    if (check_args(ac, av) || setting_up(&data, av, ac)
        || initialization(&data))
        return (write (2, "Error\n", 6), 1);


    int i = 0;
    while (i < data.nb_philo)
    {
        printf("nb_philo = %d | first_fork_id = %d | second_fork_id = %d\n", data.philosophers[i].philo_id, data.philosophers[i].first_fork->fork_id, data.philosophers[i].second_fork->fork_id);
        i++;
    }

}