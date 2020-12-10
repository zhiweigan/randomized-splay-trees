//
// Created by Zhi Wei Gan on 12/7/20.
//

//
// Created by Zhi Wei Gan on 11/25/20.
//

#include "trees.h"

using namespace std;

// To add a new tree, copy the contents of this file to another file and implement ONLY the functions we need to change.
// We let polymorphism take care of the rest.

//======================================================================================================================


void Scheme3_2Rot::AccessSplay(s *x)
{
    while (x->parent) {
        int action = this->choice(this->generator);
        if (((action == 0) != this->invert) && x->parent->parent){
            x = x->parent->parent;
            continue;
        }

        if (!x->parent->parent) {
            if (x->parent->left == x) R_Rotate(x->parent);
            else L_Rotate(x->parent);
        } else if (x->parent->left == x && x->parent->parent->left == x->parent) {
            R_Rotate(x->parent->parent);
            R_Rotate(x->parent);
        } else if (x->parent->right == x && x->parent->parent->right == x->parent) {
            L_Rotate(x->parent->parent);
            L_Rotate(x->parent);
        } else if (x->parent->left == x && x->parent->parent->right == x->parent) {
            R_Rotate(x->parent);
            L_Rotate(x->parent);
        } else {
            L_Rotate(x->parent);
            R_Rotate(x->parent);
        }

    }
}

s* Scheme3_2Rot::Search(int key) //searching
{
    s *z = root;
    while (z) {
        followedPointers += 1;
        if (z->key < key) z = z->right;
        else if (key < z->key) z = z->left;
        else {
            this->AccessSplay(z);
            return z;
        }
    }
    return nullptr;
}