/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtcsbza <vtcsbza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 19:16:08 by vtcsbza           #+#    #+#             */
/*   Updated: 2024/06/25 19:35:03 by vtcsbza          ###   ########.fr       */
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

}   t_table;

typedef struct t_philo
{
    unsigned int id;

}   t_philo;


int p_strlen(char *str);


#endif