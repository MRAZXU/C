# makefile的简单结构

1. 作为makefile其简要书写结构如下：
```makefile
targets: prerequisites;command1
    command2
```
targets：
&emsp;* 通常为需要生成的目标文件名
&emsp;* make 需要执行的命令名称
prerequisites：
&emsp;* 当前目标所依赖的目标或者文件
command：
&emsp;* 完成目标所需要执行的命令

```makefile
hello.out all : func.o main.o
	gcc -o hello.out func.o main.o
	
func.o : func.c
	gcc -o func.o -c func.c
	
main.o : main.c
	gcc -o main.o -c main.c
clean :
	rm -f main.o 
```



2. 这里要注意的是：
&emsp;1. 为了提高可读性，可以使用"\"符号将一行一分为二
&emsp;2. tab键这种问题就没必要说了吧
&emsp;3. "@"将命令去除回显功能
```makefile
all : test
	echo "make all"
#@取消echod的回显	
test :
	@echo "make test"
```

