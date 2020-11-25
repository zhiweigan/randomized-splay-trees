//
// Created by Zhi Wei Gan on 11/25/20.
//

#include "tests.h"
using namespace std;

void RandomTest::Insert(int n, SplayTree* tree) { // Inserts n items between 1 to n at random
    s* root = nullptr;
    for(int i = 0; i < n; i++){
        int toInsert = rand() % n;
        root = tree->Insert(toInsert, root);
    }
    tree->Clear(root);
}

void RandomTest::RunOnTrees(map<string, SplayTree*>* trees) {
    int trials[4] = {1000, 10000, 100000, 1000000};

    cout<<"Random"<<endl;
    cout<<setfill('-')<<setw(40)<<"-"<<setfill(' ')<<endl; // For pretty formatting
    for(pair<string, SplayTree*> tree : *trees){
        cout<<tree.first<<": "<<endl;
        for(int trial : trials){
            int start = clock();
            this->Insert(trial, tree.second);
            int end = clock();
            cout<<setw(20)<<trial<<" | "<<((float)(end - start))/CLOCKS_PER_SEC * 1000<<"ms"<<endl; // Formatting
        }
    }
}