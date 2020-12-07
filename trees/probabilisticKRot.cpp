//
// Created by Zhi Wei Gan on 12/7/20.
//

#include "trees.h"

s* randomThreeRotSplayTree::Search(int key)
{
    s *z = root;
    while (z) {
        followedPointers += 1;
        if (z->key < key) z = z->right;
        else if (key < z->key) z = z->left;
        else {
            int action = this->choice(this->generator);
            if (action == 0) this->AccessSplay(z);
            return z;
        }
    }
    return nullptr;
}

s* randomOneRotSplayTree::Search(int key)
{
    s *z = root;
    while (z) {
        followedPointers += 1;
        if (z->key < key) z = z->right;
        else if (key < z->key) z = z->left;
        else {
            int action = this->choice(this->generator);
            if (action == 0) this->AccessSplay(z);
            return z;
        }
    }
    return nullptr;
}

s* randomFourRotSplayTree::Search(int key)
{
    s *z = root;
    while (z) {
        followedPointers += 1;
        if (z->key < key) z = z->right;
        else if (key < z->key) z = z->left;
        else {
            int action = this->choice(this->generator);
            if (action == 0) this->AccessSplay(z);
            return z;
        }
    }
    return nullptr;
}
