//
// Created by Zhi Wei Gan on 11/25/20.
//

#include "tests.h"
using namespace std;

void OneTest::Insert(int n, SplayTree* tree) {
    for(int i = 0; i < n; i++){
        tree->Insert(i);
    }
}

void OneTest::Delete(int n, SplayTree* tree) {
    for(int i = 0; i < n; i++){
        tree->Delete(n-i-1);
    }
}

void OneTest::Access(int n, SplayTree* tree) {
    for(int i = 0; i < n; i++){
        tree->Search(n-i-1);
    }
}

void OneTest::RunOnTrees(map<string, SplayTree*>* trees) {
    int trials[2] = {100, 10000};

    cout<<"Testing OneTest"<<endl;
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