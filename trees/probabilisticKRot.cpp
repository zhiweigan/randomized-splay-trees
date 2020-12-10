//
// Created by Zhi Wei Gan on 12/7/20.
//

#include "trees.h"

s* Scheme1_3Rot::Search(int key)
{
    s *z = root;
    while (z) {
        followedPointers += 1;
        if (z->key < key) z = z->right;
        else if (key < z->key) z = z->left;
        else {
            int action = this->choice(this->generator);
            if ((action == 0) != this->invert) this->AccessSplay(z);
            return z;
        }
    }
    return nullptr;
}

s* Scheme1_1Rot::Search(int key)
{
    s *z = root;
    while (z) {
        followedPointers += 1;
        if (z->key < key) z = z->right;
        else if (key < z->key) z = z->left;
        else {
            int action = this->choice(this->generator);
            if ((action == 0) != this->invert) this->AccessSplay(z);
            return z;
        }
    }
    return nullptr;
}

s* Scheme1_4Rot::Search(int key)
{
    s *z = root;
    while (z) {
        followedPointers += 1;
        if (z->key < key) z = z->right;
        else if (key < z->key) z = z->left;
        else {
            int action = this->choice(this->generator);
            if ((action == 0) != this->invert) this->AccessSplay(z);

            return z;
        }
    }
    return nullptr;
}
