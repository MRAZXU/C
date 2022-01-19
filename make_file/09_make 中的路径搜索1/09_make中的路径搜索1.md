# 路径搜索

## VPATH
考虑到实际的项目的源文件不会和头文件放在一起。**所以项目中的makefile必须正确定位源文件和依赖文件。**

特殊的预定义变量**VPATH**
*   用于指示make如何查找文件
*   不同文件夹可作为VPATH的值同时出现
*   文件夹名字之间需要使用**分隔符**进行区分
例如：
`VPATH := $(INC) $(SRC)`
`VPATH := $(INC);$(SRC)`
`VPATH := $(INC):$(SRC)`
皆可
**注意**：
* VPATH只能决定make的搜索路径，无法决定命名的搜索路径
* 对于特定的编译命令，需要独立指定编译搜索路径
`gcc -I include-path`\

```makefile
OBJS := func.o main.o
INC := inc
SRC := src
VPATH := $(INC) $(SRC)
CFLAGS := -I $(INC)

hello.out : $(OBJS)
	@gcc -o $@ $^
	@echo "Target File ==> $@"
	
$(OBJS) : %.o : %.c func.h
	@gcc $(CFLAGS) -o $@ -c $<
```

## vpath
但是VPATH路径中的文件夹中如果有多个同名文件，VPATH会选择第一次搜索到的文件
用**vpath**关键字为不同类型文件指定不同的搜索路径
```makefile
vpath %.h inc
vpath %.c src
```
所以最终的makefile可以为：
```makefile

OBJS := func.o main.o
INC := inc
SRC := src
CFLAGS := -I $(INC)

vpath %.h $(INC)
vpath %.c $(SRC)

hello.out : $(OBJS)
	@gcc -o $@ $^
	@echo "Target File ==> $@"
	
# vpath %.h

$(OBJS) : %.o : %.c func.h
	@gcc $(CFLAGS) -o $@ -c $<

```
此外**vpath**还可以取消搜索
取消.h文件搜索：`vpath %.h`
设置`$(INC)`下.h文件搜索：`vpath %.h $(INC)`



