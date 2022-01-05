# 隐式规则

makefile有脚本属性，所以由上到下新的命令会把上面的旧的命令覆盖
* makefi在出现同名目标时
  * 依赖：
    * 所有依赖将合并在一起，成为目标的最终依赖
  * 命令：
    * 当多处出现同一目标命令时，make发出警告
    * 所有之间的命令被最后的命令取代

所有要注意：**include关键字需要确保被包含的文件的同名目标只有依赖，没有命令；否则同名目标的命令将被覆盖**

什么是隐式规则：make提供的一些常用的例行规则实现
当相应目标的规则未提供时，make会使用这些规则(可以理解成make自带的库函数)

```makefile
SRCS := $(wildcard *.c)
OBJS := $(SRCS:.c=.o)

app.out : $(OBJS)
	$(CC) -o $@ $^
	$(RM) $^
	@echo "Target ==> $@"
```
```shell
> make
gcc    -c -o main.o main.c
gcc    -c -o func.o func.c
gcc -o app.out main.o func.o
rm -f main.o func.o
Target ==> app.out
```
所以我们可以看出make默认填写了CC的值
而
```makefile
app.out : $(OBJS)
	$(CC) -o $@ $^
	$(RM) $^
	@echo "Target ==> $@"
```
被make理解成
```makefile
%.o:%.c
    $(CC) -c -o $@ $^
```

隐式规则的执行逻辑：当发现目标依赖不存时
* 尝试通过依赖名逐一查找隐式规则
* 并且通过依赖名推导可能需要的源文件
**但是！！！要尽量避免！！！**

## 隐式规则禁用
* 局部禁用
  * 在makefile中自定义规则
  * 在makefile中定义模式
* 全局禁用
  * make -r

后缀规则了解--一种旧的模式规则
```makefile
app.out : main func.o
	 $(CC) -lstdc++ -o $@ $^
.c.o :
	@echo "my suffix rule"
	$(CC) -o $@ -c $^
.c :
	@echo "my suffix rule"
	$(CC) -o $@ -c $^
```
