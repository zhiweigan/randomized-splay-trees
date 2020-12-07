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
        for(int trial : trials){
            vector<double> dist = this->MakeDist(trial, 1.07);
            int startInsert = clock();
            this->Insert(trial, tree.second);

            int endInsert = clock();
            double time1 = (double)(endInsert - startInsert)/CLOCKS_PER_SEC * 1000;

            int startAccess = clock();
            this->Access(trial, tree.second, &dist);
            int endAccess = clock();
            double time2 = (double)(endAccess - startAccess)/CLOCKS_PER_SEC * 1000;

            int startDelete = clock();
            this->Delete(trial, tree.second);
            int endDelete = clock();
            double time3 = (double)(endDelete - startDelete)/CLOCKS_PER_SEC * 1000;

            vt.addRow("", to_string(trial), to_string(time1), to_string(time2), to_string(time3));
        }
    }
    vt.print(std::cout);
}