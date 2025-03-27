override SRCSDIR	:= srcs/
override SRCS		= $(addprefix $(SRCSDIR), $(SRC))

override TESTDIR	:= test/
override UTILSDIR	:= utils/

SRC	+= $(addsuffix .c, $(MAIN))

override MAIN		:= \
	philosophers \

SRC += $(addprefix $(UTILSDIR), $(addsuffix .c, $(UTILSSRC)))

override UTILSSRC	:= \
	utils \
