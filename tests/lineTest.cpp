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

int getMaxDepth(s* node, int curDepth) {
    int distance[1000005] = {0};
    queue<s*> q;
    q.push(node);

    while(!q.empty()){
        s* n = q.front();
        q.pop();

        if (n->left) {
            distance[n->left->key] = distance[n->key] + 1;
            q.push(n->left);
        }
        if (n->right){
            distance[n->right->key] = distance[n->key] + 1;
            q.push(n->right);
        }
    }
    int maxdepth = 0;
    for(int i = 0; i < 1000005; i++){
        if (distance[i] > maxdepth){
            maxdepth = distance[i];
        }
    }

    return maxdepth;
}

vector<pair<int, int>> SplayLineTest::Access(int n, SplayTree* tree, bool check) { // Inserts n items between 1 to n at random
    vector<pair<int, int>> depth;
    for(int i = 0; i < n; i++){
        if ((i % 1 == 0) && i <= 20 && check) {
            int d = getMaxDepth(tree->root, 1);
            depth.push_back(make_pair(i, d));
        }
        tree->Search(n-i-1);
    }
    return depth;
}

map<string, result> SplayLineTest::RunOnTrees(map<string, SplayTree*>* trees) {

    cout<<"Testing Line"<<endl;
    map<string, result> out;


    for(pair<string, SplayTree*> tree : *trees){
        //cout<<tree.first<<endl;
        SplayTree* t = tree.second;
        if (tree.first.find("BST") != string::npos
        || tree.first.find("1-") != string::npos
        || tree.first.find("d-1") != string::npos
        || tree.first.find("3b: III-Rand-2, 0") != string::npos
        ){
            if (trial > 5000) {
                out.insert(make_pair(tree.first, result(0, 0)));
                continue;
            }
        }

        this->Insert(trial, tree.second);

        t->resetCount();
        // Uncomment these lines to get max depth calculations

//        bool check = tree.first.find("d-2") != string::npos || tree.first.find("Splay") != string::npos;
        bool check = false;
        vector<pair<int, int>> depth = this->Access(trial, tree.second, check);
        out.insert(make_pair(tree.first, result(t->rotationCount, t->followedPointers)));

//        cout<<tree.first<<endl;
//        for(int i = 0; i < depth.size(); i++){
//            cout<<"("<<depth[i].first<<", "<<depth[i].second<<") ";
//        }
//        cout<<endl;

        this->Delete(trial, tree.second);
    }
    return out;
}