#ifndef BSTNODE_H
#define BSTNODE_H

class BSTNode {
    public:
    int value;
    BSTNode* left;
    BSTNode* right;
        BSTNode(const int& value) : left(nullptr), right(nullptr), value(value) {}
};


#endif // BSTNODE_H