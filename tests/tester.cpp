//
// Created by Zhi Wei Gan on 11/25/20.
//
#include "tests.h"

Tester::Tester(){
    // Deterministic Trees
    BST* bst = new BST();
    auto* vanillaT = new SplayTree();
    auto* even = new EvenSplayTree();
    auto* oneRot = new OneRotSplayTree();
    auto* threeRot = new ThreeRotSplayTree();
    auto* fourRot = new FourRotSplayTree();

    trees = new map<string, SplayTree*>();

    trees->insert(make_pair("0a: BST", bst)); // We need a name as well as the tree pointer
    trees->insert(make_pair("0b: Splay", vanillaT));

    trees->insert(make_pair("0c: Even", even));
    trees->insert(make_pair("0d: 1-Rot", oneRot));
    trees->insert(make_pair("0e: 3-Rot", threeRot));
    trees->insert(make_pair("0f: 4-Rot", fourRot));

    //Randomized Trees

    //Scheme I, p = 1/2
    trees->insert(make_pair("1a: I-Rand-1, 1", new Scheme1_1Rot(2)));
    trees->insert(make_pair("1a: I-Rand-2, 1", new Scheme1_2Rot(2)));
    trees->insert(make_pair("1a: I-Rand-3, 1", new Scheme1_3Rot(2)));
    trees->insert(make_pair("1a: I-Rand-4, 1", new Scheme1_4Rot(2)));

    //Varying p from 1-2^{-8} to 2^{-8}
    for(int i = 0; i <= 8; i++){
        int p = 1<<i;
        trees->insert(make_pair("1b: I-Rand-1, " + to_string(i), new Scheme1_1Rot(p)));
        trees->insert(make_pair("1b: I-Rand-2, " + to_string(i), new Scheme1_2Rot(p)));
        trees->insert(make_pair("1b: I-Rand-3, " + to_string(i), new Scheme1_3Rot(p)));
        trees->insert(make_pair("1b: I-Rand-4, " + to_string(i), new Scheme1_4Rot(p)));
    }
    for(int i = -8; i <= -1; i++){
        int p = 1<<abs(i);
        trees->insert(make_pair("1b: I-Rand-1, " + to_string(i), new Scheme1_1Rot(p, true)));
        trees->insert(make_pair("1b: I-Rand-2, " + to_string(i), new Scheme1_2Rot(p, true)));
        trees->insert(make_pair("1b: I-Rand-3, " + to_string(i), new Scheme1_3Rot(p, true)));
        trees->insert(make_pair("1b: I-Rand-4, " + to_string(i), new Scheme1_4Rot(p, true)));
    }

    //Scheme I, p = 1/2
    trees->insert(make_pair("2a: II-Rand-1, 1", new Scheme2_1Rot(2)));
    trees->insert(make_pair("2a: II-Rand-2, 1", new Scheme2_2Rot(2)));
    trees->insert(make_pair("2a: II-Rand-3, 1", new Scheme2_3Rot(2)));
    trees->insert(make_pair("2a: II-Rand-4, 1", new Scheme2_4Rot(2)));

    //Varying p from 1-2^{-8} to 2^{-8}
    for(int i = 0; i <= 8; i++){
        int p = 1<<i;
        trees->insert(make_pair("2b: II-Rand-1, " + to_string(i), new Scheme2_1Rot(p)));
        trees->insert(make_pair("2b: II-Rand-2, " + to_string(i), new Scheme2_2Rot(p)));
        trees->insert(make_pair("2b: II-Rand-3, " + to_string(i), new Scheme2_3Rot(p)));
        trees->insert(make_pair("2b: II-Rand-4, " + to_string(i), new Scheme2_4Rot(p)));
    }
    for(int i = -8; i <= -1; i++){
        int p = 1<<abs(i);
        trees->insert(make_pair("2b: II-Rand-1, " + to_string(i), new Scheme2_1Rot(p, true)));
        trees->insert(make_pair("2b: II-Rand-2, " + to_string(i), new Scheme2_2Rot(p, true)));
        trees->insert(make_pair("2b: II-Rand-3, " + to_string(i), new Scheme2_3Rot(p, true)));
        trees->insert(make_pair("2b: II-Rand-4, " + to_string(i), new Scheme2_4Rot(p, true)));
    }

    //Scheme I, p = 1/2
    trees->insert(make_pair("3a: III-Rand-1, 1", new Scheme3_1Rot(2)));
    trees->insert(make_pair("3a: III-Rand-2, 1", new Scheme3_2Rot(2)));
    trees->insert(make_pair("3a: III-Rand-3, 1", new Scheme3_3Rot(2)));
    trees->insert(make_pair("3a: III-Rand-4, 1", new Scheme3_4Rot(2)));

    //Varying p from 1-2^{-8} to 2^{-8}
    for(int i = 0; i <= 8; i++){
        int p = 1<<i;
        trees->insert(make_pair("3b: III-Rand-1, " + to_string(i), new Scheme3_1Rot(p)));
        trees->insert(make_pair("3b: III-Rand-2, " + to_string(i), new Scheme3_2Rot(p)));
        trees->insert(make_pair("3b: III-Rand-3, " + to_string(i), new Scheme3_3Rot(p)));
        trees->insert(make_pair("3b: III-Rand-4, " + to_string(i), new Scheme3_4Rot(p)));
    }
    for(int i = -8; i <= -1; i++){
        int p = 1<<abs(i);
        trees->insert(make_pair("3b: III-Rand-1, " + to_string(i), new Scheme3_1Rot(p, true)));
        trees->insert(make_pair("3b: III-Rand-2, " + to_string(i), new Scheme3_2Rot(p, true)));
        trees->insert(make_pair("3b: III-Rand-3, " + to_string(i), new Scheme3_3Rot(p, true)));
        trees->insert(make_pair("3b: III-Rand-4, " + to_string(i), new Scheme3_4Rot(p, true)));
    }



    // Tests
    auto* randomTest = new RandomTest();
    auto* zipfTest = new ZipfTest();
    auto* oneTest = new OneTest();
    auto* lineTest = new SplayLineTest();
    auto* alternatingTest = new AlternatingDepthNTest();
    tests = new vector<Test*>();
//    tests->push_back(randomTest);
//    tests->push_back(zipfTest);
//    tests->push_back(oneTest);
    tests->push_back(lineTest);
//    tests->push_back(alternatingTest);

    testNames = new vector<string>();
    //testNames->push_back("1: Uniform");
//    testNames->push_back("2: Zipf");
    //testNames->push_back("3: $n \\to 1$");
    testNames->push_back("4: Line");
    //testNames->push_back("5: Alternating");
}

//======================================================================================================================



map<string, result> Test::RunOnTrees(map<string, SplayTree *> *trees) {
    map<string, result> out;
    cout<<"Base class, something went wrong."<<endl;
    return out;
}

map<string, map<string, result>> Tester::runAllTestsOnTreeSuite(string treeSuite, string optionalSecond){
    map<string, map<string, result>> res;
    map<string, SplayTree*> treemap;
    for (pair<string, SplayTree*> tree : *trees){
        if (tree.first.substr(0, 3).find(treeSuite) != string::npos &&
            tree.first.find(optionalSecond) != string::npos){
            treemap.insert(tree);
        }
    }

    for (pair<string, SplayTree*> tree : treemap){
        cout<<tree.first<<endl;
    }

    for(int i = 0; i < tests->size(); i++) {
        map<string, result> temp = (*tests)[i]->RunOnTrees(&treemap);
        res.insert(make_pair((*testNames)[i], temp));
    }

    return res;
}

void Tester::runAllTestsOnTrees(map<string, SplayTree*> trees) {
    for(Test* test : *tests) {
        test->RunOnTrees(&trees);
    }
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

