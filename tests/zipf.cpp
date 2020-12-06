//
// Created by Zhi Wei Gan on 12/6/20.
//

#include "tests.h"
using namespace std;

void ZipfTest::Insert(int n, SplayTree* tree, vector<double>* dist) { // Inserts n items between 1 to n at random
    s* root = nullptr;
    default_random_engine generator;
    discrete_distribution<int> distribution(dist->begin(), dist->end());
    for(int i = 0; i < n; i++){
        int toInsert = distribution(generator);
        root = tree->Insert(toInsert, root);
    }
    tree->Clear(root);
}

void ZipfTest::Mixed(int  n, SplayTree* tree, vector<double>* dist) {
    s* root = nullptr;
    default_random_engine generator;
    discrete_distribution<int> distribution(dist->begin(), dist->end());
    uniform_int_distribution<int> choice(0, 2);
    for(int i = 0; i < n; i++){
        int action = choice(generator);
        int item = distribution(generator);
        switch(action) {
            case 0:
                root = tree->Insert(item, root);
                break;
            case 1:
                root = tree->Delete(item, root);
                break;
            case 2:
                root = tree->Search(item, root);
                break;
            default:
                throw out_of_range("Choice generator out of bounds");
        }
    }
    tree->Clear(root);
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
    VariadicTable<string, string, string, string> vt({"Tree Type",
                                                      "N",
                                                      "Insert Only [ms]",
                                                      "Mixed(Insert, Access, Delete) [ms]"},
                                                     10);
    for(pair<string, SplayTree*> tree : *trees){
        vt.addRow(tree.first, "", "", "");
        for(int trial : trials){
            vector<double> dist = this->MakeDist(trial, 1.07);
            int startInsert = clock();
            this->Insert(trial, tree.second, &dist);
            int endInsert = clock();
            double time1 = (double)(endInsert - startInsert)/CLOCKS_PER_SEC * 1000;

            int startMixed = clock();
            this->Mixed(trial, tree.second, &dist);
            int endMixed = clock();
            double time2 = (double)(endMixed - startMixed)/CLOCKS_PER_SEC * 1000;

            vt.addRow("", to_string(trial), to_string(time1), to_string(time2));
        }
    }
    vt.print(std::cout);
}