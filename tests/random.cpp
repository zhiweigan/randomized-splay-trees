//
// Created by Zhi Wei Gan on 11/25/20.
//

#include "tests.h"
using namespace std;

void RandomTest::Insert(int n, SplayTree* tree) { // Inserts n items between 1 to n at random
    default_random_engine generator;
    vector<int> toInsert;
    for(int i = 0; i < n; i++){
        toInsert.push_back(i);
    }
    shuffle(toInsert.begin(), toInsert.end(), generator);
    for(int i = 0; i < n; i++){
        tree->Insert(toInsert[i]);
    }
}

void RandomTest::Delete(int n, SplayTree* tree) { // Inserts n items between 1 to n at random
    default_random_engine generator;
    vector<int> toDelete;
    for(int i = 0; i < n; i++){
        toDelete.push_back(i);
    }
    shuffle(toDelete.begin(), toDelete.end(), generator);
    for(int i = 0; i < n; i++){
        tree->Delete(toDelete[i]);
    }
}

void RandomTest::Access(int n, SplayTree* tree) { // Inserts n items between 1 to n at random
    default_random_engine generator;
    uniform_int_distribution<int> distribution(0, n-1);

    for(int i = 0; i < n; i++){
        int toSearch = distribution(generator);
        tree->Search(toSearch);
    }
}

map<string, result> RandomTest::RunOnTrees(map<string, SplayTree*>* trees) {

    cout<<"Testing RandomTest"<<endl;
    map<string, result> out;

    for(pair<string, SplayTree*> tree : *trees){
        SplayTree* t = tree.second;
        this->Insert(trial, tree.second);

        t->resetCount();
        this->Access(trial, tree.second);
        out.insert(make_pair(tree.first, result(t->rotationCount, t->followedPointers)));

        this->Delete(trial, tree.second);
    }
    return out;
}