/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:27:50 by amalbrei          #+#    #+#             */
/*   Updated: 2022/11/27 16:10:39 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Provides the starting time of the program
 * 
 * @param p Philosopher's struct
 * @param t Table's struct
 */
void	philo_start_clock(t_philo *p, t_table *t)
{
	gettimeofday(&p->start, NULL);
	t->p_start = (p->start.tv_sec * 1000) + (p->start.tv_usec / 1000);
}

int	philo_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

void	philo_print_error(char *err)
{
	write(2, err, philo_strlen(err));
	exit (1);
}

/**
 * @brief Checks if the provided numbers in the command line are correct
 * 
 * @param av The inputs to the command line
 * @return int Whether inputs are correct by returning 1 or 
 * incorrect by returning 0
 */
static int	philo_check_error(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!(av[i][j] >= 48 && av[i][j] <= 57))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/* Project's PDF: https://cdn.intra.42.fr/pdf/pdf/65661/en.subject.pdf

DESCRIPTION

Use threads to create a scene which includes philosophers experiencing 
a simulation with given inputs, where they will eat, sleep and think
within that order until one philosopher dies of starvation, ending
the simulation and the program, this project helps understand how
threads work, how their resources are shared and how they are joined
with the main program.

PARAMETERS

int ac: number of arguments from the command line.
char **av: the strings of arguments received from the command line.

NOTES

Inputs include:
	-Number of philosophers
	-Time it takes for philosopher to die from starvation
	-Time it takes to eat
	-Time it takes to sleep
	-(Optional) Number of times philosophers should eat for the
	simulation to end

Valgrind to check on memory leaks.
Valgrind --tool=helgrind to check on data data races, lock violations, deadlocks
and thread leaks 
*/
int	main(int ac, char **av)
{
	t_philo			*philo;
	t_table			*table;

	if (philo_check_error(av) || (ac != 5 && ac != 6))
		philo_print_error(ERR_INPUT);
	philo = malloc(sizeof(t_philo) * philo_atoi(av[1], NULL, NULL));
	if (!philo)
		philo_print_error(ERR_MALLOC);
	table = philo_init(av, philo);
	philo_summon(philo, table);
	philo_complete(table, philo);
	return (0);
}
