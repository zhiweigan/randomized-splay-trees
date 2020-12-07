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
        SplayTree* t = tree.second;
        for(int trial : trials){
            t->resetCount();
            this->Insert(trial, tree.second);
            string insert = to_string(t->rotationCount) + " "
                    + to_string(t->followedPointers) + " "
                    + to_string((int)((double)(t->rotationCount) * 2.3 + t->followedPointers));

            t->resetCount();
            this->Access(trial, tree.second);
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