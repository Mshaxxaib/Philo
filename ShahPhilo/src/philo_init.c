/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 20:11:56 by mshazaib          #+#    #+#             */
/*   Updated: 2024/06/28 20:59:07 by mshazaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/// @brief init the values for the table
/// @param av		input
/// @param philo	
/// @param table
/// @return init'ed table
static t_table *table_init(char **av, t_philo *philo, t_table *table)
{
	int i;

	i = 0;
	table->nop = p_atoi(av[i++], philo, table);
	table->time_to_eat = p_atoi(av[i++], philo, table);
	table->time_to_sleep = p_atoi(av[i++], philo, table);
	table->time_to_die = p_atoi(av[i++], philo, table);
	if(av[i])
		table->goal = p_atoi(av[i], philo, table);
	else
		table->goal = 0;
	table->philo_dead = false;
	//	init forks
	//	
}

t_table *philo_init(char **av, t_philo *philo)
{
	unsigned int	i;
	t_table			*table_info;

	i = 0;
	table_info = malloc(sizeof(t_table));
	if(!table_info)
		philo_free(ERR_MALLOC, philo, table_info);
	table_info = table_init(av, philo, table_info);
}