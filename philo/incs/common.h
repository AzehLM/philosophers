#ifndef COMMON_H
# define COMMON_H

# define BLUE		"\001\033[1;34m\002"
# define BOLD_RED	"\001\033[1;31m\002"
# define CYAN		"\001\033[1;36m\002"
# define GREEN		"\001\033[1;32m\002"
# define PURPLE		"\001\033[0;35m\002"
# define RED		"\001\033[0;31m\002"
# define WHITE_BOLD	"\001\033[1;37m\002"
# define YELLOW		"\001\033[1;33m\002"

# define TOOK_FORK	"%d %d has taken a fork"	// with first identifier
# define EATING		"%d %d is eating\n"			// timestamp_in_ms and second
# define SLEEPING	"%d %d is sleeping\n"		// identifier philosopher ID
# define THINKING	"%d %d is thinkink\n"
# define DIED		"%d %d died\n"

#endif
