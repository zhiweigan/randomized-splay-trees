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
protected:
    virtual void L_Rotate(s* k2);
    virtual void R_Rotate(s* k2);
    virtual void Splay(s* x);
    s* subtree_minimum(s *u);
    s* subtree_maximum(s *u);
    void replace(s *u, s *v);
    unsigned long p_size;
public:
    SplayTree() : root(nullptr), p_size(0) { }
    virtual void Insert(int key);
    virtual void Delete(int key);
    virtual s* Search(int key);
    s* root;
};

class Scheme1SplayTree : public SplayTree
{
private:
    void AccessSplay(s* x);
    default_random_engine generator;
    uniform_int_distribution<int> choice;
public:
    Scheme1SplayTree(int p = 1 << 10) : SplayTree() {
        choice = uniform_int_distribution<int>(0,p);
    }
    s* Search(int key);
};

// Uncomment ONLY the ones you want to implement
class TemplateSplayTree : public SplayTree
{
//private:
//    s* RR_Rotate(s* k2);
//    s* LL_Rotate(s* k2);
//    s* Splay(int key, s* root);
//    s* New_Node(int key);
//public:
//    s* Insert(int key, s* root);
//    s* Delete(int key, s* root);
//    s* Search(int key, s* root);
};

#endif //RANDOMIZED_SPLAY_TREES_TREES_H

class ThreeRotSplayTree : public SplayTree
{
    private:
        void AccessSplay(s* x);
    public:
    ThreeRotSplayTree(int p = 1 << 10) : SplayTree() {
        choice = uniform_int_distribution<int>(0, p);
    }
    s* Search(int key);
}

class OneRotSplayTree : public SplayTree
{
    private:
        void AccessSplay(s* x);
    public:
    OneRotSplayTree(int p = 1 << 10) : SplayTree() {
        choice = uniform_int_distribution<int>(0, p);
    }
    s* Search(int key);

}