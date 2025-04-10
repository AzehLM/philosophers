override SRCSDIR	:= srcs/
override SRCS		= $(addprefix $(SRCSDIR), $(SRC))

override TESTDIR	:= test/
override UTILSDIR	:= utils/
override INITDIR	:= init/

SRC	+= $(addsuffix .c, $(MAIN))

override MAIN		:= \
	philosophers \

SRC += $(addprefix $(UTILSDIR), $(addsuffix .c, $(UTILSSRC)))

override UTILSSRC	:= \
	utils \

SRC += $(addprefix $(INITDIR), $(addsuffix .c, $(INITSRC)))

override INITSRC	:= \
	initialization \
	parser \
