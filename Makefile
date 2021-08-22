#################################################
############# c++工程makefile文件 ###############
############# 作者：孙德鑫 #######################
############# 时间：2021/8/7 ####################

# 1设置编译器
CC = g++
CXXFLAGS = -std=c++11 -Wall -g

# 2设置变量
APPNAME = bin/project
objects = obj/main.o obj/list.o obj/math.o obj/database.o obj/test.o \
          obj/baidu.o obj/leetcode.o obj/thread.o

# 3执行命令
## 1链接过程(.o->project)
#all: $(APPNAME)
$(APPNAME):$(objects)
	$(CC) -o $(APPNAME) $(objects)

## 2编译过程(.cpp->.o)
obj/main.o:src/main.cpp
	$(CC) $(CXXFLAGS) -o $@ -c $< 
obj/list.o:src/list/list.cpp
	$(CC) $(CXXFLAGS) -o $@ -c $<
obj/database.o:src/database/database.cpp
	$(CC) $(CXXFLAGS) -o $@ -c $<
obj/math.o:src/math/math.cpp
	$(CC) $(CXXFLAGS) -o $@ -c $<
obj/test.o:src/test/test.cpp
	$(CC) $(CXXFLAGS) -o $@ -c $<
obj/baidu.o:src/baidu/baidu.cpp
	$(CC) $(CXXFLAGS) -o $@ -c $<
obj/leetcode.o:src/leetcode/leetcode.cpp
	$(CC) $(CXXFLAGS) -o $@ -c $<
obj/thread.o:src/thread/thread.cpp
	$(CC) $(CXXFLAGS) -o $@ -c $<
# 4清除命令
clean:
	rm -rf $(objects) $(APPNAME)