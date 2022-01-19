## VPATH与vpath

如果文件路径上文件是这样：

```
PRJ
|
|--->inc
        |--->func.h
|--->src1
        |--->func.c
|--->src2
        |--->func.c
|--->main.c   
|
```
有如下的makefile:
```makefile
VPATH := src1
CFLAGS := -I inc

vpath %.c src2
vpath %.h inc

app.out : func.o main.o
	@gcc -o $@ $^
	@echo "Target File ==> $@"

%.o : %.c func.h
	@gcc $(CFLAGS) -o $@ -c $<
```
编译出的app.out输出打印的为src2的func.c
```shell
> make
Target File ==> app.out
> ./app.out
void foo() : This file is from src2 ...
```
**vpath优先于VPATH**，如果找不到才会选VPATH
如果还是找不到就要启动隐式规则

## vpath的执行顺序

```makefile
CFLAGS := -I inc

vpath %.c src1
vpath %.c src2

vpath %.h inc

app.out : func.o main.o
	@gcc -o $@ $^
	@echo "Target File ==> $@"

%.o : %.c func.h
	@gcc $(CFLAGS) -o $@ -c $<
```
最终选的是src1
是**自上而下的搜索，如果找不到就找下一个vpath,还是找不到就会跑到隐式规则（避免使用VPATH触发隐式规则）**

## make指定目标文件的最终位置

默认的生成app.out的位置的逻辑:
* 当app.out完全不存在
  * make会在当前目录下生成app.out
* 当app.out存在于根文件以外的文件目录下
  * 如果所有的依赖不变，make不会重新创建app.out
  * 如果依赖更新，make会在当前文件夹下创建app.out

解决方案：GPATH这个特殊变量指定目标文件夹

```makefile
GPATH := src
VPATH := src
CFLAGS := -I inc

app.out : func.o main.o
	@gcc -o $@ $^
	@echo "Target File ==> $@"

%.o : %.c inc/func.h
	@gcc $(CFLAGS) -o $@ -c $<
```
这个时候生成app.out的逻辑:
* 当app.out完全不存在
  * make会在当前目录下生成app.out
* 当app.out存在于根文件以外的文件目录下
  * make会在app.out所在位置的文件夹下的创建及其更新app.out


**工程中注意**
**为编译得到的结果创建独立的文件夹**
**不要在源码的文件夹中生成目标文件**
**尽量使用vpath为不同文件指定搜索路径**
**避免使用VPATH与GVATH（误触隐式规则，这俩最好成对出现）**
