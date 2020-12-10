//
// Created by Zhi Wei Gan on 11/25/20.
//

#include "tests.h"
using namespace std;

vector<int> AlternatingDepthNTest::Insert(int n, SplayTree* tree) { // Inserts n items between 1 to n at random
    tree->root = new s(0);
    s* node = tree->root;

    vector<int> inserted;
    inserted.push_back(0);

    default_random_engine generator;
    uniform_int_distribution<int> distribution(0, 1);

    int left = 1;
    int right = n-1;

    for(int i = 1; i < n; i++){
        int action = distribution(generator);
        int toAdd = 0;
        if (action) {
            toAdd = right;
            right--;
        } else{
            toAdd = left;
            left++;
        };

        if (toAdd > node->key){
            node->right = new s(toAdd);
            node->right->parent = node;
            node = node->right;
            inserted.push_back(toAdd);
        } else{
            node->left = new s(toAdd);
            node->left->parent = node;
            node = node->left;
            inserted.push_back(toAdd);
        }
    }
    return inserted;
}

void AlternatingDepthNTest::Delete(int n, SplayTree* tree, vector<int> inserted) { // Inserts n items between 1 to n at random
    for(int item : inserted){
        tree->Delete(item);
    }
}

void AlternatingDepthNTest::Access(int n, SplayTree* tree, vector<int> inserted) { // Inserts n items between 1 to n at random
    reverse(inserted.begin(), inserted.end());
    for(int item : inserted){
        tree->Search(item);
    }
}

map<string, result> AlternatingDepthNTest::RunOnTrees(map<string, SplayTree*>* trees) {

    cout<<"Testing AlternatingDepthNTest"<<endl;
    map<string, result> out;
    for(pair<string, SplayTree*> tree : *trees){
        cout<<tree.first<<endl;
        SplayTree* t = tree.second;
        if (
                tree.first.find("BST") != string::npos
                || tree.first.find("1-") != string::npos
                || tree.first.find("d-1") != string::npos
                || tree.first.find("3b: III-Rand-2, 0") != string::npos
                ){
            if (trial > 5000) {
                out.insert(make_pair(tree.first, result(0, 0)));
                continue;
            }
        }

        vector<int> inserted = this->Insert(trial, tree.second);

        t->resetCount();
        this->Access(trial, tree.second, inserted);
        out.insert(make_pair(tree.first, result(t->rotationCount, t->followedPointers)));

        this->Delete(trial, tree.second, inserted);
    }
    return out;
}