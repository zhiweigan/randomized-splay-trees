//
// Created by Zhi Wei Gan on 12/6/20.
//

#include "tests.h"
using namespace std;

vector<int> ZipfTest::Insert(int n, SplayTree* tree) {
    default_random_engine generator;
    vector<int> toInsert;
    for(int i = 0; i < n; i++){
        toInsert.push_back(i);
    }
    shuffle(toInsert.begin(), toInsert.end(), generator);
    for(int i = 0; i < n; i++){
        tree->Insert(toInsert[i]);
    }
    return toInsert;
}

void ZipfTest::Access(int n, SplayTree* tree, vector<double>* dist) { // Inserts n items between 1 to n at random
    default_random_engine generator;
    discrete_distribution<int> distribution(dist->begin(), dist->end());
    for(int i = 0; i < n; i++){
        int toSearch = distribution(generator);
        tree->Search(toSearch);
    }
}

vector<double> ZipfTest::MakeDist(int N, double zipfS, vector<int> inserted) {
    vector<double> distribution(N);
    double denominator = 0;
    for (int n = 1; n <= N; n++){
        denominator += 1.0 / pow(n, zipfS);
    }
    for (int k = 1; k <= N; k++){
        double numerator = 1.0 / pow(k, zipfS);
        distribution[inserted[k-1]] = numerator/denominator;
    }
    return distribution;
}

map<string, result> ZipfTest::RunOnTrees(map<string, SplayTree*>* trees) {

    cout<<"Testing ZipfTest"<<endl;
    map<string, result> out;

    for(pair<string, SplayTree*> tree : *trees){
        SplayTree* t = tree.second;

        vector<int> inserted = this->Insert(trial, tree.second);
        vector<double> dist = MakeDist(trial, 1.07, inserted);

        t->resetCount();
        this->Access(trial, tree.second, &dist);
        out.insert(make_pair(tree.first, result(t->rotationCount, t->followedPointers)));

        this->Delete(trial, tree.second);
    }
    return out;
}