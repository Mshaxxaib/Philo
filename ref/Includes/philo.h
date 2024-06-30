/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:59:44 by amalbrei          #+#    #+#             */
/*   Updated: 2022/11/25 15:14:48 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* malloc, free and exit */
# include <stdlib.h>

/* write */
# include <unistd.h>

/* thread commands */
# include <pthread.h>

/* gettimeofday */
# include <sys/time.h>

/* printf */
# include <stdio.h>

/* for boolean stuff*/
# include <stdbool.h>

# define DEFAULT	"\033[0m"
# define YELLOW		"\033[1;33m"
# define GREEN		"\033[1;32m"
# define BLUE		"\033[1;34m"
# define CYAN		"\033[1;36m"
# define RED		"\033[1;31m"
# define PURPLE		"\033[0;35m"

# define ERR_INPUT "Wrong number of arguments or invalid inputs, remember:\n\
./philo no_of_philosophers time_to_die time_to_eat time_to_sleep \
[no_of_philosophers_ate]\n"
# define ERR_MALLOC "Malloc failed\n"
# define ERR_THREAD "Thread creation failed\n"
# define ERR_JOIN "Thread joining failed\n"

// # define EATING 0
// # define SLEEPING 1
// # define THINKING 2
// # define DEAD 3
typedef enum e_philo_state
{
	SPAWNED,
	EATING,
	SLEEPING,
	THINKING,
	DEAD
}	t_state;

typedef struct s_philo{
	unsigned int	id;
	bool			*lfork;
	bool			*rfork;
	unsigned int	*lmfork;
	unsigned int	*rmfork;
	pthread_mutex_t	*lffork;
	pthread_mutex_t	*rffork;
	t_state			state;
	unsigned int	meals;
	pthread_t		thread;
	struct timeval	start;
	struct timeval	life;
	size_t			p_life;
	size_t			p_lastate;
	struct s_time	*clock;
	struct s_table	*t_info;
}	t_philo;

typedef struct s_table{
	unsigned int	nop;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	time_to_die;
	unsigned int	goal;
	unsigned int	*m_forks;
	size_t			p_start;
	bool			philo_dead;
	bool			*forks;
	pthread_mutex_t	*fo_lock;
	pthread_mutex_t	dlock;
	pthread_mutex_t	plock;
}	t_table;

/* philo.c */
void	philo_start_clock(t_philo *p, t_table *t);
void	philo_print_error(char *err);
int		philo_strlen(char *str);

/* philo_init.c */
int		philo_atoi(char *av, t_philo *philo, t_table *table);
t_table	*philo_init(char **av, t_philo *philo);

/* philo_free.c */
void	philo_free(char *err, t_philo *philo, t_table *table);
void	philo_complete(t_table *table, t_philo *philo);

/* philo_solo.c*/
void	philo_solo(t_philo *p);

/* philo_summon.c */
void	philo_unlock_forks(t_philo *philo);
void	philo_lock_forks(t_philo *philo);
size_t	philo_utime(t_philo *person);
void	*philo_table(void *philo);
void	philo_summon(t_philo *philo, t_table *table);

/* philo_life.c */
void	philo_snooze(t_philo *p, unsigned int target);
void	philo_thinker(t_philo *p);
void	philo_slumber(t_philo *p);
void	philo_chowder(t_philo *p);

/* philo_check_pulse.c */
int		philo_check_pulse(t_philo *p);

/* philo_print.c */
void	philo_print(t_philo *philo, t_state state);

/* philo_very_curious */
void	philo_very_curious(t_philo *philo, t_state state);

#endif