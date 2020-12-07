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
        cout<<tree.first<<endl;
        for(int trial : trials){
            cout<<trial<<endl;
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