//
// Created by Zhi Wei Gan on 11/25/20.
//
#include "tests.h"

Tester::Tester(){
    // Trees
    SplayTree* vanillaT = new SplayTree();
    TemplateSplayTree* templateT = new TemplateSplayTree();

    trees = new map<string, SplayTree*>();
    trees->insert(make_pair("0: Vanilla", vanillaT)); // We need a name as well as the tree pointer
    trees->insert(make_pair("1: Template", templateT));

    // Tests
    RandomTest* randomTest = new RandomTest();

    tests = new vector<Test*>();
    tests->push_back(randomTest);
}

//======================================================================================================================

void Test::RunOnTrees(map<string, SplayTree *> *trees) {
    cout<<"Base class, something went wrong."<<endl;
}

void Tester::runAllTestsOneTree(SplayTree* tree, string treeName) {
    for(Test* test : *tests) {
        map<string, SplayTree*> tempTrees;
        tempTrees.insert(make_pair(treeName, tree));
        test->RunOnTrees(&tempTrees);
    }
}

void Tester::runAllTestsAllTrees() {
    for(Test* test : *tests) {
        test->RunOnTrees(trees);
    }
}

void Tester::runOneTestAllTrees(Test* test) {
    test->RunOnTrees(trees);
}

void Tester::runOneTestOneTree(SplayTree* tree, Test* test, string treeName) {
    map<string, SplayTree*> tempTrees;
    tempTrees.insert(make_pair(treeName, tree));
    test->RunOnTrees(&tempTrees);
}

