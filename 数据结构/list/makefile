export BASE = $(shell pwd)
TARGET := list
BUILD_DIR := $(BASE)/build

# $(wildcard $(DIR)/*type)
# 获取 $(DIR) 下的type类型文件
# $(notdir _names)
# 去除_names中每一个文件的路径前缀
# $(patsubst _pattern, replacement,_text)
# 将 _text中符合_pattern部分替换为replacement
# $(addprefix <prefix>,<names>)
# 作用：给名字列表 names 中的每一个名字增加前缀 prefix


C_FILES := $(wildcard $(BASE)/*.c)
OBJS := $(notdir $(patsubst %.c,%.o,$(C_FILES)))
#类似于下面表示
# 根据源文件列表生成目标文件列表（变量的值替换）
# C_OBJS := $(C_FILES:.c=.o)
C_OBJS := $(addprefix $(BUILD_DIR)/,$(notdir $(C_FILES:.c=.o)))


CC := gcc
INCLUDE := -I$(BASE)/include/
CFLAGS := -g -Wall -std=c99 -O2 $(INCLUDE)

DEBUG ?= $(C_OBJS)

$(TARGET) : $(C_OBJS) 
	$(CC) -o $@ $^

$(C_OBJS) : $(BUILD_DIR)/%.o :%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ -c $^

.PHONY : rebuild clean all

rebuild : clean all

all : $(TARGET) 
	@echo "Success! Target ==> $(TARGET)"

clean :
	$(RM) -rf $(BUILD_DIR)

debug:
	$(info $(DEBUG))
