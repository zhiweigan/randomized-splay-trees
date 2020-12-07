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
//
//using namespace std;
//
//void Scheme1SplayTree::L_Rotate(s* x)
//{
//    s *y = x->right;
//    if (y) {
//        x->right = y->left;
//        if (y->left) y->left->parent = x;
//        y->parent = x->parent;
//    }
//
//    if (!x->parent) root = y;
//    else if (x == x->parent->left) x->parent->left = y;
//    else x->parent->right = y;
//    if (y) y->left = x;
//    x->parent = y;
//}
//
//void Scheme1SplayTree::R_Rotate(s* x)
//{
//    s *y = x->left;
//    if (y) {
//        x->left = y->right;
//        if (y->right) y->right->parent = x;
//        y->parent = x->parent;
//    }
//    if (!x->parent) root = y;
//    else if (x == x->parent->left) x->parent->left = y;
//    else x->parent->right = y;
//    if (y) y->right = x;
//    x->parent = y;
//}
//
//void Scheme1SplayTree::Splay(s *x)
//{
//    while (x->parent) {
//        int action = this->choice(this->generator);
//
//        if (!x->parent->parent) {
//            if (x->parent->left == x) R_Rotate(x->parent);
//            else L_Rotate(x->parent);
//        } else if (x->parent->left == x && x->parent->parent->left == x->parent) {
//            R_Rotate(x->parent->parent);
//            R_Rotate(x->parent);
//        } else if (x->parent->right == x && x->parent->parent->right == x->parent) {
//            L_Rotate(x->parent->parent);
//            L_Rotate(x->parent);
//        } else if (x->parent->left == x && x->parent->parent->right == x->parent) {
//            R_Rotate(x->parent);
//            L_Rotate(x->parent);
//        } else {
//            L_Rotate(x->parent);
//            R_Rotate(x->parent);
//        }
//
//    }
//}

void Scheme1SplayTree::AccessSplay(s *x)
{
    while (x->parent) {

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
//
//s* Scheme1SplayTree::subtree_minimum(s *u) {
//    while (u->left) u = u->left;
//    return u;
//}
//
//s* Scheme1SplayTree::subtree_maximum(s *u) {
//    while (u->right) u = u->right;
//    return u;
//}
//
//void Scheme1SplayTree::Insert(int key)
//{
//    s *z = root;
//    s *p = nullptr;
//
//    while (z) {
//        p = z;
//        if (z->key < key) z = z->right;
//        else z = z->left;
//    }
//
//    z = new s(key);
//    z->parent = p;
//
//    if (!p) root = z;
//    else if (p->key < z->key) p->right = z;
//    else p->left = z;
//
//    this->Splay(z);
//    p_size++;
//}
//
//void Scheme1SplayTree::replace(s *u, s *v) {
//    if (!u->parent) root = v;
//    else if (u == u->parent->left) u->parent->left = v;
//    else u->parent->right = v;
//    if (v) v->parent = u->parent;
//}
//
//void Scheme1SplayTree::Delete(int key)//delete node
//{
//    s *z = this->Search(key);
//    if (!z) return;
//
//    this->Splay(z);
//
//    if (!z->left) this->replace(z, z->right);
//    else if (!z->right) this->replace(z, z->left);
//    else {
//        s *y = subtree_minimum(z->right);
//        if (y->parent != z) {
//            this->replace(y, y->right);
//            y->right = z->right;
//            y->right->parent = y;
//        }
//        this->replace(z, y);
//        y->left = z->left;
//        y->left->parent = y;
//    }
//
//    delete z;
//    p_size--;
//}
//
s* Scheme1SplayTree::Search(int key) //searching
{
    s *z = root;
    while (z) {
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