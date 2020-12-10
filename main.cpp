#include <iostream>
#include "tests/tests.h"
#include "trees/trees.h"

using namespace std;

template<typename T>
struct scientificNumberType2
{
    explicit scientificNumberType2(T number, int decimalPlaces) : number(number), decimalPlaces(decimalPlaces) {}

    T number;
    int decimalPlaces;
};

template<typename T>
scientificNumberType2<T> scientificNumber2(T t, int decimalPlaces)
{
    return scientificNumberType2<T>(t, decimalPlaces);
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const scientificNumberType2<T>& n)
{
    double numberDouble = n.number;
    int eToThe = 0;
    numberDouble /= 1e7;
    // memorize old state
    std::ios oldState(nullptr);
    oldState.copyfmt(os);
    os << std::fixed << std::setprecision(n.decimalPlaces) << numberDouble;
    // restore state
    os.copyfmt(oldState);
    return os;
}

template<typename T>
struct scientificNumberType
{
    explicit scientificNumberType(T number, int decimalPlaces) : number(number), decimalPlaces(decimalPlaces) {}

    T number;
    int decimalPlaces;
};

template<typename T>
scientificNumberType<T> scientificNumber(T t, int decimalPlaces)
{
    return scientificNumberType<T>(t, decimalPlaces);
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const scientificNumberType<T>& n)
{
    double numberDouble = n.number;
    int eToThe = 0;
    for(; numberDouble > 9; ++eToThe)
    {
        numberDouble /= 10;
    }
    // memorize old state
    std::ios oldState(nullptr);
    oldState.copyfmt(os);
    os << std::fixed << std::setprecision(n.decimalPlaces) << numberDouble << "e" << eToThe;
    // restore state
    os.copyfmt(oldState);
    return os;
}

void runDeterministic(Tester tester) {
    map<string, map<string, result>> res = tester.runAllTestsOnTreeSuite("0");

    for (pair<string, map<string, result>> test : res){
        for (pair<string, result> tree : test.second){
            cout<<tree.first<<endl;
        }
        break;
    }

    for (pair<string, map<string, result>> test : res){
        cout<<test.first.substr(3);
        for (pair<string, result> tree : test.second){
            cout<<" & "<<scientificNumber(tree.second.getTotal(), 2) ;
        }
        cout<<"\\\\"<<endl;
    }
}

void runScheme1Simple(Tester tester) {
    map<string, map<string, result>> res = tester.runAllTestsOnTreeSuite("1a");

    for (pair<string, map<string, result>> test : res){
        for (pair<string, result> tree : test.second){
            cout<<tree.first<<endl;
        }
        break;
    }

    for (pair<string, map<string, result>> test : res){
        cout<<test.first.substr(3);
        for (pair<string, result> tree : test.second){
            cout<<" & "<<scientificNumber(tree.second.getTotal(), 2) ;
        }
        cout<<"\\\\"<<endl;
    }
}

void runScheme2Simple(Tester tester) {
    map<string, map<string, result>> res = tester.runAllTestsOnTreeSuite("2a");

    for (pair<string, map<string, result>> test : res){
        for (pair<string, result> tree : test.second){
            cout<<tree.first<<endl;
        }
        break;
    }

    for (pair<string, map<string, result>> test : res){
        cout<<test.first.substr(3);
        for (pair<string, result> tree : test.second){
            cout<<" & "<<scientificNumber(tree.second.getTotal(), 2) ;
        }
        cout<<"\\\\"<<endl;
    }
}

void runScheme3Simple(Tester tester) {
    map<string, map<string, result>> res = tester.runAllTestsOnTreeSuite("3a");

    for (pair<string, map<string, result>> test : res){
        for (pair<string, result> tree : test.second){
            cout<<tree.first<<endl;
        }
        break;
    }

    for (pair<string, map<string, result>> test : res){
        cout<<test.first.substr(3);
        for (pair<string, result> tree : test.second){
            cout<<" & "<<scientificNumber(tree.second.getTotal(), 2) ;
        }
        cout<<"\\\\"<<endl;
    }
}

void runScheme1_2Rot (Tester tester){
    map<string, map<string, result>> res = tester.runAllTestsOnTreeSuite("1b", "d-2");

    map<string, map<int, long>> temp;

    for (pair<string, map<string, result>> test : res) {
        map<int, long> probabilityToResult;
        for (pair<string, result> tree : test.second) {
            std::size_t pos = tree.first.find(",");
            probabilityToResult.insert(make_pair(stoi(tree.first.substr(pos+2)), tree.second.getTotal()));
        }
        temp.insert(make_pair(test.first, probabilityToResult));
    }

    for(int i = -8; i <= 8; i++){
        if (i <= -1) {
            cout << "$1 - 2^{-" << abs(i) << "}$ ";
        }
        else {
            cout << "$2^{-" << i << "}$ ";
        }
        for (pair<string, map<int, long>> test : temp) {
            cout<<" & "<<scientificNumber(test.second[i], 2);
        }
        cout<<"\\\\"<<endl;
    }

    for (pair<string, map<int, long>> test : temp){
        cout<<"\\addplot[color, mark=square] coordinates {";
        for (int i = -8; i <= 8; i++){
            cout<<"("<<i<<", "<<scientificNumber2(test.second[i], 2)<<") " ;
        }
        cout<<"};"<<endl;
    }

    cout<<"\\legend{";
    for (pair<string, map<int, long>> test : temp) {
        cout << test.first.substr(3) <<", ";
    }
    cout<<"}"<<endl;
}

void runScheme2_2Rot (Tester tester){
    map<string, map<string, result>> res = tester.runAllTestsOnTreeSuite("2b", "d-2");

    map<string, map<int, long>> temp;

    for (pair<string, map<string, result>> test : res) {
        map<int, long> probabilityToResult;
        for (pair<string, result> tree : test.second) {
            std::size_t pos = tree.first.find(",");
            probabilityToResult.insert(make_pair(stoi(tree.first.substr(pos+2)), tree.second.getTotal()));
        }
        temp.insert(make_pair(test.first, probabilityToResult));
    }

    for(int i = -8; i <= 8; i++){
        if (i <= -1) {
            cout << "$1 - 2^{-" << abs(i) << "}$ ";
        }
        else {
            cout << "$2^{-" << i << "}$ ";
        }
        for (pair<string, map<int, long>> test : temp) {
            cout<<" & "<<scientificNumber(test.second[i], 2);
        }
        cout<<"\\\\"<<endl;
    }
    string colors[5] = {"blue", "red", "brown", "purple", "black"};
    int iter = 0;
    for (pair<string, map<int, long>> test : temp){
        cout<<"\\addplot["<<colors[iter]<<", mark=square] coordinates {";
        iter += 1;
        for (int i = -8; i <= 8; i++){
            cout<<"("<<i<<", "<<scientificNumber2(test.second[i], 2)<<") " ;
        }
        cout<<"};"<<endl;
    }

    cout<<"\\legend{";
    for (pair<string, map<int, long>> test : temp) {
        cout << test.first.substr(3) <<", ";
    }
    cout<<"}"<<endl;
}

void runScheme3_2Rot (Tester tester){
    map<string, map<string, result>> res = tester.runAllTestsOnTreeSuite("3b", "d-2");

    map<string, map<int, long>> temp;

    for (pair<string, map<string, result>> test : res) {
        map<int, long> probabilityToResult;
        for (pair<string, result> tree : test.second) {
            std::size_t pos = tree.first.find(",");
            probabilityToResult.insert(make_pair(stoi(tree.first.substr(pos+2)), tree.second.getTotal()));
        }
        temp.insert(make_pair(test.first, probabilityToResult));
    }

    for(int i = -8; i <= 8; i++){
        if (i <= -1) {
            cout << "$1 - 2^{-" << abs(i) << "}$ ";
        }
        else {
            cout << "$2^{-" << i << "}$ ";
        }
        for (pair<string, map<int, long>> test : temp) {
            cout<<" & "<<scientificNumber(test.second[i], 2);
        }
        cout<<"\\\\"<<endl;
    }

    string colors[5] = {"blue", "red", "brown", "purple", "black"};
    int iter = 0;
    for (pair<string, map<int, long>> test : temp){
        cout<<"\\addplot["<<colors[iter]<<", mark=square] coordinates {";
        iter += 1;
        for (int i = -8; i <= 8; i++){
            cout<<"("<<i<<", "<<scientificNumber2(test.second[i], 2)<<") " ;
        }
        cout<<"};"<<endl;
    }

    cout<<"\\legend{";
    for (pair<string, map<int, long>> test : temp) {
        cout << test.first.substr(3) <<", ";
    }
    cout<<"}"<<endl;
}

int main() {

    // run tests here
    Tester tester;

    // Run Deterministic
//    cout<<"Deterministic"<<endl;
//    runDeterministic(tester);
//
//    // Run Simple Schemes
    cout<<"Simple 1"<<endl;
    runScheme1Simple(tester);
    cout<<"Simple 2"<<endl;
    runScheme2Simple(tester);
    cout<<"Simple 3"<<endl;
    runScheme3Simple(tester);

//    cout<<"Scheme 1 - 2Rot"<<endl;
//    runScheme1_2Rot(tester);
//    cout<<"Scheme 2 - 2Rot"<<endl;
//    runScheme2_2Rot(tester);
//    cout<<"Scheme 3 - 2Rot"<<endl;
//    runScheme3_2Rot(tester);

    return 0;
}
