# 表示cmake的最低版本
cmake_minimum_required (VERSION 2.6)

# 表示目前编译的项目
project (myproject)

# 表示当前编译使用c++14版本来编译程序
set(CMAKE_CXX_FLAGS "-std=c++11")

#设置编译器编译模式：
set( CMAKE_BUILD_TYPE "Debug")

#编译生成库文件
add_library(myproject_shared SHARED src/baidu/baidu.cpp src/test/test.cpp src/math/math.cpp
            src/database/database.cpp src/leetcode/leetcode.cpp src/thread/thread.cpp)

# 表示项目的执行程序
add_executable(myproject src/main.cpp)
target_link_libraries(myproject myproject_shared)
