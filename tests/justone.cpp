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

    cout<<"Testing OneTest"<<endl;

    map<string, result> out;
    for(pair<string, SplayTree*> tree : *trees){
        cout<<tree.first<<endl;
        SplayTree* t = tree.second;
        if (
                //true
                tree.first.find("BST") != string::npos
//            || tree.first.find("1-") != string::npos
//             || tree.first.find("d-1") != string::npos
                || tree.first.find("3b: III-Rand-2, 0") != string::npos
            ){
            if (trial > 5000) {
                out.insert(make_pair(tree.first, result(0, 0)));
                continue;
            }
        }

        this->Insert(trial, tree.second);
//            string insert = to_string(t->rotationCount) + " "
//                            + to_string(t->followedPointers) + " "
//                            + to_string((int)((double)(t->rotationCount) * 2.3 + t->followedPointers));

        t->resetCount();
        this->Access(trial, tree.second);
        out.insert(make_pair(tree.first, result(t->rotationCount, t->followedPointers)));

        this->Delete(trial, tree.second);
    }

    return out;
}