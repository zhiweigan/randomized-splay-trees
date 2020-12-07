#include <iostream>
#include "tests/tests.h"
#include "trees/trees.h"

using namespace std;


int main() {

    // run tests here
    Tester tester;
//    tester.runAllTestsAllTrees();


//    SplayTree vanilla;
//    tester.runAllTestsOneTree(&vanilla, "Vanilla");

//    ZipfTest test;
//    vector<double> res = test.MakeDist(10, 1.07);

    SplayLineTest lineTest;
    tester.runOneTestAllTrees(&lineTest);
//
//    tester.runOneTestOneTree(&tempTree, &randomTest, "tempTree");


    return 0;
}
