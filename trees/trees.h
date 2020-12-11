//
// Created by Zhi Wei Gan on 11/25/20.
//

#ifndef RANDOMIZED_SPLAY_TREES_TREES_H
#define RANDOMIZED_SPLAY_TREES_TREES_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <random>
#include <algorithm>
#include <queue>

using namespace std;

struct s
{
    int key;
    s* left;
    s* right;
    s* parent;
    s(const int& init = int()) : left(nullptr), right(nullptr), parent(nullptr), key(init) {}
    ~s() {}
};

class SplayTree
{
public:
    virtual void L_Rotate(s* k2);
    virtual void R_Rotate(s* k2);
    s* subtree_minimum(s *u);
    s* subtree_maximum(s *u);
    void replace(s *u, s *v);
    void printHelper(const std::string& prefix, const s* node, bool isLeft);
    unsigned long p_size;
    long long rotationCount = 0;
    int followedPointers = 0;
    SplayTree() : root(nullptr), p_size(0) { }
    bool invert = false;
    s* root;
    virtual void Insert(int key);
    virtual void Delete(int key);
    virtual void Splay(s* x);
    virtual s* Search(int key);
    void prettyPrint();
    void resetCount();
};


// Deterministic
class BST : public SplayTree
{
public:
    BST() : SplayTree() { }
    void Insert(int key);
    void Delete(int key);
    s* Search(int key);
};



class ThreeRotSplayTree : public SplayTree
{
protected:
    virtual void AccessSplay(s* x);
public:
    ThreeRotSplayTree() : SplayTree() {}
    s* Search(int key);
};

class OneRotSplayTree : public SplayTree
{
protected:
    virtual void AccessSplay(s* x);
public:
    OneRotSplayTree() : SplayTree() {}
    s* Search(int key);
};

class FourRotSplayTree : public SplayTree
{
protected:
    virtual void AccessSplay(s* x);
public:
    FourRotSplayTree() : SplayTree() {}
    s* Search(int key);
};


class EvenSplayTree : public SplayTree
{
    void AccessSplay(s* x);
public:
    EvenSplayTree() : SplayTree() {}
    s* Search(int key);
};


// Randomized
class Scheme1_3Rot : public ThreeRotSplayTree
{
    default_random_engine generator;
    uniform_int_distribution<int> choice;
public:
    Scheme1_3Rot(int p = 1 << 1, bool invert = false) : ThreeRotSplayTree() {
        choice = uniform_int_distribution<int>(0,p-1);
        this->invert = invert;
    }
    s* Search(int key);
};

class Scheme1_1Rot : public OneRotSplayTree
{
    default_random_engine generator;
    uniform_int_distribution<int> choice;
public:
    Scheme1_1Rot(int p = 1 << 1, bool invert = false) : OneRotSplayTree() {
        choice = uniform_int_distribution<int>(0,p-1);
        this->invert = invert;
    }
    s* Search(int key);
};


class Scheme1_4Rot : public FourRotSplayTree
{
    default_random_engine generator;
    uniform_int_distribution<int> choice;
public:
    Scheme1_4Rot(int p = 1 << 1, bool invert = false) : FourRotSplayTree() {
        choice = uniform_int_distribution<int>(0,p-1);
        this->invert = invert;
    }
    s* Search(int key);
};

class Scheme1_2Rot : public SplayTree
{
private:
    void AccessSplay(s* x);
    default_random_engine generator;
    uniform_int_distribution<int> choice;
public:
    Scheme1_2Rot(int p = 1 << 1, bool invert = false) : SplayTree() {
        choice = uniform_int_distribution<int>(0,p-1);
        this->invert = invert;
    }
    s* Search(int key);
};

class Scheme2_2Rot : public SplayTree
{
private:
    void AccessSplay(s* x);
    default_random_engine generator;
    uniform_int_distribution<int> choice;
public:
    Scheme2_2Rot(int p = 1 << 1, bool invert = false) : SplayTree() {
        choice = uniform_int_distribution<int>(0,p-1);
        this->invert = invert;
    }
    s* Search(int key);
};

class Scheme2_4Rot : public FourRotSplayTree
{
    default_random_engine generator;
    uniform_int_distribution<int> choice;
    void AccessSplay(s* x);
public:
    Scheme2_4Rot(int p = 1 << 1, bool invert = false) : FourRotSplayTree() {
        choice = uniform_int_distribution<int>(0,p-1);
        this->invert = invert;
    }
    s* Search(int key);
};

class Scheme2_3Rot : public ThreeRotSplayTree
{
    default_random_engine generator;
    uniform_int_distribution<int> choice;
    void AccessSplay(s* x);
public:
    Scheme2_3Rot(int p = 1 << 1, bool invert = false) : ThreeRotSplayTree() {
        choice = uniform_int_distribution<int>(0,p-1);
        this->invert = invert;
    }
    s* Search(int key);
};

class Scheme2_1Rot : public OneRotSplayTree
{
    default_random_engine generator;
    uniform_int_distribution<int> choice;
    void AccessSplay(s* x);
public:
    Scheme2_1Rot(int p = 1 << 1, bool invert = false) : OneRotSplayTree() {
        choice = uniform_int_distribution<int>(0,p-1);
        this->invert = invert;
    }
    s* Search(int key);
};

class Scheme3_2Rot : public SplayTree
{
private:
    void AccessSplay(s* x);
    default_random_engine generator;
    uniform_int_distribution<int> choice;
public:
    Scheme3_2Rot(int p = 1 << 1, bool invert = false) : SplayTree() {
        choice = uniform_int_distribution<int>(0,p-1);
        this->invert = !invert;
    }
    s* Search(int key);
};

class Scheme3_4Rot : public FourRotSplayTree
{
    default_random_engine generator;
    uniform_int_distribution<int> choice;
    void AccessSplay(s* x);
public:
    Scheme3_4Rot(int p = 1 << 1, bool invert = false) : FourRotSplayTree() {
        choice = uniform_int_distribution<int>(0,p-1);
        this->invert = !invert;
    }
};

class Scheme3_3Rot : public ThreeRotSplayTree
{
    default_random_engine generator;
    uniform_int_distribution<int> choice;
    void AccessSplay(s* x);
public:
    Scheme3_3Rot(int p = 1 << 1, bool invert = false) : ThreeRotSplayTree() {
        choice = uniform_int_distribution<int>(0,p-1);
        this->invert = !invert;
    }
};


class Scheme3_1Rot : public OneRotSplayTree
{
    default_random_engine generator;
    uniform_int_distribution<int> choice;
    void AccessSplay(s* x);
public:
    Scheme3_1Rot(int p = 1 << 1, bool invert = false) : OneRotSplayTree() {
        choice = uniform_int_distribution<int>(0,p-1);
        this->invert = !invert;
    }
};

#endif //RANDOMIZED_SPLAY_TREES_TREES_H