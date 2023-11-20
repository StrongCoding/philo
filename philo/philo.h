/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 20:31:28 by dnebatz           #+#    #+#             */
/*   Updated: 2023/11/20 18:20:20 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data	t_data;

typedef struct s_philo
{
	pthread_t			thread;
	int					index;
	t_data				*data;
	unsigned long long	last_diner;
	int					should_eat;
	int					dead;
	int					eaten;
}	t_philo;

typedef struct s_data
{
	pthread_mutex_t	*fork;
	int				*fork_val;
	t_philo			*philo;
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				max_eat;
	int				run;
}	t_data;

int					init_struct(t_data *data, int argc, char **argv);
unsigned long long	get_time(void);
int					ft_atoi(const char *str);
void				*death_checker(void *data);
void	sleep_until(unsigned long long timestamp);

#endif