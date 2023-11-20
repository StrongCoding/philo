/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:12:22 by dnebatz           #+#    #+#             */
/*   Updated: 2023/11/20 19:31:14 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// return 1 if all philosophers have eaten max_eat times
int	get_eaten_meals(t_data *data)
{
	int	i;
	int	ate_enough;

	i = -1;
	ate_enough = 0;
	if (data->max_eat == 0)
		return (0);
	while (++i < data->number_of_philosophers)
	{
		if (data->philo[i].eaten >= data->max_eat)
			ate_enough++;
		// printf("%i has eaten %i times\n\n\n", i, data->philo[i].eaten);
	}
	if (ate_enough == data->number_of_philosophers)
	{
		// printf("All philosophers have eaten %i times\n\n\n", data->max_eat);
		return (1);
	}
	return (0);
}

// checking if any philosopher has died
// or if all philosophers have eaten max_eat times
void	*death_checker(void *data)
{
	int		i;
	int		dead;
	t_data	*data_ptr;

	dead = 0;
	data_ptr = (t_data *)data;
	while (!dead)
	{
		i = -1;
		while (++i < data_ptr->number_of_philosophers)
		{
			// if ((get_time() - data_ptr->philo[i].last_diner >= data_ptr->time_to_die) || get_eaten_meals(data_ptr))
			if (get_time() - data_ptr->philo[i].last_diner >= data_ptr->time_to_die)
			{
				printf("%llu %i died because: %llu - %llu >= %llu\n", get_time(), i, get_time(), data_ptr->philo[i].last_diner, data_ptr->time_to_die);
				dead = 1;
				break ;
			}
			if (get_eaten_meals(data_ptr))
			{
				printf("you ate enough\n");
				dead = 1;
				break ;
			}
		}
		usleep(10000);
	}
	data_ptr->run = 0;
	return (NULL);
}
