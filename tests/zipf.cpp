//
// Created by Zhi Wei Gan on 12/6/20.
//

#include "tests.h"
using namespace std;

void ZipfTest::Access(int n, SplayTree* tree, vector<double>* dist) { // Inserts n items between 1 to n at random
    default_random_engine generator;
    discrete_distribution<int> distribution(dist->begin(), dist->end());
    for(int i = 0; i < n; i++){
        int toSearch = distribution(generator);
        tree->Search(toSearch);
    }
}

vector<double> ZipfTest::MakeDist(int N, double zipfS) {
    vector<double> distribution;
    double denominator = 0;
    for (int n = 1; n <= N; n++){
        denominator += 1.0 / pow(n, zipfS);
    }
    for (int k = 1; k <= N; k++){
        double numerator = 1.0 / pow(k, zipfS);
        distribution.push_back(numerator/denominator);
    }
    return distribution;
}

void ZipfTest::RunOnTrees(map<string, SplayTree*>* trees) {
    int trials[4] = {1000, 10000, 100000, 1000000};

    cout<<"Testing ZipfTest"<<endl;
    VariadicTable<string, string, string, string, string> vt({"Tree Type",
                                                              "N",
                                                              "Insert Only [ms]",
                                                              "Access Only [ms]",
                                                              "Delete Only [ms]"
                                                             },
                                                             10);

    for(pair<string, SplayTree*> tree : *trees){
        vt.addRow(tree.first, "", "", "", "");
        SplayTree* t = tree.second;
        for(int trial : trials){
            vector<double> dist = MakeDist(trial, 1.07);
            t->resetCount();
            this->Insert(trial, tree.second);
            string insert = to_string(t->rotationCount) + " "
                            + to_string(t->followedPointers) + " "
                            + to_string((int)((double)(t->rotationCount) * 2.3 + t->followedPointers));

            t->resetCount();
            this->Access(trial, tree.second, &dist);
            string access = to_string(t->rotationCount) + " "
                            + to_string(t->followedPointers) + " "
                            + to_string((int)((double)(t->rotationCount) * 2.3 + t->followedPointers));

            t->resetCount();
            this->Delete(trial, tree.second);
            string del = to_string(t->rotationCount) + " "
                         + to_string(t->followedPointers) + " "
                         + to_string((int)((double)(t->rotationCount) * 2.3 + t->followedPointers));

            vt.addRow("", to_string(trial), insert, access, del);
        }
    }
    vt.print(std::cout);
}