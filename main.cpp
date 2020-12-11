#include <iostream>
#include <fstream>
#include "tests/tests.h"
#include "scientific.h"

using namespace std;

void printSimple(map<string, map<string, result>> res){
//    ofstream cout("output.txt", ios::app);
    for (pair<string, map<string, result>> test : res){
        cout<<"Trees (Num Rotations, Num Pointers Traversed, Total)";
        for (pair<string, result> tree : test.second){
            cout<<"| "<<tree.first.substr(3)<<" ";
        }
        cout<<endl;

        cout<<"--- ";
        for (int i = 0; i < test.second.size(); i++){
            cout<<"| --- ";
        }
        cout<<endl;
        break;
    }

    for (pair<string, map<string, result>> test : res){
        cout<<test.first.substr(3);
        for (pair<string, result> tree : test.second){
            cout<<" | "<<scientificNumber(tree.second.num_rotations, 2)
            <<", "<<scientificNumber(tree.second.num_followed, 2)
            <<", "<<scientificNumber(tree.second.getTotal(), 2);
        }
        cout<<endl;
    }
    cout<<endl;
}

void runDeterministic(Tester tester) {
    map<string, map<string, result>> res = tester.runAllTestsOnTreeSuite("0");

    printSimple(res);
}

void runScheme1Simple(Tester tester) {
    map<string, map<string, result>> res = tester.runAllTestsOnTreeSuite("1a");

    printSimple(res);
}

void runScheme2Simple(Tester tester) {
    map<string, map<string, result>> res = tester.runAllTestsOnTreeSuite("2a");

    printSimple(res);
}

void runScheme3Simple(Tester tester) {
    map<string, map<string, result>> res = tester.runAllTestsOnTreeSuite("3a");

    printSimple(res);
}

void printComplex(map<string, map<string, result>> res){
//    ofstream cout("output.txt", ios::app);
    map<string, map<int, long>> temp;
    for (pair<string, map<string, result>> test : res) {
        map<int, long> probabilityToResult;
        for (pair<string, result> tree : test.second) {
            std::size_t pos = tree.first.find(",");
            probabilityToResult.insert(make_pair(stoi(tree.first.substr(pos+2)), tree.second.getTotal()));
        }
        temp.insert(make_pair(test.first, probabilityToResult));
    }

    cout<<"Tests ";
    for (pair<string, map<int, long>> test : temp) {
        std::size_t pos = test.first.substr(3).find(", ");
        cout <<"| "<< test.first.substr(3).substr(0, pos);
    }
    cout<<endl;
    cout<<"--- ";
    for (int i = 0; i < temp.size(); i++) {
        cout <<"| --- ";
    }
    cout<<endl;

    for(int i = -8; i <= 8; i++){
        if (i == -8 || i == 0 || i == -1 || i == 8) continue;
        if (i <= -1) {
            cout << "1 - 2^{-" << abs(i) << "} ";
        }
        else {
            cout << "2^{-" << i << "} ";
        }

        for (pair<string, map<int, long>> test : temp) {
            cout<<" | "<<scientificNumber(test.second[i], 2);
        }
        cout<<endl;
    }

    // Print plots
//    for (pair<string, map<int, long>> test : temp){
//        cout<<"\\addplot[color, mark=square] coordinates {";
//        for (int i = -8; i <= 8; i++){
//            if (i == -8 || i == 0 || i == -1 || i == 8) continue;
//            int toAdd = (i > 0) ? -1 : 1;
//            cout<<"("<<i+toAdd<<", "<<scientificNumber2(test.second[i], 2)<<") " ;
//        }
//        cout<<"};"<<endl;
//    }
//
//    cout<<"\\legend{";
//    for (pair<string, map<int, long>> test : temp) {
//        cout << test.first.substr(3) <<", ";
//    }
//    cout<<"}"<<endl;
    cout<<endl;
}

void runScheme1_2Rot (Tester tester){
    map<string, map<string, result>> res = tester.runAllTestsOnTreeSuite("1b", "d-2");

    printComplex(res);
}

void runScheme2_2Rot (Tester tester){
    map<string, map<string, result>> res = tester.runAllTestsOnTreeSuite("2b", "d-2");

    printComplex(res);
}

void runScheme3_2Rot (Tester tester){
    map<string, map<string, result>> res = tester.runAllTestsOnTreeSuite("3b", "d-2");

    printComplex(res);
}

int main() {

    // run tests here
    Tester tester;

//     Run Deterministic
//    cout<<"Testing Deterministic Tests"<<endl;
//    runDeterministic(tester);
//
//    // Run Simple Schemes
//    cout<<"Testing Simple Scheme 1 Tests"<<endl;
//    runScheme1Simple(tester);
//    cout<<"Testing Simple Scheme 2 Tests"<<endl;
//    runScheme2Simple(tester);
//    cout<<"Testing Simple Scheme 3 Tests"<<endl;
//    runScheme3Simple(tester);
//
//    // Run over varying p
//    cout<<"Testing Varying p Scheme 1 Tests"<<endl;
//    runScheme1_2Rot(tester);
//    cout<<"Testing Varying p Scheme 2 Tests"<<endl;
//    runScheme2_2Rot(tester);
    cout<<"Testing Varying p Scheme 3 Tests"<<endl;
    runScheme3_2Rot(tester);

    return 0;
}
