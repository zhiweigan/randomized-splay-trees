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

class OneTest : public Test{
public:
    void RunOnTrees(map<string, SplayTree*>* trees); // Every test must have a RunOnTrees function
protected:
    void Insert(int n, SplayTree* tree); // Tests
    void Delete(int n, SplayTree* tree);
    void Access(int n, SplayTree* tree);
};

class SplayLineTest : public Test{
public:
    void RunOnTrees(map<string, SplayTree*>* trees); // Every test must have a RunOnTrees function
protected:
    void Insert(int n, SplayTree* tree); // Tests
    void Delete(int n, SplayTree* tree);
    void Access(int n, SplayTree* tree);
};

class RandomTest : public Test{
public:
    void RunOnTrees(map<string, SplayTree*>* trees); // Every test must have a RunOnTrees function
protected:
    void Insert(int n, SplayTree* tree); // Tests
    void Delete(int n, SplayTree* tree);
    void Access(int n, SplayTree* tree);
};

class ZipfTest : public RandomTest{
public:
    void RunOnTrees(map<string, SplayTree*>* trees); // Every test must have a RunOnTrees function
    static vector<double> MakeDist(int n, double zipfS);
private:
    void Access(int n, SplayTree* tree, vector<double>* dist);
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
