//
// Created by Zhi Wei Gan on 11/25/20.
//
// Got from https://www.tutorialspoint.com/cplusplus-program-to-implement-splay-tree

#include "trees.h"
using namespace std;

//void TemplateSplayTree::L_Rotate(s* x)
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
//void TemplateSplayTree::R_Rotate(s* x)
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
//void TemplateSplayTree::Splay(s *x)
//{
//    while (x->parent) {
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
//    }
//}
//
//s* TemplateSplayTree::subtree_minimum(s *u) {
//    while (u->left) u = u->left;
//    return u;
//}
//
//s* TemplateSplayTree::subtree_maximum(s *u) {
//    while (u->right) u = u->right;
//    return u;
//}
//
//void TemplateSplayTree::Insert(int key)
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
//void TemplateSplayTree::replace(s *u, s *v) {
//    if (!u->parent) root = v;
//    else if (u == u->parent->left) u->parent->left = v;
//    else u->parent->right = v;
//    if (v) v->parent = u->parent;
//}
//
//void TemplateSplayTree::Delete(int key)//delete node
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
//s* TemplateSplayTree::Search(int key) //searching
//{
//    s *z = root;
//    while (z) {
//        if (z->key < key){
//            if (z->right == nullptr){
//                this->Splay(z);
//                return root;
//            }
//            else z = z->right;
//        }
//        else if (key < z->key){
//            if (z->left == nullptr){
//                this->Splay(z);
//                return root;
//            }
//            else z = z->left;
//        }
//        else {
//            this->Splay(z);
//            return root;
//        }
//    }
//    return nullptr;
//}
//
