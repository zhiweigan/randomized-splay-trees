//
// Created by Zhi Wei Gan on 11/25/20.
//
#include "tests.h"

Tester::Tester(){
    // Trees
    BST* bst = new BST();
    SplayTree* vanillaT = new SplayTree();
    Scheme1SplayTree* s1_10 = new Scheme1SplayTree();
    Scheme2SplayTree* s2_1 = new Scheme2SplayTree();
//    TemplateSplayTree* templateT = new TemplateSplayTree();

    trees = new map<string, SplayTree*>();
    trees->insert(make_pair("0: BST", bst)); // We need a name as well as the tree pointer
    trees->insert(make_pair("1: Vanilla", vanillaT));
    trees->insert(make_pair("2: Scheme 1, p = 2^-10", s1_10));
    trees->insert(make_pair("3: Scheme 2, p = 2^-1", s2_1));
//    trees->insert(make_pair("1: Template", templateT));

    // Tests
    RandomTest* randomTest = new RandomTest();
    ZipfTest* zipfTest = new ZipfTest();
    OneTest* oneTest = new OneTest();
    tests = new vector<Test*>();
    tests->push_back(randomTest);
    tests->push_back(zipfTest);
    tests->push_back(oneTest);
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

