//
// Created by Zhi Wei Gan on 11/25/20.
//

#include "tests.h"
using namespace std;

void OneTest::Insert(int n, SplayTree* tree) {
    for(int i = 0; i < n; i++){
        tree->Insert(i);
    }
}

void OneTest::Delete(int n, SplayTree* tree) {
    for(int i = 0; i < n; i++){
        tree->Delete(i);
    }
}

void OneTest::Access(int n, SplayTree* tree) {
    for(int i = 0; i < n; i++){
        tree->Search(n-i-1);
    }
}

map<string, result> OneTest::RunOnTrees(map<string, SplayTree*>* trees) {

    cout<<"Testing Stack"<<endl;

    map<string, result> out;
    for(pair<string, SplayTree*> tree : *trees){
        SplayTree* t = tree.second;
        if (tree.first.find("BST") != string::npos
        || tree.first.find("3b: III-Rand-2, 0") != string::npos
        ){
            if (trial > 5000) {
                out.insert(make_pair(tree.first, result(0, 0)));
                continue;
            }
        }

        this->Insert(trial, tree.second);

        t->resetCount();
        this->Access(trial, tree.second);
        out.insert(make_pair(tree.first, result(t->rotationCount, t->followedPointers)));

        this->Delete(trial, tree.second);
    }

    return out;
}