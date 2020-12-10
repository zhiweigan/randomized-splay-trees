//
// Created by Zhi Wei Gan on 11/25/20.
//
#include "tests.h"

Tester::Tester(){
    // Trees
    BST* bst = new BST();
    SplayTree* vanillaT = new SplayTree();


    OneRotSplayTree* oneRot = new OneRotSplayTree();
    ThreeRotSplayTree* threeRot = new ThreeRotSplayTree();
    FourRotSplayTree* fourRot = new FourRotSplayTree();
    EvenSplayTree* even = new EvenSplayTree();

    Scheme2SplayTree* s2_1 = new Scheme2SplayTree();
    randomOneRotSplayTree* oneRotRand = new randomOneRotSplayTree(2);
    Scheme1SplayTree* twoRotRand = new Scheme1SplayTree(2);
    randomThreeRotSplayTree* threeRotRand = new randomThreeRotSplayTree(2);
    randomFourRotSplayTree* fourRotRand = new randomFourRotSplayTree(2);
//    TemplateSplayTree* templateT = new TemplateSplayTree();

    trees = new map<string, SplayTree*>();
    //trees->insert(make_pair("0: BST", bst)); // We need a name as well as the tree pointer
    trees->insert(make_pair("1: Vanilla", vanillaT));
//    trees->insert(make_pair("2a: Rand 1-Rot, p = 2^-1", oneRotRand));
    trees->insert(make_pair("2b: Rand 2-Rot, p = 2^-1", twoRotRand));
    trees->insert(make_pair("2c: Rand 3-Rot, p = 2^-1", threeRotRand));
    trees->insert(make_pair("2d: Rand 4-Rot, p = 2^-1", fourRotRand));

    trees->insert(make_pair("3: Scheme 2, p = 2^-1", s2_1));

//    trees->insert(make_pair("4a: OneRot", oneRot));
    trees->insert(make_pair("4b: Vanilla/TwoRot", vanillaT));
    trees->insert(make_pair("4c: ThreeRot", threeRot));
    trees->insert(make_pair("4d: FourRot", fourRot));

    trees->insert(make_pair("5: EvenScheme", even));
//    trees->insert(make_pair("1: Template", templateT));

    // Tests
    RandomTest* randomTest = new RandomTest();
    ZipfTest* zipfTest = new ZipfTest();
    OneTest* oneTest = new OneTest();
    SplayLineTest* lineTest = new SplayLineTest();
    tests = new vector<Test*>();
    tests->push_back(randomTest);
    tests->push_back(zipfTest);
    tests->push_back(oneTest);
    tests->push_back(lineTest);
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

