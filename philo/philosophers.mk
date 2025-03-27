override SRCSDIR	:= srcs/
override SRCS		= $(addprefix $(SRCSDIR), $(SRC))

override TESTDIR	:= test/
override UTILSDIR	:= utils/

SRC += $(addprefix $(TESTDIR), $(addsuffix .c, $(TESTSRC)))

override TESTSRC	:= \
	test \

SRC += $(addprefix $(UTILSDIR), $(addsuffix .c, $(UTILSSRC)))

override UTILSSRC	:= \
	utils \
