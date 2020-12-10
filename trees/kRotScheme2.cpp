//
// Created by Zhi Wei Gan on 12/7/20.
//

#include "trees.h"

s* Scheme2_1Rot::Search(int key)
{
    s *z = root;
    while (z) {
        followedPointers += 1;
        if (z->key < key) z = z->right;
        else if (key < z->key) z = z->left;
        else {
            followedPointers -= 1;
            int action = this->choice(this->generator);
            if ((action == 0) != this->invert) this->AccessSplay(z);
            else if (z->parent != nullptr) this->AccessSplay(z->parent);
            return z;
        }
    }
    return nullptr;
}

s* Scheme2_3Rot::Search(int key)
{
    s *z = root;
    while (z) {
        followedPointers += 1;
        if (z->key < key) z = z->right;
        else if (key < z->key) z = z->left;
        else {
            followedPointers -= 1;
            int action = this->choice(this->generator);
            if ((action == 0) != this->invert) this->AccessSplay(z);
            else if (z->parent != nullptr) this->AccessSplay(z->parent);
            return z;
        }
    }
    return nullptr;
}

void Scheme2_1Rot::AccessSplay(s* x)
{
    while (x->parent) {
        if (x->parent->left == x) R_Rotate(x->parent);
        else L_Rotate(x->parent);
    }
}

void Scheme2_3Rot::AccessSplay(s* x)
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

void Scheme2_4Rot::AccessSplay(s* x)
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
                    }
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

s* Scheme2_4Rot::Search(int key)
{
    s *z = root;
    while (z) {
        followedPointers += 1;
        if (z->key < key) z = z->right;
        else if (key < z->key) z = z->left;
        else {
            followedPointers -= 1;
            int action = this->choice(this->generator);
            if ((action == 0) != this->invert) this->AccessSplay(z);
            // bool = 0, invert = 0, out = 0
            // bool = 1, invert = 0, out = 1
            // bool = 0, invert = 1, out = 1
            // bool = 1, invert = 1, out = 0
            else if (z->parent != nullptr) this->AccessSplay(z->parent);
            return z;
        }
    }
    return nullptr;
}