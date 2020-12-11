cmake_minimum_required(VERSION 3.17)
project(randomized_splay_trees)

set(CMAKE_CXX_STANDARD 14)

add_executable(randomized_splay_trees main.cpp trees/trees.h tests/tests.h trees/splay.cpp tests/uniformTest.cpp tests/tester.cpp tests/zipfTest.cpp trees/2RotScheme1.cpp trees/2RotScheme2.cpp trees/regularBST.cpp tests/stackTest.cpp tests/lineTest.cpp trees/kRotScheme1.cpp trees/kRotDeterministic.cpp trees/even.cpp trees/2RotScheme3.cpp trees/kRotScheme2.cpp trees/kRotScheme3.cpp tests/randomLineTest.cpp scientific.h)