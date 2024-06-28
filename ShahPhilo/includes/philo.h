/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 19:16:08 by vtcsbza           #+#    #+#             */
/*   Updated: 2024/06/28 20:44:45 by mshazaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct t_table
{
    unsigned int nop;
    unsigned int time_to_die;
    unsigned int time_to_eat;
    unsigned int time_to_sleep;
    unsigned int goal;
    bool philo_dead;
}   t_table;

typedef struct t_philo
{
    unsigned int id;

}   t_philo;


int p_strlen(char *str);
int p_atoi(char *av, t_philo *philo, t_table *table);


#endif