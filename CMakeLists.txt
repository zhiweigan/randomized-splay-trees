cmake_minimum_required(VERSION 3.17)
project(randomized_splay_trees)

set(CMAKE_CXX_STANDARD 14)

add_executable(randomized_splay_trees main.cpp trees/trees.h tests/tests.h trees/vanilla.cpp trees/template.cpp tests/random.cpp tests/tester.cpp tests/zipf.cpp trees/scheme1.cpp trees/scheme2.cpp trees/regularBST.cpp tests/justone.cpp tests/splayline.cpp trees/probabilisticKRot.cpp trees/kRotScheme.cpp trees/evenScheme.cpp trees/scheme3.cpp trees/kRotScheme2.cpp trees/kRotScheme3.cpp tests/alternatingDepthN.cpp)