OBJS := func.o main.o

hello.out : $(OBJS)
	@gcc -o $@ $^
	@echo "Target File ==> $@"
	
$(OBJS) : %.o : %.c func.h
	@gcc -o $@ -c $<
#自动搜索
#$(OBJS) : %.o : %.c 
#	@gcc -o $@ -c $^
#头文件没有写入的话，并不会更新对应内容
