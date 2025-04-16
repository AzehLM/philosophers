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

# define RESET      "\001\033[0m\002"

# define TOOK_FORK	"%d %d has taken a fork"	// with first identifier
# define EATING		"%d %d is eating"			// timestamp_in_ms and second
# define SLEEPING	"%d %d is sleeping\n"		// identifier philosopher ID
# define THINKING	"%d %d is thinkink\n"
# define DIED		"%d %d died\n"

# define MISSING_ARGS "Error: Missing arguments.\n"
# define TOO_MANY_ARGS "Error: Too many arguments.\n"
# define LITERAL_ARGS "Error: An argument contains literal character(s).\n"
# define OOR_ARGS "Error: An argument contains an out of range number.\n"
# define LEAVE_TABLE "Philosophers don't have to eat, they left the table.\n"

# define AVAILABLE 0
# define UNAVAILABLE 1

# define SIM_ON 0
# define SIM_OFF 1

#endif
