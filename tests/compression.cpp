//
// Created by Zhi Wei Gan on 12/6/20.
//

#include "tests.h"
using namespace std;

void HuffmanCoding::Insert(int n, SplayTree* tree) { // Inserts n items between 1 to n at random
    s* root = nullptr;
    default_random_engine generator;
    uniform_int_distribution<int> distribution(0, n-1);
    for(int i = 0; i < n; i++){
        int toInsert = distribution(generator);
        root = tree->Insert(toInsert, root);
    }
    tree->Clear(root);
}

void HuffmanCoding::Mixed(int  n, SplayTree* tree) {
    s* root = nullptr;
    default_random_engine generator;
    uniform_int_distribution<int> distribution(0, n-1);
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


void HuffmanCoding::RunOnTrees(map<string, SplayTree*>* trees) {
    int trials[4] = {1000, 10000, 100000, 1000000};

    cout<<"Testing RandomTest"<<endl;
    VariadicTable<string, string, string, string> vt({"Tree Type",
                                                      "N",
                                                      "Insert Only [ms]",
                                                      "Mixed(Insert, Access, Delete) [ms]"},
                                                     10);

    for(pair<string, SplayTree*> tree : *trees){
        vt.addRow(tree.first, "", "", "");
        for(int trial : trials){
            int startInsert = clock();
            this->Insert(trial, tree.second);
            int endInsert = clock();
            double time1 = (double)(endInsert - startInsert)/CLOCKS_PER_SEC * 1000;

            int startMixed = clock();
            this->Mixed(trial, tree.second);
            int endMixed = clock();
            double time2 = (double)(endMixed - startMixed)/CLOCKS_PER_SEC * 1000;

            vt.addRow("", to_string(trial), to_string(time1), to_string(time2));
        }
    }
    vt.print(std::cout);
}