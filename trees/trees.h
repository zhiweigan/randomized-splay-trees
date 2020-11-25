//
// Created by Zhi Wei Gan on 11/25/20.
//

#ifndef RANDOMIZED_SPLAY_TREES_TREES_H
#define RANDOMIZED_SPLAY_TREES_TREES_H

#include <iostream>
#include <cstdio>
#include <cstdlib>

struct s
{
    int k;
    s* lch;
    s* rch;
};

class SplayTree
{
protected:
    virtual s* RR_Rotate(s* k2);
    virtual s* LL_Rotate(s* k2);
    virtual s* Splay(int key, s* root);
    virtual s* New_Node(int key);
public:
    virtual s* Insert(int key, s* root);
    virtual s* Delete(int key, s* root);
    virtual s* Search(int key, s* root);
    void InOrder(s* root);
    void Clear(s* root);
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
