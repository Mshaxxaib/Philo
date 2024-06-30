/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 19:19:23 by vtcsbza           #+#    #+#             */
/*   Updated: 2024/06/30 19:13:24 by mshazaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void philo_start_clock(t_philo *philo, t_table *table)
{
    gettimeofday(&philo->start, NULL);
    table->p_start = (philo->start.tv_sec * 1000) + (philo->start.tv_usec / 1000);
}

void print_error(char **error)
{
    write(2, error, p_strlen(error));
    exit(1);
}

int philo_num_check(char **av)
{
    int i;
    int j;
    
    i = 1;
    while(av[1])
    {
        j = 0;
        while(av[i][j])
        {
            if(!(av[1][i] >= 48 && av[1][i] <= 57))
                return(1);
            j++;
        }
        i++;
    }
    return(0);
}

int main(int ac, char **av)
{
    t_philo *philo;
    t_table *table;

    if(philo_num_check(av) && av != 5 || av != 6)
        print_error(ERR_INPUT);
    philo = malloc(sizeof(t_philo) * p_atoi(av[1], NULL, NULL));
    if(!philo)
        print_error(ERR_MALLOC);
    table = philo_init(av, philo);
    philo_spawn(philo, table);
    philo_cleanup(philo, table);
    return (0);
}