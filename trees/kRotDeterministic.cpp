#include "trees.h"

using namespace std;

void ThreeRotSplayTree::AccessSplay(s* x)
{
    while (x->parent) {
        if (!x->parent->parent) {
            if (x->parent->left == x) R_Rotate(x->parent);
            else L_Rotate(x->parent);
        } else if (!x->parent->parent->parent) {
            if (x->parent->left == x && x->parent->parent->left == x->parent) {
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
        } else {
            if (x->parent->left == x) {
                if (x->parent->parent->left == x->parent) {
                    if (x->parent->parent->parent->left == x->parent->parent) {
                        R_Rotate(x->parent->parent->parent);
                        R_Rotate(x->parent->parent);
                        R_Rotate(x->parent);
                    } else {
                        R_Rotate(x->parent->parent);
                        R_Rotate(x->parent);
                        L_Rotate(x->parent);
                    }
                } else {
                    if (x->parent->parent->parent->left == x->parent->parent) {
                        R_Rotate(x->parent);
                        L_Rotate(x->parent);
                        R_Rotate(x->parent);
                    } else {
                        R_Rotate(x->parent);
                        L_Rotate(x->parent->parent);
                        L_Rotate(x->parent);
                    }
                }
            } else {
                if (x->parent->parent->left == x->parent) {
                    if (x->parent->parent->parent->left == x->parent->parent) {
                        L_Rotate(x->parent);
                        R_Rotate(x->parent->parent);
                        R_Rotate(x->parent);
                    } else {
                        L_Rotate(x->parent);
                        R_Rotate(x->parent);
                        L_Rotate(x->parent);
                    }
                } else {
                    if (x->parent->parent->parent->left == x->parent->parent) {
                        L_Rotate(x->parent->parent);
                        L_Rotate(x->parent);
                        R_Rotate(x->parent);
                    } else {
                        L_Rotate(x->parent->parent->parent);
                        L_Rotate(x->parent->parent);
                        L_Rotate(x->parent);
                    }

                }
            }

        }
    }
}

s* ThreeRotSplayTree::Search(int key)
{
    s *z = root;
    while (z) {
        followedPointers += 1;
        if (z->key < key) z = z->right;
        else if (key < z->key) z = z->left;
        else {
            followedPointers -= 1;
            this->AccessSplay(z);
            return z;
        }
    }
    return nullptr;
}

void OneRotSplayTree::AccessSplay(s* x)
{
    while (x->parent) {
        if (x->parent->left == x) R_Rotate(x->parent);
        else L_Rotate(x->parent);
    }
}

s* OneRotSplayTree::Search(int key)
{
    s *z = root;
    while (z) {
        followedPointers += 1;
        if (z->key < key) z = z->right;
        else if (key < z->key) z = z->left;
        else {
            followedPointers -= 1;
            this->AccessSplay(z);
            return z;
        }
    }
    return nullptr;
}

void FourRotSplayTree::AccessSplay(s* x)
{
    while (x->parent) {
        if (!x->parent->parent) {
            if (x->parent->left == x) R_Rotate(x->parent);
            else L_Rotate(x->parent);
        } else if (!x->parent->parent->parent) {
            if (x->parent->left == x && x->parent->parent->left == x->parent) {
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
        } else if (!x->parent->parent->parent->parent) {
            if (x->parent->left == x) {
                if (x->parent->parent->left == x->parent) {
                    if (x->parent->parent->parent->left == x->parent->parent) {
                        R_Rotate(x->parent->parent->parent);
                        R_Rotate(x->parent->parent);
                        R_Rotate(x->parent);
                    } else {
                        R_Rotate(x->parent->parent);
                        R_Rotate(x->parent);
                        L_Rotate(x->parent);
                    }
                } else {
                    if (x->parent->parent->parent->left == x->parent->parent) {
                        R_Rotate(x->parent);
                        L_Rotate(x->parent);
                        R_Rotate(x->parent);
                    } else {
                        R_Rotate(x->parent);
                        L_Rotate(x->parent->parent);
                        L_Rotate(x->parent);
                    }
                }
            } else {
                if (x->parent->parent->left == x->parent) {
                    if (x->parent->parent->parent->left == x->parent->parent) {
                        L_Rotate(x->parent);
                        R_Rotate(x->parent->parent);
                        R_Rotate(x->parent);
                    } else {
                        L_Rotate(x->parent);
                        R_Rotate(x->parent);
                        L_Rotate(x->parent);
                    }
                } else {
                    if (x->parent->parent->parent->left == x->parent->parent) {
                        L_Rotate(x->parent->parent);
                        L_Rotate(x->parent);
                        R_Rotate(x->parent);
                    } else {
                        L_Rotate(x->parent->parent->parent);
                        L_Rotate(x->parent->parent);
                        L_Rotate(x->parent);
                    }

                }
            }

        } else {
            if (x->parent->left == x) {
                if (x->parent->parent->left == x->parent) {
                    if (x->parent->parent->parent->left == x->parent->parent) {
                        if (x->parent->parent->parent->parent->left == x->parent->parent->parent) {
                            R_Rotate(x->parent->parent->parent->parent);
                            R_Rotate(x->parent->parent->parent);
                            R_Rotate(x->parent->parent);
                            R_Rotate(x->parent);
                        } else {
                            R_Rotate(x->parent->parent->parent);
                            R_Rotate(x->parent->parent);
                            R_Rotate(x->parent);
                            L_Rotate(x->parent);
                        }
                    } else {
                        if(x->parent->parent->parent->parent->left == x->parent->parent->parent) {
                            R_Rotate(x->parent->parent);
                            R_Rotate(x->parent);
                            L_Rotate(x->parent);
                            R_Rotate(x->parent);
                        } else {
                            R_Rotate(x->parent->parent);
                            R_Rotate(x->parent);
                            L_Rotate(x->parent->parent);
                            L_Rotate(x->parent);
                        }
                    }
                } else {
                    if (x->parent->parent->parent->left == x->parent->parent) {
                        if (x->parent->parent->parent->parent->left == x->parent->parent->parent) {
                            R_Rotate(x->parent);
                            L_Rotate(x->parent);
                            R_Rotate(x->parent->parent);
                            R_Rotate(x->parent);
                        } else {
                            R_Rotate(x->parent);
                            L_Rotate(x->parent);
                            R_Rotate(x->parent);
                            L_Rotate(x->parent);
                        }
                    } else {
                        if (x->parent->parent->parent->parent->left == x->parent->parent->parent) {
                            R_Rotate(x->parent);
                            L_Rotate(x->parent->parent);
                            L_Rotate(x->parent);
                            R_Rotate(x->parent);
                        } else {
                            R_Rotate(x->parent);
                            L_Rotate(x->parent->parent->parent);
                            L_Rotate(x->parent->parent);
                            L_Rotate(x->parent);
                        }
                    }
                }
            } else {
                if (x->parent->parent->left == x->parent) {
                    if (x->parent->parent->parent->left == x->parent->parent) {
                        if (x->parent->parent->parent->parent->left == x->parent->parent->parent) {
                            L_Rotate(x->parent);
                            R_Rotate(x->parent->parent->parent);
                            R_Rotate(x->parent->parent);
                            R_Rotate(x->parent);
                        } else {
                            L_Rotate(x->parent);
                            R_Rotate(x->parent->parent);
                            R_Rotate(x->parent);
                            L_Rotate(x->parent);
                        }
                    } else {
                        if (x->parent->parent->parent->parent->left == x->parent->parent->parent) {
                            L_Rotate(x->parent);
                            R_Rotate(x->parent);
                            L_Rotate(x->parent);
                            R_Rotate(x->parent);
                        } else {
                            L_Rotate(x->parent);
                            R_Rotate(x->parent);
                            L_Rotate(x->parent->parent);
                            L_Rotate(x->parent);
                        }
                    }d 
                } else {
                    if (x->parent->parent->parent->left == x->parent->parent) {
                        if (x->parent->parent->parent->parent->left == x->parent->parent->parent) {
                            L_Rotate(x->parent->parent);
                            L_Rotate(x->parent);
                            R_Rotate(x->parent->parent);
                            R_Rotate(x->parent);
                        } else {
                            L_Rotate(x->parent->parent);
                            L_Rotate(x->parent);
                            R_Rotate(x->parent);
                            L_Rotate(x->parent);
                        }
                    } else {
                        if (x->parent->parent->parent->parent->left == x->parent->parent->parent) {
                            L_Rotate(x->parent->parent->parent);
                            L_Rotate(x->parent->parent);
                            L_Rotate(x->parent);
                            R_Rotate(x->parent);
                        } else {
                            L_Rotate(x->parent->parent->parent->parent);
                            L_Rotate(x->parent->parent->parent);
                            L_Rotate(x->parent->parent);
                            L_Rotate(x->parent);
                        }
                    }
                }
            }
        }
    }
}

s* FourRotSplayTree::Search(int key)
{
    s *z = root;
    while (z) {
        followedPointers += 1;
        if (z->key < key) z = z->right;
        else if (key < z->key) z = z->left;
        else {
            followedPointers -= 1;
            this->AccessSplay(z);
            return z;
        }
    }
    return nullptr;
}
