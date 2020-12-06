//
// Created by Zhi Wei Gan on 11/25/20.
//

#ifndef RANDOMIZED_SPLAY_TREES_TESTS_H
#define RANDOMIZED_SPLAY_TREES_TESTS_H

#include "../trees/trees.h"
#include <time.h>
#include <iomanip>
#include <vector>
#include <map>
#include <random>
#include "VariadicTable.h"

using namespace std;

class Test { // Abstract test class
public:
    virtual void RunOnTrees(map<string, SplayTree*>* trees);
};

// Implement function headers here
class RandomTest : public Test{
public:
    void RunOnTrees(map<string, SplayTree*>* trees); // Every test must have a RunOnTrees function
private:
    static void Insert(int n, SplayTree* tree); // Tests
    static void Mixed(int n, SplayTree* tree);
};

// Implement function headers here
class ZipfTest : public Test{
public:
    void RunOnTrees(map<string, SplayTree*>* trees); // Every test must have a RunOnTrees function
    static vector<double> MakeDist(int n, double zipfS);
private:
    static void Insert(int n, SplayTree* tree, vector<double>* dist); // Tests
    static void Mixed(int n, SplayTree* tree, vector<double>* dist);
};

// Implement function headers here
class HuffmanCoding : public Test{
public:
    void RunOnTrees(map<string, SplayTree*>* trees); // Every test must have a RunOnTrees function
private:
    static void Insert(int n, SplayTree* tree); // Tests
    static void Mixed(int n, SplayTree* tree);
};

class Tester { // Main testing class
public:
    Tester();

    // Call these functions to test specific trees
    void runAllTestsOneTree(SplayTree* tree, string treeName = "");
    void runAllTestsAllTrees();
    void runOneTestAllTrees(Test* test);
    void runOneTestOneTree(SplayTree* tree, Test* test, string treeName = "");
private:
    map<string, SplayTree*>* trees = nullptr;
    vector<Test*>* tests = nullptr;
};

#endif //RANDOMIZED_SPLAY_TREES_TESTS_H
