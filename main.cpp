#include <iostream>
#include "tests/tests.h"
#include "trees/trees.h"

using namespace std;


int main() {

    // run tests here
    Tester tester;
    tester.runAllTestsAllTrees();

    SplayTree tempTree;
    tester.runAllTestsOneTree(&tempTree, "tempTree");

    RandomTest randomTest;
    tester.runOneTestAllTrees(&randomTest);

    tester.runOneTestOneTree(&tempTree, &randomTest, "tempTree");

    return 0;
}
