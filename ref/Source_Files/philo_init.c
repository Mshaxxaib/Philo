/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:32:22 by amalbrei          #+#    #+#             */
/*   Updated: 2022/11/27 16:29:30 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_atoi(char *av, t_philo *philo, t_table *table)
{
	int		sign;
	size_t	i;
	size_t	res;

	i = 0;
	sign = 1;
	res = 0;
	while (av[i] == ' ' || av[i] == '\f' || av[i] == '\n'
		|| av[i] == '\r' || av[i] == '\t' || av[i] == '\v')
		i++;
	if (av[i] == '+' || av[i] == '-')
	{
		if (av[i++] == '-')
			sign *= -1;
	}
	while (av[i] >= '0' && av[i] <= '9')
	{
		res = (res * 10) + (av[i++] - '0');
	}
	if ((res > 4294967295 && sign == 1) || res == 0)
		philo_free(ERR_INPUT, philo, table);
	if ((res > 4294967295 && sign == -1) || res == 0)
		philo_free(ERR_INPUT, philo, table);
	return (res * sign);
}

/**
 * @brief Assigns forks with pointers to philosophers for 
 * easier access to the forks on the table
 * 
 * @param philo Struct containing all information for each individual philosopher
 * @param table Struct containing table variables, available to all philosophers
 */
static void	assign_forks(t_philo *philo, t_table *table)
{
	unsigned int	i;

	i = -1;
	while (++i < table->nop)
	{
		philo[i].lfork = &table->forks[i];
		if (i == table->nop - 1)
			philo[i].rfork = &table->forks[0];
		else
			philo[i].rfork = &table->forks[i + 1];
		philo[i].lmfork = &table->m_forks[i];
		if (i == table->nop - 1)
			philo[i].rmfork = &table->m_forks[0];
		else
			philo[i].rmfork = &table->m_forks[i + 1];
		philo[i].lffork = &table->fo_lock[i];
		if (i == table->nop - 1)
			philo[i].rffork = &table->fo_lock[0];
		else
			philo[i].rffork = &table->fo_lock[i + 1];
	}
}

/**
 * @brief Initializing fork arrays for philosophers to use and lock
 * 
 * @param philo Struct containing all information for each individual philosopher
 * @param table Struct containing table variables, available to all philosophers
 */
static void	fork_init(t_philo *philo, t_table *table)
{
	unsigned int	i;

	table->forks = malloc(sizeof(int) * table->nop);
	if (!table->forks)
		philo_free(ERR_MALLOC, philo, table);
	table->m_forks = malloc(sizeof(int) * table->nop);
	if (!table->m_forks)
		philo_free(ERR_MALLOC, philo, table);
	table->fo_lock = malloc(sizeof(pthread_mutex_t) * table->nop);
	if (!table->fo_lock)
		philo_free(ERR_MALLOC, philo, table);
	i = -1;
	while (++i < table->nop)
	{
		table->forks[i] = false;
		table->m_forks[i] = 0;
		pthread_mutex_init(&table->fo_lock[i], NULL);
	}
	assign_forks(philo, table);
}

/**
 * @brief Initializing the variables for the table struct
 * 
 * @param av 2D array from the command line
 * @param philo Struct containing all information for each individual philosopher
 * @param table Struct containing table variables, available to all philosophers
 * @return t_table* The table struct
 */
static t_table	*table_init(char **av, t_philo *philo, t_table *table)
{
	int	i;

	i = 1;
	table->nop = philo_atoi(av[i++], philo, table);
	table->time_to_die = philo_atoi(av[i++], philo, table);
	table->time_to_eat = philo_atoi(av[i++], philo, table);
	table->time_to_sleep = philo_atoi(av[i++], philo, table);
	if (av[i])
		table->goal = philo_atoi(av[i], philo, table);
	else
		table->goal = 0;
	table->philo_dead = false;
	fork_init(philo, table);
	pthread_mutex_init(&table->dlock, NULL);
	pthread_mutex_init(&table->plock, NULL);
	return (table);
}

/**
 * @brief Initializes all variables needed for the simulation
 * 
 * @param av 2D array from the command line
 * @param philo Struct containing all information for each individual philosopher
 * @return t_table* The struct of the table for proper freeing
 */
t_table	*philo_init(char **av, t_philo *philo)
{
	unsigned int		i;
	t_table				*table_info;

	i = 0;
	table_info = malloc(sizeof(t_table));
	if (!table_info)
		philo_free(ERR_MALLOC, philo, table_info);
	table_info = table_init(av, philo, table_info);
	while (i < table_info->nop)
	{
		philo[i].id = i + 1;
		philo[i].state = SPAWNED;
		if (table_info->goal != 0)
			philo[i].meals = 0;
		else
			philo[i].meals = 1;
		philo[i].t_info = table_info;
		i++;
	}
	return (table_info);
}
