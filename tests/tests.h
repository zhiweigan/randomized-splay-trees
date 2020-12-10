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



struct result{
    long num_rotations = 0;
    long num_followed = 0;

    result(long rots, long followed) {
        this->num_followed = followed;
        this->num_rotations = rots;
    }

    long getTotal () {
        return (long)((double)(this->num_rotations) * 2.3 + this->num_followed);
    }
};

class Test { // Abstract test class
public:
    virtual map<string, result> RunOnTrees(map<string, SplayTree*>* trees);
    int trial = 1000000;
};

class OneTest : public Test{
public:
    map<string, result> RunOnTrees(map<string, SplayTree*>* trees); // Every test must have a RunOnTrees function
protected:
    void Insert(int n, SplayTree* tree); // Tests
    void Delete(int n, SplayTree* tree);
    void Access(int n, SplayTree* tree);
};

class SplayLineTest : public Test{
public:
    map<string, result> RunOnTrees(map<string, SplayTree*>* trees); // Every test must have a RunOnTrees function
protected:
    void Insert(int n, SplayTree* tree); // Tests
    void Delete(int n, SplayTree* tree);
    vector<pair<int, int>> Access(int n, SplayTree* tree, bool check);
};

class AlternatingDepthNTest : public Test{
public:
    map<string, result> RunOnTrees(map<string, SplayTree*>* trees); // Every test must have a RunOnTrees function
    vector<int> Insert(int n, SplayTree* tree); // Tests
    void Delete(int n, SplayTree* tree, vector<int> inserted);
    void Access(int n, SplayTree* tree, vector<int> inserted);
};

class RandomTest : public Test{
public:
    virtual map<string, result> RunOnTrees(map<string, SplayTree*>* trees); // Every test must have a RunOnTrees function
protected:
    void Insert(int n, SplayTree* tree); // Tests
    void Delete(int n, SplayTree* tree);
    void Access(int n, SplayTree* tree);
};

class ZipfTest : public RandomTest{
public:
    map<string, result> RunOnTrees(map<string, SplayTree*>* trees); // Every test must have a RunOnTrees function
    static vector<double> MakeDist(int n, double zipfS, vector<int> inserted);
private:
    vector<int> Insert(int n, SplayTree* tree);
    void Access(int n, SplayTree* tree, vector<double>* dist);
};


class Tester { // Main testing class
public:
    Tester();

    // Call these functions to test specific trees
    map<string, map<string, result>> runAllTestsOnTreeSuite(string treeSuite = "0a", string optionalSecond = "");
    void runAllTestsOneTree(SplayTree* tree, string treeName = "");
    void runAllTestsAllTrees();
    void runOneTestAllTrees(Test* test);
    void runOneTestOneTree(SplayTree* tree, Test* test, string treeName = "");
    void runAllTestsOnTrees(map<string, SplayTree*> trees);
private:
    map<string, SplayTree*>* trees = nullptr;
    vector<Test*>* tests = nullptr;
    vector<string>* testNames = nullptr;
};

#endif //RANDOMIZED_SPLAY_TREES_TESTS_H
