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

void RandomTest::RunOnTrees(map<string, SplayTree*>* trees) {
    int trials[4] = {100, 10000, 100000, 1000000};

    cout<<"Testing RandomTest"<<endl;
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
            int startInsert = clock();
            this->Insert(trial, tree.second);

            int endInsert = clock();
            double time1 = (double)(endInsert - startInsert)/CLOCKS_PER_SEC * 1000;

            int startAccess = clock();
            this->Access(trial, tree.second);
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