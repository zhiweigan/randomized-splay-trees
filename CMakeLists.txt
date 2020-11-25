cmake_minimum_required(VERSION 3.17)
project(randomized_splay_trees)

set(CMAKE_CXX_STANDARD 14)

add_executable(randomized_splay_trees main.cpp trees/trees.h tests/tests.h trees/vanilla.cpp trees/template.cpp tests/random.cpp tests/tester.cpp)