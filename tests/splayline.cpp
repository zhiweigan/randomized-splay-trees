//
// Created by Zhi Wei Gan on 11/25/20.
//

#include "tests.h"
using namespace std;

void SplayLineTest::Insert(int n, SplayTree* tree) { // Inserts n items between 1 to n at random
    tree->root = new s(0);
    s* node = tree->root;

    for(int i = 1; i < n; i++){
        node->right = new s(i);
        node->right->parent = node;
        node = node->right;
    }
}

void SplayLineTest::Delete(int n, SplayTree* tree) { // Inserts n items between 1 to n at random
    for(int i = 0; i < n; i++){
        tree->Delete(i);
    }
}

void SplayLineTest::Access(int n, SplayTree* tree) { // Inserts n items between 1 to n at random
    for(int i = 0; i < n; i++){
        tree->Search(n-i-1);
    }
}

void SplayLineTest::RunOnTrees(map<string, SplayTree*>* trees) {
    int trials[3] = {100, 10000, 100000};

    cout<<"Testing SplayLineTest"<<endl;
    VariadicTable<string, string, string> vt({"Tree Type",
                                                              "N",
                                                              "Access Only [ms]",
                                                             },
                                                             10);

    for(pair<string, SplayTree*> tree : *trees){
        vt.addRow(tree.first, "", "");
        for(int trial : trials){
            this->Insert(trial, tree.second);

            int startAccess = clock();
            this->Access(trial, tree.second);
            int endAccess = clock();
            double time2 = (double)(endAccess - startAccess)/CLOCKS_PER_SEC * 1000;

            this->Delete(trial, tree.second);

            vt.addRow("", to_string(trial), to_string(time2));
        }
    }
    vt.print(std::cout);
}