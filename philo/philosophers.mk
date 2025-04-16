override SRCSDIR	:= srcs/
override SRCS		= $(addprefix $(SRCSDIR), $(SRC))

override TESTDIR	:= test/
override UTILSDIR	:= utils/
override INITDIR	:= init/
override ROUTINEDIR	:= routine/

SRC	+= $(addsuffix .c, $(MAIN))

override MAIN		:= \
	philosophers \

SRC += $(addprefix $(UTILSDIR), $(addsuffix .c, $(UTILSSRC)))

override UTILSSRC	:= \
	cleanup \
	utils \

SRC += $(addprefix $(INITDIR), $(addsuffix .c, $(INITSRC)))

override INITSRC	:= \
	initialization \
	parser \

SRC += $(addprefix $(ROUTINEDIR), $(addsuffix .c, $(ROUTINESRC)))

override ROUTINESRC	:= \
	actions \
	fork \
	monitoring \
	routine \
	simulation \
