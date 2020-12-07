#include "trees.h"

using namespace std;

void EvenSplayTree::AccessSplay(s* x) {
    while (x->parent) {
        if (x->parent->left == x) {
            if (x->parent->parent->left == x->parent) {
                R_Rotate(x->parent->parent);
                R_Rotate(x->parent);
            } else {
                R_Rotate(x->parent);
                L_Rotate(x->parent);
            }
        } else {
            if (x->parent->parent->left == x->parent) {
                L_Rotate(x->parent);
                R_Rotate(x->parent);
            } else {
                L_Rotate(x->parent->parent);
                L_Rotate(x->parent);
            }
        }
    }
}

s* EvenSplayTree::Search(int key) {
    s* z = root;
    int k = 0;
    while (z) {
        if (z->key < key) z = z->right;
        else if (z->key > key) z = z->left;
        else {
            if (k % 2) {
                this->AccessSplay(z->parent);
            }
            else {
                this->AccessSplay(z);
            }
            return z;
        }
        ++k;
    }
}