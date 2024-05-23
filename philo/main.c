#include "philo.h"

// size_t	get_current_time(void)
// {
// 	struct timeval	time;

// 	gettimeofday(&time, NULL);
// 	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
// }


int main (int ac, char **av)
{
    t_data      data;

    if (check_args(ac, av) || setting_up(&data, av, ac)
        || data_init(&data))
        return (write (2, "Error\n", 6), 1);
    

}