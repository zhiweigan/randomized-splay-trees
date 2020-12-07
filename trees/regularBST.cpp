//
// Created by Zhi Wei Gan on 12/7/20.
//

#include "trees.h"

void BST::Insert(int key)
{
    s *z = root;
    s *p = nullptr;

    while (z) {
        p = z;
        if (z->key < key) z = z->right;
        else z = z->left;
        followedPointers += 1;
    }

    z = new s(key);
    z->parent = p;

    if (!p) root = z;
    else if (p->key < z->key) p->right = z;
    else p->left = z;

    p_size++;
}

s* BST::Search(int key) {
    s *z = root;
    while (z) {
        followedPointers += 1;
        if (z->key < key) z = z->right;
        else if (key < z->key) z = z->left;
        else return z;
    }
    return nullptr;
}

void BST::Delete(int key)//delete node
{
    s *z = this->Search(key);
    if (!z) return;

    if (!z->left) this->replace(z, z->right);
    else if (!z->right) this->replace(z, z->left);
    else {
        s *y = subtree_minimum(z->right);
        if (y->parent != z) {
            this->replace(y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        this->replace(z, y);
        y->left = z->left;
        y->left->parent = y;
    }

    delete z;
    p_size--;
}