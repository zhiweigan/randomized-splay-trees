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

//s* HalfSplayTree::RR_Rotate(s* k2)
//{
//    s* k1 = k2->lch;
//    k2->lch = k1->rch;
//    k1->rch = k2;
//    return k1;
//}
//
//s* HalfSplayTree::LL_Rotate(s* k2)
//{
//    s* k1 = k2->rch;
//    k2->rch = k1->lch;
//    k1->lch = k2;
//    return k1;
//}
//
s* HalfSplayTree::Splay(int key, s* root)
{
    if (!root)
        return NULL;
    s header;
    header.lch= header.rch = NULL;
    s* LeftTreeMax = &header;
    s* RightTreeMin = &header;

    default_random_engine generator;
    uniform_int_distribution<int> choice(0, 100);
    while (1)
    {
        int action = choice(generator);

        if (key < root->k)
        {
            if (!root->lch)
                break;
            if (key< root->lch->k && action < 80)
            {
                root = RR_Rotate(root);
                if (!root->lch)
                    break;
            }
            if (action < 80) {
                RightTreeMin->lch= root;
                RightTreeMin = RightTreeMin->lch;
                root = root->lch;
                RightTreeMin->lch = NULL;
            } else{
                root = root->lch;
            }
        }
        else if (key > root->k)
        {
            if (!root->rch)
                break;
            if (key > root->rch->k && action < 80)
            {
                root = LL_Rotate(root);
                if (!root->rch)
                    break;
            }
            LeftTreeMax->rch= root;
            LeftTreeMax = LeftTreeMax->rch;
            root = root->rch;
            LeftTreeMax->rch = NULL;
        }
        else
            break;
    }
    LeftTreeMax->rch = root->lch;
    RightTreeMin->lch = root->rch;
    root->lch = header.rch;
    root->rch = header.lch;
    return root;
}
//
//s* HalfSplayTree::New_Node(int key)
//{
//    s* p_node = new s;
//    if (!p_node)
//    {
//        fprintf(stderr, "Out of memory!\n");
//        exit(1);
//    }
//    p_node->k = key;
//    p_node->lch = p_node->rch = NULL;
//    return p_node;
//}
//
//s* HalfSplayTree::Insert(int key, s* root)
//{
//    static s* p_node = NULL;
//    if (!p_node)
//        p_node = New_Node(key);
//    else
//        p_node->k = key;
//    if (!root)
//    {
//        root = p_node;
//        p_node = NULL;
//        return root;
//    }
//    root = Splay(key, root);
//    if (key < root->k)
//    {
//        p_node->lch= root->lch;
//        p_node->rch = root;
//        root->lch = NULL;
//        root = p_node;
//    }
//    else if (key > root->k)
//    {
//        p_node->rch = root->rch;
//        p_node->lch = root;
//        root->rch = NULL;
//        root = p_node;
//    }
//    else
//        return root;
//    p_node = NULL;
//    return root;
//}
//
//s* HalfSplayTree::Delete(int key, s* root)//delete node
//{
//    s* temp;
//    if (!root)//if tree is empty
//        return NULL;
//    root = Splay(key, root);
//    if (key != root->k)//if tree has one item
//        return root;
//    else
//    {
//        if (!root->lch)
//        {
//            temp = root;
//            root = root->rch;
//        }
//        else
//        {
//            temp = root;
//            root = Splay(key, root->lch);
//            root->rch = temp->rch;
//        }
//        free(temp);
//        return root;
//    }
//}
//
//s* HalfSplayTree::Search(int key, s* root) //seraching
//{
//    return Splay(key, root);
//}
