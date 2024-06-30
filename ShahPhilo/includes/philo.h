/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 19:16:08 by vtcsbza           #+#    #+#             */
/*   Updated: 2024/06/30 19:13:06 by mshazaib         ###   ########.fr       */
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

# define ERR_INPUT "Error in input\n"
# define ERR_MALLOC "Error while allocating memory space\n"
# define ERR_THREAD "Error creating thread\n"
# define ERR_JOIN "Error joining thread\n"


typedef enum e_philo_state
{
    SPAWNED,
    EATING,
    SLEEPING,
    THINKING,
    DEAD
}   t_state;

typedef struct t_table
{
    unsigned int nop;
    unsigned int time_to_die;
    unsigned int time_to_eat;
    unsigned int time_to_sleep;
    unsigned int goal;
    unsigned int *m_fork;
    bool *forks;
    bool philo_dead;
    size_t  p_start;
    pthread_mutex_t *fo_lock;
    pthread_mutex_t *dlock;
    pthread_mutex_t *plock;
}   t_table;

typedef struct t_philo
{
    unsigned int id;
    unsigned int meals;
    unsigned int *lmfork;
    unsigned int *rmfork;
    bool *lfork;
    bool *rfork;
    struct t_table *table;
    struct timeval start;
    struct timeval life;
    size_t p_life;
    size_t p_lastate;
    t_state state;
    pthread_t thread;
    pthread_mutex_t *lffork;
    pthread_mutex_t *rffork;

}   t_philo;


int     p_strlen(char *str);
int     p_atoi(char *av, t_philo *philo, t_table *table);
void    philo_free(char **err, t_philo *philo, t_table *table);
void    print_error(char **error);
void    philo_start_clock(t_philo *philo, t_table *table);
size_t  philo_utime(t_philo *philo);
void    philo_solo(t_philo *philo);
void    philo_print(t_philo *philo, t_state state);
int     philo_check_pulse(t_philo *philo);

void    philo_unlock_forks(t_philo *philo);
void    philo_lock_forks(t_philo *philo);

void    philo_spawn(t_philo *philo, t_table *table);
void philo_cleanup(t_table *table, t_philo *philo);

#endif