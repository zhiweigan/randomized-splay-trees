//
// Created by Zhi Wei Gan on 12/8/20.
//

#include "trees.h"

void Scheme3_1Rot::AccessSplay(s* x)
{
    while (x->parent) {
        int action = this->choice(this->generator);
        if (((action == 0) != this->invert)){
            rotationCount -= 1;
            followedPointers += 1;
            if (x->parent) {
                x = x->parent;
            }
            continue;
        }
        if (x->parent->left == x) R_Rotate(x->parent);
        else L_Rotate(x->parent);
    }
}

void Scheme3_3Rot::AccessSplay(s *x)
{
    while (x->parent) {
        int action = this->choice(this->generator);
        if (((action == 0) != this->invert)){
            rotationCount -= 1;
            followedPointers += 1;
            if (x->parent->parent && x->parent->parent->parent) {
                x = x->parent->parent->parent;
            } else {
                x = x->parent;
            }
            continue;
        }
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

void Scheme3_4Rot::AccessSplay(s *x) {
    while (x->parent) {
        int action = this->choice(this->generator);
        if (((action == 0) != this->invert)){
            rotationCount -= 1;
            followedPointers += 1;
            if (x->parent->parent && x->parent->parent->parent && x->parent->parent->parent->parent) {
                x = x->parent->parent->parent->parent;
            } else {
                x = x->parent;
            }
            continue;
        }
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