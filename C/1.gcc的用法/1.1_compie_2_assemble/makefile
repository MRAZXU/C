CC := gcc
RM := rm -fr
CURR := $(shell pwd)

OUT := out
TARGET_FILE := $(addprefix $(CURR)/,$(OUT))

SRCS := $(wildcard *.c)

i_FILE := $(SRCS:.c=.i)
s_FILE := $(SRCS:.c=.s)
o_FILE := $(SRCS:.c=.o)
a_FILE := $(SRCS:.c=.a)

 
.PHONY : preprocess compile assemble all rebuild clean

preprocess :
	mkdir $(TARGET_FILE)
	$(CC) -E $(SRCS) -o  $(addprefix $(TARGET_FILE)/,$(i_FILE))
compile : preprocess
	$(CC) -S $(addprefix $(TARGET_FILE)/,$(i_FILE)) -o $(addprefix $(TARGET_FILE)/,$(s_FILE))
assemble : compile
	$(CC) -C $(addprefix $(TARGET_FILE)/,$(s_FILE)) -o $(addprefix $(TARGET_FILE)/,$(o_FILE))
	
all : assemble

rebuild : clean all

clean :
	$(RM) $(TARGET_FILE)